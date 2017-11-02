#pragma once
#include <ctime>

namespace Project2 {
	using namespace System;
	public value class Station
	{
	public:
		Station(int nid, int c_id, String^ c_contract_name, String^ c_name, String^ c_address, double c_lat, double c_lng, bool c_banking, bool c_bonus, bool c_status, int c_bike_stands, int c_available_bike_stands, int c_available_bikes, std::time_t c_last_update);
		int const getId();
		int const getAvailableBikes();
		int const getAvailableBikeStands();
		int getBikeStands();
		int getCost();
		void setCost(int c);
		int getLessCost();
		void setLessCost(int lc);
		int getOverCost();
		void setOverCost(int oc);
		void print();
	private:
		int id;
		int contract_id;
		String^ contract_name;
		String^ name;
		String^ address;
		double lat;
		double lng;
		bool banking;
		bool bonus;
		bool status;
		int bike_stands, cost, lesscost, overcost;
		int available_bike_stands;
		int available_bikes;
		std::time_t last_update;

	};
}