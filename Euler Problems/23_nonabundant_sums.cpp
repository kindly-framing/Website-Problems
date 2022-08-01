/**
 * @file 23_nonabundant_sums.cpp
 * @author Steven Aquino
 * @brief A perfect number is a number for which the sum of its proper divisors
 * is exactly equal to the number. For example, the sum of the proper divisors
 * of 28 would be 1 + 2 + 4 + 7 + 14 = 28, which means that 28 is a perfect
 * number.
 *
 * A number n is called deficient if the sum of its proper divisors is less than
 * n and it is called abundant if this sum exceeds n.
 *
 * As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest
 * number that can be written as the sum of two abundant numbers is 24. By
 * mathematical analysis, it can be shown that all integers greater than 28123
 * can be written as the sum of two abundant numbers. However, this upper limit
 * cannot be reduced any further by analysis even though it is known that the
 * greatest number that cannot be expressed as the sum of two abundant numbers
 * is less than this limit.
 *
 * Find the sum of all the positive integers which cannot be written as the sum
 * of two abundant numbers.
 *
 * @version 0.1
 * @date 2022-08-01
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <algorithm>
#include <iostream>
#include <vector>

bool is_abundant(const int &n);
bool is_abundant_sum(const int &n, const std::vector<int> &vec);

int main()
{
    const unsigned int UPPER_LIMIT = 28123;

    // get a list of abundant numbers
    std::vector<int> abundant_numbers;
    for (int i = 12; i <= UPPER_LIMIT; i++) {
        if (is_abundant(i)) {
            abundant_numbers.push_back(i);
        }
    }

    // get the sum of all the positive integers which cannot be written as the
    // sum of two abundant numbers.
    int sum = 0;
    for (int i = 1; i <= UPPER_LIMIT; i++) {
        if (!is_abundant_sum(i, abundant_numbers)) {
            sum += i;
        }
    }
    std::cout << sum << "\n";

    return 0;
}

bool is_abundant(const int &n)
{
    int sum = 1;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            sum += i;

            int divisor = n / i;
            if (divisor != i) {
                sum += divisor;
            }
        }

        if (sum > n) {
            return true;
        }
    }
    return false;
}

bool is_abundant_sum(const int &n, const std::vector<int> &vec)
{
    for (int sum : vec) {
        if (sum > n) {
            return false;
        }
        int sub = n - sum;
        if (std::binary_search(vec.begin(), vec.end(), sub)) {
            return true;
        }
    }
    return false;
}