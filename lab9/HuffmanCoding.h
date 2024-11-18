#ifndef HUFFMAN_CODING_H
#define HUFFMAN_CODING_H

#include <string>
#include <unordered_map>

class HuffmanCoding {
public:
    std::string encode(const std::string& text);
    std::string decode(const std::string& encodedText, const std::string& huffmanTree);
    std::string getHuffmanTree() const;
    ~HuffmanCoding();

private:
    struct Node {
        char ch;
        int freq;
        Node* left;
        Node* right;

        Node(char c, int f) : ch(c), freq(f), left(nullptr), right(nullptr) {}
    };

    struct Compare {
        bool operator()(Node* l, Node* r) {
            return l->freq > r->freq;
        }
    };

    std::unordered_map<char, std::string> huffmanTable;
    Node* root;

    void buildTree(const std::string& text);
    void generateCodes(Node* node, const std::string& code);
    void deleteTree(Node* node);
};

#endif