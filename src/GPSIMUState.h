/**************************************************************************************************/

/*
* File: GPSIMUState.h
* Author: Ray Weaver
* NetID: rayweaver
* Date: November 4, 2014
*/

/**************************************************************************************************/

#ifndef GPSIMUState_H
#define GPSIMUState_H

#include <iostream>
using namespace std;

class GPSIMUState {

public:
	// Constructor and Destructor
	GPSIMUState(void);
	GPSIMUState(string sentence);
	~GPSIMUState(void);

	/* Implement other methods as you see fit */

	/* Mutators for variables are below */

	// mutators for week
	void setWeek( unsigned long week ) { this->week = week; }
	unsigned long getWeek( ) const { return this->week; }

	// mutators for seconds
	void setSeconds( double seconds ) { this->seconds = seconds; }
	double getSeconds( ) const { return this->seconds; }

	// mutators for latitude
	void setLatitude( double latitude ) { this->latitude = latitude; }
	double getLatitude( ) const { return this->latitude; }

	// mutators for longitude
	void setLongitude( double longitude ) { this->longitude = longitude; }
	double getLongitude( ) const { return this->longitude; }

	// mutators for state
	void setState(string state ) { this->state = state; }
	string getState( ) const { return this->state; }

	// mutators for location
	void setLocation(string location ) { this->location = location; }
	string getLocation( ) const { return this->location; }

private:
	unsigned long week; // The week number from the NMEA sentence.
	double seconds; // The seconds from the NMEA sentence.
	double latitude; // The latitude from the NMEA sentence.
	double longitude; // The longitude from the NMEA sentence.
	string state; // The GPS/IMU State at this point.
	string location; // The location name for this position.
};

#endif