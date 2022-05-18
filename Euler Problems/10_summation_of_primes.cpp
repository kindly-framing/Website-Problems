/**
 * @file 10_summation_of_primes.cpp
 * @author Steven Aquino
 * @brief The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
 * Find the sum of all the primes below two million.
 * @date 2020-06-14
 *
 * @copyright Copyright (c) 2020
 *
 */

#include <iostream>

long long sum_of_primes_below(long long max);
bool is_prime(long long num);

/**
 * @brief Controls the main operation of the program.
 */
int main()
{
    std::cout << "Sum of primes below 10 is: " << sum_of_primes_below(10)
              << "\n";

    std::cout << "Sum of primes below 2,000,000 is: "
              << sum_of_primes_below(2'000'000) << "\n";

    return 0;
}

/**
 * @brief Gets the sum of primes below a number limit.
 * @param last Number limit.
 * @return The sum of primes below the number.
 */
long long sum_of_primes_below(long long last)
{
    long long sum = 0;

    for (long long n = 0; n < last; n++) {
        if (is_prime(n)) {
            sum += n;
        }
    }

    return sum;
}

/**
 * Checks if the number is prime.
 * @param num An integer number.
 * @return True if the number is prime.
 */
bool is_prime(long long num)
{
    // Lowest prime is 2!
    if (num <= 1) {
        return false;
    }

    // By setting the divisor limit up to the square root of the number, this
    // eliminates checking redundant divisors.
    for (long long i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }

    return true;
}