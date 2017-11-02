#pragma once
#include "Station.h"
#include "Trajet.h"

#define TEMPERATURE_INITIALE 1000

namespace Project2 {
	public ref class ProblemVLS
	{
	public:
		ProblemVLS();
		void generateDemandes(bool stochastique);
		double getValue(System::Collections::ArrayList^ solution);
		System::Collections::ArrayList^ getStations();
		System::Collections::ArrayList^ getTrajets();
		void printStation(int s_id);
		void printAllStations();
	protected:
		System::Collections::ArrayList^ listeStation;
		System::Collections::ArrayList^ listeTrajet;
		double getRandProba();
		int getRandProba(int  min, int max);

	};
}