#pragma once


class Trajet
{
	public:
		Trajet(int dep, int arv, int dem);
		Trajet(int dep, int arv, int dem, int offre);
		int getIdDepart() const;
		int getIdArrv() const;
		int getDemande() const;
		int getOffre() const;
		void setIdDepart(int dep);
		void setIdArriv(int arrv);
		void setDemande(int dem);
		void setOffre(int off);
	private:
		int id_depart, id_arrv, demande, offre;
};