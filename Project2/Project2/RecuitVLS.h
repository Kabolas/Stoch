#pragma once
#include "Recuit.h"
#include "ProblemVLS.h"

#define DIMINUTION_TEMPERATURE 0.95
namespace Project2 {
	public ref class RecuitVLS : public Recuit
	{

	private:
		double coefDiminutionTemp;
		ProblemVLS problem;

	public:
		RecuitVLS(double tInitiale, int nIter, int pallier);
		~RecuitVLS();

		System::Collections::ArrayList^ getVicinity(System::Collections::ArrayList^ solution) override;
		System::Collections::ArrayList^ generateFirstSolution() override;
		double getValue(System::Collections::ArrayList^ solution) override;
		double changeTemp() override;
	};
}

