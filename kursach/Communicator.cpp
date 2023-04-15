#include "Communicator.h"

Communicator::Communicator() {
	velocity = 2;
	batteryCharge = 1;
}

Communicator::Communicator(int comRange) :Drone(id, type, batteryCharge, velocity, currentX, currentY, destinationX, destinationY) {
	communicationRange = comRange;
}

void Communicator::setCommunicationRange(int a) {
	communicationRange = a;
}

int Communicator::getCommunicationRange() {
	return communicationRange;
}

void Communicator::info(){
	cout << "***Information about Communicator***" << endl;
	cout << "ID: " << id << endl;
	cout << "TYPE: " << type << endl;
	cout << "COMMUNICATION RANGE: " << communicationRange << endl;
	cout << "BATTERY CHARGE: " << batteryCharge << endl;
	cout << "VELOCITY: " << velocity << endl;
	cout << "CURRENT X: " << currentX << endl;
	cout << "CURRENT Y: " << currentY << endl;
	cout << "DESTINATION X: " << destinationX << endl;
	cout << "DESTINATION Y: " << destinationY << endl;
	cout << endl;
}

void Communicator::enterInfo(){
	cout << "Please enter informaton about Communicator" << endl;
	cout << "ID:";
	cin >> id;
	cout << "TYPE: ";
	cin.ignore();
	getline(cin, type);
	cout << "COMMUNICATION RANGE: ";
	cin >> communicationRange;
	cout << endl;
}

void Communicator::arrived(){
	cout << "Communicator arrived!!! Congratulations!!" << endl;
}