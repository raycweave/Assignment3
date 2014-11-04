/**************************************************************************************************/

/*
* File: main.cpp
* Author: Ray Weaver
* NetID: rayweaver
* Date: November 4, 2014
*/

/**************************************************************************************************/

/**************************************************************************************************/
/*							Assignment 3
*
*	
*
*/
/**************************************************************************************************/


#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdlib>
#include <cstdio>

#include "NMEAParser.h"
#include "VehicleJourney.h"
#include "Visit.h"

using namespace std;

/**************************************************************************************************/

/*
This data includes the complete PVT (position, velocity, time) solution computed by the GPS receiver. 
The idea of NMEA is to send a line of data called a sentence that is totally self contained 
and independent from other sentences.

Source: gpsinformation.org/dale/nmea.htm
*/

int main(int argc, char *argv [])
{

	/*
	* check for the correct number of command line arguments.  If incorrect
	* provide a simple usage message to the assist the user
	*/

	if (argc != 3) {
		cerr << "Usage: " << argv[0] << " logFile outputFile" << endl;
		return -1;
	}
	
	//VehicleJourney roadTrip;
	//roadTrip.setStates(NMEAParser::parseLogFile(argv[1]));

	/*
	if (roadTrip.getStates().size() > 0)
	{
		roadTrip.analyzeJourney();
		if (roadTrip.writeOutputFile(argv[2]) == false)
		{
			cerr << "Cannot open file " << argv[2] << endl;
			return -1;
		}
	}

	else {
		cerr << "The file " << argv[1] << " cannot open or is empty" << endl;
		return -1;
	}
	*/
	NMEAParser::parseLogFile(argv[1]);

	return 0;
}
