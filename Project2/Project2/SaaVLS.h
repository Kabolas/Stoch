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
			int nb_stat_considered;
			float moyenne;
			RecuitStocha^ sampleRef;
			ProblemVLS^ problem;

			System::Collections::ArrayList^ bestSolutions;
			System::Collections::ArrayList^ listSolutions;
			System::Collections::ArrayList^ listObjectives;
			System::Collections::ArrayList^ listObjectivesRef;
	public:
		SaaVLS(int nb_sa,int nb_sc, int nbIter, ProblemVLS^ pb,int nb_st_c);
		void generateSampleSolutions();
		void calculateSampleRef();
		void chooseMinimum();
		void algo();
		String^ afficher();
	};
}