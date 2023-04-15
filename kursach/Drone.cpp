#include "Drone.h"

Drone::Drone() {
}

Drone::Drone(string id, string type, float battery, float velocity,
	float curX, float curY, float destX, float destY) {
	this->id = id;
	this->type = type;
	batteryCharge = battery;
	this->velocity = velocity;
	currentX = curX;
	currentY = curY;
	destinationX = destX;
	destinationY = destY;
}
void Drone::setId(string name) {
	id = name;
}

void Drone::setType(string name) {
	type = name;
}

void Drone::setBattery(float a){
	battery = a;
}

void Drone::setBatteryCharge(float a) {
	batteryCharge = a;
}

void Drone::setVelocity(float a) {
	velocity = a;
}

void Drone::setCurrentX(float x) {
	currentX = x;
}

void Drone::setCurrentY(float y) {
	currentY = y;
}

void Drone::setDestinationX(float x) {
	destinationX = x;
}

void Drone::setDestinationY(float y) {
	destinationY = y;
}

void Drone::setFinished(bool x){
	finished = x;
}

void Drone::setStarted(bool x){
	started = x;
}

string Drone::getId() {
	return id;
}

string Drone::getType() {
	return type;
}

float Drone::getBattery(){
	return battery;
}

float Drone::getBatteryCharge() {
	return batteryCharge;
}

float Drone::getVelocity() {
	return velocity;
}

float Drone::getCurrentX() {
	return currentX;
}

float Drone::getCurrentY() {
	return currentY;
}

float Drone::getDestinationX() {
	return destinationX;
}

float Drone::getDestinationY() {
	return destinationY;
}

bool Drone::getFinished(){
	return finished;
}

bool Drone::getStarted(){
	return started;
}

void Drone::enterInfo() {
}

void Drone::info() {
}

void Drone::move(Point *mas) {
	bool busy = false;
	int x, y;
	if (currentX < destinationX)       x = 1;
	else if (currentX > destinationX)  x = -1;
	else	                           x = 0;

	if (currentY < destinationY)       y = 1;
	else	                           y = 0;

	for (int i = 0; i < CNT; i++) {
		if ((currentX + x) == mas[i].getX() && (currentY + y) == mas[i].getY())
			busy = true;
	}
	if (!busy) {
		currentX += x;
		currentY += y;
	}
}

void Drone::arrived(){
}
