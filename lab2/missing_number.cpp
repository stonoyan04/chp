#include "missing_number.h"
#include <algorithm>
#include <numeric>
#include <cstdlib>
#include <ctime>
#include <random>

std::vector<int> generateArray(int n) {
    std::vector<int> numbers(n + 1);
    for (int i = 0; i < n + 1; ++i) {
        numbers[i] = i + 1;
    }

    srand(static_cast<unsigned int>(time(0)));
    int missing_index = rand() % (n + 1);
    numbers.erase(numbers.begin() + missing_index);

    std::random_device rd;   // Seed generator
    std::mt19937 g(rd());    // Mersenne Twister engine
    std::shuffle(numbers.begin(), numbers.end(), g);

    return numbers;
}

int findMissingNumber(const std::vector<int>& numbers, int n) {
    int expected_sum = (n + 1) * (n + 2) / 2;  // Sum from 1 to n+1
    int actual_sum = std::accumulate(numbers.begin(), numbers.end(), 0);
    return expected_sum - actual_sum;
}