#pragma once
#include "cMember.h"
#include "Population.h"
#include <iostream>
#include "cLoader.h"
#include "cGA.h"
#include "cExcel.h"
#include "cTabu.h"
#include "cAenaling.h"
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




int main() 
{
	for (int mat = 7; mat <= 7; mat++)
	{
		cLoader load("D:\\Matrix" + std::to_string(mat) + string(".txt"));
		
		int** d = load.mLoadMatrix();
		int s = load.size;
		
		//Members amount, matrix, size of matrix
		Population pop(100, d, s);
		Population pop2(100, d, s);
		//Crossing rate mutation rate, group size, MembersAmount, NumberOfCycle
		
		//cGA ga(80, 40, 2, mat, pop.fPopSize, 1000);
		//ga.RunGA(pop);

		//cGA ga2(90, 1, 5, mat, pop2.fPopSize, 1000);
		//ga2.RunGA(pop2);
		//Max tabu list size , Max candidats list size, stop condition  
		cTabu t(30, 300, 10000, mat);
		cTabu t2(10, 300, 10000, mat);
		//cTabu t3(20, 300, 1000, mat);
		//cAenaling a(10, 100, -20);
		
		//t3.TabuSerch(&pop);
		//t2.TabuSerch(&pop);
		t2.TabuSerch(&pop);
		//a.aenaling(&pop, x);

		//for (int i = 0; i < NumberOfCycle; i++)
			//RunGA(ga, x, pop, i);

		}

	system("pause");
}



