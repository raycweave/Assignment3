/**************************************************************************************************/

/*
* File: VehicleJourney.h
* Author: Ray Weaver
* NetID: rayweaver
* Date: November 4, 2014
*/

/**************************************************************************************************/

#ifndef VehicleJourney_H
#define VehicleJourney_H

#include "GPSIMUState.h"
#include "Visit.h"
#include "Location.h"

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class VehicleJourney {
public:
	// Constructor and Destructor
	/* also constructs the interesting locations vector to consider in this journey */

	VehicleJourney(void);
	~VehicleJourney(void);

	/* Implement other methods as you see fit */

	
	/* Analyse journey calculates the visits and sorts them */
	void analyzeJourney( );

	/* writes the output file */
	bool writeOutputFile(string filename );

	/* returns the output strings for printing out */
	string getVisitsAsStrings( ) const;

	Location* findLocation(GPSIMUState* state);

	/* Mutators for variables are below */
	void setStates(vector<GPSIMUState*> states ) { this->states = states; }
	vector<GPSIMUState*> getStates( ) const { return this->states; }
	

private:
	/* looks through the state vector and determines the visits, including
	 setting all values for each visit */
	void determineVisits( );
	/* sorts the visits vector after it is populated */
	void sortVisits( );

	// member variables
	vector<GPSIMUState*> states; // The list of GPS locations and states.
	vector<Visit*> visits; // The locations that were visited.

	// if you create this list when you construct your vehicle journey, then
	// it may be easier to check whether you are in a location or not
	vector<Location*> locations;

};

#endif
