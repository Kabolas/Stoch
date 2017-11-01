#include "Parsing.h"
#include <algorithm>
#include <ctime>

using namespace Project2;

void Project2::readTextBike(String^ filePath, Collections::ArrayList^ stList)
{
		
	String^ buf_name = "", ^buf_address = "", ^buf_contract_name = "";
	int buf_c_id = 0, buf_bike_stands = 0, buf_available_bike_stands = 0, buf_available_bikes = 0;
	bool buf_banking = false, buf_bonus = false, buf_status = false;
	double buf_lat = 0.0, buf_lng = 0.0;
	std::time_t buf_last_update = 0;
	int id_count = 0;

	for each(String^ str in System::IO::File::ReadAllLines(filePath))
	{
		if (str->Contains("\"number\":"))
			buf_c_id = int::Parse(str->Replace(",", "")->Split(':')[1]);
		else if (str->Contains("\"name\":"))
			buf_name = str->Replace(",", "")->Split(':')[1]->Replace("\"", "");
		else if (str->Contains("\"address\":"))
			buf_address = str->Replace(",", "")->Split(':')[1]->Replace("\"", "");
		else if (str->Contains("\"lat\":"))
			buf_lat = double::Parse(str->Replace(",", "")->Split('"')[1]);
		else if (str->Contains("\"lng\":"))
			buf_lng = double::Parse(str->Replace(",", "")->Split('"')[1]);
		else if (str->Contains("\"banking\":"))
			buf_banking = str->Replace(",", "")->Split(':')[1]->Contains("true") ? true : false;
		else if (str->Contains("\"bonus\":"))
			buf_bonus = str->Replace(",", "")->Split(':')[1]->Contains("true") == 0 ? true : false;
		else if (str->Contains("\"status\":"))
			buf_status = str->Replace(",", "")->Split(':')[1]->Contains("OPEN") == 0 ? true : false;
		else if (str->Contains("\"contract_name\":"))
			buf_contract_name = str->Replace(",", "")->Split(':')[1];
		else if (str->Contains("\"bike_stands\":"))
			buf_bike_stands = int::Parse(str->Replace(",", "")->Split(':')[1]);
		else if (str->Contains("\"available_bike_stands\":"))
			buf_available_bike_stands = int::Parse(str->Replace(",", "")->Split(':')[1]);
		else if (str->Contains("\"available_bikes\":"))
			buf_available_bikes = int::Parse(str->Replace(",", "")->Split(':')[1]);
		else if (str->Contains("\"last_update\":"))
		{
			buf_last_update = Convert::ToInt32(str->Replace(",", "")->Split(':')[1]);
			stList->Add(gcnew Station(id_count, buf_c_id, buf_contract_name, buf_name, buf_address, buf_lat, buf_lng, buf_banking, buf_bonus, buf_status, buf_bike_stands, buf_available_bike_stands, buf_available_bikes, buf_last_update));
		}

	}
}