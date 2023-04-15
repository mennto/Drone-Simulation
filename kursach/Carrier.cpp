#include "Carrier.h"

Carrier::Carrier() {
	velocity = 1;
	batteryCharge = 2;
}

Carrier::Carrier(string carryCap) :Drone(id, type, batteryCharge, velocity,
	currentX, currentY, destinationX, destinationY) {
	carryingCapacity = carryCap;
}

void Carrier::setCarryingCapacity(string a) {
	carryingCapacity = a;
}

string Carrier::getCarryingCapacity() {
	return carryingCapacity;
}

void Carrier::info(){
	cout << "***Information about Carrier***" << endl;
	cout << "ID: " << id << endl;
	cout << "TYPE: " << type << endl;
	cout << "CARRYING CAPACITY: " << carryingCapacity << endl;
	cout << "BATTERY CHARGE: " << batteryCharge << endl;
	cout << "VELOCITY: " << velocity << endl;
	cout << "CURRENT X: " << currentX << endl;
	cout << "CURRENT Y: " << currentY << endl;
	cout << "DESTINATION X: " << destinationX << endl;
	cout << "DESTINATION Y: " << destinationY << endl;
	cout << endl;
}

void Carrier::enterInfo(){
	cout << "Please enter informaton about Carrier" << endl;
	cout << "ID:";
	cin >> id;
	cout << "TYPE: ";
	cin.ignore();
	getline(cin, type);
	cout << "CARRYING CAPACITY: ";
	getline(cin, carryingCapacity);
	cout << endl;
}

void Carrier::arrived(){
	cout << "Carrier arrived!!! Congratulations!!" << endl;
}


