import os

def rle_encoder(input_string):
    encoding = ''
    i = 0
    while i < len(input_string):
        count = 1

        while i+1 < len(input_string) and input_string[i] == input_string[i+1]:
            i += 1
            count += 1
        
        while count > 0:
            encoded_count = min(count, 255)
            encoding += chr(encoded_count) + input_string[i]
            count -= encoded_count
        
        i += 1
    return encoding
    
def rle_decoder(encoded_string):
    decoding = ''
    i = 0
    while i < len(encoded_string):
        decoding += encoded_string[i+1] * ord(encoded_string[i])
        i += 2
    return decoding

# read from input data
with open('file.txt', 'r') as f:
    input_data = f.read().replace('\n', '\\n')

print("Original file size: ", os.stat('file.txt').st_size, "bytes")

# encode the input data
encoded_data = rle_encoder(input_data)

# write encoded data
with open('encoded_file.txt', 'w') as f:
    f.write(encoded_data)
print("Encoded file size: ", os.stat('encoded_file.txt').st_size, "bytes")

# decode the encoded data
decoded_data = rle_decoder(encoded_data).replace('\\n', '\n')

# write decoded data
with open('decoded_file.txt', 'w') as f:
    f.write(decoded_data)

print("Decoded file size: ", os.stat("decoded_file.txt").st_size, "bytes")