#include <raylib.h>

class timer{
private:
    double time;
    double triggerTime;

public:
    timer(double SetTimer);
    void setTimer(double SetTimer);
    bool isTimerTriggered();
};