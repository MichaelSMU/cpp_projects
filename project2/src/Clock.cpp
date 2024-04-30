#include <vector>

#include "../include/Clock.h"
#include "../include/util.h"

using namespace std;

vector<int> Clock::int_to_clock(long long num) {
 
    vector<int> arr(4);

    long long res = num; 
    arr[3] = int(res % 60); // find the second
    res /= 60; // round to minute
    arr[2] = int(res % 60); // find the minute
    res /= 60; // round to hour
    arr[1] = int(res % 24); // find the hour
    arr[0] = int(res / 24); // find the day

    return arr;
}

long long Clock::clock_to_int() const {
    long long out = 0;
    out = out + this->days;
    out = out * 24 + this->hours;
    out = out * 60 + this->minutes;
    out = out * 60 + this->seconds;
    return out;
}

void Clock::reset() { this->days = this->hours = this->minutes = this->seconds = 0; }
void Clock::set_days(int d) { this->days = d; }
void Clock::set_hours(int h) { this->hours = h; }
void Clock::set_minutes(int m) { this->minutes = m; }
void Clock::set_seconds(int s) { this->seconds = s; }

int Clock::get_days() const { return this->days; }
int Clock::get_hours() const { return this->hours; }

int Clock::get_minutes() const { return this->minutes; }
int Clock::get_seconds() const { return this->seconds; }

Clock Clock::operator+(const Clock& c) const { 

    vector<int> arr = int_to_clock(this->clock_to_int() + c.clock_to_int());
    return Clock(arr[0],arr[1],arr[2],arr[3]); 

}

Clock Clock::operator-(const Clock& c) const { 

    std::vector<int> arr = int_to_clock(this->clock_to_int() - c.clock_to_int());
    return Clock(arr[0],arr[1],arr[2],arr[3]); 

}

Clock Clock::operator-() const { return Clock(-this->days, -this->hours, -this->minutes, -this->seconds); }

bool Clock::operator<(const Clock& c) const { return (this->clock_to_int() < c.clock_to_int()); }
bool Clock::operator>(const Clock& c) const { return (this->clock_to_int() > c.clock_to_int()); }
bool Clock::operator<=(const Clock& c) const { return (this->clock_to_int() <= c.clock_to_int()); }
bool Clock::operator>=(const Clock& c) const { return (this->clock_to_int() >= c.clock_to_int()); }
bool Clock::operator==(const Clock& c) const { return (this->clock_to_int() == c.clock_to_int()); }

std::ostream& operator<<(std::ostream& os, const Clock& c) {
    os << (c.days < 0 || c.hours < 0 || c.minutes < 0 || c.seconds < 0 ? "-" : "") 
    << (abs(c.days) < 10 ? "0" : "") << abs(c.days) << ":"
    << (abs(c.hours) < 10 ? "0" : "") << abs(c.hours) << ":"
    << (abs(c.minutes) < 10 ? "0" : "") << abs(c.minutes) << ":"
    << (abs(c.seconds) < 10 ? "0" : "") << abs(c.seconds) << "\n";
    return os;
}