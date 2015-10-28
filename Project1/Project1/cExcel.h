#pragma once
#include "include_cpp\libxl.h"
#include <string>
#include "cMember.h"
using namespace libxl;

class cExcel{
public:

	cExcel() {
		book = xlCreateBook();

		sheet = book->addSheet("Sheet3");
	}
	~cExcel() { book->release(); }

	Book* book;
	Sheet* sheet;
	/*
	void write() {
		Book* book = xlCreateBook(); // xlCreateXMLBook() for xlsx
		if (book)
		{
			Sheet* sheet = book->addSheet("Sheet1");
			if (sheet)
			{
				sheet->writeStr(2, 1, "Hello, World !");
				sheet->writeNum(3, 1, 1000);
			}
			book->save("example.xls");
			book->release();
		}
	}*/

	void WriteHeader() {}
	
	void WriteNextOne(int max, int avg, int min, int i, std::string s) {
		
		//book->load(cokolwiek.xls)
		if (book)
		{
			if (sheet)
			{
				
				sheet->writeNum(i, 1, max);
				sheet->writeNum(i, 2, avg);
				sheet->writeNum(i, 3, min);
				//sheet->writeStr(2, 1, "Hello, World !");
				//sheet->writeNum(3, 1, 1000);

				book->save(s.c_str());
				//book->release();
			}

		}
	}

};