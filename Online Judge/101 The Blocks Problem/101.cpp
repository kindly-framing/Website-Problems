/**
 * @file 101.cpp
 * @author Steven Aquino
 * @brief This is the solution for Problem 101 from Online Judge.
 * @version 0.1
 * @date 2022-06-24
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "101.h"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

/**
 * @brief The main operation of the program.
 *
 */
int main()
{
    int amount_of_blocks;
    std::cin >> amount_of_blocks;
    BlockWorld online_judge(amount_of_blocks);

    std::string input;
    while (std::getline(std::cin, input)) {
        if (input == "quit") {
            break;
        }

        try {
            online_judge.execute(input);
        }
        catch (const std::invalid_argument &e) {
            std::cerr << e.what() << '\n';
        }
    }

    online_judge.display();

    return 0;
}

BlockWorld::BlockWorld(int blocks)
{
    // Initializes the map with the blocks
    for (int i = 1; i <= blocks; i++) {
        map.push_back(i);
    }
}

BlockWorld::~BlockWorld() {}

/**
 * @brief Puts block a onto block b after returning any blocks that are stacked
 * on top of blocks a and b to their initial positions.
 *
 * @param a Block to be moved.
 * @param b Block for a to be placed on top of.
 */
void BlockWorld::move_onto(int a, int b)
{
    std::pair<int, int> a_location = find_block(a);
    map[a_location.first].erase(a_location.second);

    // Find block b and place block a next to block b
    std::pair<int, int> b_location = find_block(b);
    map[b_location.first].insert(b_location.second + 1, a);
}

/**
 * @brief Puts block a onto the top of the stack containing block b, after
 * returning any blocks that are stacked on top of block a to their initial
 * positions.
 *
 * @param a Block to be moved
 * @param b Block for a to be placed on the stack of.
 */
void BlockWorld::move_over(int a, int b)
{
    std::pair<int, int> a_location = find_block(a);
    map[a_location.first].erase(a_location.second);

    // Find block b and place block a on top of the stack on block b
    std::pair<int, int> b_location = find_block(b);
    map[b_location.first].push_back(a);
}

/**
 * @brief Moves the pile of blocks consisting of block a, and any blocks
 * that are stacked above block a, onto block b. All blocks on top of block b
 * are moved to their initial positions prior to the pile taking place. The
 * blocks stacked above block a retain their order when moved.
 *
 * @param a Block to be moved
 * @param b Block for a to be placed onto
 */
void BlockWorld::pile_onto(int a, int b)
{
    std::vector<int> pile = grab_pile(a);

    // Find block b and place the entire stack next to block b
    std::pair<int, int> b_location = find_block(b);
    int row = b_location.first;
    int col = b_location.second;
    map[row].insert(col, std::begin(pile), std::end(pile));
}

/**
 * @brief Puts the pile of blocks consisting of block a, and any blocks that
 * are stacked above block a, onto the top of the stack containing block b. The
 * blocks stacked above block a retain their original order when moved.
 *
 * @param a Block to be moved
 * @param b Block for a to be placed on the stack of.
 */
void BlockWorld::pile_over(int a, int b)
{
    std::vector<int> pile = grab_pile(a);

    // Find block b and place the pile on top of the stack of block b
    std::pair<int, int> b_location = find_block(b);
    int row = b_location.first;
    int col = b_location.second;
    map[row].insert(std::end(map[row]), std::begin(pile), std::end(pile));
}

/**
 * @brief Validates the input and executes the corresponding command. Throws
 * invalid_argument if the command can't be executed.
 *
 * @param cmd Command to be executed
 */
void BlockWorld::execute(std::string cmd)
{
    if (is_command(cmd)) {
    }
    else {
        throw std::invalid_argument;
    }
}

bool BlockWorld::is_command(std::string cmd) {}

/**
 * @brief Outputs the map to the console in the indented format.
 *
 * Location: Blocks (spaced)
 *
 */
void BlockWorld::display()
{
    for (int i = 0; i < map.size(); i++) {
        std::cout << i << ": ";
        for (int j = 0; j < map[i].size(); j++) {
            std::cout << map[i][j] << " ";
        }
        std::cout << "\n";
    }
}

/**
 * @brief Finds the location for the block and return the coordinates for the
 * location.
 *
 * @param a The block to be found
 * @return std::pair<int, int> Coordinates for block a.
 */
std::pair<int, int> find_block(int a)
{
    std::pair<int, int> location;

    for (int i = 0; i < map.size(); i++) {
        for (int j = 0; j < map[i].size(); j++) {
            if (map[i][j] == a) {
                location = std::make_pair(i, j);
                goto found;
            }
        }
    }

found:
    return location;
}

/**
 * @brief Grabs pile on top of block a, including a. If there is no pile on top
 * of block a, returns just block a. Deletes the pile from original location.
 *
 * @param a Block a
 * @return std::vector<int> A pile of blocks.
 */
std::vector<int> grab_pile(int a)
{
    std::vector<int> pile;

    std::pair<int, int> location = find_block(a);
    int row = location.first;
    int col = location.second;

    // Not using for loop since erase() shifts the position back to column
    while (col + 1 != map[row].size()) {
        pile.push_back(map[row][col]);
        map[row].erase(col);
    }

    return pile;
}