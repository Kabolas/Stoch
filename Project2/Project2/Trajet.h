#pragma once


namespace Project2 {
	public value class Trajet
	{
	public:
		Trajet(int idepart, int idarr, int demand, int offre);
		int const getIdDepart();
		int const getIdArrv();
		int const getDemande();
		int const getOffre();
		void setIdDepart(int dep);
		void setIdArriv(int arrv);
		void setDemande(int dem);
		void setOffre(int off);
	private:
		int id_depart, id_arrv, demande, offre;
	};
}