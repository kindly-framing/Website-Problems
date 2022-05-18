/**
 * The header file for the "Move Block Using Commands". Contains all of the
 * function declarations and struct to store the coordinates for the blocks
 * @file robot_arm.h
 * @author Steven Aquino
 */

#include <string>
#include <vector>

/* Creates coordinates for block locations */
struct Point {
    int row;
    int col;
};

/* Validators */

bool isValidPile(Point a, int b);
bool isValidCommand(std::string first, int a, std::string second, int b);

/* Get Functions */

Point getBlockLocation(int block);
std::vector<int> getPile(Point a);
std::vector<std::string> getSectionsOfCommand(std::string command);

/* User Input Functions */

void askForCommands();
void executeCommand(std::string cmd);
void printBlockMap();

/* Robot arm commands */

void moveBlockAOntoBlockB(int a, int b);
void moveBlockAOverBlockB(int a, int b);
void pileBlockAOntoBlockB(int a, int b);
void pileBlockAOverBlockB(int a, int b);
