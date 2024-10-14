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
        std::cout << "12. Exit\n";
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
        else if (choice == "12") break;
        else std::cout << "Invalid choice. Please enter 1 to 12.\n";
    }
    return 0;
}