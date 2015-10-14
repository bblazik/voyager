#pragma once
#include "cMember.h"
#include "Population.h"
#include <iostream>
#include "cLoader.h"
#include "cGA.h"

using namespace std;

bool fCompare(cMember* i, cMember* j) { return (i->fLengeth < j->fLengeth); }

void TestMatrix(int s, int **matrix) {

	for (int i = 0; i < s; i++) {
		for (int j = 0; j < s; j++)
			cout << matrix[i][j] << " ";
		cout << endl;
	}
}

void TestOrder(vector<cMember*> *v) {

	for each (cMember* m in *v) {
		for each(int i in m->fOrder) {
			cout << i << " ";
		}
		cout << endl;
	}
}

void TestPopulation(vector<cMember*> *v){
	for (int i = 0; i < v->size(); i++) {
		cout << v->at(i)->fId;
	}
}


int main() {

	const int MembersAmount = 12;
	const int MutationRate = 30;
	const int CrossingRate = 75;
	const int NumberOfCycle = 20;

	cLoader load;
	Population pop;
	cGA ga(CrossingRate, MutationRate);

	//Wype³niamy Tablice referencji
	pop.fRefMatrix = load.mLoadMatrix();

	//Okreslanie wielkoœci macierzy oraz populacji
	pop.fPopSize = MembersAmount;
	pop.fRefMatrixSize = load.size;

	///*@TEST OK*/ TestMatrix(pop.fRefMatrixSize, pop.fRefMatrix);

	//Inicjacja Osobników
	pop.mInitializeMembers();
	sort(pop.fPopulation.begin(), pop.fPopulation.end(), fCompare);
		
	///*@TEST OK*/ TestPopulation(&pop.fPopulation);
	///*@Test OK*/ TestOrder(&pop.fPopulation); 
	

	pop.mPrintMembers();
	
	for (int i = 0; i < NumberOfCycle; i++) {
		ga.selection(&pop);
		ga.crossing(&pop);
		ga.mutation(&pop);
		ga.graduation(&pop);
		sort(pop.fPopulation.begin(), pop.fPopulation.end(), fCompare);

		pop.mPrintMembers();
	}
	
	//load.mLoadMatrix();
	system("pause");
}



