#pragma once

#include <vector>
#include <random>

namespace Project2 {
#define TEMPERATURE_INITIALE 1000;
	public ref class Recuit
	{

	protected:
		double tempInitiale;
		double temp;
		System::Collections::ArrayList^ bestSolution;
		double minValue;
		int nIteration;
		int nPallier;


	public:
		Recuit();
		Recuit(double tInitiale, int nIter, int nPallier);
		~Recuit();

		virtual System::Collections::ArrayList^ getVicinity(System::Collections::ArrayList^ solution) = 0;
		virtual System::Collections::ArrayList^ generateFirstSolution() = 0;
		virtual double getValue(System::Collections::ArrayList^ solution) = 0;
		virtual double changeTemp() = 0;
		void algo();
		System::Collections::ArrayList^ getBestSolution();
		double getMinValue();
		double getRandProba(double min, double max);

	};
}

