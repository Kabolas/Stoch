#pragma once
#include "Station.h"
#include "Trajet.h"

namespace Project2
{
	public ref class ScenarioVLS
	{
	private:
		System::Collections::Generic::Dictionary<int, System::Collections::ArrayList^ > ^ listeTrajetScenario;
	public:
		ScenarioVLS();
		ScenarioVLS(int nb_stations);
		void generateTrajetsFromStation(Station^ s, int nb_stations);
		void generateAllTrajets(System::Collections::ArrayList^ listeStations, int nb_stations);
		System::Collections::ArrayList ^ getTrajetsFromStation(int id_depart);
		Trajet^ getTrajet(int id_dep, int id_arv);
		System::Collections::Generic::Dictionary<int, System::Collections::ArrayList^ > ^ const getListeTrajetsSce();
		double getRandProba();
		int getRandProba(int  min, int max);
	};
}