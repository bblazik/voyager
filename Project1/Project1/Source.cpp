#pragma once
#include "cMember.h"
#include "Population.h"
#include <iostream>
#include "cLoader.h"

using namespace std;

void TestMatrix(int s, int **matrix) {

	for (int i = 0; i < s; i++)
		for (int j = 0; j < s; j++)
			cout << matrix[i][j] << endl;
}


int main() {

	cLoader load;
	Population pop;

	pop.fRefMatrix = load.mLoadMatrix();
	//TestMatrix(4, pop.fRefMatrix);
	//load.mLoadMatrix();
	system("pause");
}

