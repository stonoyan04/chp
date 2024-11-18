#include "HuffmanCoding.h"
#include <queue>
#include <iostream>
#include <sstream>

void HuffmanCoding::buildTree(const std::string& text) {
    std::unordered_map<char, int> freqMap;
    for (char ch : text) {
        freqMap[ch]++;
    }

    std::priority_queue<Node*, std::vector<Node*>, Compare> pq;
    for (const auto& pair : freqMap) {
        pq.push(new Node(pair.first, pair.second));
    }

    while (pq.size() > 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();
        Node* merged = new Node('\0', left->freq + right->freq);
        merged->left = left;
        merged->right = right;
        pq.push(merged);
    }

    root = pq.top();
    generateCodes(root, "");
}

void HuffmanCoding::generateCodes(Node* node, const std::string& code) {
    if (!node) return;

    if (!node->left && !node->right) {
        huffmanTable[node->ch] = code;
    }

    generateCodes(node->left, code + "0");
    generateCodes(node->right, code + "1");
}

std::string HuffmanCoding::encode(const std::string& text) {
    huffmanTable.clear();
    if (text.empty()) return "";

    buildTree(text);

    std::string encodedText;
    for (char ch : text) {
        encodedText += huffmanTable[ch];
    }
    return encodedText;
}

static std::string trim(const std::string& str) {
    size_t start = str.find_first_not_of(" \t\n\r");
    if (start == std::string::npos) return "";
    size_t end = str.find_last_not_of(" \t\n\r");
    return str.substr(start, end - start + 1);
}

std::string HuffmanCoding::decode(const std::string& encodedText, const std::string& huffmanTreeInput) {
    if (encodedText.empty()) {
        std::cerr << "Error: Encoded text is empty.\n";
        return "";
    }

    std::unordered_map<std::string, char> reverseTable;
    std::istringstream treeStream(huffmanTreeInput);
    std::string line;

    while (std::getline(treeStream, line)) {
        line = trim(line);
        if (line.empty()) continue;

        std::istringstream lineStream(line);
        std::string character, code;
        if (!(lineStream >> character >> code)) {
            std::cerr << "Error: Invalid Huffman Tree format: " << line << "\n";
            continue;
        }
        if (character.length() != 1) {
            std::cerr << "Error: Character in Huffman Tree must be a single character: " << character << "\n";
            continue;
        }
        reverseTable[code] = character[0];
    }

    std::cout << "Reverse Table:\n";
    for (const auto& pair : reverseTable) {
        std::cout << pair.first << " -> " << pair.second << "\n";
    }

    std::string decodedText;
    std::string currentCode;

    for (char bit : encodedText) {
        currentCode += bit;
        if (reverseTable.count(currentCode)) {
            decodedText += reverseTable[currentCode];
            currentCode.clear();
        }
    }

    if (!currentCode.empty()) {
        std::cerr << "Error: Encoded string does not align with Huffman Tree.\n";
        return "";
    }

    return decodedText;
}

std::string HuffmanCoding::getHuffmanTree() const {
    std::stringstream ss;
    for (const auto& pair : huffmanTable) {
        ss << pair.first << " " << pair.second << "\n";
    }
    return ss.str();
}

void HuffmanCoding::deleteTree(Node* node) {
    if (!node) return;
    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}

HuffmanCoding::~HuffmanCoding() {
    deleteTree(root);
}