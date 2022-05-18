/**
 * @file 4_largest_palindrome_product.cpp
 * @author Steven Aquino
 * @brief A palindromic number reads the same both ways. The largest palindrome
 * made from the product of two 2-digit numbers is 9009 = 91 × 99.
 * Find the largest palindrome made from the product of two 3-digit numbers.
 * @date 2020-06-15
 *
 * @copyright Copyright (c) 2020
 */

#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>

/**
 * @brief Checks if the number is a palindrome. NOTE: Not to be used for double!
 * @param num Any integer number to check.
 * @return True if the number forwards is the same backwards.
 */
bool is_palindrome(long long num)
{
    std::string original = std::to_string(num); // string to use reverse().

    std::string temp = original;
    std::reverse(temp.begin(), temp.end());
    std::string reversed = temp;

    return (original == reversed);
}

/**
 * @brief Finds the largest palindrome product based on the number of
 * digits. Ex. 2 -> 10-99, 3 -> 100-999
 * @param num_of_digits The number of digits.
 * @return Largest palindrome product.
 */
long long largest_palindrome_product(int num_of_digits)
{
    long long largest_palindrome = 0;

    // Using the power of 10 to define the range.
    long long digits = pow(10, num_of_digits - 1);
    long long start = 9 * digits;
    long long end = 10 * digits;

    // Finding the largest palindrome.
    for (int i = start; i < end; i++) {
        for (int j = start; j < end; j++) {
            long long product = i * j;

            if (is_palindrome(product)) {
                largest_palindrome = std::max(product, largest_palindrome);
            }
        }
    }

    return largest_palindrome;
}

/**
 * @brief Controls the main operation of the program.
 */
int main()
{
    std::cout << "Largest palindrome product of 2-digit numbers: "
              << largest_palindrome_product(2) << '\n';

    std::cout << "Largest palindrome product of 3-digit numbers: "
              << largest_palindrome_product(3) << '\n';

    return 0;
}
