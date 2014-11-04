/**************************************************************************************************/

/*
* File: Location.h
* Author: Ray Weaver
* NetID: rayweaver
* Date: November 4, 2014
*/

/**************************************************************************************************/


#ifndef LOCATION_H
#define LOCATION_H
using namespace std;

#include <string>

/***
 As a convenience to you for this assignment, the values for 
 each location are included in this header, and this class is
 given as (almost) fully implemented. Use this in a clever way
 in your VehicleJourney class, to create a vector of locations
 that you can look through to see whether you are at one of them.
*/

#define FRYS "Fry's"
#define FRYS_LAT 32.251223
#define FRYS_LON -110.961524
#define ECE "ECE Back Lot"
#define ECE_LAT 32.235599
#define ECE_LON -110.953088
#define UNIVERSITY "University Boulevard"
#define UNIVERSITY_LAT 32.231672
#define UNIVERSITY_LON -110.959131
#define FOURTH "4th Avenue"
#define FOURTH_LAT 32.227751
#define FOURTH_LON -110.965590
#define EEGEES "Eegee's"
#define EEGEES_LAT 32.235891
#define EEGEES_LON -110.934919
#define CATTRAN "CAT Vehicle Testing Lot"
#define CATTRAN_LAT 32.217875
#define CATTRAN_LON -110.914389
#define INO "In-N-Out"
#define INO_LAT 32.221842
#define INO_LON -110.957492
#define ELLIOT "Elliot Electronics"
#define ELLIOT_LAT 32.205207
#define ELLIOT_LON -110.959206
#define UNKNOWN "Unknown"



// the amount of tolerance for whether we are at a location or not
#define LOCATION_TOLERANCE 0.002

class Location {
public:
	// Note: if you ever try to create a Location without any parameters,
	// it will work with a generated constructor, since we didn't include one
	
	// this overloaded constructor permits us to rapidly set the values
	// of this location without having to call the getter/setter methods
	Location(string name, double latitude, double longitude );
	// the destructor doesn't have anything to do, since all our types
	// will delete themselves
	~Location( ) { }
	
	// returns TRUE if both latitude and longitude are within 
	// LOCATION_TOLERANCE of this Location objects's latitude and longitude
	bool inLocation( double latitude, double longitude ) const;

	/* Mutators for variables are below */

	// you will need to update these comments
	void setName(string name ) { this->name = name; }
	// you will need to update these comments
	string getName( ) const { return name; }

	// you will need to update these comments
	void setLatitude( double latitude ) { this->latitude = latitude; }
	// you will need to update these comments
	double getLatitude( ) const { return latitude; }
	
	// you will need to update these comments
	void setLongitude( double longitude ) { this->longitude = longitude; }
	// you will need to update these comments
	double getLongitude( ) const { return longitude; }
	

private:
	// you will need to update these comments
	string name;
	double latitude;
	double longitude;
};

#endif // LOCATION_H
