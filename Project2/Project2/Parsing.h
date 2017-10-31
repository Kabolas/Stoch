#pragma once
#include "Station.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

class Parser
{
	public:
		bool readFile(std::string filePath, std::vector<std::string>& buffer);
		void readTextBike(std::string filePath,std::vector<Station>& stList);

};
