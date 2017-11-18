#include "ProblemVLS.h"
#include "Parsing.h"
#include "Station.h"
#include <algorithm>

using namespace Project2;
/***
	Génère les trajets où il y a une demande.
	Si stochastique est faux, on part sur un problème déterministe,
	i.e la demande pour un certains trajet correspond à available_stands de la station
	sinon on prend dans un intervalle.
	Crée une liste de trajet
***/
void ProblemVLS::generateDemandes(bool stochastique)
{
	if (listeStation->Count > 0)
	{
		int taille = listeStation->Count;
		/* Pour chaque station, on regarde le nb de place disponible
		pour en déduire la demande et créer le trajet*/
		for each(Station^ stat in listeStation)
		{
			int nb_demand = stochastique ? (int)getRandProba(0.8*stat->getAvailableBikeStands(), 1.2*stat->getAvailableBikeStands()) : stat->getAvailableBikeStands();
			int id_dest; // id de la station d arrivee

			// on crée un trajet pour chaque demande
			for (int i = 1; i < nb_demand; ++i)
			{
				// choix de la station d arrivee
				do
				{
					id_dest = getRandProba(1, taille);
				} while (id_dest == stat->getId() && id_dest > listeStation->Count);

				bool found = false;
				/* s il y a deja un trajet pour la station d arrivee
				 on augmente juste la demande pour celle ci,
				sinon on cree un nouveau trajet */
				/*for each(Trajet^ traj in listeTrajet)
					if ((traj->getIdDepart() == stat->getId()) && (traj->getIdArrv() == id_dest))
					{
						traj->setDemande(traj->getDemande() + 1);
						found = true;
						break;
					}*/

				Trajet ^ trajet = getTrajet(stat->getId(),id_dest);
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
					/*for each(Trajet^ t in listeTrajet) {
						if (t->getIdDepart() == stat->getId() && t->getIdArrv() == id_dest) { has = true; }
					}*/

					if (!has)
					{
						int ofer = getRandProba(0, stat->getAvailableBikes());
						//listeTrajet->Add(gcnew Trajet(stat->getId(), id_dest, b->Next(12), ofer));
						listeTrajet[stat->getId()]->Add(gcnew Trajet(stat->getId(), id_dest,b->Next(12),ofer));
						stat->lessBikes(ofer);
					}
				}
			}
		}
	}
}

void Project2::ProblemVLS::calcul_couts(int s_id, int id_arv)
{
	Station^ st = getStation(s_id);
	if (st != nullptr)
	{
		Trajet^ trj = getTrajet(s_id,id_arv);
		if (trj != nullptr)
		{
			int c_surplus = 0, c_manque = 0;
			c_surplus = st->getAvailableBikes() - trj->getOffre();
			c_manque = trj->getOffre() - st->getAvailableBikes();

			trj->setSurplus(c_surplus > 0 ? c_surplus : 0);
			trj->setManque(c_manque > 0 ? c_manque : 0);
		}
	}
}

ProblemVLS::ProblemVLS()
{
	listeStation = gcnew System::Collections::ArrayList();
	listeTrajet = gcnew System::Collections::Generic::Dictionary<int, System::Collections::ArrayList^ >();
	readTextBike(System::IO::Directory::GetCurrentDirectory() + "\\stations_velib_paris.txt", listeStation);
	for each(Station^ stat in listeStation)
		listeTrajet->Add(stat->getId(), gcnew System::Collections::ArrayList());
}

void Project2::ProblemVLS::randomizeStations()
{
	System::Random^ rand = gcnew System::Random();
	for each(Station^ stat in listeStation)
	{
		stat->setCost(rand->NextDouble() * 75);
		stat->setLessCost(rand->NextDouble() * 75);
		stat->setOverCost(rand->NextDouble() * 75);
	}
}


void ProblemVLS::printStation(int s_id)
{
	//auto it = find_if(listeStation.begin(), listeStation.end(), [&](Station const& s) {return s.getId() == s_id;});
	//if (it != listeStation.end())
	//	it->print();
	//else
	//	std::cout << "Station not found" << std::endl;
}

void ProblemVLS::printAllStations()
{
	//for (std::vector<Station>::iterator i = listeStation.begin(); i != listeStation.end(); ++i)
	//{
	//	Station& s = *i;
	//	s.print();
	//}
}

double ProblemVLS::getRandProba()
{
	System::Random^ rd = gcnew System::Random();
	return rd->NextDouble();
}

