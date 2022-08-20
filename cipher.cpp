#include <iostream>
#include <string>
using namespace std;

string get_alphabet () {
    string alphabet {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    return alphabet;
}

string get_cipher_key () {
    string key  {"XZNLWEBGJHQDYVTKFUOMPCIASRxznlwebgjhqdyvtkfuompciasr"};
    return key;
}

string encrypt_task (string plain_text,string key, string alphabet) {
    string encrypted_text {};
    for (char c: plain_text) {
        if (c != ' ')
            encrypted_text += key[alphabet.find(c)];
        else
            encrypted_text += c;
    }
    return encrypted_text;
    }

string decrypt_task (string encrypted_text, string key, string alphabet) {
    string decrypted_text {};
    for (char c: encrypted_text) {
        if (c != ' ')
            decrypted_text += alphabet[key.find(c)];
        else
            decrypted_text += " ";
    }
    return decrypted_text;
}

string run_encrypt () {
    string plain_text{};
    string encrypted_text{};
    cout << "Enter a message to be encrypted: ";
    getline(cin,plain_text);
    encrypted_text = encrypt_task(plain_text, get_cipher_key(), get_alphabet());
    cout << "\n" << "Encrypted message: " << encrypted_text << endl;
    return encrypted_text;
}

string run_decrypt (string encrypted_text) {
    string decrypted_text{};
    cout << "Decrypting.. \n" << endl;
    decrypted_text = decrypt_task(encrypted_text, get_cipher_key(), get_alphabet());
    return decrypted_text;
}

int main() {
    string encrypted_text{};
    string decrypted_text{};
    encrypted_text = run_encrypt();
    decrypted_text = run_decrypt(encrypted_text);
    cout << decrypted_text;
    return 0;
} 