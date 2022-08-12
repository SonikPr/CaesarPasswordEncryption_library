// SonikCeasarEncryption.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "SonikEncrypt_1.0.h"
#define EncrShift 19
using namespace std;
int main()
{
    string input, output;
    
    cout << "Enter your password:" << endl << "*HINT* All lower & uppercase leters and numbers 0-9" << endl;
    getline(cin, input);
    if (PassCompatibility(input)) {
        SetEncryptionShift(EncrShift);
        output = CaesarEncrypt(input);
        cout << "The encrypted password is:" << endl << output << endl << endl << endl;
    }
    else
        if (!PassCompatibility(input)) {
            cout << "You spelled forbiidden character! Rewrite your password!" <<  endl;
        }
   cout << "Enter your encrypted password to decrypt it:" << endl;
   getline(cin, input);
   output = CaesarDecrypt(input);
   cout << "The encrypted password is:" << endl << output << endl;

}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
