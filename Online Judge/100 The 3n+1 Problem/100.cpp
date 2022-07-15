/**
 * @file 100.cpp
 * @author Steven Aquino
 * @brief This is the main file for Problem 100 for Online Judge.
 * @version 0.1
 * @date 2022-04-21
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>

/**
 * @brief Calculates the cycle length of a given number. The algorithm for cycle
 * length takes the given number and applies this formula until n = 1. If n is
 * odd, n = 3n + 1. Otherwise, n = n/2.
 *
 * @return int The cycle length for the number.
 */
int cycle_length(int);

int main()
{
    int n1, n2;

    while (scanf("%d%d", &n1, &n2) == 2) {
        int max_length = 0;

        // Finding the max cycle length for numbers given
        int min = std::min(n1, n2);
        int max = std::max(n1, n2);
        for (int i = min; i <= max; i++) {
            max_length = std::max(max_length, cycle_length(i));
        }

        printf("%d %d %d\n", n1, n2, max_length);
    }

    return 0;
}

int cycle_length(int n)
{
    int len = 1;

    while (n != 1) {
        if ((n % 2) != 0) {
            n = 3 * n + 1;
        }
        else {
            n /= 2;
        }

        len++;
    }

    return len;
}