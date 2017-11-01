#pragma once

#include <vector>
#include <random>

class Recuit
{

protected:
	double tempInitiale;
	double temp;
	std::vector<int> bestSolution;
	double minValue;
	int nIteration;
	int nPallier;


public:
	Recuit();
	Recuit(double tInitiale, int nIter, int nPallier);
	~Recuit();

	virtual std::vector<int> getVicinity(std::vector<int> solution) = 0;
	virtual std::vector<int> generateFirstSolution() = 0;
	virtual double getValue(std::vector<int> solution) = 0;
	virtual double changeTemp() = 0;
	void algo();
	std::vector<int> getBestSolution();
	double getMinValue();
	double getRandProba(double min, double max);

};

