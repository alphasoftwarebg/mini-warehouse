																			 /*
-------- Store.cpp ------------------------------------------------------------

		Copyright © 2018 ZZZ Ltd. - Bulgaria. All rights reserved.
-------------------------------------------------------------------------------
																			 */
#ifdef _WIN32
#include <windows.h>
#include <tchar.h>
#endif
#include <string>
#include <iostream>
#include <sstream>
#include <math.h>			// fabs
#include "Store.h"
#include "Tools.h"
#include "../include/ZZZConsole.h"


using namespace std;
using namespace ZzzBase;
using namespace ZzzKernel;


const string REPORTS_BASE = "Reports.zzz";
const bool GLOBAL = true;
const bool LOCAL = false;
const double EPSILON = 0.0000001;



Store::Store()
{
    Init();
}
Store::~Store()
{
    Clean();
}

bool Store::Add(
	string const& barcode,
	string const& name,
	string const& measure,
	string const& quantity,
	string const& price)
{
	long long int id = zzz->BeginWriteProcess("", "");
	try
	{
		if(zzz->MoveToElementByPath(id, path("/items/barcode/"+barcode), GLOBAL) == false)
		{
			double addQuantity = ToDouble(quantity);
			double addPrice = ToDouble(price);
			double newPrice = addQuantity * addPrice;

			zzz->AddElementByPath(id, path("/items/barcode/"+barcode+"/name/"+name), GLOBAL);
			zzz->AddElementByPath(id, path("/items/barcode/"+barcode+"/measure/"+measure), GLOBAL);
			zzz->AddElementByPath(id, path("/items/barcode/"+barcode+"/quantity/"+quantity), GLOBAL);
			zzz->AddElementByPath(id, path("/items/barcode/"+barcode+"/price/"+ToString(newPrice)), GLOBAL);
		}
		else
		{
			if(zzz->GetElementByPath(id, path("/items/barcode/"+barcode+"/name/"), GLOBAL).compare(name) != 0)
			{
				if(zzz->MoveToElementByPath(id, path("/items/barcode/"+barcode+"/name"), GLOBAL))
				{
					zzz->RemoveElement(id);
					zzz->AddElementByPath(id, path("/items/barcode/"+barcode+"/name/"+name), GLOBAL);
				}
			}
			double oldQuantity = ToDouble(zzz->GetElementByPath(id, path("/items/barcode/"+barcode+"/quantity/"), GLOBAL));
			double addQuantity = ToDouble(quantity);
			double oldPrice = ToDouble(zzz->GetElementByPath(id, path("/items/barcode/"+barcode+"/price/"), GLOBAL));
			double addPrice = ToDouble(price);

			double newQuantity = oldQuantity + addQuantity;
			double newPrice = oldPrice + addQuantity * addPrice;

			if(zzz->MoveToElementByPath(id, path("/items/barcode/"+barcode+"/quantity"), GLOBAL))
			{
				zzz->RemoveElement(id);
			}
			zzz->AddElementByPath(id, path("/items/barcode/"+barcode+"/quantity/"+ToString(newQuantity)), GLOBAL);
			if(zzz->MoveToElementByPath(id, path("/items/barcode/"+barcode+"/price"), GLOBAL))
			{
				zzz->RemoveElement(id);
			}
			zzz->AddElementByPath(id, path("/items/barcode/"+barcode+"/price/"), GLOBAL);
			zzz->ChangeElement(id, ToString(newPrice));
		}
		zzz->EndProcess(id);
	}
	catch(exception& ex)
	{
		zzz->BreakWriteProcess();

		throw runtime_error(ex.what());
	}
	return true;
}

bool Store::Get(
	string const& barcode,
	string const& quantity)
{
	bool result = false;

	long long int id = zzz->BeginWriteProcess("", "");
	try
	{
		if(zzz->MoveToElementByPath(id, path("/items/barcode/"+barcode), GLOBAL))
		{
			double oldQuantity = ToDouble(zzz->GetElementByPath(id, path("/items/barcode/"+barcode+"/quantity/"), GLOBAL));
			double getQuantity = ToDouble(quantity);

			double newQuantity = oldQuantity - getQuantity;
			if(fabs(newQuantity) < EPSILON)
			{
				newQuantity = 0;
			}
			else if(newQuantity < 0)
			{
				stringstream ss;
				ss << "No enough quantity!" << endl;
				ss << "Store quantity is " << oldQuantity << endl;
				ss << "Requested quantity is " << getQuantity << endl;

				throw runtime_error(ss.str());
			}

			double oldPrice = ToDouble(zzz->GetElementByPath(id, path("/items/barcode/"+barcode+"/price/"), GLOBAL));
			double newPrice = oldPrice - (oldPrice / oldQuantity) * getQuantity;
			if(zzz->MoveToElementByPath(id, path("/items/barcode/"+barcode+"/quantity"), GLOBAL))
			{
				zzz->RemoveElement(id);
			}
			zzz->AddElementByPath(id, path("/items/barcode/"+barcode+"/quantity/"+ToString(newQuantity)), GLOBAL);
			if(zzz->MoveToElementByPath(id, path("/items/barcode/"+barcode+"/price"), GLOBAL))
			{
				zzz->RemoveElement(id);
			}
			zzz->AddElementByPath(id, path("/items/barcode/"+barcode+"/price/"+ToString(newPrice)), GLOBAL);

			result = true;
		}
		zzz->EndProcess(id);
	}
	catch(exception& ex)
	{
		zzz->BreakWriteProcess();

		throw runtime_error(ex.what());
	}
	return result;
}

