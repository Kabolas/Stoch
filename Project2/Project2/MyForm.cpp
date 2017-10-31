#include "MyForm.h"
#include "Parsing.h"
#include "Station.h"
#include "ProblemVLS.h"
#include <random>

using namespace System;
using namespace System::Windows::Forms;


[STAThreadAttribute]
void Main(array<String^>^ args) 
{
	std::random_device rd;
	std::mt19937 gen(rd());

	std::vector<std::string> buf;
	Parser parse;
	
	ProblemVLS problem;
	problem.printStation(1);
	//problem.printAllStations();
	
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Project2::MyForm form;
	Application::Run(%form);

}
