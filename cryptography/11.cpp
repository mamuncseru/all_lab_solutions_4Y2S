/*
11. Write a program to implement Diffie-Hellman Key Exchange.


The Diffie-Hellman Key Exchange algorithm is a method for securely exchanging cryptographic keys over an insecure communication channel. 
It allows two parties, traditionally named Alice and Bob, to agree upon a shared secret key without explicitly transmitting it. 
The algorithm is based on the mathematical concept of modular exponentiation and relies on the difficulty of the discrete logarithm 
problem to provide security.

Here's a high-level description of the Diffie-Hellman Key Exchange algorithm:

1. Setup: Agree on a prime number `p` and a base `g`, which are known to both Alice and Bob. These values are public and can be shared openly.
2. Private key generation: Each party, Alice and Bob, independently generates a private key. Let's denote Alice's private key as `a` and Bob's private key 
    as `b`. These private keys are kept secret.
3. Public key calculation: Alice and Bob calculate their respective public keys by performing modular exponentiation. Alice computes `A = g^a mod p`, and 
    Bob computes `B = g^b mod p`.
4. Key derivation: Alice and Bob exchange their public keys, `A` and `B`, over the insecure channel.
5. Secret key calculation: Alice calculates the secret key by raising Bob's public key `B` to the power of her private key `a`, i.e., `K = B^a mod p`. 
    Bob calculates the secret key by raising Alice's public key `A` to the power of his private key `b`, i.e., `K = A^b mod p`.
6. Both Alice and Bob now have the same shared secret key `K`, which can be used for symmetric encryption or other cryptographic operations.


*/

#include <bits/stdc++.h>
using namespace std;
long long int modularExponentiation(long long int base, long long exponent, long long modulus)
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
    // Step 1. Agree on prime number and base (Known to both Alice and Bob)
    long long int p = 23;   // Prime number
    long long int g = 5;    // Base

    // Step 2. Generate private keys (known only to Alice and Bob)
    long long int a, b;     // Private keys
    cout << "Alice's private key (a): ";
    cin >> a;
    cout << "Bob's private key (b): ";
    cin >> b;

    // Step 3: Calculate Public keys
    long long A = modularExponentiation(g, a, p);       // Alice's public key
    long long B = modularExponentiation(g, b, p);       // Bob's public key

    // Step 4: Exchange public keys (over the insecure channel)
    cout << "Alice's public key (A): " << A << endl;
    cout << "Bob's public key (B): " << B << endl;

    // Step 5: Calculate the secret key
    long long int secretKeyAlice = modularExponentiation(B, a, p);      // Alice's secret key
    long long int secretKeyBob = modularExponentiation(A, b, p);        // Bob's secret key

    // Step 6: Both Alice and Bob have the same shared secret key
    cout << "Alice's secret key: " << secretKeyAlice << endl;
    cout << "Bob's secret key: " << secretKeyBob << endl;

    return 0;

}