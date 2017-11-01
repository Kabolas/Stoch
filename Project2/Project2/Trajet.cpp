#include "Trajet.h"

int Trajet::getIdDepart() const
{
	return id_depart;
}

int const Trajet::getIdArrv() { return id_arrv; }

int const Trajet::getDemande() { return demande; }

int const Trajet::getOffre() { return offre; }

void Trajet::setIdDepart(int dep) { id_depart = dep; }

void Trajet::setIdArriv(int arrv) { id_arrv = arrv; }

void Trajet::setDemande(int dem) { demande = dem; }

void Trajet::setOffre(int off) { offre = off; }
