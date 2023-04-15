#include "Commander.h"

Commander::Commander() {
	velocity = 2;
	batteryCharge = 1;
}

Commander::Commander(string CACT) :Navigator(gpsType) {
	commandAndControlType = CACT;
}

void Commander::setCommandAndControlType(string CACT) {
	commandAndControlType = CACT;
}

string Commander::getCommandAndContorlType() {
	return commandAndControlType;
}

void Commander::info(){
	cout << "***Information about Commander***" << endl;
	cout << "ID: " << id << endl;
	cout << "TYPE: " << type << endl;
	cout << "GPS TYPE: " << gpsType << endl;
	cout << "COMMAND AND CONTROL TYPE: " << commandAndControlType << endl;
	cout << "BATTERY CHARGE: " << batteryCharge << endl;
	cout << "VELOCITY: " << velocity << endl;
	cout << "CURRENT X: " << currentX << endl;
	cout << "CURRENT Y: " << currentY << endl;
	cout << "DESTINATION X: " << destinationX << endl;
	cout << "DESTINATION Y: " << destinationY << endl;
	cout << endl;
}

void Commander::enterInfo(){
	cout << "Please enter informaton about Commander" << endl;
	cout << "ID:";
	cin >> id;
	cout << "TYPE: ";
	cin.ignore();
	getline(cin, type);
	cout << "GPS TYPE: ";
	getline(cin, gpsType);
	cout << "COMMAND AND CONTROL TYPE: ";
	getline(cin, commandAndControlType);
	cout << endl;
}

void Commander::arrived() {
	cout << "Commander arrived!!! Congratulations!!" << endl;
}

int Commander::giveDestinationForDrone(int b){
	return randCordinate(b);
}
