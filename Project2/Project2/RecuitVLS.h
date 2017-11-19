#pragma once
#include "Recuit.h"
#include "ProblemVLS.h"

#define DIMINUTION_TEMPERATURE 0.95
namespace Project2 {
	public ref class RecuitVLS : public Recuit
	{
	private:
		ProblemVLS ^problem;
		double coefDiminutionTemp;
		int nStations;

	public:
		RecuitVLS(double tInitiale, int nIter, int pallier, ProblemVLS^ prob,int nb_stations);
		~RecuitVLS();

		System::Collections::ArrayList^ getVicinity(System::Collections::ArrayList^ solution) override;
		System::Collections::ArrayList^ generateFirstSolution() override;
		double getValue(System::Collections::ArrayList^ solution) override;
		double changeTemp() override;
		ProblemVLS^ getProb();
		void setIter(int nIter);
		String^ afficher() override;
	};
}