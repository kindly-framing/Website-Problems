/**
 * @file 14_longest_collatz_sequence.cpp
 * @author Steven Aquino
 * @brief The following iterative sequence is defined for the set of positive
 * integers: n -> n/2 (n is even) and n -> 3n + 1 (n is odd)
 *
 * Using the rule above and starting with 13, we generate the following
 * sequence: 13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1
 *
 * It can be seen that this sequence (starting at 13 and finishing at 1)
 * contains 10 terms. Although it has not been proved yet (Collatz Problem), it
 * is thought that all starting numbers finish at 1.
 *
 * Which starting number, under one million, produces the longest chain?
 * @date 2020-06-20
 *
 * @copyright Copyright (c) 2020
 *
 */

#include <iostream>

long long collatz_sequence_length(long long num);

/**
 * @brief Controls the main operation of the program.
 */
int main()
{
    const long NUM_LIMIT = 1000000;

    long long num = 0;           // Number with the longest chain.
    long long longest_chain = 0; // Longest chain of the number.

    // Finding the number with the longest chain.
    for (long long i = 1; i < NUM_LIMIT; i++) {
        long long chain = collatz_sequence_length(i);

        if (chain > longest_chain) {
            longest_chain = chain;
            num = i;
        }
    }

    std::cout << "Longest chain: " << longest_chain << "\n";
    std::cout << "Number: " << num << "\n";
    return 0;
}

/**
 * @brief Gets the length of the Collatz sequence for the number. The Collatz
 * sequence is defined for the set of positive integers: n -> n/2 (n is even) n
 * -> 3n + 1 (n is odd).
 *
 * @param num An integer.
 * @return The length of the Collatz sequence for the number.
 */
long long collatz_sequence_length(long long num)
{
    // Loop doesn't count the "1" which ends the sequence.
    long long length = 1;

    while (num > 1) {
        // n/2 (n is even) and 3n + 1 (n is odd)
        num = (num % 2 == 0) ? (num / 2) : (3 * num + 1);
        length++;
    }

    return length;
}
