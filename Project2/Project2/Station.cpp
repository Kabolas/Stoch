#include "Station.h"

using namespace Project2;

Station::Station() :
id(0), contract_id(0), contract_name(""), name(""), address(""),
lat(0.0), lng(0.0), banking(false), bonus(false), status(false),
bike_stands(0), available_bike_stands(0), available_bikes(0),
last_update(0)
{}

Station::Station(int nid, int c_id, String^ c_contract_name, String^ c_name, String^ c_address, double c_lat, double c_lng, bool c_banking, bool c_bonus, bool c_status, int c_bike_stands, int c_available_bike_stands, int c_available_bikes, std::time_t c_last_update) :
	id(nid), contract_id(c_id), contract_name(c_contract_name), name(c_name), address(c_address),
	lat(c_lat), lng(c_lng), banking(c_banking), bonus(c_bonus), status(c_status),
	bike_stands(c_bike_stands), available_bike_stands(c_available_bike_stands), available_bikes(c_available_bikes),
	last_update(c_last_update)
{}

int const Station::getId()
{
	return contract_id;
}
int const Station::getAvailableBikes()
{
	return available_bikes;
}

int const Station::getAvailableBikeStands()
{
	return available_bike_stands;
}

int Station::getBikeStands() {
	return bike_stands;
}

void Project2::Station::setBikeStands(int bs) { bike_stands = bs; }

int Station::getCost() { return cost; }

void Project2::Station::setCost(int c) { cost = c; }

int Project2::Station::getLessCost() { return lesscost; }

void Project2::Station::setLessCost(int lc) { lesscost = lc; }

int Project2::Station::getOverCost() { return overcost; }

void Project2::Station::setOverCost(int oc) { overcost = oc; }

void Station::print()
{
	//std::cout << "Station \n" << "Id: "<< id << std::endl << "Contract id : " << contract_id << std::endl << "Name: " << name << std::endl << "Adresse: " << address << std::endl << "Latitude: " << lat << std::endl << "Longitude: " << lng << std::endl << "Banking terminal: " << banking << std::endl << "Station bonus: " << bonus << std::endl << "Ouvert: " << status << std::endl << "Place pour v�los total: " << bike_stands << std::endl << "places velos disponibles: " << available_bike_stands << std::endl << "Velos disponibles: " << available_bikes << std::endl << "Mise a jour le : " << last_update << std::endl<<std::endl;
}
