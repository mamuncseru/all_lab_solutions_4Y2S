import os

def lzw_encoder(input_string):
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

def lzw_decoder(encoded_string):
    # Build the initial dictionary with ASCII values
    dictionary = {i: chr(i) for i in range(256)}
    temp = chr(encoded_string[0])
    dictionary_size = 256
    result = temp

    for code in encoded_string[1:]:
        if code not in dictionary:
            dictionary[code] = temp + temp[0]
        result += dictionary[code]
        dictionary[dictionary_size] = temp + dictionary[code][0]
        dictionary_size += 1
        temp = dictionary[code]

    return result



# Read data from file
with open('file2.txt', 'r') as f:
    data = f.read()

print('Original file size: ', os.stat('file2.txt').st_size, "bytes")

# encode data
encoded_data = lzw_encoder(data)

# write encode data
with open('encoded_file2.txt', 'w') as f:
    for item in encoded_data:
        f.write("%s "%item)

print('Encoder file size: ', os.stat('encoded_file2.txt').st_size, 'bytes')

# read encode data
with open('encoded_file2.txt', 'r') as f:
    encoded_data = list(map(int, f.read().split()))

# decode the encoded data
decoded_data = lzw_decoder(encoded_data)

# write decode data
with open('decoded_file2.txt', 'w') as f:
    f.write(decoded_data)

print("Decoded file size: ", os.stat('decoded_file2.txt').st_size, "bytes")
