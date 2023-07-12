/*
8. Write a program to implement MD5 one way hash function.


MD5 (Message Digest Algorithm 5) is a widely used cryptographic hash function that produces a 128-bit (16-byte) hash value, typically represented as a sequence of hexadecimal digits. It takes an input message of arbitrary length and applies a series of operations to produce the hash value. MD5 is designed to be a one-way function, meaning that it is computationally infeasible to reverse the process and obtain the original message from the hash value.

Here's a high-level description of the MD5 algorithm:

1. Pad the input message: The message is padded to a length that is a multiple of 512 bits, leaving room for a 64-bit representation of the original message length.

2. Initialize state variables: The algorithm starts with four 32-bit state variables (A, B, C, and D) that are initialized to fixed constants.

3. Process the message in 512-bit blocks: The padded message is divided into 512-bit blocks, and each block is processed in a series of rounds.

4. Round 1: In this round, a series of bitwise operations (bitwise XOR, logical AND, logical OR, etc.) are applied to the state variables and the message block.

5. Round 2: Similar to Round 1, a different set of bitwise operations are applied to the state variables and the message block.

6. Round 3: Similar to Rounds 1 and 2, a different set of bitwise operations are applied to the state variables and the message block.

7. Round 4: Similar to Rounds 1, 2, and 3, a different set of bitwise operations are applied to the state variables and the message block.

8. Finalize the hash value: The resulting state variables (A, B, C, D) are concatenated and converted to a 128-bit hash value.

*/