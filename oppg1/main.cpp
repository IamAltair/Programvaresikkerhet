//
// Created by altair on 19.09.2019.
//
#include "crypto.hpp"
#include <iostream>

using namespace std;

int main() {

    string key = "ab29d7b5c589e18b52261ecba1d3a7e7cbf212c6";
    string salt = "Saltet til Ola";
    int iterations = 2048;
    int keyLength = 160 / 8;
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    char password[3];

    for (char c1 : alphabet) {
        password[0] = c1;

        for (char c2 : alphabet) {
            password[1] = c2;

//            for(char c3 : alphabet) {
//                password[2] = c3;

//                for(char c4 : alphabet) {
//                    password[3] = c4;

                    for (char c3 : alphabet) {
                        password[2] = c3;
                        string hash = Crypto::hex(Crypto::pbkdf2(password, salt, iterations, keyLength));
                        cout << hash << ": " << password << endl;

                        if (hash == key) {
                            cout << "Password found: " << password << endl;
                            return 0;
                        }
                    }
//                }
//            }
        }
    }
    return 0;
}