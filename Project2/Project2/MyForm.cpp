#include "MyForm.h"
#include "Parsing.h"
#include "Station.h"

using namespace System;
using namespace System::Windows::Forms;


[STAThreadAttribute]
void Main(array<String^>^ args) 
{
	std::vector<std::string> buf;
	Parser parse;
	/*parse.readFile("c:\\Users\\Shankar\\Desktop\\données_statiques_velib_paris.csv",buf);
	
	for (std::vector<std::string>::const_iterator i = buf.begin(); i != buf.end(); ++i)
		std::cout << *i << ' ' << std::endl;*/
	std::vector<Station> myStations;
	parse.readTextBike("c:\\Users\\Shankar\\Desktop\\stations_velib_paris.txt",myStations);
	
	for (std::vector<Station>::iterator i = myStations.begin(); i != myStations.end(); ++i)
	{
		Station& s = *i;
		s.print();
	}
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Project2::MyForm form;
	Application::Run(%form);

}
