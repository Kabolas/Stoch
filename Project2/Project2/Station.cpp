#include "Station.h"

Station::Station(int c_id, std::string c_contract_name, std::string c_name, std::string c_address, double c_lat, double c_lng, bool c_banking, bool c_bonus, bool c_status, int c_bike_stands, int c_available_bike_stands,int c_available_bikes, std::time_t c_last_update) : 
	contract_id(c_id), contract_name(c_contract_name),name(c_name),address(c_address),
	lat(c_lat),lng(c_lng),banking(c_banking),bonus(c_bonus),status(c_status),
	bike_stands(c_bike_stands),available_bike_stands(c_available_bike_stands),available_bikes(c_available_bikes),
	last_update(c_last_update)
{}

void Station::print()
{
	std::cout << "Station \n" << "Contract id : " << contract_id << std::endl << "Name: " << name << std::endl << "Adresse: " << address << std::endl << "Latitude: " << lat << std::endl << "Longitude: " << lng << std::endl << "Banking terminal: " << banking << std::endl << "Station bonus: " << bonus << std::endl << "Ouvert: " << status << std::endl << "Place pour v�los total: " << bike_stands << std::endl << "places velos disponibles: " << available_bike_stands << std::endl << "Velos disponibles: " << available_bikes << std::endl << "Mise a jour le : " << last_update << std::endl<<std::endl;
}