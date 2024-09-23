#include "lcm.h"
#include "../lab1/gcd.h"

int lcm(int a, int b) {
    return (a / gcd(a, b)) * b;
}