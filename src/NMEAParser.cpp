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

	if (inputFile.is_open()) 
	{
		while (!inputFile.eof()) 
		{
			getline(inputFile, line);

			if (line.compare("#INSPVAA") == 1)   //line.substr(0,8) == "#INSPVAA")
			{
				temp = NMEAParser::parseNMEASentence(line);
				if (temp) 
				{
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

		