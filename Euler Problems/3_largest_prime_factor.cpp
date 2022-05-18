/**
 * @file 3_largest_prime_factor.cpp
 * @author Steven Aquino
 * @brief The prime factors of 13195 are 5, 7, 13 and 29.
 * What is the largest prime factor of the number 600851475143?
 * @date 2020-06-14
 *
 * @copyright Copyright (c) 2020
 */

#include <iostream>

/**
 * @brief Finds the largest prime factor of the given number using the prime
 * factorization method.
 * @param num A natural number to find the largest prime factor of.
 * @return The largest prime factor.
 */
long long largest_prime_factor(long long num)
{
    long long factor = 2; // Minimum prime factor is 2.

    // Implements the prime factorization method to find the largest prime
    // factor.
    while (num > 1) {
        if (num % factor == 0) {
            num /= factor;
            factor--; // Ensures current factor is tested again.
        }
        factor++;
    }

    return factor;
}

/**
 * @brief Controls the main operation of the program.
 */
int main()
{
    std::cout << "The largest prime factor of 13195 is: "
              << largest_prime_factor(13195) << "\n";

    std::cout << "The largest prime factor of 600851475143 is: "
              << largest_prime_factor(600851475143) << '\n';

    return 0;
}
