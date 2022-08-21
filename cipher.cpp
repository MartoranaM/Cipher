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

size_t get_position (char c, string searchable) {
    size_t position{searchable.find(c)};
    return position;
}

string encrypt_task (string plain_text,string key, string alphabet) {
    size_t position {};
    string encrypted_text {};

    for (char c: plain_text) {
        position = get_position(c, alphabet);
        if (position != string::npos)
            encrypted_text += key[position];
        else
            encrypted_text += c;
    }
    return encrypted_text;
    }

string decrypt_task (string encrypted_text, string key, string alphabet) {
    size_t position{};
    string decrypted_text {};

    for (char c: encrypted_text) {
        position = get_position(c, key);
        if (position != string::npos)
            decrypted_text += alphabet[position];
        else
            decrypted_text += c;
    }
    return decrypted_text;
}

string run_encrypt () {
    string plain_text{};
    string encrypted_text{};

    cout << "Enter a message to be encrypted: ";
    getline(cin,plain_text);
    cout << "\nEncrypting.." << endl;
    encrypted_text = encrypt_task(plain_text, get_cipher_key(), get_alphabet());

    return encrypted_text;
}

string run_decrypt (string encrypted_text) {
    string decrypted_text{};

    cout << "\nDecrypting.." << endl;
    decrypted_text = decrypt_task(encrypted_text, get_cipher_key(), get_alphabet());
    return decrypted_text;
}

int main() {
    string encrypted_text{};
    string decrypted_text{};

    encrypted_text = run_encrypt();
    cout << "Encrypted message: " << encrypted_text << endl;
    decrypted_text = run_decrypt(encrypted_text);
    cout << "Decrypted Message: " << decrypted_text << endl;
    return 0;
} 