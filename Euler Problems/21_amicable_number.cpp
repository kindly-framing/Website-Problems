/**
 * @file 21_amicable_number.cpp
 * @author Steven Aquino
 * @brief Let d(n) be defined as the sum of proper divisors of n (numbers less
 * than n which divide evenly into n). If d(a) = b and d(b) = a, where a ≠ b,
 * then a and b are an amicable pair and each of a and b are called amicable
 * numbers.
 *
 * For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44,
 * 55 and 110; therefore d(220) = 284. The proper divisors of 284 are 1, 2, 4,
 * 71 and 142; so d(284) = 220.
 *
 * Evaluate the sum of all the amicable numbers under 10000.
 * @version 0.1
 * @date 2022-07-31
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>

int d(const int &n);
bool is_amicable(const int &a, const int &b);

int main()
{
    unsigned long sum;
    for (int i = 1; i < 10000; i++) {
        if (is_amicable(i, d(i))) {
            sum += i;
        }
    }
    std::cout << sum << "\n";
    return 0;
}

int d(const int &n)
{
    int sum = 0;
    for (int i = 1; i < n; i++) {
        sum += (n % i == 0) ? i : 0;
    }
    return sum;
}

bool is_amicable(const int &a, const int &b) { return a != b && d(b) == a; }