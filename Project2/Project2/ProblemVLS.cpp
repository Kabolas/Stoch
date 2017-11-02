#include "ProblemVLS.h"
#include "Parsing.h"
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
				} while (id_dest == stat->getId());

				bool found = false;
				/* s il y a deja un trajet pour la station d arrivee
				 on augmente juste la demande pour celle ci,
				sinon on cree un nouveau trajet */
				for each(Trajet^ traj in listeTrajet)
					if ((traj->getIdDepart() == stat->getId()) && (traj->getIdDepart() == id_dest))
					{
						traj->setDemande(traj->getDemande() + 1);
						found = true;
						break;
					}

				if (!found)
					listeTrajet->Add(gcnew Trajet(stat->getId(), id_dest, 1, getRandProba(1,stat->getAvailableBikes()) ));
			}
		}
	}
}

void Project2::ProblemVLS::calcul_couts(int s_id, int id_dep)
{
	Station^ st = getStation(s_id);
	if (!st->getId())
	{
		
	}
	throw gcnew System::NotImplementedException();
}

ProblemVLS::ProblemVLS() {
	listeStation = gcnew System::Collections::ArrayList();
	listeTrajet = gcnew System::Collections::ArrayList(); 
	readTextBike(System::IO::Directory::GetCurrentDirectory() + "\\stations_velib_paris.txt", listeStation);
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
	//TODO
	return 0.0;
}

System::Collections::ArrayList^ ProblemVLS::getStations()
{
	return listeStation;
}

Station^ Project2::ProblemVLS::getStation(int s_id)
{
	Station^ stPtr = gcnew Station;
	if (s_id  <= listeStation->FixedSize)
	{
		for each(Station^ stat in listeStation)
		{
			if (stat->getId() == s_id)
				return stPtr = stat;
		}
	}
	
	return nullptr;
}
