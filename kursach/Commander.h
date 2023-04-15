#pragma once
#include "Navigator.h"//velocity 2 //batteryCharge 1	
class Commander :public Navigator {
	string commandAndControlType;
public:
	Commander();
	Commander(string CACT);
	void setCommandAndControlType(string CACT);
	string getCommandAndContorlType();
	void info()override;
	void enterInfo()override;
	void arrived() override;
	int giveDestinationForDrone(int b);
};
