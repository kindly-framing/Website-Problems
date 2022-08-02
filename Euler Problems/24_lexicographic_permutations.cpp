/**
 * @file 24_lexicographic_permutations.cpp
 * @author Steven Aquino
 * @brief A permutation is an ordered arrangement of objects. For example, 3124
 * is one possible permutation of the digits 1, 2, 3 and 4. If all of the
 * permutations are listed numerically or alphabetically, we call it
 * lexicographic order. The lexicographic permutations of 0, 1 and 2 are:
 *
 * 012   021   102   120   201   210
 *
 * What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4,
 * 5, 6, 7, 8 and 9?
 *
 * @version 0.1
 * @date 2022-08-02
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <algorithm>
#include <iostream>
#include <string>

#define PERMUTATE(x, y) std::next_permutation(x, y)

int main()
{
    const int TARGET_POSITION = 1000000;

    std::string number = "0123456789";
    int pos = 1;
    do {
        pos++;
    } while (PERMUTATE(number.begin(), number.end()) && pos < TARGET_POSITION);

    std::cout << pos << ": " << number << "\n";
    return 0;
}