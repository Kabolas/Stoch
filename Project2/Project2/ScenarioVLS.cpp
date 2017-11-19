#include "ScenarioVLS.h"


using namespace Project2;

Project2::ScenarioVLS::ScenarioVLS()
{
	for (int i = 0; i < 100;++i)
		listeTrajetScenario->Add(i, gcnew System::Collections::ArrayList());
}

Project2::ScenarioVLS::ScenarioVLS(int nb_stations)
{
	for (int i = 0; i < nb_stations;++i)
		listeTrajetScenario->Add(i, gcnew System::Collections::ArrayList());
}


/**
Genere les ksi de chaque trajet avec la station de depart,
Crée autant de trajets que des places dispo mais entre 80% et 120%
**/
void Project2::ScenarioVLS::generateTrajetsFromStation(Station^ s, int nb_stations)
{
	if (nb_stations > 0)
	{
		int nb_demand = (int)getRandProba(0.8*s->getAvailableBikeStands(), 1.2*s->getAvailableBikeStands());
		int id_dest;

		// on crée un trajet pour chaque demande
		for (int i = 1; i < nb_demand; ++i)
		{
			// choix de la station d arrivee
			do
			{
				id_dest = getRandProba(1, nb_stations);
			} while (id_dest == s->getId() && id_dest > nb_stations);

			bool found = false;
			/* s il y a deja un trajet pour la station d arrivee
			on augmente juste la demande pour celle ci,
			sinon on cree un nouveau trajet */

			Trajet ^ trajet = getTrajet(s->getId(), id_dest);
			if (trajet != nullptr)
			{
				trajet->setDemande(trajet->getDemande() + 1);
				found = true;
				break;
			}

			if (!found)
			{
				System::Random^b = gcnew System::Random();
				bool has = false;

				if (!has)
				{
					int ofer = getRandProba(0, s->getAvailableBikes());
					listeTrajetScenario[s->getId()]->Add(gcnew Trajet(s->getId(), id_dest, b->Next(12), ofer));
					s->lessBikes(ofer); // A VERIFIER
				}
			}
		}
	}
}

/** Genere la demande, tous les trajets pour chaque station 
	et selon le nombre de station entre par l utilisateur **/
void Project2::ScenarioVLS::generateAllTrajets(System::Collections::ArrayList^ listeStations,int nb_stations)
{
	int length = listeStations->Count;
	for (int i = 0; i < nb_stations;++i)
	{
		Station^ stat = (Station^)listeStations[i];
		generateTrajetsFromStation(stat, nb_stations);
	}
}

/** retourne l'arraylist de trajets selon la station de depart **/
System::Collections::ArrayList ^ Project2::ScenarioVLS::getTrajetsFromStation(int id_depart)
{
	if (listeTrajetScenario->ContainsKey(id_depart))
		return listeTrajetScenario[id_depart];
	return nullptr;
}

/* retourne un trajet specifique selon la station de depart et d'arrivee */
Trajet^ Project2::ScenarioVLS::getTrajet(int id_dep, int id_arv)
{

	System::Collections::ArrayList^ al = getTrajetsFromStation(id_dep);
	if (al != nullptr)
	{
		for each(Trajet^ trajet in al)
		{
			if (trajet->getIdArrv() == id_arv)
				return trajet;
		}
	}
	return nullptr;
}

System::Collections::Generic::Dictionary<int, System::Collections::ArrayList^> ^ const Project2::ScenarioVLS::getListeTrajetsSce()
{
	return listeTrajetScenario;
}

double Project2::ScenarioVLS::getRandProba()
{
	System::Random^ rd = gcnew System::Random();
	return rd->NextDouble();
}

int Project2::ScenarioVLS::getRandProba(int min, int max)
{
	System::Random^ rd = gcnew System::Random();
	double re = max * rd->NextDouble();
	if (re < min)	return min;
	else return re;
}
