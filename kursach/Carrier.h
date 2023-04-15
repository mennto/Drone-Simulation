#pragma once
#include "Drone.h"//velocity 1 //batteryCharge 2
class Carrier :public Drone {
	string carryingCapacity;
public:
	Carrier();
	Carrier(string carryCap);
	void setCarryingCapacity(string a);
	string getCarryingCapacity();
	void info()override;
	void enterInfo()override;
	void arrived() override;
};

