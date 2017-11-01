#include "ProblemVLS.h"
#include "Parsing.h"
#include <algorithm>

using namespace Project2;
void ProblemVLS::generateDemandes(bool stochastique)
{
	if (listeStation->Count > 0)
	{
		int taille = listeStation->Count;
		for each(Station^ stat in listeStation)
		{
			int nb_demand = stochastique ? (int)getRandProba(0.8*stat->getAvailableBikeStands(), 1.2*stat->getAvailableBikeStands()) : stat->getAvailableBikeStands();
			int id_dest;
			for (int i = 1; i < nb_demand; ++i)
			{
				do
				{
					id_dest = getRandProba(1, taille);
				} while (id_dest == stat->getId());
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
