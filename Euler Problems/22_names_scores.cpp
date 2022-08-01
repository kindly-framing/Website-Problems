/**
 * @file 22_names_scores.cpp
 * @author Steven Aquino
 * @brief Using names.txt (right click and 'Save Link/Target As...'), a 46K text
 * file containing over five-thousand first names, begin by sorting it into
 * alphabetical order. Then working out the alphabetical value for each name,
 * multiply this value by its alphabetical position in the list to obtain a name
 * score.
 *
 * For example, when the list is sorted into alphabetical order, COLIN, which is
 * worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list. So, COLIN
 * would obtain a score of 938 × 53 = 49714.
 *
 * What is the total of all the name scores in the file?
 *
 * @version 0.1
 * @date 2022-07-31
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int alpha_value(const std::string &s);

int main()
{
    // get only the names from the file by removing quotes and commas
    std::vector<std::string> names;
    std::ifstream names_file("p022_names.txt");
    std::string name;
    while (std::getline(names_file, name, ',')) {
        name.erase(remove(name.begin(), name.end(), '\"'), name.end());
        names.push_back(name);
    }

    // sort the names
    std::sort(names.begin(), names.end());

    // for each name, get the name score
    int len = names.size();
    long long total = 0;
    for (int pos = 0; pos < len; pos++) {
        total += (pos + 1) * alpha_value(names[pos]);
    }
    std::cout << "Total of name scores: " << total << "\n";

    return 0;
}

int alpha_value(const std::string &s)
{
    int val = 0;
    for (char c : s) {
        val += int(c) - 64;
    }
    return val;
}