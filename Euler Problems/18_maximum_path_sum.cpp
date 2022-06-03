/**
 * @file 18_maximum_path_sum.cpp
 * @author Steven Aquino
 * @brief By starting at the top of the triangle below and moving to adjacent
 * numbers on the row below, the maximum total from top to bottom is 23.
 *
 *    3
 *   7 4
 *  2 4 6
 * 8 5 9 3
 *
 * 3+7+4+9 = 23
 * @version 0.1
 * @date 2022-05-31
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <algorithm>
#include <iostream>
#include <vector>

std::vector<std::vector<int>> smallTriangle = {
    {3}, {7, 4}, {2, 4, 6}, {8, 5, 9, 3}};

std::vector<std::vector<int>> bigTriangle = {
    {75},
    {95, 64},
    {17, 47, 82},
    {18, 35, 87, 10},
    {20, 4, 82, 47, 65},
    {19, 1, 23, 75, 3, 34},
    {88, 2, 77, 73, 7, 63, 67},
    {99, 65, 4, 28, 6, 16, 70, 92},
    {41, 41, 26, 56, 83, 40, 80, 70, 33},
    {41, 48, 72, 33, 47, 32, 37, 16, 94, 29},
    {53, 71, 44, 65, 25, 43, 91, 52, 97, 51, 14},
    {70, 11, 33, 28, 77, 73, 17, 78, 39, 68, 17, 57},
    {91, 71, 52, 38, 17, 14, 91, 43, 58, 50, 27, 29, 48},
    {63, 66, 4, 68, 89, 53, 67, 30, 73, 16, 69, 87, 40, 31},
    {4, 62, 98, 27, 23, 9, 70, 98, 73, 93, 38, 53, 60, 4, 23}};

/**
 * @brief Helper function to display a vector on console.
 *
 * @param arr The vector to print.
 */
void display(std::vector<int> arr) {
    for (int n : arr) {
        std::cout << n << " ";
    }
    std::cout << "\n";
}

/**
 * @brief Finds the maximum path sum of a triangle number set.
 *
 * @param tri The triangle with numbers.
 * @return int The maximum path sum of a triangle number set.
 */
int maxPathSum(std::vector<std::vector<int>> tri) {
    // The algorithm for this problem is to find the maximum sum that you can
    // make from each row to the next row, such that c is the result in the next
    // row and (a,b) are the numbers above it and c must be the max sum between
    // (a+c) or (b+c), until you make it to the bottom of the triangle where all
    // you would have to do is return the maximum sum.

    // Adding top number to next row since there is only one path.
    std::vector<int> sums;
    sums.push_back(tri[0][0] + tri[1][0]);
    sums.push_back(tri[0][0] + tri[1][1]);

    for (int row = 2; row < tri.size(); row++) {
        display(sums);

        std::vector<int> numsInRow = tri[row];
        for (int i = 0; i < numsInRow.size(); i++) {
            // First and last number in a row only have one sum path.
            // Anything else can have two different paths.
            if (i == 0) {
                numsInRow[0] += sums[0];
            } else if (sums.size() == i) {
                numsInRow[i] += sums.back();
            } else {
                int ac = sums[i - 1] + numsInRow[i];
                int bc = sums[i] + numsInRow[i];
                numsInRow[i] = std::max(ac, bc);
            }
        }

        sums = numsInRow; // Summed row is needed for the next row.
    }
    display(sums);

    // The algorithm results in sums having
    return *std::max_element(sums.begin(), sums.end());
}

int main() {
    std::cout << "Maximum path of small triangle is: "
              << maxPathSum(smallTriangle) << "\n\n";
    std::cout << "Maximum path of big triangle is : " << maxPathSum(bigTriangle)
              << "\n";
    return 0;
}