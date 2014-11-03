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
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include <sstream>
#include <string>

#include "GPSIMUState.h"
#include "NMEAParser.h"
#include "VehicleJourney.h"
#include "Visit.h"

/**************************************************************************************************/

/*
The National Marine Electronics Association (NMEA) has developed a specification that defines 
the interface between various pieces of marine electronic equipment.

GPS receiver communication is defined within this specification. Most computer programs that 
provide real time position information understand and expect data to be in NMEA format. This 
data includes the complete PVT (position, velocity, time) solution computed by the GPS receiver. 
The idea of NMEA is to send a line of data called a sentence that is totally self contained 
and independent from other sentences.

Source: gpsinformation.org/dale/nmea.htm
*/

int main(int argc, char *argv [])
{

	std::stringstream stream;

	/*
	* check for the correct number of command line arguments.  If incorrect
	* provide a simple usage message to the assist the user
	*/

	if (argc != 3) {
		std::cout << "Usage: " << argv[0] << " logFile outputFile \n\n" << std::endl;
		return false;
	}

	std::ifstream inputFile;
	inputFile.open(argv[1]);

	//#INSPVAA,COM1,0,54.5,FINESTEERING,1748,502500.800,00000000,5615,4674;1748,502500.794775700,0.000000000,0.000000000,0.000000000,0.000000000,0.000000000,0.000000000,0.000000000,0.000000000,0.000000000,INS_ALIGNING*3fe523b6

	if (inputFile.is_open()) {
		//do stuff
		std::string temp = "";
		getline(inputFile, temp);
		std::stringstream stream(temp);

		for (int i = 0; i < temp.size(); i++) {
			if (temp.at(i) == ',') {
				temp.at(i) = ' ';
			}
		}

		/*
		This first block of variables is for information pertaining to the NMEA Sentence Header Field. It is seperated from the INSPVAA sentence field by a semicolon
		*/
		std::string hashtag;
		std::string message;
		std::string dataPort;
		int seqNum;
		int idleTimePercent;
		std::string gpsTimeStatus;
		int week;
		int seconds;
		int recStatus;
		int reserved;
		int recVersion;
		
		stream >> message;
		stream >> dataPort;
	}


	return 0;
}