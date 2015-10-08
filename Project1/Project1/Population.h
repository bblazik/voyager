#pragma once
#include "cMember.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <vector>

class Population
{
public:
	Population();
	Population::Population(int Size);


	~Population();

	int fPopSize;
	int **fRefMatrix;
	cMember fBestMemberRef;
	vector <cMember> fPopulation;


	cMember mDrawMember() {
		srand(time(NULL));

		int iSecret = rand() % fPopSize;

		

	}
	
	cMember mChoseBestMember() {
		for each (cMember m in fPopulation) {
			if (m.fLengeth < fBestMemberRef.fLengeth)
				fBestMemberRef.fLengeth = m.fLengeth;
		}
	}
	void mInitializeMembers() {
		for (int i = 0; i < fPopSize; i++) {
			fPopulation.push_back(cMember(i));
		}
		//@TEST cout << fPopulation.size();
	}


};

