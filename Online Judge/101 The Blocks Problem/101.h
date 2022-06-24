/**
 * The header file for the "Move Block Using Commands". Contains all of the
 * function declarations and struct to store the coordinates for the blocks
 * @file robot_arm.h
 * @author Steven Aquino
 */
#include <string>
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

    // Display
    void display();

    // Helpers
    std::pair<int, int> find_block(int a);
    std::vector<int> grab_pile(int a);
};

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
    // Find block a
    // Remove from location
    // Find block b
    // Place block a next to block b (aka insert)
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
    // Find block a
    // Remove from location
    // Find block b
    // Place block a on top of the stack on block b (aka last one)
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
    // Find block a
    // Grab the pile on top of block a
    // Remove blocks from location
    // Find block b
    // Place the entire stack next to block b (aka insert)
}

/**
 * @brief Puts the pile of blocks consisting of block a, and any blocks that are
 * stacked above block a, onto the top of the stack containing block b. The
 * blocks stacked above block a retain their original order when moved.
 *
 * @param a Block to be moved
 * @param b Block for a to be placed on the stack of.
 */
void BlockWorld::pile_over(int a, int b)
{
    // Find block a
    // Grab the pile on top of block b
    // Remove blocks from location
    // Find block b
    // Place the pile on top of the stack of block b (aka last one)
}

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
        for (int i = 0; i < map[i].size(); i++) {
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
std::pair<int, int> find_block(int a) {}

/**
 * @brief Grabs pile on top of block a, including a. If there is no pile on top
 * of block a, returns just block a.
 *
 * @param a Block a
 * @return std::vector<int> A pile of blocks.
 */
std::vector<int> grab_pile(int a) {}