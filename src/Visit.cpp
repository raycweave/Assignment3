/**************************************************************************************************/

/*
* File: Visit.cpp
* Author: Ray Weaver
* NetID: rayweaver
* Date: November 4, 2014
*/

/**************************************************************************************************/

#include "Visit.h"
#include "GPSIMUState.h"
#include "Location.h"
#include "NMEAParser.h"
#include "VehicleJourney.h"
#include <algorithm>



Visit::Visit(void) {
	location = "";
	startTime = 0.0;
	endTime = 0.0;

	return;
}

Visit::~Visit(void) { }

Visit::Visit(string location, double startTime, double endTime) {
	this->location = location;
	this->startTime = startTime;
	this->endTime = endTime;

	return;
}

bool Visit::compare(Visit* v1, Visit* v2) {
	return true;
}

string Visit::getVisitString() const {
	return location;
}

void Visit::addState(string stateString) {
	state.push_back(stateString);
}