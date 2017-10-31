#include "Trajet.h"

int Trajet::getIdDepart() const
{
	return id_depart;
}

int Trajet::getIdArrv() const
{
	return id_arrv;
}

int Trajet::getDemande() const
{
	return demande;
}

int Trajet::getOffre() const
{
	return offre;
}

void Trajet::setIdDepart(int dep)
{
	id_depart = dep;
}

void Trajet::setIdArriv(int arrv)
{
	id_arrv = arrv;
}

void Trajet::setDemande(int dem)
{
	demande = dem;
}

void Trajet::setOffre(int off)
{
	offre = off;
}