bool Store::Report(string barcode)
{
	bool result = false;

	long long int id = zzz->BeginReadProcess("", "");
	try
	{
		if(barcode.compare("all") == 0)
		{
			if(zzz->MoveToElementByPath(id, path("/items/barcode/"), GLOBAL))
			{
				if(zzz->MoveToFirstElement(id))
				{
					do
					{
						string currentPath = zzz->MakePathToElement(id, true);

						Store::Report(zzz->GetElement(id));

						zzz->MoveToElementByPath(id, currentPath, GLOBAL);
					}
					while(zzz->MoveToNextElement(id));
				}
			}
			result = true;
		}
		else
		{
			if(zzz->MoveToElementByPath(id, path("/items/barcode/"+barcode+"/"), GLOBAL))
			{
				string name = zzz->GetElementByPath(id, path("name/"), LOCAL);
				string measure = zzz->GetElementByPath(id, path("measure/"), LOCAL);
				string quantity = zzz->GetElementByPath(id, path("quantity/"), LOCAL);
				string price = zzz->GetElementByPath(id, path("price/"), LOCAL);

				double quantityValue = ToDouble(quantity);
				double priceValue = ToDouble(price) / quantityValue;
				printf("%s, %s, %s, %0.2lf, %0.2lf\n", barcode.c_str(),
					name.c_str(), measure.c_str(), quantityValue, priceValue);

				result = true;
			}
		}
		zzz->EndProcess(id);
	}
	catch(exception& ex)
	{
		zzz->EndProcess(id);

		throw runtime_error(ex.what());
	}
	return result;
}

void Store::Init()
{
	divider = "/";

	zzz = new ZZZBaseMini();
	zzz->Open(STORE_BASE+"1", STORE_BASE+"2");

	#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
	#endif
}
void Store::Clean()
{
	zzz->Close();
	delete zzz;
	zzz = NULL;
}


bool Store::CommandLine(vector<string> arguments)
{
	bool result = false;

	if(arguments.size() > 0)
	{
		if(arguments[0].compare("addStock") == 0)
		{
			if(arguments.size() == 6)
			{
				string barcode = arguments[1];
				string name = arguments[2];
				string measure = arguments[3];
				string quantity = arguments[4];
				string price = arguments[5];

				result = Add(barcode, name, measure, quantity, price);
			}
		}
		else if(arguments[0].compare("getStock") == 0)
		{
			if(arguments.size() == 3)
			{
				string barcode = arguments[1];
				string quantity = arguments[2];
				result = Get(barcode, quantity);
			}
		}
		else if(arguments[0].compare("report") == 0)
		{
			zzz->Remove(REPORTS_BASE+"1");
			zzz->Remove(REPORTS_BASE+"2");
			{
				ZZZBaseMini zzzReports(REPORTS_BASE+"1", REPORTS_BASE+"2");
				for(size_t i=1; i<arguments.size(); i++)
				{
					string barcode = arguments[i];
					long long int id = zzzReports.BeginWriteProcess("", "");
					try
					{
						if(zzzReports.MoveToElement(id, barcode) == false)
						{
							if(zzzReports.AddElement(id, barcode))
							{
								result = Report(barcode);
							}
							if(result == false)
								break;
						}
						zzzReports.EndProcess(id);
					}
					catch(exception& ex)
					{
						zzzReports.BreakWriteProcess();

						throw runtime_error(ex.what());
					}
				}
			}
			zzz->Remove(REPORTS_BASE+"1");
			zzz->Remove(REPORTS_BASE+"2");
		}
	}
	return result;
}

string Store::path(string const& dividerPath)
{
	return zzz->DividerPathToPath(dividerPath, divider);
}
