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
		void calcul_couts(int s_id, int id_arv);

		double getValue(System::Collections::ArrayList^ solution);
		System::Collections::ArrayList^ getStations();
		Station^ getStation(int s_id);
		System::Collections::Generic::Dictionary<int,System::Collections::ArrayList^>^ getTrajets();
		System::Collections::ArrayList ^ getTrajetsList();
		System::Collections::ArrayList ^ getTrajetsFromStation(int id_depart);
		Trajet^ getTrajet(int id_dep,int id_arv);
		void randomizeStations();
		void printStation(int s_id);
		void printAllStations();
		System::Collections::ArrayList^ getTrajetsFrom(Station^ s);
		System::Collections::ArrayList^ getTrajetsTo(Station^ s);
		void setTrajets(System::Collections::Generic::Dictionary<int, System::Collections::ArrayList^ >^ newTrajets);
		
	protected:
		System::Collections::ArrayList^ listeStation;
		//System::Collections::ArrayList^ listeTrajet;
		System::Collections::Generic::Dictionary<int, System::Collections::ArrayList^ >^ listeTrajet;
		double getRandProba();
		int getRandProba(int  min, int max);

	};
}