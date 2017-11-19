#include "RecuitStocha.h"
#include <iostream>


using namespace Project2;
Project2::RecuitStocha::RecuitStocha(double tInitiale, int nIter, int pallier, ProblemVLS^ prob, int pena, int nbStations, int nbScenarios)
{
	penalite = pena;
	System::Collections::ArrayList^ scenars = gcnew System::Collections::ArrayList();
	scenarios = gcnew System::Collections::ArrayList();
	for (int i = 0; i < nbScenarios; i++) {
		scenars->Add(gcnew ScenarioVLS(nbStations));
		((ScenarioVLS^)scenars[i])->generateAllTrajets(prob->getStations(), nbStations);
	}
	for each(ScenarioVLS^ scenar in scenars) {
		scenarios->Add(gcnew RecuitVLS(tInitiale, nIter, pallier, prob, scenar->getListeTrajetsSce(), nbStations));
	}
}

Project2::RecuitStocha::~RecuitStocha()
{
}

void Project2::RecuitStocha::algo(int nbStations)
{
	System::Collections::ArrayList^ lastSolution = gcnew System::Collections::ArrayList();
	System::Collections::ArrayList^ sumSolution = gcnew System::Collections::ArrayList();
	int nbScenarios = scenarios->Count;
	for (int i = 0; i < nbStations; i++) {
		sumSolution->Add((int)0);
	}
	double lastValue;
	bool goOn = false;
	for each(RecuitVLS^ scenar in scenarios) {
		scenar->algo();
		if (!solutionsAreEquals(lastSolution, scenar->getBestSolution()))
			goOn = true;
		lastSolution = scenar->getBestSolution();
		lastValue = scenar->getMinValue();
		sumSolution = addVectors(sumSolution, lastSolution);
	}

	System::Collections::ArrayList^ moySolution = gcnew System::Collections::ArrayList();
	for each(int sol in sumSolution) {
		moySolution->Add(sol / nbScenarios);
	}
	
	if (goOn) {
		lastSolution->Clear();
		int x = 0;
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
			moySolution->Clear();
			for each(int sol in sumSolution) {
				moySolution->Add(sol / nbScenarios);
			}
			std::cout << "x = " << x << " " << std::endl;
			++x;

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
	System::Collections::ArrayList^ v3 = gcnew System::Collections::ArrayList();
	for(int i = 0; i < v1->Count; i++) {
		v3->Add((int)v1[i] + (int)v2[i]);
	}
	return v3;
}

String^ Project2::RecuitStocha::afficher()
{
	String^ s = "Solution :\n";
	for (int i = 0; i<finalSolutions->Count; i++) {
		s += "Station " + i + " : " + finalSolutions[i] + " velos.\n";
	}
	return s;
}
