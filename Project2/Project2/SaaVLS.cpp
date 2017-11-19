#include "SaaVLS.h"
#include "RecuitStocha.h"

using namespace Project2;

Project2::SaaVLS::SaaVLS(int nb_sa, int nb_sc, int nbIter, ProblemVLS ^ pb, int nb_st_c): nb_sample(nb_sa), nb_scenario(nb_sc), problem(pb), nb_iter(nbIter), nb_stat_considered(nb_st_c)
{
	bestSolutions = gcnew System::Collections::ArrayList();
	listSolutions = gcnew System::Collections::ArrayList();
	listObjectives = gcnew System::Collections::ArrayList();
	listObjectivesRef = gcnew System::Collections::ArrayList();
	moyenne = 0;
}

/* Determine les solutions et valeurs objectives pour chaque echantillons
    et les stockes dans des listes , puis calcule la moyenne */
void Project2::SaaVLS::generateSampleSolutions()
{
	for (int i = 0;i < nb_sample;++i)
	{
		RecuitStocha^ rec = gcnew RecuitStocha(TEMPERATURE_INITIALE, nb_iter, NB_PALLIER, problem, PENALITE, problem->getStations()->Count, nb_scenario);
		rec->algo(nb_stat_considered);
		listSolutions->Add(rec->getFinalSolutions());;
		listObjectives->Add(problem->getValue(rec->getFinalSolutions()));
	}

	double moy = 0;
	for each(double i in listObjectives)
	{
		double test = (double)i;
		moy += test;
	}
	moyenne = moy/nb_sample;
}

/* retourne les valeurs objectives dans le problem de l'échantillon référent et stocke les valeurs objectives dans une liste */
void Project2::SaaVLS::calculateSampleRef()
{
	sampleRef = gcnew RecuitStocha(TEMPERATURE_INITIALE, nb_iter, NB_PALLIER, problem, PENALITE, problem->getStations()->Count, 20*nb_scenario);
	/* ERREUR , il faudrait calculer la valeur de la fonction objective a partir de chaque solution des echantillons */
	for (int i = 0; i < nb_sample;++i)
	{
		double sol = (double)problem->getValue((System::Collections::ArrayList^)listSolutions[i]);
		listObjectivesRef->Add(sol);
	}
}

/* choisit la valeur objective optimale et sa solution analogue */
void Project2::SaaVLS::chooseMinimum()
{
	double min = (double)listObjectivesRef[0];
	for (int i = 1; i < nb_sample;++i)
	{
		double test = (double)listObjectivesRef[i];
		if (test < min)
		{
			min = test;
			bestSolutions = (System::Collections::ArrayList^)listSolutions[i];
		}
	}
}

/* execute l'algorithme du saa */
void Project2::SaaVLS::algo()
{
	generateSampleSolutions();
	calculateSampleRef();
	chooseMinimum();
}


String ^ Project2::SaaVLS::afficher()
{
	String^ s = "Estimation couts moyens : "+moyenne +"\n\n Solution :\n";
	for (int i = 0; i<bestSolutions->Count; i++) {
		s += "Station " + i + " : " + bestSolutions[i] + " velos.\n";
	}
	return s;
}
