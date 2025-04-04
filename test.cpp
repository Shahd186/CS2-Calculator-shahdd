#include <iostream>
#include <ctime>
#include "calculator.h"

using namespace std;

int main() {
    srand(time(0)); // Seed for random number generation

    cout << "Addition (5 + 3): " << add(5, 3) << endl;
    cout << "Subtraction (5 - 3): " << subtract(5, 3) << endl;
    cout << "Multiplication (5 * 3): " << multiply(5, 3) << endl;
    cout << "Division (10 / 2): " << divide(10, 2) << endl;
    cout << "Factorial (5!): " << factorial(5) << endl;
    cout << "GCD (48, 18): " << gcd(48, 18) << endl;
    cout << "LCM (4, 6): " << lcm(4, 6) << endl;
    cout << "Random number (1 to 10): " << generateRandom(1, 10) << endl;

    return 0;
}
