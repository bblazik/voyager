#pragma once
#include "cMember.h"

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

	void mLoadPopulation();
	cMember mChoseBestMember() {
		for each (cMember m in fPopulation) {
			if (m.fLengeth < fBestMemberRef.fLengeth)
				fBestMemberRef.fLengeth = m.fLengeth;
		}
	}

};

