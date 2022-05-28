/**
 * @file 15_lattice_paths.cpp
 * @author Steven Aquino
 * @brief Starting in the top left corner of a 2×2 grid, and only being able to
 * move to the right and down, there are exactly 6 routes to the bottom right
 * corner.
 *
 * How many such routes are there through a 20×20 grid?
 * @version 0.1
 * @date 2022-05-26
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>

long long latticePaths(int gridSize) {
    long long routes = 1;

    // Pascal's Triangle
    for (int i = 1; i <= gridSize; i++) {
        routes = routes * (i + gridSize) / i;
    }

    return routes;
}

int main() {
    std::cout << "Lattice Paths of a 2x2 grid is: " << latticePaths(2) << "\n";
    std::cout << "Lattice Paths of a 20x20 grid is : " << latticePaths(20)
              << "\n";
}