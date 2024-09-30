#include <iostream>
#include <string>
#include <vector>
#include "lab1/gcd.h"
#include "lab2/lcm.h"
#include "lab2/missing_number.h"
#include "lab3/cipher.h"

void calculateGCD();
void calculateLCM();
void findMissingNumberOption();
void encryptMessage();
void decryptMessage();

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

void encryptMessage() {
    std::string message;
    std::string key;

    std::cout << "Enter the message to encrypt: ";
    std::getline(std::cin, message);

    std::cout << "Enter the key for encryption (must be the same length as the message): ";
    std::getline(std::cin, key);

    if (message.length() != key.length()) {
        std::cout << "Error: The key must be the same length as the message for One-Time Pad cipher.\n";
        return;
    }

    OneTimePadCipher cipher;
    try {
        std::string encryptedMessage = cipher.encrypt(message, key);
        std::cout << "Encrypted Message: " << encryptedMessage << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cout << e.what() << "\n";
    }
}

void decryptMessage() {
    std::string encryptedMessage;
    std::string key;

    std::cout << "Enter the message to decrypt: ";
    std::getline(std::cin, encryptedMessage);

    std::cout << "Enter the key for decryption (must be the same length as the message): ";
    std::getline(std::cin, key);

    if (encryptedMessage.length() != key.length()) {
        std::cout << "Error: The key must be the same length as the message for One-Time Pad cipher.\n";
        return;
    }

    OneTimePadCipher cipher;
    try {
        std::string decryptedMessage = cipher.decrypt(encryptedMessage, key);
        std::cout << "Decrypted Message: " << decryptedMessage << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cout << e.what() << "\n";
    }
}

int main() {
    std::string choice;
    while (true) {
        std::cout << "\nChoose an option:\n";
        std::cout << "1. Calculate GCD\n";
        std::cout << "2. Calculate LCM\n";
        std::cout << "3. Find Missing Number\n";
        std::cout << "4. Encrypt Message\n";
        std::cout << "5. Decrypt Message\n";
        std::cout << "6. Exit\n";
        std::cout << "Enter your choice: ";
        std::getline(std::cin, choice);

        if (choice == "1") {
            calculateGCD();
        } else if (choice == "2") {
            calculateLCM();
        } else if (choice == "3") {
            findMissingNumberOption();
        } else if (choice == "4") {
            encryptMessage();
        } else if (choice == "5") {
            decryptMessage();
        } else if (choice == "6") {
            break;
        } else {
            std::cout << "Invalid choice. Please enter 1, 2, 3, 4, 5, or 6.\n";
        }
    }

    return 0;
}