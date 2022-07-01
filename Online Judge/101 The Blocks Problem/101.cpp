/**
 * @file r101.cpp
 * @author Steven Aquino
 * @brief This is the solution for Problem 101 from Online Judge.
 * @version 0.1
 * @date 2022-06-29
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
#include <string>
#include <utility>
#include <vector>

using std::pair;
using std::string;
using std::vector;

class BlockWorld {
   private:
    vector<vector<int>> m_map;

   public:
    BlockWorld(int blocks);
    void execute(char *, int, char *, int);
    void move_onto(int, int);
    void move_over(int, int);
    void pile_onto(int, int);
    void pile_over(int, int);
    void display();
    bool valid_command(char *, int, char *, int);
    vector<int> grab_pile(int);
    pair<int, int> find_block(int);
    void remove_blocks_on_top(int);
};

int main()
{
    // The first line is the amount of blocks and it determines the block world
    int total_blocks;
    std::cin >> total_blocks;
    BlockWorld judge(total_blocks);

    // Every line after that is commands to be read until "quit" is reached
    char word1[5];
    char word2[5];
    int block_a;
    int block_b;
    while (scanf("%s %d %s %d", word1, &block_a, word2, &block_b) == 4) {
        if (judge.valid_command(word1, block_a, word2, block_b)) {
            judge.execute(word1, block_a, word2, block_b);
        }
    }

    // Displays the final arrangement of the block world
    judge.display();

    return 0;
}

BlockWorld::BlockWorld(int blocks)
{
    // Initializes the block world with the blocks
    vector<vector<int>> x(blocks, vector<int>(1));
    m_map = x;
    for (int i = 0; i < blocks; i++) {
        m_map[i][0] = i;
    }
}

void BlockWorld::execute(char *w1, int a, char *w2, int b)
{
    if (w1[0] == 'm' && w2[1] == 'n') {
        move_onto(a, b);
    }
    else if (w1[0] == 'm' && w2[1] == 'v') {
        move_over(a, b);
    }
    else if (w1[0] == 'p' && w2[1] == 'n') {
        pile_onto(a, b);
    }
    else {
        pile_over(a, b);
    }
}

void BlockWorld::move_onto(int a, int b)
{
    remove_blocks_on_top(a);

    pair<int, int> locate_a = find_block(a);
    int row = locate_a.first;
    m_map[row].pop_back();

    remove_blocks_on_top(b);

    pair<int, int> locate_b = find_block(b);
    row = locate_b.first;
    m_map[row].push_back(a);
}

void BlockWorld::move_over(int a, int b)
{
    remove_blocks_on_top(a);

    pair<int, int> locate_a = find_block(a);
    int row = locate_a.first;
    m_map[row].pop_back();

    pair<int, int> locate_b = find_block(b);
    row = locate_b.first;
    m_map[row].push_back(a);
}

void BlockWorld::pile_onto(int a, int b)
{
    vector<int> pile = grab_pile(a);

    remove_blocks_on_top(b);

    pair<int, int> locate_b = find_block(b);
    int row = locate_b.first;
    m_map[row].insert(m_map[row].end(), pile.begin(), pile.end());
}

void BlockWorld::pile_over(int a, int b)
{
    vector<int> pile = grab_pile(a);

    pair<int, int> locate_b = find_block(b);
    int row = locate_b.first;
    m_map[row].insert(m_map[row].end(), pile.begin(), pile.end());
}

void BlockWorld::remove_blocks_on_top(int a)
{
    pair<int, int> coordinates = find_block(a);
    int row = coordinates.first;
    int col = coordinates.second;

    while (col + 1 < m_map[row].size()) {
        int block = m_map[row].back();
        m_map[row].pop_back();
        m_map[block].push_back(block);
    }
}

bool BlockWorld::valid_command(char *w1, int a, char *w2, int b)
{
    // Problem states that an invalid command would be if the two blocks are the
    // same, and if the blocks are within the same stack when trying to do pile
    // command.
    bool same_block = (a == b);

    bool same_stack = false;
    if (w1[0] == 'p') {
        pair<int, int> locate_a = find_block(a);
        pair<int, int> locate_b = find_block(b);

        bool same_row = (locate_a.first == locate_b.first);
        same_stack = (same_row && locate_a.second < locate_b.second);
    }

    return !same_block && !same_stack;
}

pair<int, int> BlockWorld::find_block(int a)
{
    pair<int, int> coordinates;

    for (int i = 0; i < m_map.size(); i++) {
        for (int j = 0; j < m_map[i].size(); j++) {
            if (m_map[i][j] == a) {
                coordinates = std::make_pair(i, j);
                goto found;
            }
        }
    }

found:
    return coordinates;
}

vector<int> BlockWorld::grab_pile(int a)
{
    pair<int, int> coordinates = find_block(a);
    int row = coordinates.first;
    int col = coordinates.second;

    vector<int>::iterator start = m_map[row].begin() + col;
    vector<int> pile(start, m_map[row].end());
    m_map[row].erase(start, m_map[row].end());

    return pile;
}

void BlockWorld::display()
{
    // Row: Blocks (New line)
    for (int i = 0; i < m_map.size(); i++) {
        std::cout << i << ":";
        for (int j = 0; j < m_map[i].size(); j++) {
            std::cout << " " << m_map[i][j];
        }
        std::cout << "\n";
    }
}
