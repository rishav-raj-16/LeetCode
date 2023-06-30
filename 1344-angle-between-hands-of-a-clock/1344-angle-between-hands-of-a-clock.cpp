class Solution {
public:
    double angleClock(int hour, int minutes) {
        double a , b;
        if(hour == 12)
            a = ((30*minutes)/double(60));
        else
            a = (30 * hour) + ((30*minutes)/double(60));
        
        b = 6 * minutes;
        return min(abs(a-b),360-abs(a-b));
    }
};