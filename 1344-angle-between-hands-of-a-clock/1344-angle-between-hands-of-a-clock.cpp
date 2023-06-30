class Solution {
public:
    double angleClock(int hour, int minutes) {
        double a;
        if(hour == 12)
            a = ((30*minutes)/double(60));
        else
            a = (30 * hour) + ((30*minutes)/double(60));
        return min(abs(a-(6 * minutes)),360-abs(a-(6 * minutes)));
    }
};