/**
 * @file Calendar.cpp
 * @author Steven Aquino
 * @brief You are given the following information, but you may prefer to do
 * some research for yourself.
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
#include <vector>

class Calendar {
private:
  std::string days[7] = {"Sunday",   "Monday", "Tuesday", "Wednesday",
                         "Thursday", "Friday", "Saturday"};
  int date;
  int month;
  int year;
  std::string day;

public:
  Calendar(int date_, int month_, int year_, std::string day_);
  ~Calendar();

  int date();
  int month();
  int year();
  std::string day();

  void next_day();
};

int main() {
  Calendar euler(1, 1, 1900, "Monday");

  int current_day = euler.date();
  int current_month = euler.month();
  int current_year = euler.year();

  int first_sundays = 0;
  while (current_day != 1 && current_month != 1 && current_year != 2001) {
    if (current_day == 1 && euler.day() == "Sunday") {
      first_sundays++;
    }

    euler.next_day();
    current_day = euler.date();
    current_month = euler.month();
    current_year = euler.year();
  }

  std::cout << " The amount of Sundays on the first are " << first_sundays
            << "\n";

  return 0;
}

Calendar::Calendar(int date_, int month_, int year_, std::string day_) {
  date = date_;
  month = month_;
  year = year_;
  day = day_;
}

Calendar::~Calendar() {}

int date() { return date; }
int month() { return month; }
int year() { return year; }
std::string day() { return day; }