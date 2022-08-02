/**
 * @file 26_reciprocal_cycles.cpp
 * @author Steven Aquino
 * @brief A unit fraction contains 1 in the numerator. The decimal
 * representation of the unit fractions with denominators 2 to 10 are given:
 *
 * 1/2	= 	0.5
 * 1/3	= 	0.(3)
 * 1/4	= 	0.25
 * 1/5	= 	0.2
 * 1/6	= 	0.1(6)
 * 1/7	= 	0.(142857)
 * 1/8	= 	0.125
 * 1/9	= 	0.(1)
 * 1/10	= 	0.1
 *
 * Where 0.1(6) means 0.166666..., and has a 1-digit recurring cycle. It can be
 * seen that 1/7 has a 6-digit recurring cycle.
 *
 * Find the value of d < 1000 for which 1/d contains the longest recurring cycle
 * in its decimal fraction part.
 *
 * @version 0.1
 * @date 2022-08-02
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
#include <map>
#include <string>

std::string recurring_cycle(int n);

int main()
{
    const int LIMIT = 1000;

    int max_cycle = 0;
    int max_d = 0;
    for (int d = 2; d < LIMIT; d++) {
        std::string cycle = recurring_cycle(d);
        int cycle_length = cycle.size();
        if (cycle_length > max_cycle) {
            max_cycle = cycle_length;
            max_d = d;
        }
    }

    std::cout << "Value with longest recurring cycle: " << max_d << "\n";
    return 0;
}

std::string recurring_cycle(int n)
{
    std::string recurring = "";

    // utilizing a map to store the remainders found
    std::map<int, int> mp;
    mp.clear();

    // using division to calculate each remainder and store it in result
    int remainder = 1 % n;
    while ((remainder != 0) && (mp.find(remainder) == mp.end())) {
        mp[remainder] = recurring.length();
        remainder *= 10;
        recurring += std::to_string(remainder / n);
        remainder %= n;
    }

    return recurring;
}