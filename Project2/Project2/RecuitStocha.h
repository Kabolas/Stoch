#pragma once

#include "RecuitVLS.h"
#include "ScenarioVLS.h"

#define PENALITE 400
#define NB_SCENARIO 20
namespace Project2 {
	public ref class RecuitStocha
	{
	public:
		RecuitStocha(double tInitiale, int nIter, int pallier, ProblemVLS^ prob, int pena, int nbStations, int nbScenarios);
		~RecuitStocha();
		void algo();
		double getFinalValue();
		System::Collections::ArrayList ^ getFinalSolutions();
		bool solutionsAreEquals(System::Collections::ArrayList ^ sol1, System::Collections::ArrayList ^ sol2);
		System::Collections::ArrayList ^ addVectors(System::Collections::ArrayList ^ v1, System::Collections::ArrayList ^ v2);
		String^ afficher();
	private:
		System::Collections::ArrayList^ scenarios;
		int penalite;
		int finalValue;
		System::Collections::ArrayList^ finalSolutions;
	};
}