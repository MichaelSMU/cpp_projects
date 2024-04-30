#include <iostream>
#include <string>

using namespace std;

string string_to_upper(string s) {

    for(int i=0; i<s.size(); i++) s[i] = std::toupper(s[i]);
    return s;
}

string string_to_lower(string s) {

    for(int i=0; i<s.size(); i++) s[i] = std::tolower(s[i]);
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
            int dint = 0;

            switch(day) {

                case "SUNDAY":
                    dint = 1;
                    break;
                case "MONDAY":
                    dint = 2;
                    break;
                case "TUESDAY":
                    dint = 3;
                    break;
                case "WEDNESDAY":
                    dint = 4;
                    break;
                case "THURSDAY":
                    dint = 5;
                    breaks;
                case "FRIDAY":
                    dint = 6;
                    break;
                case "SATURDAY":
                    dint = 7;
                    break;
            }

            Clock(dint,0,0,0);
        }

        Clock(long long num) {
            
            long long res = num; 

            int s = res%60; // find the second
            res /= 60; // round to minute
            int m = res%60; // find the minute
            res /= 60; // round to hour
            int h = res%24; // find the hour
            int d = res/24; // find the day

            Clock(d,h,m,s);

        }

        long long clock_to_int() {
            
            long long out = 0;

            out = out + this->days;
            out = out*24 + this->hours;
            out = out*60 + this->minutes;
            out = out*60 + this->second;

            return out;
        }

        void reset() {this->days, this->hours, this->minutes, this->seconds = 0,0,0,0;}

        void set_days(int d) { this->days = d; }
        void set_days(int h) { this->hours = h; }
        void set_days(int m) { this->minutes = m; }
        void set_days(int s) { this->seconds = s; }

        int get_days() const { return this->days; }
        int get_days() const { return this->hours; }
        int get_days() const { return this->minutes; }
        int get_days() const { return this->seconds; }
    
        Clock operator+(Clock const& c) { return Clock(this->clock_to_int()+c.clock_to_int());}
        Clock operator-(Clock const& c) { return Clock(this->clock_to_int()-c.clock_to_int());}
        Clock operator-() { return Clock(-this->days,-this->hours,-this->minutes,-this->seconds); }
 
        bool operator<(Clock const& c) const { return (this->clock_to_int()<c.clock_to_int()) ? true: false; }
        bool operator>(Clock const& c) const { return (this->clock_to_int()>c.clock_to_int()) ? true : false; }
        bool operator<=(Clock const& c) const { return (this->clock_to_int()<=c.clock_to_int()) ? true: false; }
        bool operator>=(Clock const& c) const { return (this->clock_to_int()>=c.clock_to_int()) ? true : false; }
        bool operator==(Clock const& c) const { return (this->clock_to_int()==c.clock_to_int()) ? true: false; }

        void operator<<() const {      
            (this->days<10) ? cout<<'0'<<this->days<<":" : cout<<this->days<<":";
            (this->hours<10) cout<<'0'<<this->hours<<":" : cout<<this->hours<<":";
            (this->minutes<10) cout<<'0'<<this->minutes<<":" : cout<<this->minutes<<":";
            (this->seconds<10) cout<<'0'<<this->seconds<<"\n" : cout<<this->seconds<<"\n";
        }

        ~Clock();
    };

    int main() {
        
        Clock a = Clock();
        cout<<a;
    }