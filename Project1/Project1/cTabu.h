#pragma once
#include <vector>
#include "cMember.h"
#include "Population.h"

using namespace std;

class cTabu {
public:
	cTabu() {}
	cTabu(int MaxTabuSize, int neig, int stop) {
		TabuListSize = MaxTabuSize;
		neighborhood = neig;
		stopCondition = stop;
	}
	vector <cMember*> TabuList;
	
	int TabuListSize;
	int neighborhood;
	int stopCondition;
	cMember result;

	void TabuSerch(Population *pop, cExcel x) {
		
		cMember Best = pop->mChoseBestMember();
		
		srand(time(NULL));
		
		for (int ii = 0; ii < stopCondition; ii++){
			cMember bestCandidate;
			for (int i = 0; i < neighborhood; i++) {
				//Create new candidate
				int k = rand() % pop->fRefMatrixSize;
				int l = rand() % pop->fRefMatrixSize;
				//swap cities
				cMember candidate = Best;
				swap(&candidate, l, k);
				candidate.mSumLength(pop->fRefMatrix);

				if (i == 0) bestCandidate = candidate;
				if (bestCandidate.fLengeth > candidate.fLengeth && !find(TabuList, &candidate)) {
					bestCandidate = candidate;
				}
			}
			if (Best.fLengeth > bestCandidate.fLengeth) Best = bestCandidate;
			TabuList.push_back(new cMember(bestCandidate));
			if (TabuList.size() > TabuListSize)
				TabuList.erase(TabuList.begin());
			cout << ii << ": " <<Best.fLengeth << endl;
			x.TabuWite(Best.fLengeth, ii);
		}
		result = Best;
		
	}

	void swap(cMember *m, int l, int k) {
		int temp = m->fOrder[k];
		m->fOrder[k] = m->fOrder[l];
		m->fOrder[l] = temp;
	}

	bool find(vector<cMember*> v, cMember* m) {
		for each (cMember* k in v) {
			if (k->fLengeth == m->fLengeth) return true;
		}
		return false;
	}

	void print() {
		cout << result.fLengeth<< endl;
	}


};