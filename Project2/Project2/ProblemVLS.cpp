#include "ProblemVLS.h"
#include "Parsing.h"
#include <algorithm>

using namespace Project2;
ProblemVLS::ProblemVLS() : listeStation(), listeTrajet() { readTextBike("c:\\Users\\Shankar\\Desktop\\stations_velib_paris.txt", listeStation); }

void ProblemVLS::generateDemandes()
{

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
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<> dis(0.0, 1.0);
	return dis(gen);
}
