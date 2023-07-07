/*
4. Find out corresponding double Transposition Cipher of the above plaintext. Then perform the
reverse operation to get original plaintext


same approach as problem 3. Here I just calling 2 times encryption for double transposition and 2 times decryption for getting back original text

*/

#include <bits/stdc++.h>
using namespace std;

string encrypt_transposition(string plaintext, int width)
{
    string encrypted_text = "";
    int height = ceil(static_cast<double>(plaintext.length()) / width);
    int total_chars = height * width;

    // padding the plaintext with spaces if necessary
    string padded_text = plaintext;
    if (padded_text.length() < total_chars)
    {
        int padding = total_chars - padded_text.length();
        padded_text.append(padding, ' ');
    }
    
    // performing encryption
    for (int col = 0; col < width; col++)
    {
        for (int row = 0; row < height; row++)
        {
            int index = col + (row * width);
            encrypted_text += padded_text[index];
        }
    }

    return encrypted_text;

}


string decrypt_transposition(string encrypted_text, int width)
{
    string decrypted_text = "";
    int height = ceil(static_cast<double>(encrypted_text.length()) / width);

    for (int row=0; row < height; row++)
    {
        for (int col=0; col < width; col++)
        {
            int index = col * height + row;
            decrypted_text += encrypted_text[index];

        }
    }

    return decrypted_text;
}


int main()
{
    string plaintext = "DEPARTMENT OF COMPUTER SCIENCE AND TECHNOLOGY UNIVERSITY OF RAISHAHI BANGLADESH";
    int width;

    cout << "Please enter the width: ";
    cin >> width;

    cout << "Original plaintext: " << plaintext << endl;

    // Encryption
    string encrypted_text = encrypt_transposition(plaintext, width);
    cout << "Encrypted text: " << encrypted_text << endl;
    string double_encrypted_text = encrypt_transposition(encrypted_text, width);
    cout << "Double Encrypted text: " << double_encrypted_text << endl;

    // Decryption
    string decrypted_text = decrypt_transposition(double_encrypted_text, width);
    cout << "Decrypted text: " << decrypted_text << endl;
    
    string double_decrypted_text = decrypt_transposition(decrypted_text, width);
    cout << "Double Decrypted text: " << double_decrypted_text << endl;
    

    return 0;

}

