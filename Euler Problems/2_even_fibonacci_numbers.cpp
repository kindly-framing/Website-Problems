/**
 * @file 2_even_fibonacci_numbers.cpp
 * @author Steven Aquino
 * @brief Each new term in the Fibonacci sequence is generated by adding the
 * previous two terms.
 *
 * By starting with 1 and 2, the first 10 terms will be:
 * 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...
 *
 * By considering the terms in the Fibonacci sequence whose values do not exceed
 * four million, find the sum of the even-valued terms.
 * @date 2020-06-14
 *
 * @copyright Copyright (c) 2020
 */

#include <iostream>

/**
 * @brief Gets the sum of the even Fibonacci numbers up to a number limit.
 * @param num_limit Limit that the Fibonacci number cannot surpass.
 * @return The sum of even Fibonacci numbers.
 */
long long sum_of_even_fibonacci(long long num_limit)
{
    // Used to get the next Fibonacci number.
    long long n1 = 0;
    long long n2 = 1;
    long long fib = n1 + n2;

    // Adding even fibonacci numbers.
    long long even_sum = 0;

    while (fib <= num_limit) {
        if ((fib % 2) == 0) {
            even_sum += fib;
        }

        // Getting the next Fibonacci number.
        n1 = n2;
        n2 = fib;
        fib = n1 + n2;
    }

    return even_sum;
}

/**
 * @brief Controls the main operation of the program.
 */
int main()
{
    std::cout << sum_of_even_fibonacci(4'000'000) << "\n";
    return 0;
}