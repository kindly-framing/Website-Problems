/**
 * @file 8_largest_product_in_series.cpp
 * @author Steven Aquino
 * @brief The four adjacent digits in the 1000-digit number that have the
 * greatest product are 9 × 9 × 8 × 9 = 5832.
 *
 * Find the thirteen adjacent digits in the 1000-digit number that have the
 * greatest product. What is the value of this product?
 * @date 2020-06-14
 *
 * @copyright Copyright (c) 2020
 *
 */

#include <algorithm>
#include <iostream>
#include <string>

// The 1000 digit number from the problem.
const std::string THOUSAND_DIGIT_NUM =
    "73167176531330624919225119674426574742355349194934969835203127745063262395"
    "78318016984801869478851843858615607891129494954595017379583319528532088055"
    "11125406987471585238630507156932909632952274430435576689664895044524452316"
    "17318564030987111217223831136222989342338030813533627661428280644448664523"
    "87493035890729629049156044077239071381051585930796086670172427121883998797"
    "90879227492190169972088809377665727333001053367881220235421809751254540594"
    "75224352584907711670556013604839586446706324415722155397536978179778461740"
    "64955149290862569321978468622482839722413756570560574902614079729686524145"
    "35100474821663704844031998900088952434506585412275886668811642717147992444"
    "29282308634656748139191231628245861786645835912456652947654568284891288314"
    "26076900422421902267105562632111110937054421750694165896040807198403850962"
    "45544436298123098787992724428490918884580156166097919133875499200524063689"
    "91256071760605886116467109405077541002256983155200055935729725716362695618"
    "82670428252483600823257530420752963450";

/**
 * Multiplies the individual digits within a number.
 * @param num An integer number.
 * @return The multiplication of the individual digits.
 */
long long multiply_digits(std::string num) {
    if (num.empty()) {
        return 0; // No digits to multiply!
    }

    // Multiplying individual digits.
    long long product = 1;
    for (char c : num) {
        product *= c - '0';
    }

    return product;
}

/**
 * Finds the greatest product in the 1000-digit number by adjacent digits.
 * @param adjacent The amount of adjacent digits.
 * @return The greatest product.
 */
long long greatest_adjacent_product(int adjacent) {
    std::string greatest_substr;
    long long greatest_product = 0;

    // Multiplying the adjacent digits in the number.
    for (int i = 0; i < THOUSAND_DIGIT_NUM.length(); i++) {
        std::string digits = THOUSAND_DIGIT_NUM.substr(i, adjacent);

        long long product = multiply_digits(digits);

        if (product > greatest_product) {
            greatest_product = product;
            greatest_substr = digits;
        }
    }

    std::cout << "The adjacent digits: " << greatest_substr << "\n";
    return greatest_product;
}

/**
 * @brief Controls the main operation of the program.
 */
int main() {
    std::cout << greatest_adjacent_product(4) << "\n";
    std::cout << greatest_adjacent_product(13) << "\n";
    return 0;
}
