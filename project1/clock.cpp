#include <iostream>
#include <ostream>
#include <string>

using namespace std;

string string_to_upper(string s) {
    for(int i=0; i<s.size(); i++)
        s[i] = toupper(s[i]);
    return s;
}

string string_to_lower(string s) {
    for(int i=0; i<s.size(); i++)
        s[i] = tolower(s[i]);
    return s;
}

class Clock {

private:
    int days, hours, minutes, seconds;

public:
    Clock(): days(0), hours(0), minutes(0), seconds(0) {}
    Clock(int d, int h, int m, int s): days(d), hours(h), minutes(m), seconds(s) {}
    Clock(int m, int s): days(0), hours(0), minutes(m), seconds(s) {}

    Clock(string day) {
        day = string_to_upper(day);
        string weekdays[7] = {"SUNDAY", "MONDAY", "TUESDAY", "WEDNESDAY", "THURSDAY", "FRIDAY", "SATURDAY"};

        for(int i=0; i<7; i++) {
            this->days = (weekdays[i]==day) ? (i+1) : 0;
            break;
        }

        this->hours = this->minutes = this->seconds = 0;
    }

    Clock(long long num) {
        int res = num; 
        this->seconds = res%60; // find the second
        res /= 60; // round to minute
        this->minutes = res%60; // find the minute
        res /= 60; // round to hour
        this->hours = res%24; // find the hour
        this->days = res/24; // find the day
    }

    long long clock_to_int() const {
        long out = 0;
        out = out + this->days;
        out = out*24 + this->hours;
        out = out*60 + this->minutes;
        out = out*60 + this->seconds;
        return out;
    }

    void reset() { this->days = this->hours = this->minutes = this->seconds = 0; }

    void set_days(int d) { this->days = d; }
    void set_hours(int h) { this->hours = h; }
    void set_minutes(int m) { this->minutes = m; }
    void set_seconds(int s) { this->seconds = s; }

    int get_days() const { return this->days; }
    int get_hours() const { return this->hours; }
    int get_minutes() const { return this->minutes; }
    int get_seconds() const { return this->seconds; }

    Clock operator+(const Clock& c) const { return Clock(this->clock_to_int()+c.clock_to_int());}
    Clock operator-(const Clock& c) const { return Clock(this->clock_to_int()-c.clock_to_int());}
    Clock operator-() const { return Clock(-this->days,-this->hours,-this->minutes,-this->seconds); }

    bool operator<(const Clock& c) const { return (this->clock_to_int()<c.clock_to_int()) ? true: false; }
    bool operator>(const Clock& c) const { return (this->clock_to_int()>c.clock_to_int()) ? true : false; }
    bool operator<=(const Clock& c) const { return (this->clock_to_int()<=c.clock_to_int()) ? true: false; }
    bool operator>=(const Clock& c) const { return (this->clock_to_int()>=c.clock_to_int()) ? true : false; }
    bool operator==(const Clock& c) const { return (this->clock_to_int()==c.clock_to_int()) ? true: false; }

    friend std::ostream& operator<<(std::ostream& os, const Clock& clock);
};

// Define the operator<< function outside of the Clock class
std::ostream& operator<<(std::ostream& os, const Clock& c) {
    os << (c.days < 0 || c.hours < 0 || c.minutes < 0 || c.seconds < 0 ? "-" : "") 
    << (abs(c.days) < 10 ? "0" : "") << abs(c.days) << ":"
    << (abs(c.hours) < 10 ? "0" : "") << abs(c.hours) << ":"
    << (abs(c.minutes) < 10 ? "0" : "") << abs(c.minutes) << ":"
    << (abs(c.seconds) < 10 ? "0" : "") << abs(c.seconds) << "\n";
    return os;
}

int main() {
    Clock a = Clock();
    Clock b = Clock(1,2,3,4);
    Clock c = Clock(2,3);
    Clock d = Clock(120001);
    Clock e = Clock("TUESDAY");

    std::cout<<a<<endl;
    std::cout<<b<<endl;
    std::cout<<c<<endl;
    std::cout<<d<<endl;
    std::cout<<e<<endl;

    std::cout<<a+b<<endl;
    std::cout<<a-b<<endl;
    std::cout<<-b<<endl;
    std::cout<<(a>b)<<endl;
    std::cout<<(a<b)<<endl;
    std::cout<<(a==b)<<endl;
    return 0;
}