int ProblemVLS::getRandProba(int min, int max)
{
	System::Random^ rd = gcnew System::Random();
	double re = max * rd->NextDouble();
	if (re < min)	return min;
	else return re;
}


double ProblemVLS::getValue(System::Collections::ArrayList^ solution) {

	double value = 0;
	for (int i = 0; i < listeStation->Count; i++) {
		value = value + ((Station^)listeStation[i])->getCost()*(int)solution[i];
		int o = ((int)solution[i]) - ((Station^)listeStation[i])->getBikeStands();
		for each(Trajet t in getTrajetsTo(((Station^)listeStation[i]))) {
			o = o - t.getOffre();
			calcul_couts(((Station)listeStation[i]).getId(),t.getIdArrv());
		}
		for each(Trajet t in getTrajetsFrom(((Station)listeStation[i]))) {
			o = o + t.getOffre();
		}
		if (o < 0)
			o = 0;
		value = value + o*((Station)listeStation[i]).getOverCost();
	}
	int cout_manque = 0;
	for each(Station^ stat in listeStation)
	{
		int id_dest_tmp = 0;
		//v_i * I-_i_j_s en recuperant les trajets de destinations
		/*for each(Trajet^ trj in listeTrajet)
		{
			if (trj->getIdDepart() == stat->getId() && trj->getIdArrv() > id_dest_tmp)
			{
				id_dest_tmp = trj->getIdArrv();
				cout_manque += stat->getLessCost()*trj->getManque();
			}
		}*/
		System::Collections::ArrayList ^ al = getTrajetsFromStation(stat->getId());
		for each(Trajet^ trj in al)
			cout_manque += stat->getLessCost()*trj->getManque();
	}
	value += cout_manque;

	return value;
}

System::Collections::ArrayList^ ProblemVLS::getStations()
{
	return listeStation;
}

Station^ Project2::ProblemVLS::getStation(int s_id)
{
	Station^ stPtr = gcnew Station;
	if (s_id  <= listeStation->Count)
	{
		for each(Station^ stat in listeStation)
		{
			if (stat->getId() == s_id)
				return stPtr = stat;
		}
	}
	
	return nullptr;
}

System::Collections::Generic::Dictionary<int, System::Collections::ArrayList^> ^ Project2::ProblemVLS::getTrajets()
{
	return listeTrajet;
}

System::Collections::ArrayList ^ Project2::ProblemVLS::getTrajetsList()
{
	System::Collections::ArrayList ^ allTrajets = gcnew System::Collections::ArrayList();
	for each(Station ^ stat in listeStation)
	{
		System::Collections::ArrayList ^ al = getTrajetsFromStation(stat->getId());
		if (al != nullptr)
		{
			for each(Trajet^ trj in al)
				allTrajets->Add(trj);
		}
	}
	return allTrajets;
}

System::Collections::ArrayList ^ Project2::ProblemVLS::getTrajetsFromStation(int id_depart)
{
	if (listeTrajet->ContainsKey(id_depart))
		return listeTrajet[id_depart];
	return nullptr;
}

Trajet ^ Project2::ProblemVLS::getTrajet(int id_dep, int id_arv)
{
	/*for each(Trajet^ trajet in listeTrajet)
	{
		if (trajet->getIdDepart() == id_dep && trajet->getIdArrv() == id_arv)
			return trj = trajet;
	}*/

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

System::Collections::ArrayList^ ProblemVLS::getTrajetsFrom(Station^ s) {

	System::Collections::ArrayList^ a = gcnew System::Collections::ArrayList();

	/*for each(Trajet^ t in listeTrajet) {
		if (t->getIdDepart() == s->getId()) {
			a->Add(t);
		}
	}*/
	return getTrajetsFromStation(s->getId());
}

System::Collections::ArrayList^ ProblemVLS::getTrajetsTo(Station^ s) {

	System::Collections::ArrayList^ a = gcnew System::Collections::ArrayList();
	/*for each(Trajet^ t in listeTrajet) {
		if (t->getIdArrv() == s->getId()) {
			a->Add(t);
		}
	}*/
	for each(Station ^ stat in listeStation)
	{
		System::Collections::ArrayList^ al = getTrajetsFromStation(stat->getId());
		if ( (stat->getId() != s->getId()) && al != nullptr)
		{
			for each(Trajet ^ t in al)
			{
				if (t->getIdArrv() == s->getId())
					a->Add(t);
			}
		}
	}
	return a;
}
