/**
 * @file 20_factorial_digit_sum.cpp
 * @author Steven Aquino
 * @brief n! means n × (n − 1) × ... × 3 × 2 × 1
 *
 * For example, 10! = 10 × 9 × ... × 3 × 2 × 1 = 3628800,
 * and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0
 * = 27.
 *
 * Find the sum of the digits in the number 100!
 * @version 0.1
 * @date 2022-06-24
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
#include <string>

using namespace std;

typedef string Number;

Number factorial(int n);
Number multiply(const Number n1, const Number n2);
long long sum_of_digits(const Number n);

int main()
{
    cout << sum_of_digits(factorial(100)) << endl;
    return 0;
}

Number factorial(int n)
{
    Number factorial = "1";
    for (int i = 2; i <= n; i++) {
        factorial = multiply(to_string(i), factorial);
    }
    return factorial;
}

Number multiply(const Number n1, const Number n2)
{
    Number product(n1.size() + n2.size(), '0');

    for (int i = n1.size() - 1; i >= 0; i--) {
        for (int j = n2.size() - 1; j >= 0; j--) {
            int p = (n1[i] - '0') * (n2[j] - '0') + (product[i + j + 1] - '0');
            product[i + j + 1] = p % 10 + '0';
            product[i + j] += p / 10;
        }
    }

    // There will be a leading zero because of the carry
    for (int i = 0; i < product.size(); i++) {
        if (product[i] != '0') {
            return product.substr(i);
        }
    }
    return "0";
}

long long sum_of_digits(const Number n)
{
    long long sum = 0;
    for (char digit : n) {
        sum += digit - '0';
    }
    return sum;
}
