#pragma once
#include "include_cpp\libxl.h"
#include <string>
#include "cMember.h"
using namespace libxl;

class cExcel{
public:

	cExcel(std::string name) {
		book = xlCreateBook();
		sheet = book->addSheet("Sheet3");
		this->name = name;
	}
	~cExcel() { book->release(); }

	Book* book;
	Sheet* sheet;
	std::string name;
	
	void WriteNextOne(int max, int avg, int min, int i) {
		if (book)
		{
			if (sheet)
			{
				sheet->writeNum(i, 1, max);
				sheet->writeNum(i, 2, avg);
				sheet->writeNum(i, 3, min);
				book->save(name.c_str());
			}

		}
	}

};