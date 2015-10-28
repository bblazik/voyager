#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class cMember
{
public:
	cMember();
	cMember(int tId, int s);
	~cMember();

	int fId;
	float fLengeth;
	vector<int> fOrder;
	vector <int> OrderPosibilities;

	void mSumLength(int **matrix) {


		for (int i = 0; i < fOrder.size() - 1; i++) {
			fLengeth += matrix[fOrder[i]] [fOrder[i+1]];
			//cout << "length: " << matrix[fOrder[i]][fOrder[i + 1]] << "i: " << fOrder[i] <<" i+1: "<<fOrder[i+1] << endl;
		}
		//cout << "\n All: " << fLengeth << endl;
	}
};