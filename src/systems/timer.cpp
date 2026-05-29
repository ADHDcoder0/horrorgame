#include "timer.h"


timer::timer(double SetTimer){
    time = GetTime();
    triggerTime = time + SetTimer;
}

void timer::setTimer(double SetTimer){
    time = GetTime();
    triggerTime = time + SetTimer;
}

bool timer::isTimerTriggered(){
    double currentTime =  GetTime();
    if(currentTime < triggerTime){
        return false;
    }
    return true;
}   
