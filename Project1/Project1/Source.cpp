#pragma once
#include "cMember.h"
#include "Population.h"
#include <iostream>
#include "cLoader.h"
#include "cGA.h"
#include "cExcel.h"
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

	//Mutacja -- wiêksza mutacja to 
	//Krzy¿owanie -- 
	int MembersAmount = 100;
	int MutationRate = 70;
	int CrossingRate = 80;
	int NumberOfCycle = 100;
	int GroupSize = 10;

	cLoader load;
	Population pop;
	cGA ga(CrossingRate, MutationRate, GroupSize);
	string temp = "Badania_" + string("MA_") +std::to_string(MembersAmount) + string("MR_") + std::to_string(MutationRate) + string("CR_") + std::to_string(CrossingRate) + string("NoC_") + std::to_string(NumberOfCycle) + string("GS_") + std::to_string(GroupSize)+ string(".xls");
	//cExcel x(temp)
	
	cExcel x;
	//Wype³niamy Tablice referencji
	pop.fRefMatrix = load.mLoadMatrix();

	//Okreslanie wielkoœci macierzy oraz populacji
	pop.fPopSize = MembersAmount;
	pop.fRefMatrixSize = load.size;

	///*@TEST OK*/ TestMatrix(pop.fRefMatrixSize, pop.fRefMatrix);

	//Inicjacja Osobników
	pop.mInitializeMembers();
	//sort(pop.fPopulation.begin(), pop.fPopulation.end(), fCompare);
		
	///*@TEST OK*/ TestPopulation(&pop.fPopulation);
	///*@Test OK*/ TestOrder(&pop.fPopulation); 
	

	//pop.mPrintMembers("Stan poczatkowy");
	
	for (int i = 0; i < NumberOfCycle; i++) {
		ga.selection(&pop);
		//pop.mPrintMembers("After selection");
		ga.crossing(&pop);
		ga.graduation(&pop);
		//pop.mPrintMembers("After crossing");
		//TestOrder(&pop.fPopulation);
		ga.mutation(&pop);
		ga.graduation(&pop);
		//sort(pop.fPopulation.begin(), pop.fPopulation.end(), fCompare);
		//pop.mPrintMembers();
		
		pop.mFindMax();
		pop.mFindMin();
		pop.mFindAvarange();
		
		x.WriteNextOne(pop.fMaxMember, pop.fAvarangeMember, pop.fMinMember, i,temp);
		//x.WriteNextOne();
		//pop.mPrintMembers();
		pop.mPrint();
	}
	//sort(pop.fPopulation.begin(), pop.fPopulation.end(), fCompare);
	pop.mPrintMembers("Stan koncowy");
	
	//load.mLoadMatrix();
	system("pause");
}



