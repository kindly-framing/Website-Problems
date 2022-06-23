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
    int day_index;

  public:
    Calendar(int date_, int month_, int year_, std::string day_);
    ~Calendar();

    int get_date();
    int get_month();
    int get_year();
    std::string get_day();

    bool is_leap_year();

    void next_month();
    void next_day();
    void next_year();
    void display_date();
};

int main()
{
    Calendar euler(1, 1, 1901, "Tuesday");

    int current_day = euler.get_date();
    int current_month = euler.get_month();
    int current_year = euler.get_year();

    int first_sundays = 0;
    while (current_year != 2001) {
        if (current_day == 1 && euler.get_day() == "Sunday") {
            euler.display_date();
            first_sundays++;
        }

        euler.next_day();
        current_day = euler.get_date();
        current_month = euler.get_month();
        current_year = euler.get_year();
    }

    std::cout << "The amount of Sundays on the first are " << first_sundays
              << "\n";

    return 0;
}

Calendar::Calendar(int date_, int month_, int year_, std::string day_)
{
    date = date_;
    month = month_;
    year = year_;

    for (int i = 0; i < 7; i++) {
        if (days[i] == day_) {
            day_index = i;
            break;
        }
    }
}

Calendar::~Calendar() {}

int Calendar::get_date() { return date; }
int Calendar::get_month() { return month; }
int Calendar::get_year() { return year; }
std::string Calendar::get_day() { return days[day_index]; }

bool Calendar::is_leap_year()
{
    return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}

void Calendar::next_year()
{
    month = 1;
    year++;
}

void Calendar::next_month()
{
    date = 1;
    month++;

    if (month == 13) {
        next_year();
    }
}

void Calendar::next_day()
{
    date++;
    day_index++;

    if (day_index == 7) {
        day_index = 0;
    }

    // Thirty days has September, April, June and November.
    if (month == 9 || month == 4 || month == 6 || month == 11) {
        if (date == 31) {
            next_month();
        }
    }
    // Saving February alone, which has twenty-eight, rain or shine. And on leap
    // years, twenty-nine.
    else if (month == 2) {
        if (!is_leap_year() && date == 29) {
            next_month();
        }
        if (is_leap_year() && date == 30) {
            next_month();
        }
    }
    // All the rest have thirty-one
    else {
        if (date == 32) {
            next_month();
        }
    }
}

void Calendar::display_date()
{
    std::cout << days[day_index] << " " << month << ", " << date << ", " << year
              << "\n";
}