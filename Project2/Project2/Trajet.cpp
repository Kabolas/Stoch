#include "Trajet.h"
using namespace Project2;
Trajet::Trajet(int idepart, int idarr, int demand, int offre)
{
	id_arrv = idarr;
	id_depart = idepart;
	demande = demand;
	this->offre = offre;
}
int const Trajet::getIdDepart() { return id_depart; }

int const Trajet::getIdArrv() { return id_arrv; }

int const Trajet::getDemande() { return demande; }

int const Trajet::getOffre() { return offre; }

void Trajet::setIdDepart(int dep) { id_depart = dep; }

void Trajet::setIdArriv(int arrv) { id_arrv = arrv; }

void Trajet::setDemande(int dem) { demande = dem; }

void Trajet::setOffre(int off) { offre = off; }

System::String ^ Project2::Trajet::ToString() { return "station " + id_depart + "->" + " Demande :" + demande + " -> station " + id_arrv; }
