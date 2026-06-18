class Solution {
    public:
        double angleClock(int hour, int minutes) {
            hour = hour == 12 ? 0 : hour;
            double hourangle = hour * 30 + minutes/2.0, minuteangle = minutes * 6;
            return min(abs(hourangle - minuteangle), 360-abs(hourangle - minuteangle));
        }
    };