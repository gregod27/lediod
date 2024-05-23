#include "diod.h"
#include <cmath>  

LedDiod::LedDiod() : brightness(0), color("red") {}  

void LedDiod::setColor(const std::string & color) {
    if (color == "red" || color == "green" || color == "blue") {
        this->color = color;
    } else {
        this->color = "red"; 
    }
}

void LedDiod::setBrightness(int br) {
    if (br >= 0 && br <= 100) {
        brightness = br;
    } else {
        brightness = 0;  
    }
}

void LedDiod::showColor() const {
    std::cout << "led color is " << color << std::endl;
}

void LedDiod::showBrightness() const {
    std::cout << "led brightness is " << brightness << std::endl;
}

double LedDiod::calcDiodCurrent(double voltage) const {
    const double reverseSaturationCurrent = 10e-6;  
    const double thermalVoltage = 0.026;  
    

    double current = reverseSaturationCurrent * (exp(voltage / thermalVoltage) - 1);
    return current;
}
