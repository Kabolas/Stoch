#include "RecuitVLS.h"
#include "Station.h"
#include "math.h"

using namespace Project2;
RecuitVLS::RecuitVLS(double tInitiale, int nIter, int pallier, ProblemVLS^ prob, int nb_station) : Recuit(tInitiale,nIter,pallier)
{
	problem = prob;
	temp = tempInitiale;
	coefDiminutionTemp = DIMINUTION_TEMPERATURE;
	nStations = nb_station ? nb_station : prob->getStations()->Count;
}

Project2::RecuitVLS::RecuitVLS(double tInitiale, int nIter, int pallier, ProblemVLS ^ prob, System::Collections::Generic::Dictionary<int, System::Collections::ArrayList^ > ^ listTrajets, int nb_station)
{
	tempInitiale = tInitiale;
	problem = prob;
	temp = tempInitiale;
	nIteration = nIter;
	nPallier = pallier;
	coefDiminutionTemp = DIMINUTION_TEMPERATURE;
	problem->setTrajets(listTrajets);
	nStations = nb_station ? nb_station : prob->getStations()->Count;
}


RecuitVLS::~RecuitVLS()
{
}


System::Collections::ArrayList^ RecuitVLS::getVicinity(System::Collections::ArrayList^ solution) {

	//System::Collections::ArrayList^ stations = problem->getStations();
	System::Collections::ArrayList^ newSolution = gcnew System::Collections::ArrayList();
	for (int i = 0; i < solution->Count; i++) {
		newSolution->Add(solution[i]);
	}

	int stationWinsBike = 0;
	int stationLosesBike = 0;
	do {
		stationWinsBike = (int)getRandProba(0, (double)solution->Count  -1);
	} while ((int)solution[stationWinsBike] >= problem->getStation(stationWinsBike)->getBikeStands());
	do {
		stationLosesBike = (int)getRandProba(0, (double)solution->Count -1);
	} while (stationLosesBike == stationWinsBike && (int)solution[stationWinsBike] < 1);
	if ((int)newSolution[stationLosesBike] > 0)
		newSolution[stationLosesBike] = ((int)newSolution[stationLosesBike]) - 1;
	if ((int)newSolution[stationWinsBike] < problem->getStation(stationWinsBike)->getBikeStands())
		newSolution[stationWinsBike] = ((int)newSolution[stationWinsBike]) +1;
	return newSolution;
}

System::Collections::ArrayList^ RecuitVLS::generateFirstSolution() {

	System::Collections::ArrayList^ stations = gcnew System::Collections::ArrayList();
	System::Collections::ArrayList^ tmp = problem->getStations();
	for (int i = 0;i < nStations;++i)
		stations->Add(tmp[i]);
	System::Collections::ArrayList^ firstSolution = gcnew System::Collections::ArrayList();
	for each(Station s in stations) {
		firstSolution->Add((int)getRandProba(0, s.getBikeStands()));
	}
	return firstSolution;
}

double RecuitVLS::getValue(System::Collections::ArrayList^ solution) { return problem->getValue(solution); }

double RecuitVLS::getValueWithMalus(System::Collections::ArrayList^ solution, System::Collections::ArrayList^ solToCompare, int kMalus) {
	double value = problem->getValue(solution);
	if (kMalus > 0 && solToCompare != nullptr) {
		for (int i = 0; i < solution->Count; i++) {
			if ((int)solution[i] >(int)solToCompare[i])
				value = value + kMalus * ((int)solution[i] - (int)solToCompare[i]);
			else
				value = value + kMalus * ((int)solToCompare[i] - (int)solution[i]);
		}
	}
	return value;
}

void Project2::RecuitVLS::algoWithMalus(System::Collections::ArrayList^ solToCompare, int kMalus)
{
	System::Collections::ArrayList^ currentSolution = generateFirstSolution();
	bestSolution = currentSolution;
	minValue = getValueWithMalus(bestSolution, solToCompare, kMalus);
	int i = 0;
	while (i < nIteration) {
		do {
			System::Collections::ArrayList^ newSol = getVicinity(currentSolution);
			double newValue = getValueWithMalus(newSol, solToCompare, kMalus);
			double delta = newValue - getValueWithMalus(currentSolution, solToCompare, kMalus);
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

double RecuitVLS::changeTemp() { return temp * coefDiminutionTemp; }


ProblemVLS ^ RecuitVLS::getProb() { return problem; }

void RecuitVLS::setIter(int nIter) { this->nIteration = nIter; }

String^ RecuitVLS::afficher() {

	String^ s = "Solution :\n";
	for (int i = 0; i<bestSolution->Count; i++) {
		s += "Station " + i + " : " + bestSolution[i] + " velos.\n";
	}
	return s;
}