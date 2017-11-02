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
		int const getSurplus();
		int const getManque();
		void setIdDepart(int dep);
		void setIdArriv(int arrv);
		void setDemande(int dem);
		void setOffre(int off);
		void setSurplus();
		void setSurplus(int s);
		void setManque();
		void setManque(int m);
	private:
		int id_depart, id_arrv, demande, offre, cout_manque, cout_surplus;
	};
}