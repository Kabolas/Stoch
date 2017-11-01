#include "RecuitVLS.h"
#include "Station.h"

using namespace Project2;
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


System::Collections::ArrayList^ RecuitVLS::getVicinity(System::Collections::ArrayList^ solution) {
	//TODO : J''ai besoin d'accéder à chaque station pour avoir leur place
	//On a mis temporairement une initialisation ci-dessous, mais en vrai il faut accéder aux stations du problème.
	System::Collections::ArrayList^ stations = gcnew System::Collections::ArrayList();

	//Debut algo
	System::Collections::ArrayList^ newSolution = gcnew System::Collections::ArrayList();

	for (int i = 0; i < solution->Count; i++) {
		newSolution->Add(solution[i]);
	}


	int stationToChange = (int)getRandProba(0, (double)solution->Count);
	newSolution[stationToChange] = (int)getRandProba(0, ((Station^)stations[stationToChange])->getBikeStands());
	return newSolution;
}

System::Collections::ArrayList^ RecuitVLS::generateFirstSolution() {
	//TODO : J''ai besoin d'accéder à chaque station pour avoir leur place
	//On a mis temporairement une initialisation ci-dessous, mais en vrai il faut accéder aux stations du problème.
	System::Collections::ArrayList^ stations = gcnew System::Collections::ArrayList();

	//Debut algo
	System::Collections::ArrayList^ firstSolution = gcnew System::Collections::ArrayList();
	for each(Station s in stations) {
		firstSolution->Add((int)getRandProba(0, s.getBikeStands()));
	}

	return firstSolution;
	
}

double RecuitVLS::getValue(System::Collections::ArrayList^ solution) {
	//TODO : Il faut la valeur de la fonction objectif
}

double RecuitVLS::changeTemp() {
	return temp * coefDiminutionTemp;
}
