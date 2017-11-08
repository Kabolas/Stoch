#include "RecuitVLS.h"
#include "Station.h"

using namespace Project2;
RecuitVLS::RecuitVLS(double tInitiale, int nIter, int pallier, ProblemVLS^ prob)
{
	tempInitiale = tInitiale;
	problem = prob;
	temp = tempInitiale;
	nIteration = nIter;
	nPallier = pallier;
	coefDiminutionTemp = DIMINUTION_TEMPERATURE;
}


RecuitVLS::~RecuitVLS()
{
}


System::Collections::ArrayList^ RecuitVLS::getVicinity(System::Collections::ArrayList^ solution) {

	System::Collections::ArrayList^ stations = problem->getStations();
	System::Collections::ArrayList^ newSolution = gcnew System::Collections::ArrayList();
	for (int i = 0; i < solution->Count; i++) {
		newSolution->Add(solution[i]);
	}


	int stationToChange = (int)getRandProba(0, (double)solution->Count);
	newSolution[stationToChange] = (int)getRandProba(0, ((Station^)stations[stationToChange])->getBikeStands());
	return newSolution;
}

System::Collections::ArrayList^ RecuitVLS::generateFirstSolution() {

	System::Collections::ArrayList^ stations = problem->getStations();
	System::Collections::ArrayList^ firstSolution = gcnew System::Collections::ArrayList();
	for each(Station s in stations) {
		firstSolution->Add((int)getRandProba(0, s.getBikeStands()));
	}
	return firstSolution;
}

double RecuitVLS::getValue(System::Collections::ArrayList^ solution) { return problem->getValue(solution); }

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