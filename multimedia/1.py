import re
import os

def run_length_encode(input_string):
    return ''.join(f"{len(match.group())};{match.group()[0]};" for match in re.finditer(r'(.)\1*', input_string))

def run_length_decode(input_string):
    elements = input_string.split(';')
    if elements[-1] == '':
        elements.pop()
    decoded_string = ''
    for i in range(0, len(elements), 2):
        decoded_string += int(elements[i]) * elements[i + 1]
    return decoded_string

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
