#pragma once
#include <string>
#include "Func.h"
#include "Point.h"
#include "Define.h"
using namespace std;

class Drone {
protected:
	string id;
	string type;
	float battery;
	float batteryCharge;
	float velocity;
	float currentX;
	float currentY;
	float destinationX;
	float destinationY;
	bool started;
	bool finished;

public:
	Drone();
	Drone(string id, string type, float battery, float velocity,
		float curX, float curY, float destX, float destY);

	void setId(string name);
	void setType(string name);
	void setBattery(float a);
	void setBatteryCharge(float a);
	void setVelocity(float a);
	void setCurrentX(float x);
	void setCurrentY(float y);
	void setDestinationX(float x);
	void setDestinationY(float y);
	void setFinished(bool x);
	void setStarted(bool x);

	string getId();
	string getType();
	float getBattery();
	float getBatteryCharge();
	float getVelocity();
	float getCurrentX();
	float getCurrentY();
	float getDestinationX();
	float getDestinationY();
	bool getFinished();
	bool getStarted();

	void move(Point* mas);
	virtual void enterInfo();
	virtual void info();
	virtual void arrived()=0;
};
