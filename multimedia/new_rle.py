import os

def run_length_encode(input_string):
    encoding = ''
    i = 0

    while i < len(input_string):
        count = 1
        while i + 1 < len(input_string) and input_string[i] == input_string[i+1]:
            i += 1
            count += 1

        while count > 0:
            encoded_count = min(count, 255)
            encoding += chr(encoded_count) + input_string[i]
            count -= encoded_count
            
        i += 1
    return encoding

def run_length_decode(input_string):
    decoding = ''
    i = 0
    while i < len(input_string):
        count = ord(input_string[i])
        decoding += input_string[i+1] * count
        i += 2
    return decoding



# Read from the input file
with open('file.txt', 'r') as file:
    data = file.read().replace('\n', '\\n')
print("Original file size: ", os.stat('file.txt').st_size, "bytes")

# Encode the data
encoded_data = run_length_encode(data)

# Write the encoded data to the output file
with open('encoded_file.txt', 'w') as file:
    file.write(encoded_data)
print("Encoded file size: ", os.stat('encoded_file.txt').st_size, "bytes")


# Decode the encoded data
decoded_data = run_length_decode(encoded_data).replace('\\n', '\n')

# Write the decoded data to another output file
with open('decoded_file.txt', 'w') as file:
    file.write(decoded_data)
print("Decoded file size: ", os.stat('decoded_file.txt').st_size, "bytes")
