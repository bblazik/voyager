#pragma once
#include <vector>
#include <iostream>
#include "cMember.h"
#include "Population.h"

using namespace std;

class cGA
{
public:
	cGA(int cross, int mutate) { fCrossingRate = cross; fMutationRate = mutate; };
	~cGA() {};

	int fMutationRate;
	int fCrossingRate;

	void selection(Population *p) {
		// ranking method
		p->mRemoveHalf();
	}
	void crossing(Population *p) {
		srand(time(NULL));

		p->mAddNew();
		//Dla wszystkich osobnikow
		for (int i = 0; i < p->fPopSize/2 - 1; i++) {
			// wylosuj liczbe podzialu
			int l = 1;//rand() % p->fRefMatrixSize;
			for (int j = 0; j < l; j++) {
				// Wez kolejnosc z pierwszego osobnika
				p->fPopulation[i + p->fPopSize / 2]->fOrder[j] = p->fPopulation[i]->fOrder[j];
				p->fPopulation[i + 1 + p->fPopSize / 2]->fOrder[j] = p->fPopulation[i + 1]->fOrder[j];
			}
			for (int k = l; k < p->fPopSize/2 - 1; k++) {
				//Wez kolejnosc z drugiego osobnika
				p->fPopulation[i + p->fPopSize / 2]->fOrder[k] = p->fPopulation[i + 1]->fOrder[k];
				p->fPopulation[i + 1 + p->fPopSize / 2]->fOrder[k] = p->fPopulation[i]->fOrder[k];
			}

			p->fPopulation[i + p->fPopSize/2]->mSumLength(p->fRefMatrix);
			p->fPopulation[i+1 + p->fPopSize / 2]->mSumLength(p->fRefMatrix);
		}
	}
	void mutation(Population *p) {
		srand(time(NULL));
		
		for each(cMember * m in p->fPopulation) {
			if ((rand() % 100 + 1) > fMutationRate) {

			}
		}
	}
	void graduation(Population *p) {
		
	}

	
};

