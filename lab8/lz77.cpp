#include <iostream>
#include <sstream>
#include "lz77.h"

LZ77::Match LZ77::findLongestMatch(const std::string& data, int pos, int window_size) {
    Match best_match = {0, 0, data[pos]};
    int end = std::min(pos + window_size, (int)data.size());

    for (int i = std::max(0, pos - window_size); i < pos; i++) {
        int length = 0;
        while (pos + length < end && data[i + length] == data[pos + length]) {
            length++;
        }
        if (length > best_match.length) {
            best_match.offset = pos - i;
            best_match.length = length;
            best_match.next_char = data[pos + length];
        }
    }
    return best_match;
}

std::string LZ77::encode(const std::string& input) {
    const int window_size = 4096;
    std::string encoded;
    int pos = 0;

    while (pos < input.size()) {
        Match match = findLongestMatch(input, pos, window_size);
        encoded += std::to_string(match.offset) + "," + std::to_string(match.length) + "," + match.next_char + " ";
        pos += match.length + 1;
    }

    return encoded;
}

std::string LZ77::decode(const std::string& encoded) {
    std::string decoded;
    std::istringstream iss(encoded);
    std::string segment;

    while (std::getline(iss, segment, ' ')) {
        if (segment.empty()) continue;

        std::istringstream segmentStream(segment);
        int offset = 0, length = 0;
        char next_char = '\0';

        char delimiter;

        if ((segmentStream >> offset >> delimiter >> length >> delimiter >> next_char)) {
            if (offset > 0) {
                int start = decoded.size() - offset;
                for (int i = 0; i < length; i++) {
                    decoded += decoded[start + i];
                }
            }
            decoded += next_char;
        } else {
            std::cerr << "Error parsing segment: " << segment << std::endl;
        }
    }

    return decoded;
}