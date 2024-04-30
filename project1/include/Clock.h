#ifndef CLOCK_H
#define CLOCK_H

#include <string>
#include <iostream>

class Clock {

    private:
        int days, hours, minutes, seconds;

    public:

        Clock(): days(0), hours(0), minutes(0), seconds(0) {}
        Clock(int d, int h, int m, int s): days(d), hours(h), minutes(m), seconds(s) {}
        Clock(int m, int s): days(0), hours(0), minutes(m), seconds(s) {}
        Clock(std::string day);
        Clock(long long num);

        long long clock_to_int() const;

        void reset();
        void set_days(int d);
        void set_hours(int h);
        void set_minutes(int m);
        void set_seconds(int s);

        int get_days() const;
        int get_hours() const;
        int get_minutes() const;
        int get_seconds() const;

        Clock operator+(const Clock& c) const;
        Clock operator-(const Clock& c) const;
        Clock operator-() const;

        bool operator<(const Clock& c) const;
        bool operator>(const Clock& c) const;
        bool operator<=(const Clock& c) const;
        bool operator>=(const Clock& c) const;
        bool operator==(const Clock& c) const;

        friend std::ostream& operator<<(std::ostream& os, const Clock& clock);
};

#endif