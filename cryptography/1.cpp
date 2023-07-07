/*
1. Suppose you are given a line of text as a plaintext, find out the corresponding Caesar 
Cipher (i.e. character three to the right modulo 26). 
Then perform the reverse operation to get original plaintext.


Here's how the Caesar cipher works:

Choose a number, known as the "key" or "shift value." This key determines how many positions each letter will be shifted.
Take your plaintext message and go through each letter.
Shift each letter by the key value. If the key is positive, you move forward in the alphabet, and if the key is negative, you move backward.
Wrap around the alphabet if you reach the end. For example, if you reach 'z' and need to shift forward, you wrap around to 'a'.
The resulting ciphertext is the encrypted message.
To decrypt the message, you simply apply the opposite shift. If you used a positive key value to encrypt, you would use a negative key value to decrypt, and vice versa.

*/



#include <bits/stdc++.h>

using namespace std;

string ceaser_cipher_encryption(string plain_text, int shift_value)
{
    string encrypted_text = "";

    for (char c : plain_text)
    {
        if (isalpha(c)) 
        {
            char base = isupper(c) ? 'A' : 'a';
            char encrypted = ((c - base + shift_value) % 26) + base;
            encrypted_text += encrypted;
        }
        else
        {
            encrypted_text += c;
        }
    }

    return encrypted_text;
}

string ceaser_cipher_decryption(string encrypted_text, int shift_value)
{

    int decrypt_key = (26 - shift_value) % 26;
    return ceaser_cipher_encryption(encrypted_text, decrypt_key);

}

int main()
{
    string s, encrypted_text, decrypted_text;
    int shift_value;

    // "Taking Original text and the shift value from user "
    cout << "Please enter your text: ";
    getline(cin, s);
    
    cout << "Please enter the shift value: ";
    cin >> shift_value;

    cout << "Original text: " << s << endl;

    // calling encryption function to encrypt the original text
    encrypted_text = ceaser_cipher_encryption(s, shift_value);
    cout << "Encrypted text: " << encrypted_text << endl;

    // calling decryption function to decryption the encrypted text
    decrypted_text = ceaser_cipher_decryption(encrypted_text, shift_value);
    cout << "Decrypted text: " << decrypted_text << endl;


    return 0;
}