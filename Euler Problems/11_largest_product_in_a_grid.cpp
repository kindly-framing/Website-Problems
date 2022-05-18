/**
 * @file 11_largest_product_in_a_grid.cpp
 * @author Steven Aquino
 * @brief In the 20×20 grid below, four numbers along a diagonal line have been
 * marked in red.
 *
 * The product of these numbers is 26 × 63 × 78 × 14 = 1788696.
 * What is the greatest product of four adjacent numbers in the same direction
 * (up, down, left, right, or diagonally) in the 20×20 grid?
 * @date 2020-06-15
 *
 * @copyright Copyright (c) 2020
 */

#include <iostream>

const int GRID_SIZE = 20;
const int NUM_OF_ADJACENTS = 4;

// 20x20 grid defined in the problem.
const int NUMBER_GRID[20][20] = {
    {8, 2, 22, 97, 38, 15, 0, 40, 0, 75, 4, 5, 7, 78, 52, 12, 50, 77, 91, 8},
    {49, 49, 99, 40, 17, 81, 18, 57, 60, 87, 17, 40, 98, 43, 69, 48, 4, 56, 62, 0},
    {81, 49, 31, 73, 55, 79, 14, 29, 93, 71, 40, 67, 53, 88, 30, 3, 49, 13, 36, 65},
    {52, 70, 95, 23, 4, 60, 11, 42, 69, 24, 68, 56, 1, 32, 56, 71, 37, 2, 36, 91},
    {22, 31, 16, 71, 51, 67, 63, 89, 41, 92, 36, 54, 22, 40, 40, 28, 66, 33, 13, 80},
    {24, 47, 32, 60, 99, 3, 45, 2, 44, 75, 33, 53, 78, 36, 84, 20, 35, 17, 12, 50},
    {32, 98, 81, 28, 64, 23, 67, 10, 26, 38, 40, 67, 59, 54, 70, 66, 18, 38, 64, 70},
    {67, 26, 20, 68, 2, 62, 12, 20, 95, 63, 94, 39, 63, 8, 40, 91, 66, 49, 94, 21},
    {24, 55, 58, 5, 66, 73, 99, 26, 97, 17, 78, 78, 96, 83, 14, 88, 34, 89, 63, 72},
    {21, 36, 23, 9, 75, 0, 76, 44, 20, 45, 35, 14, 0, 61, 33, 97, 34, 31, 33, 95},
    {78, 17, 53, 28, 22, 75, 31, 67, 15, 94, 3, 80, 4, 62, 16, 14, 9, 53, 56, 92},
    {16, 39, 5, 42, 96, 35, 31, 47, 55, 58, 88, 24, 0, 17, 54, 24, 36, 29, 85, 57},
    {86, 56, 0, 48, 35, 71, 89, 7, 5, 44, 44, 37, 44, 60, 21, 58, 51, 54, 17, 58},
    {19, 80, 81, 68, 5, 94, 47, 69, 28, 73, 92, 13, 86, 52, 17, 77, 4, 89, 55, 40},
    {4, 52, 8, 83, 97, 35, 99, 16, 7, 97, 57, 32, 16, 26, 26, 79, 33, 27, 98, 66},
    {88, 36, 68, 87, 57, 62, 20, 72, 3, 46, 33, 67, 46, 55, 12, 32, 63, 93, 53, 69},
    {4, 42, 16, 73, 38, 25, 39, 11, 24, 94, 72, 18, 8, 46, 29, 32, 40, 62, 76, 36},
    {20, 69, 36, 41, 72, 30, 23, 88, 34, 62, 99, 69, 82, 67, 59, 85, 74, 4, 36, 16},
    {20, 73, 35, 29, 78, 31, 90, 1, 74, 31, 49, 71, 48, 86, 81, 16, 23, 57, 5, 54},
    {1, 70, 54, 71, 83, 51, 54, 69, 16, 92, 33, 48, 61, 43, 52, 1, 89, 19, 67, 48}};
    
typedef unsigned int Coordinate; // Labels grid coordinates.

long long multiply_row(Coordinate x, Coordinate y);
long long multiply_column(Coordinate x, Coordinate y);
long long multiply_diagonals(Coordinate x, Coordinate y);
long long get_max(long long a, long long b, long long c);

/**
 * @brief Controls the main operation of the program.
 */
int main()
{
    long long max_product = 0;

    // Getting the max product of adjacent numbers in the grid.
    for (Coordinate x = 0; x < GRID_SIZE; x++) {
        for (Coordinate y = 0; y < GRID_SIZE; y++) {
            long long row = multiply_row(x, y);
            long long col = multiply_column(x, y);
            long long diagonal = multiply_diagonals(x, y);

            long long product = get_max(row, col, diagonal);
            max_product = std::max(product, max_product);
        }
    }

    std::cout << "Max product of 4 adjacents numbers: " << max_product << "\n";
    return 0;
}

/**
 * @brief Gets the horizontal product of the adjacent numbers starting from the
 * x and y coordinates. If the multiplication will go out of the grid, will
 * return 0.
 *
 * @param x Coordinate.
 * @param y Coordinate.
 * @return The product of the row.
 */
long long multiply_row(Coordinate x, Coordinate y)
{
    // Out of bounds!
    if (y + NUM_OF_ADJACENTS > GRID_SIZE) {
        return 0;
    }

    long long row_product = 1;

    for (int i = 0; i < NUM_OF_ADJACENTS; i++) {
        row_product *= NUMBER_GRID[x][y + i];
    }

    return row_product;
}

/**
 * @brief Gets the column product of the adjacent numbers from coordinates. If
 * the multiplication of the column will end out of the
 * grid, will return 0.
 *
 * @param x Coordinate
 * @param y Coordinate
 * @return The product of the column.
 */
long long multiply_column(Coordinate x, Coordinate y)
{
    // Out of bounds!
    if (x + NUM_OF_ADJACENTS > GRID_SIZE) {
        return 0;
    }

    long long column_product = 1;

    for (int i = 0; i < NUM_OF_ADJACENTS; i++) {
        column_product *= NUMBER_GRID[x + i][y];
    }

    return column_product;
}

/**
 * @brief Get the max diagonal product of the adjacent numbers from coordinates.
 *
 * @param x Coordinate
 * @param y Coordinate
 * @return The max product of the two diagonals. If no diagonals, will return 0.
 */
long long multiply_diagonals(Coordinate x, Coordinate y)
{
    // Out of bounds!
    if (x + NUM_OF_ADJACENTS > GRID_SIZE) {
        return 0;
    }

    long long main_diagonal = 1; // (\)
    if (y <= GRID_SIZE - NUM_OF_ADJACENTS) {
        for (int i = 0; i < NUM_OF_ADJACENTS; i++) {
            main_diagonal *= NUMBER_GRID[x + i][y + i]; // Down and right.
        }
    }

    long long anti_diagonal = 1; // (/)
    if (y >= NUM_OF_ADJACENTS) {
        for (int i = 0; i < NUM_OF_ADJACENTS; i++) {
            anti_diagonal *= NUMBER_GRID[x + i][y - i]; // Down and left.
        }
    }

    return std::max(main_diagonal, anti_diagonal);
}

/**
 * @param a Integer
 * @param b Integer
 * @param c Integer
 * @return Max of the three numbers.
 */
long long get_max(long long a, long long b, long long c)
{
    long long max = std::max(a, b);
    return std::max(max, c);
}