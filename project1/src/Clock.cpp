#include "../include/Clock.h"
#include "../include/util.h"

Clock::Clock(std::string day) {

    day = string_to_upper(day);
    std::string weekdays[7] = {"SUNDAY", "MONDAY", "TUESDAY", "WEDNESDAY", "THURSDAY", "FRIDAY", "SATURDAY"};

    for(int i = 0; i < 7; i++) {
        if (weekdays[i] == day) {

            cout<<weekday[i]<<endl;
            this->days = (i + 1);
            break;
        }
    }

    this->hours = this->minutes = this->seconds = 0;
}

Clock::Clock(long long num) {
    long long res = num; 
    this->seconds = res % 60; // find the second
    res /= 60; // round to minute
    this->minutes = res % 60; // find the minute
    res /= 60; // round to hour
    this->hours = res % 24; // find the hour
    this->days = res / 24; // find the day
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

Clock Clock::operator+(const Clock& c) const { return Clock(this->clock_to_int() + c.clock_to_int()); }
Clock Clock::operator-(const Clock& c) const { return Clock(this->clock_to_int() - c.clock_to_int()); }
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