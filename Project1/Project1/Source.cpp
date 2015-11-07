#pragma once
#include "cMember.h"
#include "Population.h"
#include <iostream>
#include "cLoader.h"
#include "cGA.h"
#include "cExcel.h"
#include "cTabu.h"
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
void RunGA(cGA ga, cExcel x, Population pop, int i) {
	ga.selection(&pop);
	ga.crossing(&pop);
	ga.mutation(&pop);
	ga.graduation(&pop);

	pop.mFindMax();
	pop.mFindMin();
	pop.mFindAvarange();

	x.WriteNextOne(pop.fMaxMember, pop.fAvarangeMember, pop.fMinMember, i);
	pop.mPrint();
}



int main() 
{
	for (int mat = 6; mat <= 6; mat++)
	{
		cLoader load("D:\\Matrix" + std::to_string(mat) + string(".txt"));
		
		int** d = load.mLoadMatrix();
		int s = load.size;
		
		//Members amount, matrix, size of matrix
		Population pop(100, d, s);
		
		//Crossing rate mutation rate, group size
		
		cGA ga(80, 5, 5);
		
		//Max tabu list size , Max candidats list size, stop condition  
		cTabu t(100, 30, 10200);
		cTabu t2(10, 300, 10200);

		//string temp = "Badania_banchmark" + std::to_string(mat) + string("-jedno") + string("MA_") + std::to_string(MembersAmount) + string("MR_") + std::to_string(MutationRate) + string("CR_") + std::to_string(CrossingRate) + string("NoC_") + std::to_string(NumberOfCycle) + string("GS_") + std::to_string(GroupSize) + string(".xls");
		string temp = "Tabu_100_30_12000.xls";
		string temp2 = "Tabu_10_300_20000.xls";
		cExcel x(temp);
		cExcel x2(temp2);
		

		t2.TabuSerch(&pop, x2);
		t.TabuSerch(&pop, x );
		

		//for (int i = 0; i < NumberOfCycle; i++)
			//RunGA(ga, x, pop, i);

		}

	system("pause");
}



