#include "ProblemVLS.h"
#include "Parsing.h"
#include <algorithm>


ProblemVLS::ProblemVLS(bool stocha = false) : listeStation(), listeTrajet(), recuitVLS(TEMPERATURE_INITIALE, 10000, 10)
{
	Parser parse;
	parse.readTextBike("c:\\Users\\Shankar\\Desktop\\stations_velib_paris.txt", listeStation);
	generateDemandes(stocha);
}

void ProblemVLS::generateDemandes(bool stochastique = false)
{
	if (!listeStation.empty())
	{
		int taille = listeStation.size();
		for (std::vector<Station>::iterator i = listeStation.begin(); i != listeStation.end(); ++i)
		{
			Station& s = *i;
			int nb_demand = stochastique ? (int)getRandProba(0.8*s.getAvailableBikeStands(),1.2*s.getAvailableBikeStands()) : s.getAvailableBikeStands();
			int id_dest;
			for (int i = 1;i < nb_demand;++i)
			{
				do
				{
					id_dest = getRandProba(1, taille);
				} while (id_dest == s.getId());

				auto it = find_if(listeTrajet.begin(), listeTrajet.end(), [&](Trajet const& t) {return (t.getIdDepart() == s.getId()) && (t.getIdArrv() == id_dest);});

				if (it != listeTrajet.end())
				{
					it->setDemande(it->getDemande()+1);
				}
				else
				{
					Trajet trj(s.getId(), id_dest, 1, s.getAvailableBikes());
					listeTrajet.push_back(trj);
				}

			}
		}
	}
}

void ProblemVLS::printStation(int s_id)
{
	auto it = find_if(listeStation.begin(), listeStation.end(), [&](Station const& s) {return s.getId() == s_id;});
	if (it != listeStation.end())
		it->print();
	else
		std::cout << "Station " << s_id << " not found" << std::endl;
}

void ProblemVLS::printAllStations()
{
	for (std::vector<Station>::iterator i = listeStation.begin(); i != listeStation.end(); ++i)
	{
		Station& s = *i;
		s.print();
	}
}

double ProblemVLS::getRandProba()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<> dis(0.0, 1.0);
	return dis(gen);
}

int ProblemVLS::getRandProba(int min, int max)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<> dis(min, max);
	return dis(gen);
}
