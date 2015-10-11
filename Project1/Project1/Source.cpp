#pragma once
#include "cMember.h"
#include "Population.h"
#include <iostream>
#include "cLoader.h"

using namespace std;

void TestMatrix(int s, int **matrix) {

	for (int i = 0; i < s; i++) {
		for (int j = 0; j < s; j++)
			cout << matrix[i][j] << " ";
		cout << endl;
	}
}

void TestOrder(vector<cMember> v) {

	for each (cMember m in v) {
		for each(int i in m.fOrder) {
			cout << i << " ";
		}
		cout << endl;
	}
}

void TestPopulation(vector<cMember> v){
	for (int i = 0; i < v.size(); i++) {
		cout << v[i].fId;
	}
}


int main() {

	const int MembersAmount = 10;

	cLoader load;
	Population pop;
	

	//Wype³niamy Tablice referencji
	pop.fRefMatrix = load.mLoadMatrix();

	//Okreslanie wielkoœci macierzy oraz populacji
	pop.fPopSize = MembersAmount;
	pop.fRefMatrixSize = load.size;

	//@TEST OK TestMatrix(pop.fRefMatrixSize, pop.fRefMatrix);

	//Inicjacja Osobników
	pop.mInitializeMembers();
	//@TEST OK TestPopulation(pop.fPopulation);
	
	

	//TestOrder(pop.fPopulation);

	

	
	//load.mLoadMatrix();
	system("pause");
}

