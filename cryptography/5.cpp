/*
5. You are supplied a file of large nonrepeating set of truly random key letter. Your job is to encrypt the plaintext 
using ONE TIME PAD technique. Then perform the reverse operation to get original plaintext.


One-Time Pad (OTP) encryption technique:

The One-Time Pad is a cryptographic technique that uses a random key of the same length as the plaintext to encrypt and decrypt messages. 
The key is generated using truly random and nonrepeating characters.

Here's how the OTP encryption and decryption processes work:

Encryption:
1. Take the original plaintext and the random key of the same length as the plaintext.
2. Convert both the plaintext and the key into binary form.
3. Perform a bitwise XOR operation between each corresponding bit of the plaintext and the key.
4. The result of the XOR operation is the ciphertext.

Decryption:
1. Take the ciphertext and the random key used for encryption.
2. Perform the same bitwise XOR operation between each corresponding bit of the ciphertext and the key.
3. The result of the XOR operation is the original plaintext.

The key principle of OTP encryption is that the random key is used only once and never reused. 
This ensures perfect secrecy and makes the encryption unbreakable if the key is truly random, 
remains secret, and is not reused.

*/

#include <bits/stdc++.h>
using namespace std;


string encryptOTP(string plaintext, string key)
{
    string encrypted_text = "";
    for (int i = 0; i < plaintext.length(); i++)
    {
        char encryptedChar = plaintext[i] ^ key[i];
        encrypted_text += encryptedChar;

    }

    return encrypted_text;

}


string decryptOTP(string encrypted_text, string key)
{
    string decrypted_text = "";
    for (int i = 0; i < encrypted_text.length(); i++)
    {
        char decryptedChar = encrypted_text[i] ^ key[i];
        decrypted_text += decryptedChar;
    }

    return decrypted_text;
}


string read_key_from_file(string filename, size_t length)
{
    ifstream file(filename, ios::binary);
    if (!file)
    {
        cerr << "Error opening key file." << endl;
        exit(1);
    }

    string key;
    getline(file, key);
    file.close();

    // Trim key to the desired length
    if(key.length() > length)
        key = key.substr(0, length);
    else if (key.length() < length)
    {
        cerr << "Key file does not contain enough characters." << endl;
        exit(1);

    }

    return key;

}

int main()
{
    string plaintext;

    cout << "Please enter your plaintext you want to encrypt: ";
    getline(cin, plaintext);

    string key_filename = "key.txt";
    size_t key_length = plaintext.length();

    // Read the key from file
    string key = read_key_from_file(key_filename, key_length);

    cout << "Original plaintext: " << plaintext << endl;

    // Encryption
    string encrypted_text = encryptOTP(plaintext, key);
    cout << "Encrypted text: " << encrypted_text << endl;

    // Decryption
    string decrypted_text = decryptOTP(encrypted_text, key);
    cout << "Decrypted text: " << decrypted_text << endl;


    return 0;

}