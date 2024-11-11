#ifndef LZ77_H
#define LZ77_H

#include <string>
#include <vector>

class LZ77 {
public:
    struct Match {
        int offset;
        int length;
        char next_char;
    };

    std::string encode(const std::string& input);
    std::string decode(const std::string& encoded);

private:
    Match findLongestMatch(const std::string& data, int pos, int window_size);
};

#endif