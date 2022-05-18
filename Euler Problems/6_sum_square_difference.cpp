/**
 * @file 6_sum_square_difference.cpp
 * @author Steven Aquino
 * @brief The sum of the squares of the first ten natural numbers is,
 * 1^2 + 2^2 +...+ 10^2 = 385.
 *
 * The square of the sum of the first ten natural numbers is,
 * (1+2+...+10)^2 = 55^2 = 3025.
 *
 * Hence the difference between the sum of the squares of the first ten natural
 * numbers and the square of the sum is 3025 − 385 = 2640.
 *
 * Find the difference between the sum of the squares of the first one hundred
 * natural numbers and the square of the sum.
 * @date 2020-06-14
 *
 * @copyright Copyright (c) 2020
 *
 */

#include <iostream>

/**
 * @brief Gets the difference of the sum of the squares and the square of the
 * sum for all natural numbers up to a number limit.
 * @param end Last number to add to the sums.
 * @return The difference of the sum of squares and the square of the sum.
 */
long long difference_of_sum_of_squares_and_squared_sum(long long end)
{
    long long sum_of_squares = 0;
    long long sum = 0; // First step for squared sum.

    // Calculating the sum of squares and the square of the sum.
    for (long long i = 1; i <= end; i++) {
        sum_of_squares += i * i;
        sum += i;
    }
    long long squared_sum = sum * sum;

    return abs(sum_of_squares - squared_sum);
}

/**
 * @brief Controls the main operation of the program.
 */
int main()
{
    std::cout << "First ten natural numbers: "
              << difference_of_sum_of_squares_and_squared_sum(10) << "\n";

    std::cout << "First 100 natural numbers: "
              << difference_of_sum_of_squares_and_squared_sum(100) << "\n";

    return 0;
}
