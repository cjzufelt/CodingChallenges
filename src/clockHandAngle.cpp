#include <iostream>

using namespace std;

int calcAngle(double& hourHand, double& minuteHand) {
    if (hourHand > 12 || hourHand == 0) {
        hourHand = 12;
    }
    if (minuteHand > 60 || minuteHand == 0) {
        minuteHand = 60;
    }

    int hourHandAngle = hourHand * (360 / 12);
    int minuteHandAngle = minuteHand * (360 / 60);

    if ((hourHandAngle - minuteHandAngle) > (minuteHandAngle - hourHandAngle)) {
        return hourHandAngle - minuteHandAngle;
    }
    
    return minuteHandAngle - hourHandAngle;
}

int main(int argc, char* argv[]) {
    cout << "What is the hour hand at?" << endl;
    double hourHand = 0.0;
    cin >> hourHand;
    cout << endl;

    cout << "What is the minute hand at?" << endl;
    double minuteHand = 0.0;
    cin >> minuteHand;
    cout << endl;

    int angle = calcAngle(hourHand, minuteHand);

    cout << "The angle is: " << angle << endl;

    return 0;
}
