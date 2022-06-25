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

class BlockWorld {
  private:
    std::vector<std::vector<int>> map; // Block world for the problem

  public:
    // Constructors
    BlockWorld();
    ~BlockWorld();

    // Commands
    void move_onto(int a, int b);
    void move_over(int a, int b);
    void pile_onto(int a, int b);
    void pile_over(int a, int b);
    void execute(std::string cmd);
    bool is_command(std::string cmd);

    // Display
    void display();

    // Helpers
    std::pair<int, int> find_block(int a);
    std::vector<int> grab_pile(int a);
};

#endif