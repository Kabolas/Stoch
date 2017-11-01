#pragma once
#include "Station.h"
#include "Trajet.h"
#include <random>


namespace Project2 {
	using namespace System;
	public ref class ProblemVLS
	{
	public:
		ProblemVLS();
		void generateDemandes();
		void printStation(int s_id);
		void printAllStations();
	protected:
		Collections::ArrayList listeStation;
		Collections::ArrayList listeTrajet;
		double getRandProba();

	};
}