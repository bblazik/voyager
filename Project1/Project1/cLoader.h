#pragma once
#include <fstream>
#include <iostream>
#include <string>s
using namespace std;

class cLoader
{
public:
	cLoader();
	~cLoader();

	int** mLoadMatrix() {
		std::fstream myfile("D:\\Matrix.txt", std::ios_base::in);
		if (myfile.is_open()) {
			int a = 0;
			myfile >> a;

			int** ary = new int*[a];
			for (int i = 0; i < a; ++i)
				ary[i] = new int[a];

			for (int i = 0; i < a; i++)
				for (int j = 0; j < a; j++)
				{
					myfile >> ary[i][j];
					//cout << ary[i][j]<< endl;
				}

			return ary;
		}
		else { cout << "Unable to open file"; return 0; };
	}
};

