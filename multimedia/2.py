import os

# LZW Encoding
def lzw_encode(input_string):
    # Build the initial dictionary with ASCII values
    dictionary = {chr(i): i for i in range(256)}
    result = []
    temp = ""
    dictionary_size = 256

    for char in input_string:
        temp += char
        if temp not in dictionary:
            dictionary[temp] = dictionary_size
            dictionary_size += 1
            result.append(dictionary[temp[:-1]])
            temp = char

    if temp:
        result.append(dictionary[temp])

    return result

# LZW Decoding
def lzw_decode(input_data):
    # Build the initial dictionary with ASCII values
    dictionary = {i: chr(i) for i in range(256)}
    dictionary_size = 256
    temp = chr(input_data[0])
    result = temp

    for code in input_data[1:]:
        if code not in dictionary:
            dictionary[code] = temp + temp[0]
        result += dictionary[code]
        dictionary[dictionary_size] = temp + dictionary[code][0]
        dictionary_size += 1
        temp = dictionary[code]

    return result

# Read from the input file
with open('file2.txt', 'r') as file:
    data = file.read()

print("Original file size: ", os.stat('file2.txt').st_size, "bytes")

# Encode the data
encoded_data = lzw_encode(data)

# Write the encoded data to the output file
with open('encoded_file2.txt', 'w') as file:
    for item in encoded_data:
        file.write("%s " % item)

print("Encoded file size: ", os.stat('encoded_file2.txt').st_size, "bytes")

# Convert encoded data back to list of integers
with open('encoded_file2.txt', 'r') as file:
    encoded_data = list(map(int, file.read().split()))

# Decode the encoded data
decoded_data = lzw_decode(encoded_data)

# Write the decoded data to another output file
with open('decoded_file2.txt', 'w') as file:
    file.write(decoded_data)

print("Decoded file size: ", os.stat('decoded_file2.txt').st_size, "bytes")
