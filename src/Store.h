																			 /*
-------- Store.h --------------------------------------------------------------

	ZZZ Base Mini sample warehouse program

-------- © 2019 ZZZ Ltd. - Bulgaria -------------------------------------------
																			 */
#pragma once

#include <string>
#include <vector>
#include "../include/ZZZBaseMini.h"


const std::string STORE_BASE = "Store.zzz";


class Store
{
public:
	Store();
	virtual ~Store();

	virtual bool Add(
		std::string const& barcode,
		std::string const& name,
		std::string const& measure,
		std::string const& quantity,
		std::string const& price);

	virtual bool Get(
		std::string const& barcode,
		std::string const& quantity);

	virtual bool Report(std::string barcode);

	bool CommandLine(std::vector<std::string> arguments);

protected:
	ZzzBase::ZZZBaseMini* zzz;
	std::string divider;

	void Init();
	void Clean();
	std::string path(std::string const& dividerPath);
	void setValueByPath(long long int id, std::string const& dividerPath, double const value);
};
