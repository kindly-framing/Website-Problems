/**
 * @file 7_10001st_prime.cpp
 * @author Steven Aquino
 * @brief By listing the first six prime numbers:
 * 2, 3, 5, 7, 11, and 13
 * we can see that the 6th prime is 13.
 *
 * What is the 10,001st prime number?
 * @date 2020-06-14
 *
 * @copyright Copyright (c) 2020
 *
 */

#include <cmath>
#include <iostream>

/**
 * @brief Checks if the number is prime.
 * @param num An integer number.
 * @return True if the number is prime.
 */
bool is_prime(long long num)
{
    // Lowest prime is 2!
    if (num <= 1) {
        return false;
    }

    // (i * i <= num) removes checking redundant divisors.
    for (long long i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }

    return true;
}

/**
 * @brief Finds the prime at a given position.
 * Position 1 : 2, Position 2 : 3, Position 3 : 5
 * @param prime_pos Position of the prime.
 * @return The prime at the given position.
 */
long long find_prime_at_position(long long prime_pos)
{
    long long pos = 0;
    long long num = 0;

    // Gets the prime number at position given.
    while (pos != prime_pos) {
        num++;
        if (is_prime(num)) {
            pos++;
        }
    }

    return num;
}

/**
 * @brief Controls the main operation of the program.
 */
int main()
{
    std::cout << "Position 6 prime: " << find_prime_at_position(6) << '\n';

    std::cout << "Position 10001 prime: " << find_prime_at_position(10001)
              << "\n";

    return 0;
}
