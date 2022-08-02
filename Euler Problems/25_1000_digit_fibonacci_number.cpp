/**
 * @file 25_1000_digit_fibonacci_number.cpp
 * @author Steven Aquino
 * @brief The Fibonacci sequence is defined by the recurrence relation:
 *
 * Fn = Fn−1 + Fn−2, where F1 = 1 and F2 = 1.
 * Hence the first 12 terms will be:
 *
 * F1 = 1
 * F2 = 1
 * F3 = 2
 * F4 = 3
 * F5 = 5
 * F6 = 8
 * F7 = 13
 * F8 = 21
 * F9 = 34
 * F10 = 55
 * F11 = 89
 * F12 = 144
 *
 * The 12th term, F12, is the first term to contain three digits.
 *
 * What is the index of the first term in the Fibonacci sequence to contain 1000
 * digits?
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

typedef std::string Integer;
Integer add(Integer n1, Integer n2);

int main()
{
    const int TARGET_DIGITS = 1000;

    Integer f1 = "1";
    Integer f2 = "1";
    int pos = 2; // the first two are already accounted for
    while (f2.size() < TARGET_DIGITS) {
        Integer fn = add(f1, f2);
        f1 = f2;
        f2 = fn;
        pos++;
    }
    std::cout << "The index of the first term in the Fibonacci sequence to "
                 "contain 1000 digits: "
              << pos << "\n";

    return 0;
}

Integer add(Integer n1, Integer n2)
{
    // treating n1 as the largest number
    if (n2.size() > n1.size()) {
        std::swap(n1, n2);
    }
    int max_size = n1.size();
    int min_size = n2.size();

    // reversing to add from left to right
    std::reverse(n1.begin(), n1.end());
    std::reverse(n2.begin(), n2.end());

    // performing add operation
    Integer sum = "";
    int n = 0;
    int carry = 0;
    for (int i = 0; i < min_size; i++) {
        // adding digits from both integers
        n = (n1[i] - '0') + (n2[i] - '0') + carry;
        sum.insert(0, std::to_string(n % 10));
        carry = n / 10;
    }
    for (int i = min_size; i < max_size; i++) {
        // if any, adds leftover digits from the largest number
        n = (n1[i] - '0') + carry;
        sum.insert(0, std::to_string(n % 10));
        carry = n / 10;
    }

    // if present, add leftover carry to the sum
    if (carry != 0) {
        sum.insert(0, std::to_string(carry));
    }
    return sum;
}