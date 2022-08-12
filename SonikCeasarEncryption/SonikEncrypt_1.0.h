#pragma once
#include <string>
using namespace std;
string CaesarEncrypt(string password);
string CaesarDecrypt(string password);
int PassCompatibility(string password);
void SetEncryptionShift(int value);