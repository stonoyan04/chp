#include "one-time-pad-cipher.h"
#include <cctype>
#include <stdexcept>

std::string OneTimePadCipher::encrypt(const std::string& text, const std::string& key) {
    if (text.length() != key.length()) {
        throw std::invalid_argument("Error: The key must be the same length as the message for One-Time Pad cipher.");
    }

    std::string result;
    for (size_t i = 0; i < text.length(); ++i) {
        char textChar = std::toupper(text[i]);
        char keyChar = std::toupper(key[i]);

        if (std::isalpha(textChar) && std::isalpha(keyChar)) {
            char encryptedChar = ((textChar - 'A') + (keyChar - 'A')) % 26 + 'A';
            result += encryptedChar;
        } else {
            result += textChar;
        }
    }
    return result;
}

std::string OneTimePadCipher::decrypt(const std::string& text, const std::string& key) {
    if (text.length() != key.length()) {
        throw std::invalid_argument("Error: The key must be the same length as the message for One-Time Pad cipher.");
    }

    std::string result;
    for (size_t i = 0; i < text.length(); ++i) {
        char textChar = std::toupper(text[i]);
        char keyChar = std::toupper(key[i]);

        if (std::isalpha(textChar) && std::isalpha(keyChar)) {
            char decryptedChar = ((textChar - 'A') - (keyChar - 'A') + 26) % 26 + 'A';
            result += decryptedChar;
        } else {
            result += textChar;
        }
    }
    return result;
}