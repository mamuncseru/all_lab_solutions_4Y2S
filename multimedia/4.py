class Node:
    def __init__(self, char, freq):
        self.char = char
        self.freq = freq
        self.left = None
        self.right = None

    def __lt__(self, other):
        return self.freq < other.freq

import heapq
import os
from collections import Counter

def calculate_freq(input_string):
    # Calculate frequency of each character
    return Counter(input_string)

def huffman_tree(freq_dict):
    # Initialize a priority queue with the frequency dictionary
    priority_queue = [Node(char, freq) for char, freq in freq_dict.items()]
    heapq.heapify(priority_queue)

    while len(priority_queue) > 1:
        node1 = heapq.heappop(priority_queue)
        node2 = heapq.heappop(priority_queue)
        merged = Node(None, node1.freq + node2.freq)
        merged.left = node1
        merged.right = node2
        heapq.heappush(priority_queue, merged)

    return heapq.heappop(priority_queue)


def huffman_code(tree, prefix="", code={}):
    if tree is None:
        return code

    if tree.char is not None:
        code[tree.char] = prefix

    code.update(huffman_code(tree.left, prefix + "0"))
    code.update(huffman_code(tree.right, prefix + "1"))
    return code

def huffman_encode(input_string, code_dict):
    return ''.join(code_dict[char] for char in input_string)

def huffman_decode(encoded_string, tree):
    decoded_string = ""
    current = tree
    for bit in encoded_string:
        if bit == "0":
            current = current.left
        else:
            current = current.right

        if current.char:
            decoded_string += current.char
            current = tree

    return decoded_string

# Read from the input file
with open('file3.txt', 'r') as file:
    data = file.read()

print("Original file size: ", os.stat('file3.txt').st_size, "bytes")

# Calculate frequency and create Huffman tree and code
freq_dict = calculate_freq(data)
huff_tree = huffman_tree(freq_dict)
huff_code = huffman_code(huff_tree)

# Encode the data
encoded_data = huffman_encode(data, huff_code)

# Write the encoded data to the output file
with open('encoded_file.txt', 'w') as file:
    file.write(str(huff_code) + "\n" + encoded_data)

print("Encoded file size: ", os.stat('encoded_file.txt').st_size, "bytes")

# Decode the encoded data
decoded_data = huffman_decode(encoded_data, huff_tree)

# Write the decoded data to another output file
with open('decoded_file.txt', 'w') as file:
    file.write(decoded_data)

print("Decoded file size: ", os.stat('decoded_file.txt').st_size, "bytes")
