#pragma once


namespace Project2 {
	public value class Trajet
	{
	public:
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
}