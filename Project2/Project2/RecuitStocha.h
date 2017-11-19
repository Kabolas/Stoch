#pragma once

#include "RecuitVLS.h"
#include "Scenario.h"

#define PENALITE 400
namespace Project2 {
	public ref class RecuitStocha
	{
	public:
		RecuitStocha(double tInitiale, int nIter, int pallier, ProblemVLS^ prob, System::Collections::ArrayList^ scenar, int pena);
		~RecuitStocha();
		void algo();
		double getFinalValue();
		System::Collections::ArrayList ^ getFinalSolutions();
		bool solutionsAreEquals(System::Collections::ArrayList ^ sol1, System::Collections::ArrayList ^ sol2);
		System::Collections::ArrayList ^ addVectors(System::Collections::ArrayList ^ v1, System::Collections::ArrayList ^ v2);
	private:
		System::Collections::ArrayList^ scenarios;
		int penalite;
		int finalValue;
		System::Collections::ArrayList^ finalSolutions;
	};
}