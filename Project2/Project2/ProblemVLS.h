#pragma once
#include "Station.h"
#include "Trajet.h"
#include <random>
#include <vector>


class ProblemVLS
{
	public:
		ProblemVLS();
		void generateDemandes();
		void printStation(int s_id);
		void printAllStations();
	protected:
		std::vector<Station> listeStation;
		std::vector<Trajet> listeTrajet;
		double getRandProba();

};