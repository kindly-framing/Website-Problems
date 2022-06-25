/**
 * The header file for the "Move Block Using Commands". Contains all of the
 * function declarations and struct to store the coordinates for the blocks
 * @file robot_arm.h
 * @author Steven Aquino
 */
#ifndef _101_
#define _101_

#include <sstream>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

class BlockWorld
{
  private:
    std::vector<std::vector<int>> m_map; // Block world for the problem
    int m_total_blocks;                  // The maximum block number
    std::vector<std::string> m_command;  // Stores command for testing

  public:
    BlockWorld(int blocks);
    ~BlockWorld();

    /**
     * @brief Puts block a onto block b after returning any blocks that are
     * stacked on top of blocks a and b to their initial positions.
     *
     * @param a Block to be moved.
     * @param b Block for a to be placed on top of.
     */
    void move_onto(int a, int b);

    /**
     * @brief Puts block a onto the top of the stack containing block b, after
     * returning any blocks that are stacked on top of block a to their initial
     * positions.
     *
     * @param a Block to be moved
     * @param b Block for a to be placed on the stack of.
     */
    void move_over(int a, int b);

    /**
     * @brief Moves the pile of blocks consisting of block a, and any blocks
     * that are stacked above block a, onto block b. All blocks on top of block
     * b are moved to their initial positions prior to the pile taking place.
     * The blocks stacked above block a retain their order when moved.
     *
     * @param a Block to be moved
     * @param b Block for a to be placed onto
     */
    void pile_onto(int a, int b);

    /**
     * @brief Puts the pile of blocks consisting of block a, and any blocks that
     * are stacked above block a, onto the top of the stack containing block b.
     * The blocks stacked above block a retain their original order when moved.
     *
     * @param a Block to be moved
     * @param b Block for a to be placed on the stack of.
     */
    void pile_over(int a, int b);

    /**
     * @brief Executes the corresponding command. Throws invalid_argument if the
     * command can't be executed.
     *
     * @param cmd Command to be executed
     */
    void execute(std::string cmd);

    /**
     * @brief Validates given input to ensure it can be executed on the block
     * world.
     *
     * @param cmd An input to test
     * @return true The command is a valid move.
     * @return false The command can't be done.
     */
    bool valid_command(std::string cmd);

    /**
     * @brief Outputs the map to the console in the indented format.
     *
     * Location: Blocks (spaced)
     *
     */
    void display();

    /**
     * @brief Finds the location for the block and return the coordinates for
     * the location.
     *
     * @param a The block to be found
     * @return std::pair<int, int> Coordinates for block a.
     */
    std::pair<int, int> find_block(int a);

    /**
     * @brief Grabs pile on top of block a, including a. If there is no pile on
     * top of block a, returns just block a. Deletes the pile from original
     * location.
     *
     * @param a Block a
     * @return std::vector<int> A pile of blocks.
     */
    std::vector<int> grab_pile(int a);
};

#endif