/**
 * @file 9_special_pythagorean_triplet.cpp
 * @author Steven Aquino
 * @brief A Pythagorean triplet is a set of three natural numbers, a < b < c,
 * for which, a^2 + b^2 = c^2. For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.
 *
 * There exists exactly one Pythagorean triplet for which a + b + c = 1000.
 * Find the product abc.
 * @date 2020-06-14
 *
 * @copyright Copyright (c) 2020
 *
 */

#include <iostream>

/**
 * @brief A PythagoreanTriplet object consists of three numbers (a, b, c) which
 * represents the Pythagorean Theorem (a^2 + b^2 = c^2).
 */
struct PythagoreanTriplet {
    // Parts of Pythagorean's Theorem.
    long long a, b, c;

    /**
     * @brief Constructs a new PythagoreanTriplet object.
     *
     * @param first a
     * @param second b
     * @param third c
     */
    PythagoreanTriplet(long long first, long long second, long long third)
    {
        a = first;
        b = second;
        c = third;
    }

    /**
     * @brief Prints each part of Pythagorean's Theorem.
     */
    void print_triplet() { std::cout << a << " " << b << " " << c << "\n"; }

    /**
     * @return The product of a, b, and c.
     */
    long long multiply_triplet() { return (a * b * c); }
};

PythagoreanTriplet find_triplet_sum_equals(long long num);
void find_m_and_n(long long num, long long* m_val, long long* n_val);

/**
 * @brief Controls the main operation of the program.
 */
int main()
{
    PythagoreanTriplet answer = find_triplet_sum_equals(1000);

    std::cout << "Triplet: ";
    answer.print_triplet();

    std::cout << "Product: " << answer.multiply_triplet() << " \n";
    return 0;
}

/**
 * @brief Gets Pythagorean triplet, if any, who's individual parts summed up
 * equals the number given.
 *
 * @param num A Pythagorean triplet's sum equals this number.
 * @return Pythagorean Triplet who's sum equals the number. If no valid triplet
 * is found, will return zeros.
 */
PythagoreanTriplet find_triplet_sum_equals(long long num)
{
    // The equation used to find the triplet is 2m(m + n) = num after combining
    // Euclid's formula (a = 2mn, b = m^2 - n^2, c = m^2 + n^2) and the sum of
    // the individual parts (a + b + c = num).
    long long m;
    long long n;
    find_m_and_n(num, &m, &n);

    // Euclid's formula states that m has to be greater than n.
    if (m <= n) {
        PythagoreanTriplet not_found(0, 0, 0);
        return not_found;
    }

    // Euclid's equations.
    long long a = 2 * m * n;
    long long b = (m * m) - (n * n);
    long long c = (m * m) + (n * n);
    PythagoreanTriplet found(a, b, c);

    return found;
}

/**
 * @brief Finds m and n by implementing a modified equation of Euclid's formula
 * for this problem. The equation used is 2m(m + n) = num.
 *
 * @param num Number to find the m and n value for.
 * @param m_val Reference to variable to store m.
 * @param n_val Reference to variable to store n.
 */
void find_m_and_n(long long num, long long* m_val, long long* n_val)
{
    bool found_m_and_n = false;

    // Finding m and n.
    for (long long m = 1; m < num; m++) {
        for (long long n = 1; n < m; n++) {
            if ((2 * m * (m + n)) == num) {
                *m_val = m;
                *n_val = n;
                found_m_and_n = true;
                goto LOOP_EXITED;
            }
        }
    }

LOOP_EXITED:
    if (!found_m_and_n) {
        // m has to be greater than n.
        *m_val = 0;
        *n_val = 0;
    }
}
