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
	cMember(int fLeng, vector<int> fOm, vector<int> OP) {
		fLengeth = fLeng;
		fOrder = fOm;
		OrderPosibilities = OP;
	}

	cMember(const cMember& rhs) {
		fLengeth = rhs.fLengeth;
		fOrder = rhs.fOrder;
		OrderPosibilities = rhs.OrderPosibilities;
	}

	int fId;
	float fLengeth;
	vector<int> fOrder;
	vector <int> OrderPosibilities;

	void mSumLength(int **matrix) {
		for (int i = 0; i < fOrder.size() - 1; i++) {
			fLengeth += matrix[fOrder[i]] [fOrder[i+1]];
		}
	}
};