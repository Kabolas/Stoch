#pragma once
#include "Station.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace System;

namespace Project2 {
		bool readFile(String^ filePath, Collections::ArrayList^ buffer);
		void readTextBike(String^ filePath,Collections::ArrayList^ stList);

}
