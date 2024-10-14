#include "rle.h"

std::string RunLengthEncoding::encode(const std::string& input) {
    std::string encoded;
    int length = input.length();

    for (int i = 0; i < length; i++) {
        int count = 1;

        while (i < length - 1 && input[i] == input[i + 1]) {
            count++;
            i++;
        }

        encoded += input[i] + std::to_string(count);
    }

    return encoded;
}

std::string RunLengthEncoding::decode(const std::string& input) {
    std::string decoded;
    int length = input.length();

    for (int i = 0; i < length; i++) {
        char character = input[i];
        i++;

        std::string countStr;
        while (i < length && isdigit(input[i])) {
            countStr += input[i];
            i++;
        }
        i--;

        int count = std::stoi(countStr);
        decoded.append(count, character);
    }

    return decoded;
}