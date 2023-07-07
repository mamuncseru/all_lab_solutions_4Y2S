/*

The RSA algorithm is an asymmetric cryptographic algorithm widely used for secure communication and data encryption. It involves the use of a public key and a private key, with encryption being performed using the recipient's public key and decryption using the recipient's private key. RSA is based on the mathematical properties of prime numbers and modular arithmetic.

Here's a high-level description of the RSA encryption and decryption process:

RSA Encryption:
1. Key Generation:
   - Choose two distinct prime numbers, `p` and `q`.
   - Calculate the modulus `n` as the product of `p` and `q`.
   - Calculate Euler's totient function `phi(n)` as `(p-1) * (q-1)`.
   - Choose a public exponent `e` such that `1 < e < phi(n)` and `gcd(e, phi(n)) = 1`. Typically, `e` is a small prime number like 65537.
   - Calculate the private exponent `d` as the modular inverse of `e` modulo `phi(n)`, i.e., `d = e^-1 mod phi(n)`.
   - The public key is `(e, n)` and the private key is `(d, n)`.

2. Encryption:
   - Convert the plaintext message to its numeric representation (e.g., using ASCII or Unicode).
   - Split the numeric representation into blocks if necessary.
   - For each block, calculate the ciphertext `C` as `C = M^e mod n`, where `M` is the numeric representation of the plaintext message and `e` and `n` are the recipient's public key values.
   - The resulting ciphertext is the encrypted message.

RSA Decryption:
1. Decryption:
   - For each ciphertext block, calculate the plaintext `M` as `M = C^d mod n`, where `C` is the numeric representation of the ciphertext and `d` and `n` are the recipient's private key values.
   - Convert the numeric representation of the plaintext back to its original form (e.g., ASCII or Unicode).


*/

#include <bits/stdc++.h>
using namespace std;

// Function to calculate the greatest common divisor (GCD) of two numbers
long long int gcd(long long int a, long long int b)
{
    while (b != 0)
    {
        long long int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to perform modular exponentiation (base^exponent mod modulus)
long long int modularExponentiation(long long int base, long long int exponent, long long int modulus)
{
    long long int result = 1;
    base = base % modulus;

    while (exponent > 0)
    {
        if (exponent % 2 == 1)
            result = (result * base) % modulus;

        base = (base * base) % modulus;
        exponent /= 2;
    }

    return result;
}

int main()
{
    // Step 1: Key Generation
    long long int p = 61;      // Prime number 1
    long long int q = 53;      // Prime number 2
    long long int n = p * q;   // Modulus
    long long int phi = (p - 1) * (q - 1);  // Euler's totient function

    // Find a suitable public exponent e such that 1 < e < phi and gcd(e, phi) = 1
    long long int e = 17;
    while (e >= phi || gcd(e, phi) != 1)
        e++;


    // Calculate the private exponent d as the modular inverse of e modulo phi
    long long int d = 1;
    while ((d * e) % phi != 1)
        d++;


    // Step 2: Encryption
    long long int plaintext = 123;   // Numeric representation of plaintext
    long long int ciphertext = modularExponentiation(plaintext, e, n);   // RSA encryption

    // Step 3: Decryption
    long long int decryptedText = modularExponentiation(ciphertext, d, n);   // RSA decryption

    cout << "Plaintext: " << plaintext << endl;
    cout << "Ciphertext: " << ciphertext << endl;
    cout << "Decrypted Text: " << decryptedText << endl;

    return 0;
}