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

	void mSumLength(int **matrix) {
		for (int i = 0; i < fOrder.size() - 1; i++) {
			fLengeth += *matrix[fOrder[i], fOrder[i + 1]];
			//cout << "length: " << *fRefMatrix[m.fOrder[i], m.fOrder[i + 1]] << endl;
		}
		//cout << m->fLengeth << endl;
	}
};

