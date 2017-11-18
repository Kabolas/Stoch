#pragma once
#include "Station.h"
#include "Trajet.h"
using namespace System;

namespace Project2 {
		void readTextBike(String^ filePath,Collections::ArrayList^ stList);
		String^ genererInfoMarqueur(Station^ stattion);
		String^ genererInfoLigne(String^ etiquette, int valeur);
		String^ genererPositionsDemandesStochastiques(Station^ stat, System::Collections::ArrayList^ trajs, System::Collections::ArrayList ^stats);
}
