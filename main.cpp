#include <iostream>
#include <string>
#include <vector>
#include "lab1/gcd.h"
#include "lab2/lcm.h"
#include "lab2/missing_number.h"
#include "lab3/one-time-pad-cipher.h"
#include "lab4/caesar-cipher.h"
#include "lab5/columnar_transposition.h"
#include "lab6/rle.h"
#include "lab7/mixed_cipher.h"
#include "lab8/lz77.h"
#include "lab9/HuffmanCoding.h"
#include "lab10/ip.h"

void displayIPAddress();
void calculateGCD();
void calculateLCM();
void findMissingNumberOption();
void encryptWithOneTimePadMessage();
void decryptWithOneTimePadMessage();
void encryptWithCaesarMessage();
void decryptWithCaesarMessage();
void encryptWithColumnarTransposition();
void decryptWithColumnarTransposition();
void runRLEEncode();
void runRLEDecode();
void runMixedEncode();
void runMixedDecode();


void displayIPAddress() {
    std::vector<std::string> ipAddresses = getIPAddress();
    if (ipAddresses.size() == 1 && ipAddresses[0].find("Failed") != std::string::npos) {
        std::cout << ipAddresses[0] << std::endl;
    } else {
        std::cout << "Resolved IP Addresses:\n";
        for (const std::string& ip : ipAddresses) {
            std::cout << "- " << ip << std::endl;
        }
    }
}

void runHuffmanEncode() {
    std::string input;
    std::cout << "Enter a string to encode using Huffman Coding: ";
    std::getline(std::cin, input);

    HuffmanCoding huffman;
    std::string encoded = huffman.encode(input);
    std::cout << "Encoded string: " << encoded << std::endl;
    std::cout << "Huffman Tree: " << std::endl << huffman.getHuffmanTree() << std::endl;
}

std::string trim(const std::string& str) {
    size_t start = str.find_first_not_of(" \t\n\r");
    if (start == std::string::npos) return "";
    size_t end = str.find_last_not_of(" \t\n\r");
    return str.substr(start, end - start + 1);
}

void runHuffmanDecode() {
    std::string encodedInput;
    std::cout << "Enter the encoded string to decode using Huffman Coding: ";
    std::getline(std::cin, encodedInput);

    std::string huffmanTree, line;
    std::cout << "Enter the Huffman Tree (format: character code per line, end input with 'END' or an empty line):\n";
    while (true) {
        std::getline(std::cin, line);
        line = trim(line);
        if (line.empty() || line == "END") break;
        huffmanTree += line + "\n";
    }

    HuffmanCoding huffman;
    std::string decodedText = huffman.decode(encodedInput, huffmanTree);

    if (!decodedText.empty()) {
        std::cout << "Decoded string: " << decodedText << "\n";
    } else {
        std::cerr << "Failed to decode the string. Please check your Huffman Tree input.\n";
    }
}

void runLZ77Encode() {
    std::string input;
    std::cout << "Enter a string to encode using LZ77: ";
    std::getline(std::cin, input);

    LZ77 lz77;
    std::string encoded = lz77.encode(input);
    std::cout << "Encoded string: " << encoded << std::endl;
}

void runLZ77Decode() {
    std::string input;
    std::cout << "Enter a string to decode using LZ77 (format: offset,length,next_char): ";
    std::getline(std::cin, input);

    LZ77 lz77;
    std::string decoded = lz77.decode(input);
    std::cout << "Decoded string: " << decoded << std::endl;
}

void runMixedEncode() {
    std::string input;
    int columns;

    std::cout << "Enter a message to encode with Columnar Transposition and Run-Length Encoding: ";
    std::getline(std::cin, input);

    std::cout << "Enter the number of columns for Columnar Transposition: ";
    std::cin >> columns;
    std::cin.ignore();

    MixedCipher mixedCipher;
    std::string encodedMessage = mixedCipher.encode(input, columns);
    std::cout << "Encoded Message: " << encodedMessage << std::endl;
}

