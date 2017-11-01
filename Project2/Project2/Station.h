#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <ctime>


class Station
{
	public:
		Station(int nid,int c_id, std::string c_contract_name,std::string c_name, std::string c_address, double c_lat, double c_lng, bool c_banking, bool c_bonus, bool c_status, int c_bike_stands, int c_available_bike_stands,int c_available_bikes, std::time_t c_last_update);
		int getId() const;
		int getAvailableBikes() const;
		int getAvailableBikeStands() const;
		int getBikeStands();
		void print();
	private:
		int id;
		int contract_id;
		std::string contract_name;
		std::string name;
		std::string address;
		double lat;
		double lng;
		bool banking;
		bool bonus;
		bool status;
		int bike_stands;
		int available_bike_stands;
		int available_bikes;
		std::time_t last_update;

};