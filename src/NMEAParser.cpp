/**************************************************************************************************/

/*
* File: NMEAParser.cpp
* Author: Ray Weaver
* NetID: rayweaver
* Date: November 4, 2014
*/

/**************************************************************************************************/

#include "NMEAParser.h"
#include "GPSIMUState.h"
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

vector<GPSIMUState*> NMEAParser::parseLogFile(string filename) {

	fstream inputFile;
	vector<GPSIMUState*> result;
	string line;
	inputFile.open(filename.c_str());
	GPSIMUState *temp = NULL;

	if (inputFile.is_open()) {
		while (!inputFile.eof()) {
			getline(inputFile, line);

			if (line.compare("#INSPVAA") == 1) {
				temp = NMEAParser::parseNMEASentence(line);
				if (temp) {
					result.push_back(temp);
				}
			}
			temp = NULL;

		}
	}
	return result;
}

GPSIMUState* NMEAParser::parseNMEASentence(string sentence)
{

	replace(sentence.begin(), sentence.end(), ',', ' ');
	replace(sentence.begin(), sentence.end(), ';', ' ');
	replace(sentence.begin(), sentence.end(), '*', ' ');

	GPSIMUState *result = new GPSIMUState(sentence);
	return result;
}

		
//#INSPVAA,COM1,0,54.5,FINESTEERING,1748,502500.800,00000000,5615,4674;1748,502500.794775700,0.000000000,0.000000000,0.000000000,0.000000000,0.000000000,0.000000000,0.000000000,0.000000000,0.000000000,INS_ALIGNING*3fe523b6