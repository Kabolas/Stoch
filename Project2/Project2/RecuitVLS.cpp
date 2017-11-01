#include "RecuitVLS.h"
#include "Station.h"


RecuitVLS::RecuitVLS(double tInitiale, int nIter, int pallier)
{
	tempInitiale = tInitiale;
	temp = tempInitiale;
	nIteration = nIter;
	nPallier = pallier;
	coefDiminutionTemp = DIMINUTION_TEMPERATURE;
}


RecuitVLS::~RecuitVLS()
{
}


std::vector<int> RecuitVLS::getVicinity(std::vector<int> solution) {
	//TODO : J''ai besoin d'accéder à chaque station pour avoir leur place
	//On a mis temporairement une initialisation ci-dessous, mais en vrai il faut accéder aux stations du problème.
	std::vector<Station> stations = std::vector<Station>();

	//Debut algo
	std::vector<int> newSolution;

	for (int i = 0; i < solution.size(); i++) {
		newSolution[i] = solution[i];
	}


	int stationToChange = (int)getRandProba(0, solution.size);
	newSolution[stationToChange] = (int)getRandProba(0, stations[stationToChange].getBikeStands());
	return newSolution;
}

std::vector<int> RecuitVLS::generateFirstSolution() {
	//TODO : J''ai besoin d'accéder à chaque station pour avoir leur place
	//On a mis temporairement une initialisation ci-dessous, mais en vrai il faut accéder aux stations du problème.
	std::vector<Station> stations = std::vector<Station>();

	//Debut algo
	std::vector<int> firstSolution;
	for (Station s : stations) {
		firstSolution.push_back((int)getRandProba(0, s.getBikeStands()));
	}

	return firstSolution;
	
}

double RecuitVLS::getValue(std::vector<int> solution) {
	//TODO : Il faut la valeur de la fonction objectif
}

double RecuitVLS::changeTemp() {

	temp *= coefDiminutionTemp;
}
