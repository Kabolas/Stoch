#include "Parsing.h"
#include <algorithm>
#include <ctime>


bool Parser::readFile(std::string filePath, std::vector<std::string>& buffer)
{
	std::ifstream infile(filePath, std::ifstream::in);
	if(infile.fail())
	{
		perror(filePath.c_str());
		return false;
	}
	std::string str;

	while (std::getline(infile, str))
	{
		buffer.push_back(str);
	}

	infile.close();

	return true;
}

void Parser::readTextBike(std::string filePath, std::vector<Station>& stList)
{
	std::ifstream infile(filePath, std::ifstream::in);
	if (infile.fail())
	{
		perror(filePath.c_str());
	}
	std::string str, buf;

	std::getline(infile,str,'[');
	std::getline(infile, str);
	
	std::string buf_name = "", buf_address = "", buf_contract_name = "";
	int buf_c_id = 0, buf_bike_stands = 0, buf_available_bike_stands = 0, buf_available_bikes = 0;
	bool buf_banking = false, buf_bonus = false, buf_status = false;
	double buf_lat = 0.0, buf_lng = 0.0;
	std::time_t buf_last_update = 0;


	while (std::getline(infile, str, ','))
	{
		
		//std::cout << "first line : " << str << " done " << std::endl;
		if(str.find("\"number\":")!= std::string::npos)
		{ 
			buf_c_id = std::stoi(str.substr(str.find(":") + 1));
			//std::cout << buf_c_id << ' ' << "done \n" << std::endl;
		}
		else if (str.find("\"name\":") != std::string::npos)
		{
			str.erase(std::remove(str.begin(), str.end(), '\"'),str.end());
			buf_name = str.substr(str.find(":") + 1);
			//std::cout << buf_name << ' ' << "done \n" << std::endl;
		}

		else if (str.find("\"address\":") != std::string::npos)
		{
			str.erase(std::remove(str.begin(), str.end(), '\"'),str.end());
			buf_address = str.substr(str.find(":") + 1);
			//std::cout << str.substr(str.find(":") + 1) << ' ' << "done \n" << std::endl;
		}

		else if (str.find("\"lat\":") != std::string::npos)
		{
			buf_lat = std::stod(str.substr(str.find("lat\":") + 5));
			//std::cout << buf_lat << ' ' << "done \n" << std::endl;
		}

		else if (str.find("\"lng\":") != std::string::npos)
		{
			str.erase(std::remove(str.begin(), str.end(), '}'), str.end());
			buf_lng = std::stod(str.substr(str.find(":") + 1));
			//std::cout << buf_lng << ' ' << "done \n" << std::endl;
		}
		else if (str.find("\"banking\":") != std::string::npos)
		{
			str.erase(std::remove(str.begin(), str.end(), ' '), str.end());
			buf_banking = str.substr(str.find(":") + 1).compare("true") == 0 ? true : false;
			//std::cout << buf_banking << ' ' << "done \n" << std::endl;
		}
		else if (str.find("\"bonus\":") != std::string::npos)
		{
			str.erase(std::remove(str.begin(), str.end(), ' '), str.end());
			buf_bonus = str.substr(str.find(":") + 1).compare("true") == 0 ? true : false;
			//std::cout << str.substr(str.find(":") + 1) << ' ' << "done \n" << std::endl;
		}
		else if (str.find("\"status\":") != std::string::npos)
		{
			str.erase(std::remove(str.begin(), str.end(), '\"'), str.end());
			str.erase(std::remove(str.begin(), str.end(), ' '), str.end());
			buf_status = str.substr(str.find(":") + 1).compare("OPEN") == 0 ? true : false;
			//std::cout << buf_status << ' ' << "done \n" << std::endl;
		}
		else if (str.find("\"contract_name\":") != std::string::npos)
		{
			str.erase(std::remove(str.begin(), str.end(), '\"'), str.end());
			buf_contract_name = str.substr(str.find(":") + 1);
			//std::cout << buf_contract_name << ' ' << "done \n" << std::endl;
		}
		else if (str.find("\"bike_stands\":") != std::string::npos)
		{
			buf_bike_stands = std::stoi(str.substr(str.find(":") + 1));
			//std::cout << buf_bike_stands << ' ' << "done \n" << std::endl;
		}
		else if (str.find("\"available_bike_stands\":") != std::string::npos)
		{
			buf_available_bike_stands = std::stoi(str.substr(str.find(":") + 1));
			//std::cout << buf_available_bike_stands << ' ' << "done \n" << std::endl;
		}
		else if (str.find("\"available_bikes\":") != std::string::npos)
		{
			buf_available_bikes = std::stoi(str.substr(str.find(":") + 1));
			//std::cout << buf_available_bikes << ' ' << "done \n" << std::endl;
		}
		else if (str.find("\"last_update\":") != std::string::npos)
		{
			str.erase(std::remove(str.begin(), str.end(), ' '));
			str.erase(std::remove(str.begin(), str.end(), '}'));
			buf_last_update = std::atoi(str.substr(str.find(":") + 1).c_str());
			//std::cout << buf_last_update << ' ' << "done \n" << "END" <<std::endl;

			Station st(buf_c_id,buf_contract_name,buf_name,buf_address,buf_lat,buf_lng,buf_banking,buf_bonus,buf_status,buf_bike_stands,buf_available_bike_stands,buf_available_bikes,buf_last_update);
			//st.print();
			stList.push_back(st);
		}
	}
}