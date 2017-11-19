#pragma once
#include "RecuitStocha.h"


namespace Project2
{
	public ref class SaaVLS
	{
	private:
		int nb_sample;
			int nb_scenario;
			int nb_iter;
			float moyenne;
			RecuitStocha^ sampleRef;
			ProblemVLS^ problem;

			System::Collections::ArrayList^ listSolutions;
			System::Collections::ArrayList^ listObjectives;
			System::Collections::ArrayList^ listObjectivesRef;
	public:
		SaaVLS(int nb_sa,int nb_sc, int nbIter, ProblemVLS^ pb);
		void generateSampleSolutions();
		void calculateSampleRef();
		void chooseMinimum();
		String^ afficher();
	};
}