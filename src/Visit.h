/**************************************************************************************************/

/*
* File: Visit.h
* Author: Ray Weaver
* NetID: rayweaver
* Date: November 4, 2014
*/

/**************************************************************************************************/



#ifndef Visit_H
#define Visit_H
#include <vector>
#include <string>

using namespace std;

class Visit {
public:

	// Constructor and Destructor
	Visit(void);
	Visit(string location, double startTime, double endTime);
	~Visit(void);

	// Compare two visits together to see which is before the other.
	// Returns true if v1 is before v2, false otherwise.
	// A visit is before another if its location is alphabetically before
	// the other visit’s location.
	// A visit with the same location name as another is before that
	// location if its startTime is before the other visit’s startTime.
	static bool compare(Visit* v1, Visit* v2);
	
	/* Implement other methods as you see fit */

	/* Mutators for variables are below */

	void setStartTime( double startTime ) { this->startTime = startTime; }
	double getStartTime( ) const { return this->startTime; }
	
	void setEndTime( double endTime ) { this->endTime = endTime; }
	double getEndTime( ) const { return this->endTime; }
	
	void addState(string stateString );
	vector<string> getStates( ) const { return this->state; }

	void setLocation( std::string location ) { this->location = location; }
	string getLocation( ) const { return this->location; }

	// returns the string for this visit
	string getVisitString( ) const;

private:

	// Note that you can assume the week will always
	// be the same for start and end times.
	string location; // The location name for this visit.
	double startTime; // The start seconds for the visit.
	double endTime; // The end seconds for the visit.
	vector<string> state; // The ordered list of states at this location.
};

#endif

