#pragma once

#include <vector>
#include "cMember.h"
#include "Population.h"


using namespace std;

class cAenaling {
public:
	cAenaling(int m, int g, int k) {
		Tmin = m;
		gamma = g;
		this->k = k;
	}

	int Tmin;
	int gamma;
	int k;

	void aenaling(Population *pop, cExcel x) {
	
		
		cMember Best = pop->mChoseBestMember();
		cMember bestCandidate = pop->mChoseBestMember();
		srand(time(NULL));
		
		int i = 0;
		for (float Temp = 100; Temp > Tmin;) {

			int k = rand() % pop->fRefMatrixSize;
			int l = rand() % pop->fRefMatrixSize;
			
			cMember candidate = Best;
			swap(&candidate, l, k);
			candidate.mSumLength(pop->fRefMatrix);
			if (Best.fLengeth > candidate.fLengeth) Best = candidate;
			if (bestCandidate.fLengeth > candidate.fLengeth) {
				bestCandidate = candidate;
			}
			else {
				float t = exp(-(candidate.fLengeth - bestCandidate.fLengeth) / Temp);
				float t1 = ((float)rand() / (RAND_MAX));
				if (t1 < t) {
					bestCandidate = candidate;
				}
			}
			Temp = 0.999f *Temp;//
			//float tm = (log(Temp + k));
//			Temp = gamma / tm;
			cout << "Temp: " << Temp << " best: " << bestCandidate.fLengeth << " Global Best: " << Best.fLengeth << endl;
			i++;
			x.TabuWite(bestCandidate.fLengeth, i);
		}

	}

	void swap(cMember *m, int l, int k) {
		int temp = m->fOrder[k];
		m->fOrder[k] = m->fOrder[l];
		m->fOrder[l] = temp;
	}

};