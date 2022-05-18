/**
 * @file 1_multiples_of_3_and_5.cpp
 * @author Steven Aquino
 * @brief If we list all the natural numbers below 10 that are multiples of 3 or
 * 5, we get 3, 5, 6 and 9. The sum of these multiples is 23. Find the sum of
 * all the multiples of 3 or 5 below 1000.
 * @date 2020-06-14
 *
 * @copyright Copyright (c) 2020
 */

#include <iostream>

/**
 * @brief Controls the main operation of the program.
 */
int main()
{
    int sum_of_multiples = 0;

    // Summing all of the multiples of 3 and 5 below 1000.
    for (int n = 1; n < 1000; n++) {
        if ((n % 3 == 0) || (n % 5 == 0)) {
            sum_of_multiples += n;
        }
    }

    std::cout << sum_of_multiples << '\n';
    return 0;
}