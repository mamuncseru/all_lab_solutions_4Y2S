/*
3. Consider the plaintext “DEPARTMENT OF COMPUTER SCIENCE AND TECHNOLOGY UNIVERSITY
OF RAISHAHI BANGLADESH", find out the corresponding Transposition Cipher (Take width as input)
Then perform the reverse operation to get original plaintext.


The Transposition Cipher is a cryptographic technique that involves rearranging the characters of the plaintext to form the ciphertext. 
In this cipher, the order of the characters is changed based on a specific rule or pattern.

Here's how the Transposition Cipher encryption and decryption processes work:

Encryption:

Take the original plaintext as input.
Determine the width of the transposition grid. This represents the number of columns in the grid.
Arrange the characters of the plaintext row by row into the transposition grid, filling up each row before moving to the next.
Read the characters column by column from the transposition grid to form the ciphertext.
The resulting ciphertext is the encrypted message.


Decryption:

Take the ciphertext as input.
Determine the width of the transposition grid, which should match the width used during encryption.
Divide the length of the ciphertext by the width to determine the number of rows in the grid.
Arrange the characters of the ciphertext column by column into the transposition grid.
Read the characters row by row from the transposition grid to obtain the original plaintext.
The resulting plaintext is the decrypted message.

*/

#include <bits/stdc++.h>
using namespace std;

string encrypt_transposition(string plaintext, int width)
{
    string encrypted_text = "";
    int height = ceil(static_cast<double>(plaintext.length()) / width);
    
    for (int col = 0; col < width; col++)
    {
        for (int row = 0; row < height; row++)
        {
            int index = col + (row * width);
            if (index < plaintext.length())
                encrypted_text += plaintext[index];
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
            if (index < encrypted_text.length())
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

    // Decryption
    string decrypted_text = decrypt_transposition(encrypted_text, width);
    cout << "Decrypted text: " << decrypted_text << endl;

    return 0;

}

