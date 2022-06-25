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
    std::cin.ignore(); // Prevents getline() to get leftover character

    std::string input;
    while (std::getline(std::cin, input)) {
        if (input == "quit") {
            break;
        }

        try {
            online_judge.execute(input);
        } catch (const std::invalid_argument &e) {
            std::cerr << e.what() << "\n";
        }
    }

    online_judge.display();

    return 0;
}

BlockWorld::BlockWorld(int blocks)
{

    std::vector<std::vector<int>> vec(blocks, std::vector<int>(1));
    m_map = vec;

    // Initializes the map with the blocks
    for (int i = 0; i < blocks; i++) {
        m_map[i][0] = i;
    }

    m_total_blocks = blocks;
}

BlockWorld::~BlockWorld() {}

void BlockWorld::move_onto(int a, int b)
{
    int row; // Row of blocks
    int col; // Column of blocks

    // Moving block a by erasing from original location
    std::pair<int, int> a_location = find_block(a);
    row = a_location.first;
    col = a_location.second;
    m_map[row].erase(std::begin(m_map[row]) + col);

    // Placing block a next to block b by inserting after
    std::pair<int, int> b_location = find_block(b);
    row = b_location.first;
    col = b_location.second;
    m_map[row].insert(std::begin(m_map[row]) + col + 1, a);
}

void BlockWorld::move_over(int a, int b)
{
    int row;
    int col;

    std::pair<int, int> a_location = find_block(a);
    row = a_location.first;
    col = a_location.second;
    m_map[row].erase(std::begin(m_map[row]) + col);

    // Find block b and place block a on top of the stack on block b
    std::pair<int, int> b_location = find_block(b);
    row = b_location.first;
    col = b_location.second;
    m_map[b_location.first].push_back(a);
}

void BlockWorld::pile_onto(int a, int b)
{
    std::vector<int> pile = grab_pile(a);

    // Find block b and place the entire stack next to block b
    std::pair<int, int> b_location = find_block(b);
    int row = b_location.first;
    int col = b_location.second;
    m_map[row].insert(std::begin(m_map[row]) + col, std::begin(pile),
                      std::end(pile));
}

void BlockWorld::pile_over(int a, int b)
{
    std::vector<int> pile = grab_pile(a);

    // Find block b and place the pile on top of the stack of block b
    std::pair<int, int> b_location = find_block(b);
    int row = b_location.first;
    int col = b_location.second;
    m_map[row].insert(std::end(m_map[row]), std::begin(pile), std::end(pile));
}

void BlockWorld::execute(std::string cmd)
{
    if (valid_command(cmd)) {
        std::string word1 = m_command[0];
        std::string word2 = m_command[2];
        int block_a = stoi(m_command[1]);
        int block_b = stoi(m_command[3]);

        if (word1 == "move" && word2 == "onto") {
            move_onto(block_a, block_b);
        } else if (word1 == "move" && word2 == "over") {
            move_over(block_a, block_b);
        } else if (word1 == "pile" && word2 == "onto") {
            pile_onto(block_a, block_b);
        } else {
            pile_over(block_a, block_b);
        }
        m_command.clear();
    } else {
        m_command.clear();
        throw std::invalid_argument("Can't execute");
    }
}

bool BlockWorld::valid_command(std::string cmd)
{
    // Seperating command word by word to test
    std::istringstream iss(cmd);
    std::string word;
    while (iss >> word) {
        m_command.push_back(word);
        // Valid command is only 4 parts
        if (m_command.size() > 4) {
            m_command.clear();
            return false;
        }
    }

    // Second and final part should be block numbers
    int block_a;
    int block_b;
    try {
        block_a = stoi(m_command[1]);
        block_b = stoi(m_command[3]);
    } catch (const std::invalid_argument &e) {
        m_command.clear();
        return false;
    }

    bool valid_nums = ((block_a >= 0 && block_a < m_total_blocks) &&
                       (block_b >= 0 && block_b < m_total_blocks));
    bool valid_words = ((m_command[0] == "move" || m_command[0] == "pile") &&
                        (m_command[2] == "onto" || m_command[2] == "over"));
    return valid_nums && valid_words;
}

void BlockWorld::display()
{
    for (int i = 0; i < m_map.size(); i++) {
        std::cout << i << ": ";
        for (int j = 0; j < m_map[i].size(); j++) {
            std::cout << m_map[i][j] << " ";
        }
        std::cout << "\n";
    }
}

std::vector<int> BlockWorld::grab_pile(int a)
{
    std::vector<int> pile;

    std::pair<int, int> location = find_block(a);
    int row = location.first;
    int col = location.second;

    // Not using for loop since erase() shifts the position back to column
    while (col != m_map[row].size()) {
        pile.push_back(m_map[row][col]);
        m_map[row].erase(std::begin(m_map[row]) + col);
    }

    return pile;
}

std::pair<int, int> BlockWorld::find_block(int a)
{
    std::pair<int, int> location;

    for (int i = 0; i < m_map.size(); i++) {
        for (int j = 0; j < m_map[i].size(); j++) {
            if (m_map[i][j] == a) {
                location = std::make_pair(i, j);
                goto found;
            }
        }
    }

found:
    return location;
}