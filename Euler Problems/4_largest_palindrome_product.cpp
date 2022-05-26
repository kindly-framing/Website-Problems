/**
 * @file 4_largestPalindromeProduct.cpp
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
 * @brief Checks if the number is a palindrome. NOTE: Not to be used for
 * fractionals!
 * @param num Any integer number to check.
 * @return True if the number is a palindrome.
 */
bool isPalindrome(long long num) {
    std::string original = std::to_string(num);
    std::string reversed = original;
    std::reverse(reversed.begin(), reversed.end());
    return (original == reversed);
}

/**
 * @brief Finds the largest palindrome product based on the number of
 * digits. Ex. 2 -> 10-99, 3 -> 100-999
 * @param digits The number of digits.
 * @return Largest palindrome product.
 */
long long largestPalindromeProduct(int digits) {
    long long largestPalindrome = 0;

    // Using the power of 10 to define the range.
    double rangeDefinition = pow(10, digits - 1);
    long long start = 1 * rangeDefinition;
    long long end = 10 * rangeDefinition;
    std::cout << "Range Defined: " << start << " - " << end << "\n";

    // Finding the largest palindrome.
    for (int i = end; i > start; i--) {
        for (int j = end; j > start; j--) {
            long long product = i * j;

            if (product > largestPalindrome) {
                largestPalindrome =
                    (isPalindrome(product)) ? product : largestPalindrome;
            }
        }
    }

    return largestPalindrome;
}

/**
 * @brief Controls the main operation of the program.
 */
int main() {
    std::cout << "Largest palindrome product of 2-digit numbers: "
              << largestPalindromeProduct(2) << '\n';

    std::cout << "Largest palindrome product of 3-digit numbers: "
              << largestPalindromeProduct(3) << '\n';

    return 0;
}
