/**************************************************************************************************/

/*
* File: GPSIMUState.cpp
* Author: Ray Weaver
* NetID: rayweaver
* Date: November 4, 2014
*/

/**************************************************************************************************/
#include "GPSIMUState.h"
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

GPSIMUState::GPSIMUState(void) {

	week = -1; // The week number from the NMEA sentence.
	seconds = -1; // The seconds from the NMEA sentence.
	latitude = -1; // The latitude from the NMEA sentence.
	longitude = -1; // The longitude from the NMEA sentence.

	//These two below are strings, may need to set to "" or null

	state = -1; // The GPS/IMU State at this point.
	location = -1; // The location name for this position.

}

GPSIMUState::GPSIMUState(string sentence) {
	
	istringstream inSS;
	inSS.clear();
	inSS.str(sentence);

	int i = 0;
	string junk = "";

	for (i = 0; i < 10; i++) {
		inSS >> junk;
	}

	//#INSPVAA,COM1,0,54.5,FINESTEERING,1748,502500.800,00000000,5615,4674;1748,502500.794775700,0.000000000,0.000000000,0.000000000,0.000000000,0.000000000,0.000000000,0.000000000,0.000000000,0.000000000,INS_ALIGNING*3fe523b6

	inSS >> week;
	inSS >> seconds;
	inSS >> latitude;
	inSS >> longitude;

	for (i = 0; i < 7; i++) {
		inSS >> junk;
	}

	inSS >> state;


}