void runMixedDecode() {
    std::string input;
    int columns;

    std::cout << "Enter an encoded message to decode with Run-Length Decoding and Columnar Transposition: ";
    std::getline(std::cin, input);

    std::cout << "Enter the number of columns used for Columnar Transposition: ";
    std::cin >> columns;
    std::cin.ignore();

    MixedCipher mixedCipher;
    std::string decodedMessage = mixedCipher.decode(input, columns);
    std::cout << "Decoded Message: " << decodedMessage << std::endl;
}

void calculateGCD() {
    int num1, num2;
    std::string input;

    std::cout << "Enter two integers separated by space to calculate GCD (or type 'exit' to return): ";
    std::getline(std::cin, input);

    if (input == "exit") {
        return;
    }

    if (sscanf(input.c_str(), "%d %d", &num1, &num2) != 2) {
        std::cout << "Please enter valid integers.\n";
        return;
    }

    std::cout << "The GCD of " << num1 << " and " << num2 << " is: " << gcd(num1, num2) << "\n";
}

void calculateLCM() {
    int num1, num2;
    std::string input;

    std::cout << "Enter two integers separated by space to calculate LCM (or type 'exit' to return): ";
    std::getline(std::cin, input);

    if (input == "exit") {
        return;
    }

    if (sscanf(input.c_str(), "%d %d", &num1, &num2) != 2) {
        std::cout << "Please enter valid integers.\n";
        return;
    }

    if (num1 < 0 || num2 < 0) {
        std::cout << "Please enter positive integers.\n";
        return;
    }

    std::cout << "The LCM of " << num1 << " and " << num2 << " is: " << lcm(num1, num2) << "\n";
}

void findMissingNumberOption() {
    int n;
    std::string input;

    std::cout << "Enter the value of n to generate an array (or type 'exit' to return): ";
    std::getline(std::cin, input);

    if (input == "exit") {
        return;
    }

    try {
        n = std::stoi(input);
    } catch (...) {
        std::cout << "Please enter a valid integer for n.\n";
        return;
    }

    std::vector<int> numbers = generateArray(n);

    std::cout << "Generated array: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << "\n";

    int missing_number = findMissingNumber(numbers, n);

    std::cout << "The missing number is: " << missing_number << std::endl;
}

void encryptWithOneTimePadMessage() {
    std::string message, key;

    std::cout << "Enter the message to encrypt: ";
    std::getline(std::cin, message);

    std::cout << "Enter the key (must be the same length as the message): ";
    std::getline(std::cin, key);

    if (message.length() != key.length()) {
        std::cout << "Error: Key must be the same length as the message.\n";
        return;
    }

    OneTimePadCipher cipher;
    std::string encryptedMessage = cipher.encrypt(message, key);
    std::cout << "Encrypted Message: " << encryptedMessage << std::endl;
}

void decryptWithOneTimePadMessage() {
    std::string encryptedMessage, key;

    std::cout << "Enter the message to decrypt: ";
    std::getline(std::cin, encryptedMessage);

    std::cout << "Enter the key: ";
    std::getline(std::cin, key);

    if (encryptedMessage.length() != key.length()) {
        std::cout << "Error: Key must be the same length as the message.\n";
        return;
    }

    OneTimePadCipher cipher;
    std::string decryptedMessage = cipher.decrypt(encryptedMessage, key);
    std::cout << "Decrypted Message: " << decryptedMessage << std::endl;
}

void encryptWithCaesarMessage() {
    std::string message;
    int key;

    std::cout << "Enter the message to encrypt: ";
    std::getline(std::cin, message);

    std::cout << "Enter the key (shift amount): ";
    std::cin >> key;
    std::cin.ignore();

    CaesarCipher cipher;
    std::string encryptedMessage = cipher.encrypt(message, key);
    std::cout << "Encrypted Message: " << encryptedMessage << std::endl;
}

void decryptWithCaesarMessage() {
    std::string encryptedMessage;
    int key;

    std::cout << "Enter the message to decrypt: ";
    std::getline(std::cin, encryptedMessage);

    std::cout << "Enter the key (shift amount): ";
    std::cin >> key;
    std::cin.ignore();

    CaesarCipher cipher;
    std::string decryptedMessage = cipher.decrypt(encryptedMessage, key);
    std::cout << "Decrypted Message: " << decryptedMessage << std::endl;
}

