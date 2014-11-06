/**************************************************************************************************/

/*
* File: VehicleJourney.cpp
* Author: Ray Weaver
* NetID: rayweaver
* Date: November 4, 2014
*/

/**************************************************************************************************/
#include <iostream>
#include "Location.h"
#include "VehicleJourney.h"
#include "GPSIMUState.h"
#include "Visit.h"
#include "NMEAParser.h"
using namespace std;
/*
VehicleJourney::VehicleJourney() is the default constructor which sets all defined locations in Location.h
to positions in the VehicleJourney objects locations vector. 
*/

VehicleJourney::VehicleJourney() 

{

	//vector<Location*> locations;

	Location *temp = NULL;
	temp = new Location(FRYS, FRYS_LAT, FRYS_LON);
	this->locations.push_back(temp);

	temp = NULL;
	temp = new Location(ECE, ECE_LAT, ECE_LON);
	this->locations.push_back(temp);

	temp = NULL;
	temp = new Location(UNIVERSITY, UNIVERSITY_LAT, UNIVERSITY_LON);
	this->locations.push_back(temp);

	temp = NULL;
	temp = new Location(FOURTH, FOURTH_LAT, FOURTH_LON);
	this->locations.push_back(temp);

	temp = NULL;
	temp = new Location(EEGEES, EEGEES_LAT, EEGEES_LON);
	this->locations.push_back(temp);

	temp = NULL;
	temp = new Location(CATTRAN, CATTRAN_LAT, CATTRAN_LON);
	this->locations.push_back(temp);

	temp = NULL;
	temp = new Location(INO, INO_LAT, INO_LON);
	this->locations.push_back(temp);

	temp = NULL;
	temp = new Location(ELLIOT, ELLIOT_LAT, ELLIOT_LON);
	this->locations.push_back(temp);

	//location unknown FIXME

}

VehicleJourney::~VehicleJourney() {

}


void VehicleJourney::analyzeJourney() {

	VehicleJourney::determineVisits();

}

bool VehicleJourney::writeOutputFile(string filename) {

	int i;
	ofstream outFS; // Output file stream

	outFS.open(filename);

	if (!outFS.is_open()) {
		cout << "Could not open file " << filename << endl;
		return 1;
	}
	for (i = 0; i < visits.size(); i++) {
		outFS << visits.at(i)->getLocation() << endl;
		outFS << visits.at(i)->getStartTime() << " to " << visits.at(i)->getEndTime() << endl;
		//outFS << "States: "; << visits.at(i)->getStates() << endl;
	}


	return true;
}

Location* VehicleJourney::findLocation(GPSIMUState* state) {

	int i = 0;

	for (i = 0; i < locations.size(); i++) {
		if ((locations.at(i)->inLocation(state->getLatitude(), state->getLongitude())) == true) {
			return locations.at(i);
		}
	}
	return NULL;
}

void VehicleJourney::determineVisits() {

	int i = 0;
	int j = 0;
	int count = 0;
	string locationName = "";
	double tempStartTime;
	double tempEndTime;
	Location *temp = NULL;
	Visit *visitTemp = NULL;

	for (i = 0; i < states.size(); i++) // This for loop sets the locations to the respective location it is at or unknown
	{			
		temp = findLocation(states.at(i));

		if (temp != NULL) 
		{
			states.at(i)->setLocation(temp->getName());		//stores the location name (EX: FRYS) from the default location vector into the respective state
		}
		else 
		{
			states.at(i)->setLocation(UNKNOWN);				//else if not at a location, make the state location unknown
		}
		temp = NULL;
	}


	for (i = 0; i < states.size(); i++) 
	{
		locationName = states.at(i)->getLocation();
	
		if (locationName != UNKNOWN) 
		{
			visitTemp = new Visit();
			tempStartTime = states.at(i)->getSeconds();
			tempEndTime = tempStartTime;

			visitTemp->addState(states.at(i)->getState());
			count = 0;

			for (j = i + 1; j < states.size(); j++)
			{
				if (locationName == states.at(j)->getLocation())
				{
					if (states.at(j)->getState() != visitTemp->getStates().back()) //visitTemp->getStates().back()
					{
						visitTemp->addState(states.at(j)->getState());			
					}
					tempEndTime = states.at(j)->getSeconds();
					count++;
				}
				else
				{
					break;
				}

			}

			visitTemp->setLocation(locationName);
			visitTemp->setStartTime(tempStartTime);
			visitTemp->setEndTime(tempEndTime);
			visits.push_back(visitTemp);

			i = i + count;

			
			
		}
	}
}

void VehicleJourney::sortVisits() {

	//sort(this->visits.begin(), this->visits.end(), visits.compare())

}

