/**************************************************************************************************/

/*
* File: Location.cpp
* Author: Ray Weaver
* NetID: rayweaver
* Date: November 4, 2014
*/

/**************************************************************************************************/

/***
You will need to update all file comments and ensure all other
method and code comments are complete---these are not sufficient, 
but are provided to remind you that it is important to carry out
detailed comments to help you structure your code, and for others
to be able to read your code
*/
#include <stdio.h>
#include <math.h>
#include "Location.h"
#include "VehicleJourney.h"
#include "GPSIMUState.h"
#include "Visit.h"

// implementation of Location nondefault constructor
/***
Note that in this nondefault constructor, the initialization
region of the constructor is used to pass along constructor 
parameters and directly set the values of the variables during
initialization. This means that when the object is placed on the stack
or on the heap, that the memory is initialized with these parameter values
already in it, rather than later assigning those values to the variables
of the functions. It makes all things run a little faster, but it only
works with constructors. We'll learn more about this in later chapters.
*/
Location::Location( std::string name, double latitude, double longitude ) 
: name(name), latitude(latitude), longitude(longitude)
{
	
}

// returns TRUE if both latitude and longitude are within 
// LOCATION_TOLERANCE of this Location objects's latitude and longitude
bool Location::inLocation( double latitude, double longitude ) const
{
	bool result=false;
	/**
	Fill in the implementation here, to tell whether both the latitude 
	and longitude are within LOCATION_TOLERANCE of this location
	*/

	if ((fabs(this->latitude - latitude) < LOCATION_TOLERANCE) && (fabs(this->longitude - longitude) < LOCATION_TOLERANCE)) {
		result = true;
	}
	

	return result;
}
