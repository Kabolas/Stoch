#include "ProblemVLS.h"
#include "Parsing.h"
#include <algorithm>

using namespace Project2;
/***
	G�n�re les trajets o� il y a une demande.
	Si stochastique est faux, on part sur un probl�me d�terministe,
	i.e la demande pour un certains trajet correspond � available_stands de la station
	sinon on prend dans un intervalle.
	Cr�e une liste de trajet
***/
void ProblemVLS::generateDemandes(bool stochastique)
{
	if (listeStation->Count > 0)
	{
		int taille = listeStation->Count;
		/* Pour chaque station, on regarde le nb de place disponible
		pour en d�duire la demande et cr�er le trajet*/
		for each(Station^ stat in listeStation)
		{
			int nb_demand = stochastique ? (int)getRandProba(0.8*stat->getAvailableBikeStands(), 1.2*stat->getAvailableBikeStands()) : stat->getAvailableBikeStands();
			int id_dest; // id de la station d arrivee

			// on cr�e un trajet pour chaque demande
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
				on cree un nouveau trajet */
				for each(Trajet^ traj in listeTrajet)
				{
					if ((traj->getIdDepart() == stat->getId()) && (traj->getIdDepart() == id_dest))
					{
						traj->setDemande(traj->getDemande() + 1);
						found = true;
						break;
					}
				}

				if (!found)
					listeTrajet->Add(gcnew Trajet(stat->getId(), id_dest, 1, stat->getAvailableBikes()));
			}
		}
	}
}

ProblemVLS::ProblemVLS() : listeStation(), listeTrajet()
{
	readTextBike("c:\\Users\\Shankar\\Desktop\\stations_velib_paris.txt", listeStation);

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
	System::Random rd;
	return rd.NextDouble();
}

int ProblemVLS::getRandProba(int min, int max)
{
	System::Random rd;
	double re = max * rd.NextDouble();
	if (re < min)	return min;
	else return re;
}