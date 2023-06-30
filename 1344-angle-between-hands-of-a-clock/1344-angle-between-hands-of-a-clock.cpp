class Solution {
public:
    double angleClock(int hour, int minutes) {
        double minuteAngle = 6.0 * minutes;
        hour %= 12; // Reduce hour to range [0, 11]
        double hourAngle = 0.5 * (60 * hour + minutes); // Each hour mark is 30 degrees, and each minute mark is 0.5 degrees

        double angle = std::abs(hourAngle - minuteAngle);
        angle = std::min(angle, 360.0 - angle);
        return angle;
    }
};
