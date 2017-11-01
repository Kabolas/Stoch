#pragma once
#include "Station.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace System;

namespace Project2 {
		bool readFile(std::string filePath, Collections::ArrayList^ buffer);
		void readTextBike(std::string filePath,Collections::ArrayList^ stList);

}
