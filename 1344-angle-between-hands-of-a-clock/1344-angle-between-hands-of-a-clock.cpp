class Solution {
public:
    double angleClock(int hour, int minutes) {
        double minute_angle=minutes*6.0;
        double hour_angle=(hour%12)*30.0 +(minutes*0.5);
        double angle=abs(hour_angle-minute_angle);
        if(angle>180.0){
            angle=360.0-angle;
        }
        return angle;
    }
};