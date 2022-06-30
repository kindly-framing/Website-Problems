/**
 * @file 102.cpp
 * @author Steven Aquino
 * @brief This is the solution for 102 Ecological Bin Packing.
 * @version 0.1
 * @date 2022-06-26
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

/**
 * @brief Bin that contains brown, green, and clear bottles.
 *
 */
struct Bin {
    int brown_bottles;
    int green_bottles;
    int clear_bottles;

    Bin(int brown, int green, int clear)
    {
        brown_bottles = brown;
        green_bottles = green;
        clear_bottles = clear;
    }
};

std::string find_min_config(std::vector<Bin>);
int moves_to_sort(std::vector<Bin>, std::string);

int main()
{
    std::vector<Bin> p_102;  // Store the bins and their bottles
    int b1, b2, b3;          // Brown bottles for each bin
    int g1, g2, g3;          // Green bottles for each bin
    int c1, c2, c3;          // Clear bottles for each bin

    while (scanf("%d%d%d%d%d%d%d%d%d", &b1, &g1, &c1, &b2, &g2, &c2, &b3, &g3,
                 &c3) == 9) {
        Bin x(b1, g1, c1);
        Bin y(b2, g2, c2);
        Bin z(b3, g3, c3);

        p_102.push_back(x);
        p_102.push_back(y);
        p_102.push_back(z);

        std::cout << find_min_config(p_102) << "\n";

        p_102.clear();
    }

    return 0;
}

std::string find_min_config(std::vector<Bin> bins)
{
    int min_moves;           // Minimum moves to sort bins
    std::string min_config;  // Configuration with the minimum moves

    std::string config = "BCG";  // The starting configuration of the bins
    do {
        int moves = moves_to_sort(bins, config);

        if (config == "BCG") {
            min_moves = moves;
            min_config = config;
        }
        else {
            if (moves < min_moves) {
                min_moves = moves;
                min_config = config;
            }
        }

    } while (std::next_permutation(std::begin(config), std::end(config)));

    return min_config + " " + std::to_string(min_moves);
}

int moves_to_sort(std::vector<Bin> bins, std::string config)
{
    int moves = 0;

    // Based on the character in config, adds the other bottles that don't match
    // the label of the bin
    for (int i = 0; i < bins.size(); i++) {
        switch (config[i]) {
            case 'B':
                moves += bins[i].clear_bottles + bins[i].green_bottles;
                break;
            case 'G':
                moves += bins[i].brown_bottles + bins[i].clear_bottles;
                break;
            default:
                moves += bins[i].brown_bottles + bins[i].green_bottles;
                break;
        }
    }

    return moves;
}