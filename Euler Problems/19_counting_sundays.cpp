/**
 * @file Calendar.cpp
 * @author Steven Aquino
 * @brief You are given the following information, but you may prefer to do some
 * research for yourself.
 *
 * 1 Jan 1900 was a Monday.
 * Thirty days has September, April, June and November.
 * All the rest have thirty-one,
 * Saving February alone,
 * Which has twenty-eight, rain or shine.
 * And on leap years, twenty-nine.
 * A leap year occurs on any year evenly divisible by 4, but not on a century
 * unless it is divisible by 400.
 *
 * How many Sundays fell on the first of the month during the twentieth century
 * (1 Jan 1901 to 31 Dec 2000)?
 * @version 0.1
 * @date 2022-06-10
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
#include <string>

class Calendar {
  private:
    int date;        // The number of the date
    int month;       // Numerical value of the month
    int year;        // The year
    std::string day; // The label for the date

  public:
    Calendar(int date_, int month_, int year_, std::string day_);
    ~Calendar();
    void nextDay(); // TODO Implement function
};

int main() {
    Calendar euler(1, 1, 1900, "Monday");

    // Go through the dates until 31 Dec 2000 counting Sundays
    int sundays = 0;
    // Print the number of Sundays
    std::cout << sundays << "\n";

    return 0;
}

Calendar::Calendar(int date_, int month_, int year_, std::string day_) {
    date = date_;
    month = month_;
    year = year_;
    day = day_;
}

Calendar::~Calendar() {}