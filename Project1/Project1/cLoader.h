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
	int size;

	int** mLoadMatrix() {
		std::fstream myfile("D:\\Matrix.txt", std::ios_base::in);
		if (myfile.is_open()) {
			
			myfile >> size;

			int** ary = new int*[size];
			for (int i = 0; i < size; ++i)
				ary[i] = new int[size];

			for (int i = 0; i < size; i++)
				for (int j = 0; j < size; j++)
				{	
					myfile >> ary[i][j];
					if(ary[i][j] == 0)
						ary[i][j] = numeric_limits<int>::infinity();
					
					//@TEST cout << ary[i][j]<< endl;
				}

			return ary;
		}
		else { cout << "Unable to open file"; return 0; };
	}
};

