#pragma once
#include "Recuit.h"

#define DIMINUTION_TEMPERATURE 0.95

class RecuitVLS : public Recuit
{

private:
	double coefDiminutionTemp;

public:
	RecuitVLS(double tInitiale, int nIter, int pallier);
	~RecuitVLS();

	std::vector<int> getVicinity(std::vector<int> solution);
	std::vector<int> generateFirstSolution();
	double getValue(std::vector<int> solution);
	double changeTemp();

};

