#pragma once
#include "Drone.h" //velocity 2 //batteryCharge 1
class Navigator :public Drone {
protected:
	string gpsType;
public:
	Navigator();
	Navigator(string gps);
	void setGpsType(string a);
	string getGpsType();
	void info()override;
	void enterInfo()override;
};