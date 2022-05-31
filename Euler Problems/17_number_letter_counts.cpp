/**
 * @file 17_number_letter_counts.cpp
 * @author Steven Aquino
 * @brief If the numbers 1 to 5 are written out in words: one, two, three, four,
 * five, then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.
 *
 * If all the numbers from 1 to 1000 (one thousand) inclusive were written out
 * in words, how many letters would be used?
 *
 *  NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and
 * forty-two) contains 23 letters and 115 (one hundred and fifteen) contains 20
 * letters. The use of "and" when writing out numbers is in compliance with
 * British usage.
 * @version 0.1
 * @date 2022-05-26
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <cmath>
#include <iostream>
#include <string>

/**
 * @brief Find the size of the string excluding hypens and spaces.
 *
 * @param str
 * @return int The amount of letters used in the string.
 */
int countOfLetters(std::string str) {
    int count = 0;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] != '-' && str[i] != ' ') {
            count++;
        }
    }
    std::cout << str << " : " << count << "\n";
    return count;
}

/**
 * @brief Converts a number to its written form. NOTE: Only works up to 1000
 *
 * @param n
 * @return std::string
 */
std::string writtenOut(int n) {
    std::cout << n << " ";
    // Utilizing arrays to store the names for numbers
    const std::string unique[] = {
        "one", "two", "three", "four", "five", "six", "seven", "eight", "nine",
    };
    const std::string teens[] = {"ten",      "eleven",  "twelve",  "thirteen",
                                 "fourteen", "fifteen", "sixteen", "seventeen",
                                 "eighteen", "nineteen"};
    const std::string tens[] = {"twenty", "thirty",  "forty",  "fifty",
                                "sixty",  "seventy", "eighty", "ninety"};

    std::string name; // The name of the number we are returning.

    std::string sNum = std::to_string(n);
    int len = sNum.size();

    switch (len) {
    case 1: {
        name += unique[n - 1];
        break;
    }
    case 2: {
        if (n < 20) {
            name += teens[n - 10];
        } else {
            int firstDigit = sNum[0] - '0';
            name += tens[firstDigit - 2];

            int secondDigit = sNum[1] - '0';
            if (secondDigit != 0) {
                name += "-" + unique[secondDigit - 1];
            }
        }
        break;
    }
    case 3: {
        int first = sNum[0] - '0';
        int second = sNum[1] - '0';
        int third = sNum[2] - '0';

        if (second == third && second == 0) {
            name += unique[first - 1] + " hundred";
            break;
        }

        name += unique[first - 1] + " hundred and ";

        int lastTwo = stoi(sNum.substr(1, 2));

        if (lastTwo >= 20) {
            name += tens[second - 2];
            if (third != 0) {
                name += "-" + unique[third - 1];
            }
        } else if (lastTwo < 10) {
            name += unique[third - 1];
        } else {
            name += teens[lastTwo - 10];
        }
        break;
    }
    default:
        name += "one thousand";
        break;
    }

    return name;
}

/**
 * @brief Finds the amount of letters needed to write each number from 1 to
 * given end inclusively. (Excludes hyphens and spaces)
 *
 * @param end The last number for the range.
 * @return long long Total of letters used.
 */
long long countOfNumLetters(int end) {
    long long sum = 0;

    // Go through each number from 1 - end inclusively.
    for (int num = 1; num <= end; num++) {
        std::string name = writtenOut(num);
        sum += countOfLetters(name); // Must exclude '-' and ' ' so no size()
    }

    return sum;
}

int main() {
    std::cout << "Enter a number to find the answer: ";
    int n;
    std::cin >> n;

    std::cout << "Letters used for 1-" << n
              << " written out: " << countOfNumLetters(n) << "\n";

    return 0;
}