#pragma once
#include "Recuit.h"
#include "ProblemVLS.h"

#define DIMINUTION_TEMPERATURE 0.7
namespace Project2 {
	public ref class RecuitVLS : public Recuit
	{
	private:
		ProblemVLS ^problem;
		double coefDiminutionTemp;
		int nStations;

	public:
		RecuitVLS(double tInitiale, int nIter, int pallier, ProblemVLS^ prob, int nb_stations);
		RecuitVLS(double tInitiale, int nIter, int pallier, ProblemVLS^ prob, System::Collections::Generic::Dictionary<int, System::Collections::ArrayList^ > ^ listTrajets, int nb_stations);
		~RecuitVLS();

		System::Collections::ArrayList^ getVicinity(System::Collections::ArrayList^ solution) override;
		System::Collections::ArrayList^ generateFirstSolution() override;
		double getValue(System::Collections::ArrayList^ solution) override;
		double getValueWithMalus(System::Collections::ArrayList^ solution, System::Collections::ArrayList^ solToCompare, int kMalus);
		double changeTemp() override;
		void algoWithMalus(System::Collections::ArrayList^ solToCompare, int kMalus);
		ProblemVLS^ getProb();
		void setIter(int nIter);
		String^ afficher() override;
	};
}