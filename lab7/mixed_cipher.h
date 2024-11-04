#ifndef MIXED_CIPHER_H
#define MIXED_CIPHER_H

#include <string>

class MixedCipher {
public:
    std::string encode(const std::string& message, int columns);
    std::string decode(const std::string& message, int columns);
};

#endif