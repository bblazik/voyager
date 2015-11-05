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

	//cout << countLenght(0, 2, 0, 0)<< endl;
	//parser();
	
	
	
	//Mutacja -- wiêksza mutacja to 
	//Krzy¿owanie --
	for (int mat = 6; mat <= 6; mat++)
	{
		cLoader load("D:\\Matrix" + std::to_string(mat) + string(".txt"));

		int MembersAmount = 100;
		for (MembersAmount; MembersAmount <=100; MembersAmount *= 10)
		{
			int MutationRate = 5;
			for (MutationRate; MutationRate <= 5; MutationRate -= 30)
			{
				int CrossingRate = 80;
				for (CrossingRate; CrossingRate <= 80; CrossingRate += 30)
				{
					int NumberOfCycle = 1000;
					for (NumberOfCycle; NumberOfCycle <= 1000; NumberOfCycle *= 10)
					{
						int GroupSize = 5;
						for (GroupSize; GroupSize <= 5; GroupSize += 5)
						{


							Population pop;
							cGA ga(CrossingRate, MutationRate, GroupSize);
							string temp = "Badania_banchmark" + std::to_string(mat) + string("-jedno") + string("MA_") + std::to_string(MembersAmount) + string("MR_") + std::to_string(MutationRate) + string("CR_") + std::to_string(CrossingRate) + string("NoC_") + std::to_string(NumberOfCycle) + string("GS_") + std::to_string(GroupSize) + string(".xls");
							cExcel x;
							pop.fRefMatrix = load.mLoadMatrix();
							pop.fPopSize = MembersAmount;
							pop.fRefMatrixSize = load.size;
							pop.mInitializeMembers();
							for (int i = 0; i < NumberOfCycle; i++) {
								ga.selection(&pop);
								ga.crossing(&pop);
								ga.mutation(&pop);
								ga.graduation(&pop);

								pop.mFindMax();
								pop.mFindMin();
								pop.mFindAvarange();

								x.WriteNextOne(pop.fMaxMember, pop.fAvarangeMember, pop.fMinMember, i, temp);
								pop.mPrint();
							}
						}
					}
				}
			}
		}
	}
	system("pause");
}



