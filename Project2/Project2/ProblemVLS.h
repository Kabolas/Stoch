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
		void calcul_couts(int s_id, int id_dep);
		double getValue(System::Collections::ArrayList^ solution);
		System::Collections::ArrayList^ getStations();
		Station getStation(int s_id);
		void printStation(int s_id);
		void printAllStations();
	protected:
		System::Collections::ArrayList^ listeStation;
		System::Collections::ArrayList^ listeTrajet;
		double getRandProba();
		int getRandProba(int  min, int max);

	};
}