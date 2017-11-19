#include "RecuitStocha.h"




Project2::RecuitStocha::RecuitStocha(double tInitiale, int nIter, int pallier, ProblemVLS^ prob, System::Collections::ArrayList ^ scenars, int pena)
{
	penalite = pena;
	scenarios = scenars;
	for each(Scenario scenar in scenars) {
		scenarios->Add(gcnew RecuitVLS(tInitiale, nIter, pallier, prob, scenar));
	}
}

Project2::RecuitStocha::~RecuitStocha()
{
}

void Project2::RecuitStocha::algo()
{
	System::Collections::ArrayList^ lastSolution;
	System::Collections::ArrayList^ sumSolution;
	int nbScenarios = scenarios->Count;
	for (int i = 0; i < ((RecuitVLS^)scenarios[i])->getProb()->getStations()->Count; i++) {
		sumSolution->Add((int)0);
	}
	double lastValue;
	bool goOn = false;
	for each(RecuitVLS^ scenar in scenarios) {
		scenar->algo();
		if (!solutionsAreEquals(lastSolution, scenar->getBestSolution))
			goOn = true;
		lastSolution = scenar->getBestSolution();
		lastValue = scenar->getMinValue();
		sumSolution = addVectors(sumSolution, lastSolution);
	}

	System::Collections::ArrayList^ moySolution;
	for each(int sol in sumSolution) {
		moySolution->Add(sol / nbScenarios);
	}
	
	if (goOn) {
		lastSolution->Clear();
		do {
			goOn = false;
			for each(int sol in sumSolution) {
				sol = 0;
			}
			for each(RecuitVLS^ scenar in scenarios) {
				scenar->algoWithMalus(moySolution, penalite);
				if (!solutionsAreEquals(lastSolution, scenar->getBestSolution()))
					goOn = true;
				lastSolution = scenar->getBestSolution();
				lastValue = scenar->getMinValue();
				sumSolution = addVectors(sumSolution, lastSolution);
			}
			for each(int sol in sumSolution) {
				moySolution->Add(sol / nbScenarios);
			}

		} while (goOn);
	}
	finalSolutions = lastSolution;
	finalValue = lastValue;
}

double Project2::RecuitStocha::getFinalValue()
{
	return finalValue;
}

System::Collections::ArrayList ^ Project2::RecuitStocha::getFinalSolutions()
{
	return finalSolutions;
}

bool Project2::RecuitStocha::solutionsAreEquals(System::Collections::ArrayList^ sol1, System::Collections::ArrayList^ sol2)
{
	if (sol1->Count != sol2->Count)
		return false;
	for (int i = 0; i < sol1->Count; i++) {
		if (sol1[i] != sol2[i])
			return false;
	}
	return true;
}

System::Collections::ArrayList^ Project2::RecuitStocha::addVectors(System::Collections::ArrayList^ v1, System::Collections::ArrayList^ v2) {

	if (v1->Count != v2->Count)
		return nullptr;
	System::Collections::ArrayList^ v3;
	for(int i = 0; i < v1->Count; i++) {
		v3->Add((int)v1[i] + (int)v2[i]);
	}
	return v3;
}