void encryptWithColumnarTransposition() {
    std::string message;
    int columns;

    std::cout << "Enter the message to encrypt: ";
    std::getline(std::cin, message);

    std::cout << "Enter the number of columns: ";
    std::cin >> columns;
    std::cin.ignore();

    ColumnarTranspositionCipher cipher;
    std::string encryptedMessage = cipher.encrypt(message, columns);
    std::cout << "Encrypted Message: " << encryptedMessage << std::endl;
}

void decryptWithColumnarTransposition() {
    std::string ciphertext;
    int columns;

    std::cout << "Enter the message to decrypt: ";
    std::getline(std::cin, ciphertext);

    std::cout << "Enter the number of columns: ";
    std::cin >> columns;
    std::cin.ignore();

    ColumnarTranspositionCipher cipher;
    std::string decryptedMessage = cipher.decrypt(ciphertext, columns);
    std::cout << "Decrypted Message: " << decryptedMessage << std::endl;
}

void runRLEEncode() {
    std::string input;
    RunLengthEncoding rle;

    std::cout << "Enter a string to encode using RLE: ";
    std::getline(std::cin, input);

    std::string encoded = rle.encode(input);
    std::cout << "Encoded string: " << encoded << std::endl;
}

void runRLEDecode() {
    std::string input;
    RunLengthEncoding rle;

    std::cout << "Enter a string to decode using RLE: ";
    std::getline(std::cin, input);

    std::string decoded = rle.decode(input);
    std::cout << "Decoded string: " << decoded << std::endl;
}

int main() {
    std::string choice;
    while (true) {
        std::cout << "\nChoose an option:\n";
        std::cout << "1. Calculate GCD\n";
        std::cout << "2. Calculate LCM\n";
        std::cout << "3. Find Missing Number\n";
        std::cout << "4. Encrypt with One-Time Pad Message\n";
        std::cout << "5. Decrypt with One-Time Pad Message\n";
        std::cout << "6. Encrypt with Caesar Message\n";
        std::cout << "7. Decrypt with Caesar Message\n";
        std::cout << "8. Encrypt with Columnar Transposition\n";
        std::cout << "9. Decrypt with Columnar Transposition\n";
        std::cout << "10. Encode with Run Length Encoding\n";
        std::cout << "11. Decode with Run Length Encoding\n";
        std::cout << "12. Encode with Mixed Cipher (Columnar Transposition + Run-Length Encoding)\n";
        std::cout << "13. Decode with Mixed Cipher (Run-Length Decoding + Columnar Transposition)\n";
        std::cout << "14. Encode with LZ77\n";
        std::cout << "15. Decode with LZ77\n";
        std::cout << "16. Encode with Huffman Coding\n";
        std::cout << "17. Decode with Huffman Coding\n";
        std::cout << "18. Display Ip Address\n";
        std::cout << "19. Exit\n";
        std::cout << "Enter your choice: ";
        std::getline(std::cin, choice);

        if (choice == "1") calculateGCD();
        else if (choice == "2") calculateLCM();
        else if (choice == "3") findMissingNumberOption();
        else if (choice == "4") encryptWithOneTimePadMessage();
        else if (choice == "5") decryptWithOneTimePadMessage();
        else if (choice == "6") encryptWithCaesarMessage();
        else if (choice == "7") decryptWithCaesarMessage();
        else if (choice == "8") encryptWithColumnarTransposition();
        else if (choice == "9") decryptWithColumnarTransposition();
        else if (choice == "10") runRLEEncode();
        else if (choice == "11") runRLEDecode();
        else if (choice == "12") runMixedEncode();
        else if (choice == "13") runMixedDecode();
        else if (choice == "14") runLZ77Encode();
        else if (choice == "15") runLZ77Decode();
        else if (choice == "16") runHuffmanEncode();
        else if (choice == "17") runHuffmanDecode();
        else if (choice == "18") displayIPAddress();
        else if (choice == "19") break;
        else std::cout << "Invalid choice. Please enter a valid number.\n";
    }
    return 0;
}