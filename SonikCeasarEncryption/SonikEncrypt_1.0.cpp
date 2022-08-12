#include <string>
#include <math.h>
#define DictionaryLength 77
int EncryptionShift = 7;
char dictionary[DictionaryLength] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+-/";
using namespace std;


void SetEncryptionShift(int value) { //Сдвиг только вправо (версия библиотеки 1.0)
    EncryptionShift = abs(value);
}

int PassCompatibility(string password) { //Проверка на наличие символов, отсутствующих в библиотеке для кодирования пароля
    int matches = 0;
    for (int i = 0; i < password.length(); i++) {
        for (int j = 0; j < DictionaryLength; j++) {
            if (dictionary[j] == password[i]) {
                matches += 1;
            }
        }
    }

    if (matches == password.length()) {
        return 1;
    }
    else
        return 0;
}

string CaesarEncrypt(string password) {


    char* SplitPassword = new char[password.length()];
    string result = "";

    for (int i = 0; i < password.length(); i++) {//Разделяем пароль на отдельные символы
        SplitPassword[i] = password[i];
    }
    for (int i = 0; i < password.length(); i++) {//Разделяем пароль на отдельные символы
        int counter = 0; //thing that applies the shift
        for (int j = 0; j < DictionaryLength; j++) {
            if (dictionary[j] == SplitPassword[i]) {
                counter = j + EncryptionShift;
                if (counter > (DictionaryLength - 1)) {
                    counter = abs((DictionaryLength - 1) - counter);
                }
                result += dictionary[counter];
            }

        }
    }
    return result;
}

string CaesarDecrypt(string password) {


    char* SplitPassword = new char[password.length()];
    string result = "";

    for (int i = 0; i < password.length(); i++) {//Разделяем пароль на отдельные символы
        SplitPassword[i] = password[i];
    }
    for (int i = 0; i < password.length(); i++) {//Разделяем пароль на отдельные символы
        int counter = 0; //thing that applies the shift
        for (int j = 0; j < DictionaryLength; j++) {
            if (dictionary[j] == SplitPassword[i]) {
                counter = j - EncryptionShift;
                if (counter < 0) {
                    counter = ((DictionaryLength - 1) - abs(counter));
                }
                result += dictionary[counter];
            }

        }
    }
    return result;
}