/**
 * @file 5_smallest_multiple.cpp
 * @author Steven Aquino
 * @brief 2520 is the smallest number that can be divided by each of the numbers
 * from 1 to 10 without any remainder.
 * What is the smallest positive number that is evenly divisible by all of the
 * numbers from 1 to 20?
 * @date 2020-06-14
 *
 * @copyright Copyright (c) 2020
 */

#include <algorithm>
#include <iostream>

/**
 * @brief Finds the Lowest Common Multiple for a range of numbers.
 * @param start Range starting point.
 * @param end Range end point.
 * @return The lowest common multiple between the user-defined range.
 */
long long lowest_common_multiple_in_range(long long start, long long end)
{
    long long lcm = 1; // Lowest Common Multiple.

    // Using the formula LCM = (a * b) / GCF(a, b) for each number in the range.
    for (long long n = start; n <= end; n++) {
        lcm = (lcm * n) / (std::__gcd(lcm, n));
    }

    return lcm;
}

/**
 * @brief Controls the main operation of the program.
 */
int main()
{
    std::cout << "LCM between 1 and 10 is: "
              << lowest_common_multiple_in_range(1, 10) << "\n";

    std::cout << "LCM between 1 and 20 is: "
              << lowest_common_multiple_in_range(1, 20) << "\n";

    return 0;
}
