/**
 * @file 16_power_digit_sum.cpp
 * @author Steven Aquino
 * @brief
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
 * @brief Find the sum of digits of 2 to the power given.
 *
 * @param pwr 2^pwr
 * @return double The sum of the digits.
 */
double powerDigitSum(int pwr) {
    double sum = 0; // Sum of digits

    double powerNum = std::pow(2, pwr); // May not work for huge power factors

    // Add each digit in the number
    std::string n = std::to_string(powerNum);
    for (int i = 0; i < n.size(); i++) {
        // Checking bc doubles contain decimal points
        if (isdigit(n[i])) {
            sum += n[i] - '0';
        }
    }

    return sum;
}

/**
 * @brief Controls the main operation of the program.
 *
 * @return int
 */
int main() {
    std::cout << "Sum of digits of 2^15 is : " << powerDigitSum(15) << "\n";
    std::cout << "Sum of digits of 2^1000 is : " << powerDigitSum(1000) << "\n";
    return 0;
}