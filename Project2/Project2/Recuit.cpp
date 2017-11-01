#include "Recuit.h"
#include "math.h"

using namespace Project2;

Recuit::Recuit() {

}

Recuit::Recuit(double tInitiale, int nIter, int pallier)
{
	tempInitiale = tInitiale;
	temp = tempInitiale;
	nIteration = nIter;
	nPallier = pallier;
}


Recuit::~Recuit()
{

	
}

System::Collections::ArrayList^ Recuit::getBestSolution() {
	return bestSolution;
}

double Recuit::getMinValue() {
	return minValue;
}

double Recuit::getRandProba(double min, double max)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<> dis(min, max);
	return dis(gen);
}

void Recuit::algo() {

	System::Collections::ArrayList^ currentSolution = generateFirstSolution();
	bestSolution = currentSolution;
	minValue = getValue(bestSolution);
	int i = 0;
	while (i < nIteration) {
		do {
			System::Collections::ArrayList^ newSol = getVicinity(currentSolution);
			double newValue = getValue(newSol);
			double delta = newValue - getValue(currentSolution);
			if (delta < 0) {
				if (newValue < minValue) {
					bestSolution = newSol;
					minValue = newValue;
				}
				currentSolution = newSol;
			}

			else {
				double p = getRandProba(0, 1);

				if (p <= exp(-delta / temp)) {
					currentSolution = newSol;
				}
			}
			i++;
		} while (i%nPallier != 0);
		temp = changeTemp();
	}
}
