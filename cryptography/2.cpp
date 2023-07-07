/*
2. Find out the Polygram Substitution Cipher of a given 
plaintext (Consider the block size of 3), 
Then perform the reverse operation to get original plaintext.



In the Polygram Substitution Cipher, we consider a block size of 3 characters. This means that we process the plaintext in chunks of 3 characters at a time.

To encrypt the plaintext:
1. We define a substitution map that maps each block of 3 characters to its corresponding substitution. For example, "HEL" might be mapped to "XJW".
2. We loop through the plaintext in blocks of size 3.
3. For each block, we check if it exists in the substitution map.
   - If it does, we replace the block with its corresponding substitution.
   - If it doesn't, we keep the block unchanged.
4. We continue this process until we have processed the entire plaintext.
5. The resulting ciphertext is the encrypted message.

To decrypt the ciphertext and obtain the original plaintext:
1. We use the same substitution map as used in encryption.
2. We loop through the ciphertext in blocks of size 3.
3. For each block, we perform a reverse lookup in the substitution map to find the original plaintext block.
4. If the block is found in the substitution map, we replace it with the corresponding plaintext block.
5. If the block is not found in the substitution map, we keep it unchanged.
6. We continue this process until we have processed the entire ciphertext.
7. The resulting plaintext is the decrypted message.

It's important to note that the substitution map should be constructed carefully to ensure the uniqueness of the substitutions and
avoid ambiguities during decryption.

*/

#include <bits/stdc++.h>
using namespace std;

string encrypt_polygram(string plaintext, unordered_map<string, string> substitution_map)
{

    string encrypted_text = "";

    // Loop through the plaintext in blocks of size 3
    for (int i = 0; i < plaintext.length(); i+=3)
    {
        string block = plaintext.substr(i, 3);

        // check if the block exist in the substitution map
        if (substitution_map.count(block) > 0) 
            encrypted_text += substitution_map.at(block); 
        else encrypted_text += block; // If the block is not in the substitution map, keep it unchanged
    }

    return encrypted_text;

}


string decrypted_polygram(string encrypted_text, unordered_map<string, string> substitution_map)
{
    string decrypted_text = "";

    // Loop through the ecrypted text in block of size 3
    for (int i = 0; i < encrypted_text.length(); i+=3)
    {
        string block = encrypted_text.substr(i, 3);

        // Reverse lookup in the substituion map to find the original plaintext block
        bool found = false;
        for (const auto entry: substitution_map) {
            if (entry.second == block) {
                decrypted_text += entry.first;
                found = true;
                break;
            }
        }

        // If the block is not found in the substitution map, keep it unchanged
        if (!found) {
            decrypted_text += block;
        }
    }

    return decrypted_text;

}


int main()
{
    string plaintext;
    unordered_map<string, string> substitution_map = {
        {"HEL", "XJW"},
        {"LO ", "PTT"},
        {"WOR", "MRD"}

    };
    // Original plaintext
    getline(cin, plaintext);
    cout << "Original Plaintext: " << plaintext << endl;

    // Encryption
    string encrypted_text = encrypt_polygram(plaintext, substitution_map);
    cout << "Encrypted Text: " << encrypted_text << endl;


    // Decryption
    string decrypted_text = decrypted_polygram(encrypted_text, substitution_map);
    cout << "Decrypted Text: " << decrypted_text << endl;



    return 0;
}

