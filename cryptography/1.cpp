/*
1. Suppose you are given a line of text as a plaintext, find out the corresponding Caesar 
Cipher (i.e. character three to the right modulo 26). 
Then perform the reverse operation to get original plaintext.


The Caesar cipher is a simple substitution cipher that shifts each letter in the plaintext by a fixed number of positions down the alphabet. 
The provided code implements the encryption and decryption processes of the Caesar cipher.

For encryption:
1. The user is prompted to enter the original text and the shift value.
2. The original text is displayed.
3. The `ceaser_cipher_encryption` function is called with the original text and the shift value as parameters.
4. Inside the `ceaser_cipher_encryption` function:
   - Each character in the plain text is checked if it is an alphabetic character.
   - If it is alphabetic, the character's case (upper or lower) is determined.
   - The character is then shifted by the given shift value, wrapping around the alphabet if necessary.
   - The shifted character is added to the encrypted text.
   - Non-alphabetic characters remain unchanged and are also added to the encrypted text.
5. The encrypted text is displayed on the console.

For decryption:
1. The encrypted text and the shift value are already known.
2. The `ceaser_cipher_decryption` function is called with the encrypted text and the shift value as parameters.
3. Inside the `ceaser_cipher_decryption` function:
   - The shift value is converted to the corresponding decryption key.
   - The `ceaser_cipher_encryption` function is called with the encrypted text and the decryption key as parameters.
   - The `ceaser_cipher_encryption` function performs the same process as encryption, but with the decryption key.
4. The decrypted text is displayed on the console.

In summary, the Caesar cipher shifts each letter in the original text by a fixed number of positions to encrypt it. 
To decrypt the encrypted text, the process is reversed by shifting each letter back by the same number of positions. 
The provided code allows the user to enter the original text and the shift value, performs encryption and decryption, and displays the results.

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