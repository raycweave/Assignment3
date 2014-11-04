/**************************************************************************************************/

/*
* File: NMEAParser.h
* Author: Ray Weaver
* NetID: rayweaver
* Date: November 4, 2014
*/

/**************************************************************************************************/

#ifndef NMEAParser_H
#define NMEAParser_H

#include "GPSIMUState.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class NMEAParser {
public:
	// If unable to read file, the vector will be of size 0
 static vector<GPSIMUState*> parseLogFile(string filename);
 static GPSIMUState* parseNMEASentence(string sentence);

private:
	// These are private because there is no need for them in a ‘static’
	// class.
 NMEAParser(void);
 ~NMEAParser(void);
};

#endif

