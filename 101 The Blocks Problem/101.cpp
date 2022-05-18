/**
 * The main file for the "Move Blocks Using Commands" project.
 * @file main.cpp
 * @author Steven Aquino
 */

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "101.h"

int g_num_of_blocks;
std::vector<std::vector<int>> g_block_map;

// Controls the operation of the program
int main(int argc, char const *argv[])
{
    std::cout << "\nEnter how many blocks you would like to generate: ";
    std::cin >> g_num_of_blocks;

    std::vector<std::vector<int>> block_map(g_num_of_blocks);
    for (int i = 0; i < block_map.size(); i++)
    {
        block_map[i].push_back(i);
    }
    g_block_map = block_map;

    askForCommands();
    printBlockMap();
    return 0;
}

/**
 * Asks the user for commands and executes command if it is valid
 */
void askForCommands()
{
    std::cout << "\nEnter commands now... ";
    std::cout << "(To print final positions of blocks, type \"quit\")\n";
    std::cin.ignore();

    std::string command;
    while (getline(std::cin, command))
    {
        if (command == "quit")
            break;

        executeCommand(command);
        system("clear");
        printBlockMap();
    }
}

/**
 * Checks if the command entered by the user is in a valid command form
 * ex. "move x onto y"
 * @param first The first word in the command (move or pile)
 * @param a A block number
 * @param second The second word in the command (over or onto)
 * @param b A block number
 * @return True or False if the command is valid
 */
bool isValidCommand(std::string first, int a, std::string second, int b)
{
    if (first != "move" && first != "pile")
        return false;
    if (second != "over" && second != "onto")
        return false;

    if (a < 0 || a > g_num_of_blocks)
        return false;
    if (b < 0 || b > g_num_of_blocks)
        return false;
    if (a == b)
        return false;

    return true;
}

/**
 * Moves blocks depending on the command from the user
 * @param cmd A command for the robot arm to execute
 */
void executeCommand(std::string cmd)
{
    std::vector<std::string> command = getSectionsOfCommand(cmd);

    std::string first_cmd = command[0];
    std::string second_cmd = command[2];
    int block_a = stoi(command[1]);
    int block_b = stoi(command[3]);

    if (isValidCommand(first_cmd, block_a, second_cmd, block_b))
    {
        if (first_cmd == "move" && second_cmd == "onto")
        {
            moveBlockAOntoBlockB(block_a, block_b);
        }
        else if (first_cmd == "move" && second_cmd == "over")
        {
            moveBlockAOverBlockB(block_a, block_b);
        }
        else if (first_cmd == "pile" && second_cmd == "onto")
        {
            pileBlockAOntoBlockB(block_a, block_b);
        }
        else
        {
            pileBlockAOverBlockB(block_a, block_b);
        }
    }
    else
    {
        std::cout << "Not a valid command! Try again.\n";
    }
}

/**
 * Divides the command into sections and returns a vector containing each part
 * of the command.
 * @param command A command to divide by spaces in between
 * @return A vector containing each word
 */
std::vector<std::string> getSectionsOfCommand(std::string command)
{
    std::vector<std::string> spilt_command;
    std::istringstream iss(command);

    do
    {
        std::string x;
        iss >> x;
        spilt_command.push_back(x);
    } while (iss);

    return spilt_command;
}

/**
 * An invalid pile is when the pile starting at block a contains block b
 * @param a A Point containing the coordinates for block a
 * @param b An integer value representing a block
 * @return True or False if it is a valid pile
 */
bool isValidPile(Point a, int b)
{
    for (int i = a.col; i < g_block_map[a.row].size(); i++)
    {
        if (g_block_map[a.row][i] == b)
        {
            return false;
        }
    }
    return true;
}

/**
 * Prints the block map to the user
 * Format (0: 0)
 */
void printBlockMap()
{
    int row = 0;
    for (auto x : g_block_map)
    {
        std::cout << row << ": ";

        for (auto y : x)
        {
            std::cout << y << ' ';
        }
        std::cout << '\n';

        row++;
    }
}

/**
 * Moves block a next to block b
 * @param a An integer representing a block number
 * @param b An integer representing a block number
 */
void moveBlockAOntoBlockB(int a, int b)
{
    // Erases a and moves a to b
    Point a_p = getBlockLocation(a);
    g_block_map[a_p.row].erase(g_block_map[a_p.row].begin() + a_p.col);

    Point b_p = getBlockLocation(b);
    g_block_map[b_p.row].insert(g_block_map[b_p.row].begin() + b_p.col + 1, a);
}

/**
 * Moves block a onto the top of the stack with block b
 * @param a An integer representing the block
 * @param b An integer representing the block
 */
void moveBlockAOverBlockB(int a, int b)
{
    // Erases a and moves it to the end of the row containing b
    Point a_p = getBlockLocation(a);
    g_block_map[a_p.row].erase(g_block_map[a_p.row].begin() + a_p.col);

    Point b_p = getBlockLocation(b);
    g_block_map[b_p.row].push_back(a);
}

/**
 * Moves the blocks on top of a (including a) next to block b
 * @param a An integer representing a block
 * @param b An integer representing a block
 */
void pileBlockAOntoBlockB(int a, int b)
{
    Point a_p = getBlockLocation(a);

    if (isValidPile(a_p, b))
    {
        std::vector<int> pile = getPile(a_p);

        Point b_p = getBlockLocation(b);

        int n = b_p.col + 1; // Inserts blocks in correct place each iteration

        for (int b : pile)
        {
            g_block_map[b_p.row].insert(g_block_map[b_p.row].begin() + n, b);
            n++;
        }
    }
    else
    {
        std::cout << "Not a valid pile command! " << b << " is within pile!\n";
    }
}

/**
 * Moves the blocks on top of a (including a) onto the stack containing block b
 * @param a An integer representing a block
 * @param b An integer representing a block
 */
void pileBlockAOverBlockB(int a, int b)
{
    Point a_p = getBlockLocation(a);

    if (isValidPile(a_p, b))
    {
        std::vector<int> pile = getPile(a_p);

        Point b_p = getBlockLocation(b);
        for (int b : pile)
        {
            g_block_map[b_p.row].push_back(b);
        }
    }
    else
    {
        std::cout << "Not a valid pile command! " << b << " is within pile!\n";
    }
}

/**
 * Gets the blocks starting from a to the top of the stack
 * @param a Point for block a
 * @return A vector containing the pile from a
 */
std::vector<int> getPile(Point a)
{
    std::vector<int> pile;

    // As elements are removed, the size decreases to position where block a
    // used to be
    while (g_block_map[a.row].size() != a.col)
    {
        pile.push_back(g_block_map[a.row][a.col]);
        g_block_map[a.row].erase(g_block_map[a.row].begin() + a.col);
    }

    return pile;
}

/**
 * Grabs the coordinates of the block in the block map
 * @param block A block number
 * @return A Point containing the location of the block
 */
Point getBlockLocation(int block)
{
    Point block_coordinates;

    for (int i = 0; i < g_block_map.size(); i++)
    {
        for (int j = 0; j < g_block_map[i].size(); j++)
        {
            if (g_block_map[i][j] == block)
            {
                block_coordinates.row = i;
                block_coordinates.col = j;
            }
        }
    }
    return block_coordinates;
}
