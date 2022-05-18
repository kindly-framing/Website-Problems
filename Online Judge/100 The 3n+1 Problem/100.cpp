/**
 * @file 100.cpp
 * @author Steven Aquino
 * @brief This is the main file for Problem 100 for Online Judge.
 * @version 0.1
 * @date 2022-04-21
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>

int cycle_length(int num);

int main()
{
    std::cout << "Enter two numbers (single line): \n";
    int num1, num2;

    while (std::cin >> num1 >> num2)
    {
        int max_length = 0;

        for (int i = num1; i <= num2; i++)
        {
            max_length = std::max(max_length, cycle_length(i));
        }

        std::cout << num1 << " " << num2 << " " << max_length << "\n";
    }

    return 0;
}

int cycle_length(int num)
{
    int len = 1;
    int n = num;

    while (n != 1)
    {
        if ((n % 2) != 0)
        {
            n = 3 * n + 1;
        }
        else
        {
            n /= 2;
        }

        len++;
    }

    return len;
}