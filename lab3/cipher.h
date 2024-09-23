#ifndef CIPHER_H
#define CIPHER_H

#include <string>
#include <unordered_map>

class Cipher {
public:
    virtual std::string encrypt(const std::string& text) = 0;
    virtual std::string decrypt(const std::string& text) = 0;
    virtual ~Cipher() = default;
};

class SimpleSubstitutionCipher : public Cipher {
private:
    std::unordered_map<char, char> encryptionMap;
    std::unordered_map<char, char> decryptionMap;
    std::string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    void generateEncryptionMap(const std::string& key);
    void generateDecryptionMap();

public:
    SimpleSubstitutionCipher(const std::string& key);
    std::string encrypt(const std::string& text) override;
    std::string decrypt(const std::string& text) override;
};

#endif