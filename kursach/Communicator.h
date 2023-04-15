#pragma once
#include"Drone.h"//velocity 2 //batteryCharge 1
class Communicator :public Drone {
	int communicationRange;
public:
	Communicator();
	Communicator(int comRange);
	void setCommunicationRange(int a);
	int getCommunicationRange();
	void info()override;
	void enterInfo()override;
    void arrived() override;
};