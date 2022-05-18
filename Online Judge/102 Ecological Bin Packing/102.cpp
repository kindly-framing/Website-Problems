/**
 * @file 102.cpp
 * @author Steven Aquino
 * @brief This is the main file for Problem 102 for Online Judge
 * @version 0.1
 * @date 2022-04-21
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

/**
 * @brief For the problem, represents the bin and the three types of bottles
 * that can be in the bin.
 *
 */
struct Bin
{
    int brown_bottles;
    int green_bottles;
    int clear_bottles;
    std::vector<int> bottles;
    std::string label = ""; // Bin is assigned later on.

    /**
     * @brief Construct a new Bin object
     *
     * @param brown Amount of brown bottles
     * @param green Amount of green bottles
     * @param clear Amount of clear bottles
     */
    Bin(int brown, int green, int clear)
    {
        // Order comes from problem
        bottles.push_back(brown);
        bottles.push_back(green);
        bottles.push_back(clear);

        brown_bottles = brown;
        green_bottles = green;
        clear_bottles = clear;
    }

    bool is_reserved() { return label != ""; }
};

int calc_min_moves_by_bottle(Bin &one, Bin &two, Bin &three,
                             std::string bottle_type);
std::string solve_problem(Bin &one, Bin &two, Bin &three);
std::string bin_labels(Bin a, Bin b, Bin c);

int main()
{
    int b1, b2, b3;
    int g1, g2, g3;
    int c1, c2, c3;

    while (std::cin >> b1 >> g1 >> c1 >> b2 >> g2 >> c2 >> b3 >> g3 >> c3)
    {
        Bin one   = Bin(b1, g1, c1);
        Bin two   = Bin(b2, g2, c2);
        Bin three = Bin(b3, g3, c3);

        std::cout << solve_problem(one, two, three) << "\n";
    }

    return 0;
}

int calc_min_moves_by_bottle(Bin &one, Bin &two, Bin &three,
                             std::string bottle_type)
{
    std::vector<int> tmp;
    if (bottle_type == "brown")
    {
        tmp = {one.brown_bottles, two.brown_bottles, three.brown_bottles};
    }
    if (bottle_type == "green")
    {
        tmp = {one.green_bottles, two.green_bottles, three.green_bottles};
    }
    if (bottle_type == "clear")
    {
        tmp = {one.clear_bottles, two.clear_bottles, three.clear_bottles};
    }

    int min_moves    = 0;
    int bin_with_max = std::max_element(tmp.begin(), tmp.end()) - tmp.begin();

    if (bin_with_max == 2)
    {
        if (three.is_reserved())
        {
            while (bin_with_max == 2)
            {
                min_moves += tmp[bin_with_max];
                tmp.erase(tmp.begin() + bin_with_max);
                bin_with_max =
                    std::max_element(tmp.begin(), tmp.end()) - tmp.begin();
            }
        }
        else
        {
            three.label = bottle_type;
        }
    }
    if (bin_with_max == 1)
    {
        if (two.is_reserved())
        {
            while (bin_with_max == 1)
            {
                min_moves += tmp[bin_with_max];
                tmp.erase(tmp.begin() + bin_with_max);
                bin_with_max =
                    std::max_element(tmp.begin(), tmp.end()) - tmp.begin();
            }
        }
        else
        {
            two.label = bottle_type;
        }
    }
    if (bin_with_max == 0)
    {
        if (one.is_reserved())
        {
            while (bin_with_max == 0)
            {
                min_moves += tmp[bin_with_max];
                tmp.erase(tmp.begin() + bin_with_max);
                bin_with_max =
                    std::max_element(tmp.begin(), tmp.end()) - tmp.begin();
            }
        }
        else
        {
            one.label = bottle_type;
        }
    }

    for (int i = 0; i < tmp.size(); i++)
    {
        if (i != bin_with_max)
        {
            min_moves += tmp[i];
        }
    }

    return min_moves;
}

/**
 * @brief Solves Problem 102 by labeling each unlabeled bin to a bottle type.
 * The algorithm is to find the largest quantity of a bottle type in
 * the bin and label that bin for that bottle type. However, once a bin is
 * labeled for a bottle type, another bin cannot be labeled for that bottle
 * type.
 *
 * @param one First bin
 * @param two Second bin
 * @param three Third bin
 * @return std::string The first letter of the bin label and the minimum number
 * of moves to move bottles to the correct bins.
 */
std::string solve_problem(Bin &one, Bin &two, Bin &three)
{
    int brown_moves = calc_min_moves_by_bottle(one, two, three, "brown");
    int green_moves = calc_min_moves_by_bottle(one, two, three, "green");
    int clear_moves = calc_min_moves_by_bottle(one, two, three, "clear");
    int total_moves = brown_moves + green_moves + clear_moves;
    return bin_labels(one, two, three) + " " + std::to_string(total_moves);
}

std::string bin_labels(Bin a, Bin b, Bin c)
{
    std::string box_labels;
    box_labels += a.label[0];
    box_labels += b.label[0];
    box_labels += c.label[0];
    return box_labels;
}
