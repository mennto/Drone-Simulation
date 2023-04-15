#include "Navigator.h"

Navigator::Navigator() {

}

Navigator::Navigator(string gps) :Drone(id, type, batteryCharge, velocity,
	currentX, currentY, destinationX, destinationY) {
	this->gpsType = gps;
}

void Navigator::setGpsType(string a) {
	gpsType = a;
}

string Navigator::getGpsType() {
	return gpsType;
}

void Navigator::info(){
	cout << "***Information about Navigator***" << endl;
	cout << "ID: " << id << endl;
	cout << "TYPE: " << type << endl;
	cout << "GPS TYPE: " << gpsType << endl;
	cout << "BATTERY CHARGE: " << batteryCharge << endl;
	cout << "VELOCITY: " << velocity << endl;
	cout << "CURRENT X: " << currentX << endl;
	cout << "CURRENT Y: " << currentY << endl;
	cout << "DESTINATION X: " << destinationX << endl;
	cout << "DESTINATION Y: " << destinationY << endl;
	cout << endl;
}

void Navigator::enterInfo(){
	cout << "Please enter informaton about Navigator" << endl;
	cout << "ID: ";
	cin >> id;
	cout << "TYPE: ";
	cin.ignore();
	getline(cin, type);
	cout << "GPS TYPE: ";
	getline(cin, gpsType);
	cout << endl;
}

