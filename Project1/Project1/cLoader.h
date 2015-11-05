#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <limits.h>
using namespace std;

class cLoader
{
public:
	cLoader();
	cLoader(string s) { name = s; }
	~cLoader();
	int size;
	string name;
	int** mLoadMatrix() {
		std::fstream myfile(name, std::ios_base::in);
		if (myfile.is_open()) {
			
			myfile >> size;

			int** ary = new int*[size];
			for (int i = 0; i < size; ++i)
				ary[i] = new int[size];

			for (int i = 0; i < size; i++)
				for (int j = 0; j < size; j++)
				{	
					myfile >> ary[i][j];
					if(ary[i][j] == -1)
						ary[i][j] = numeric_limits<int>::max();
				}

			return ary;
		}
		else { cout << "Unable to open file"; return 0; };
	}


	float countLenght(float x1, float y1, float x2, float y2) {
		return round(sqrt((pow((x2 - x1), 2) + pow((y2 - y1), 2))));
	}

	void parser(string Input, string Output) {
		std::fstream infile("D:\\" + Input + string(".txt"), std::ios_base::in);
		std::fstream outfile("D:\\" + Output + string(".txt"), std::ios_base::out);
		int ii, x, y;
		string name;
		int Optimumlength;
		int size;

		if (infile.is_open()) {

			infile >> name >> Optimumlength >> size;
			cout << name << " " << Optimumlength << " " << size;
			outfile << size << endl;

			int** ary = new int*[size];
			for (int i = 0; i < size; ++i)
				ary[i] = new int[size];

			for (int i = 0; i < size; i++) {
				infile >> ii >> x >> y;
				ary[i][0] = x;
				ary[i][1] = y;
			}


			for (int i = 0; i < size; i++) {
				for (int j = 0; j < size; j++) {
					outfile << countLenght(ary[i][0], ary[i][1], ary[j][0], ary[j][1]) << " ";
				}
				outfile << endl;
			}

		}
		else { cout << "Unable to open file"; };
	}
};

