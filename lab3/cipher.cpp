#include "Cipher.h"
#include <cctype>

SimpleSubstitutionCipher::SimpleSubstitutionCipher(const std::string& key) {
    generateEncryptionMap(key);
    generateDecryptionMap();
}

void SimpleSubstitutionCipher::generateEncryptionMap(const std::string& key) {
    std::string uniqueKey;
    for (char c : key) {
        if (uniqueKey.find(toupper(c)) == std::string::npos) {
            uniqueKey += toupper(c);
        }
    }

    size_t keyIndex = 0;
    for (char c : alphabet) {
        if (keyIndex < uniqueKey.length()) {
            encryptionMap[c] = uniqueKey[keyIndex++];
        } else {
            encryptionMap[c] = c;
        }
    }
}

void SimpleSubstitutionCipher::generateDecryptionMap() {
    for (auto& pair : encryptionMap) {
        decryptionMap[pair.second] = pair.first;
    }
}

std::string SimpleSubstitutionCipher::encrypt(const std::string& text) {
    std::string result;
    for (char c : text) {
        char upperC = toupper(c);
        if (encryptionMap.find(upperC) != encryptionMap.end()) {
            result += encryptionMap[upperC];
        } else {
            result += c;
        }
    }
    return result;
}

std::string SimpleSubstitutionCipher::decrypt(const std::string& text) {
    std::string result;
    for (char c : text) {
        char upperC = toupper(c);
        if (decryptionMap.find(upperC) != decryptionMap.end()) {
            result += decryptionMap[upperC];
        } else {
            result += c;
        }
    }
    return result;
}