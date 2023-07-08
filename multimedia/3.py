from collections import Counter
import numpy as np
import os

def calculate_cumulative_prob(input_string):
    # Calculate frequency of each character
    freq = Counter(input_string)
    total_len = len(input_string)
    
    # Calculate probability and cumulative probability
    prob_dict = {}
    cum_prob = 0
    for key, value in freq.items():
        prob_dict[key] = {'prob': value/total_len, 'cum_prob': cum_prob}
        cum_prob += value/total_len

    return prob_dict

def arithmetic_encode(input_string, prob_dict):
    lower_bound = 0
    upper_bound = 1

    for char in input_string:
        range_ = upper_bound - lower_bound
        upper_bound = lower_bound + range_ * (prob_dict[char]['cum_prob'] + prob_dict[char]['prob'])
        lower_bound = lower_bound + range_ * prob_dict[char]['cum_prob']

    return (lower_bound + upper_bound) / 2

def arithmetic_decode(encoded_value, prob_dict, length):
    decoded_string = ""
    for _ in range(length):
        for char, values in prob_dict.items():
            if values['cum_prob'] <= encoded_value < values['cum_prob'] + values['prob']:
                decoded_string += char
                encoded_value = (encoded_value - values['cum_prob']) / values['prob']
                break

    return decoded_string

# Read from the input file
with open('file3.txt', 'r') as file:
    data = file.read()

print("Original file size: ", os.stat('file3.txt').st_size, "bytes")

# Calculate probability and cumulative probability
prob_dict = calculate_cumulative_prob(data)

# Encode the data
encoded_data = arithmetic_encode(data, prob_dict)

# Write the encoded data to the output file
with open('encoded_file.txt', 'w') as file:
    file.write(str(encoded_data))

print("Encoded file size: ", os.stat('encoded_file.txt').st_size, "bytes")

# Read the encoded data from the file
with open('encoded_file.txt', 'r') as file:
    encoded_data = float(file.read())

# Decode the encoded data
decoded_data = arithmetic_decode(encoded_data, prob_dict, len(data))

# Write the decoded data to another output file
with open('decoded_file.txt', 'w') as file:
    file.write(decoded_data)

print("Decoded file size: ", os.stat('decoded_file.txt').st_size, "bytes")
