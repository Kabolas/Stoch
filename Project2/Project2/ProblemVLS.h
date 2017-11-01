#pragma once
#include "Station.h"
#include "Trajet.h"
#include "RecuitVLS.h"
#include <random>

#define TEMPERATURE_INITIALE 1000

namespace Project2 {
	using namespace System;
	public ref class ProblemVLS
	{
	public:
		ProblemVLS();
		void generateDemandes(bool stochastique = false);
		void printStation(int s_id);
		void printAllStations();
	protected:
		std::vector<Station> listeStation;
		std::vector<Trajet> listeTrajet;
		double getRandProba();
		int getRandProba(int  min, int max);

	};
}