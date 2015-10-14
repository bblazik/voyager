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
		// method turnament
		const int s = 3; // group size;
		
		vector <cMember*> TournamentResult;

		for (int j = 0; j < p->fPopSize / 2; j++) {
			//Dodaj do grup turniejowych
			vector <cMember*> TournamentGroup;
			for (int i = 0; i < s; i++) {
				TournamentGroup.push_back(p->fPopulation[rand() % p->fPopulation.size()]);
			}
			// Wybierz najlepszego
			cMember* tmp = TournamentGroup[0];
			for (int i = 1; i < s; i++) {
				if (tmp->fLengeth > TournamentGroup[i]->fLengeth)
					tmp = TournamentGroup[i];
			}
			TournamentResult.push_back(tmp);
		}
		//p->mRemoveHalf();
		//p->mAddNew();
		p->fPopulation = TournamentResult;
		p->mAddNew();
	}
	void crossing(Population *p) {
		srand(time(NULL));

		//p->mAddNew();
		//Dla wszystkich osobnikow
		
		for (int i = 0; i < p->fPopSize/2 - 1; i+=2) {
			if (rand() % 100 < fCrossingRate) {
				// wylosuj liczbe podzialu
				int l;
				do {
						l = rand() % p->fRefMatrixSize;
				}while (l==0 || l == p->fRefMatrixSize);
				for (int j = 0; j < l; j++) {
					// Wez kolejnosc z pierwszego osobnika
					p->fPopulation[i + p->fPopSize / 2]->fOrder[j] = p->fPopulation[i]->fOrder[j];
					p->fPopulation[i + 1 + p->fPopSize / 2]->fOrder[j] = p->fPopulation[i + 1]->fOrder[j];
				}
				for (int k = l; k < p->fRefMatrixSize ; k++) {
					//Wez kolejnosc z drugiego osobnika
					p->fPopulation[i + p->fPopSize / 2]->fOrder[k] = p->fPopulation[i + 1]->fOrder[k];
					p->fPopulation[i + 1 + p->fPopSize / 2]->fOrder[k] = p->fPopulation[i]->fOrder[k];
				}
				/*
				cout << "Parent1: ";
				for (int k = 0; k < p->fRefMatrixSize; k++) {
					cout << p->fPopulation[i]->fOrder[k];
				}
				cout << endl;
				cout << "Parent2: ";
				for (int k = 0; k < p->fRefMatrixSize; k++) {
					cout << p->fPopulation[i + 1]->fOrder[k];
				}
				cout << endl;

				cout << "Osobnik1: ";
				for (int k = 0; k < p->fRefMatrixSize; k++) {
					cout << p->fPopulation[i + p->fPopSize / 2]->fOrder[k];
				}
				cout << endl;
				cout << "Osobnik2: ";
				for (int k = 0; k < p->fRefMatrixSize; k++) {
					cout << p->fPopulation[i + 1 + p->fPopSize / 2]->fOrder[k];
				}
				cout << endl;
				*/
			}
		}


		//find doubles
		//dla kazdego z nowo powstalych

		for (int i = p->fPopSize / 2 ; i < p->fPopSize ; i++) {
			for (int x = 0; x < p->fRefMatrixSize; x++)
			{
				if (find(p->fPopulation[i]->OrderPosibilities.begin(), p->fPopulation[i]->OrderPosibilities.end(), p->fPopulation[i]->fOrder[x]) != p->fPopulation[i]->OrderPosibilities.end()) {
					//cout << "znalazlem: " << p->fPopulation[i]->fOrder[x] << "wywalam: " << p->fPopulation[i]->OrderPosibilities.back() << endl;
					p->fPopulation[i]->OrderPosibilities.erase(remove(p->fPopulation[i]->OrderPosibilities.begin(), p->fPopulation[i]->OrderPosibilities.end(), p->fPopulation[i]->fOrder[x]), p->fPopulation[i]->OrderPosibilities.end());
				}
				else {
					//cout << "znalazlem: " << p->fPopulation[i]->fOrder[x];
					p->fPopulation[i]->fOrder[x] = -1;	
				}
			}
			for (int x = 0; x < p->fRefMatrixSize; x++) {
		
				if (p->fPopulation[i]->fOrder[x] == -1) {
					//Losuj z mozliwosci ktore zostaly;
					int tmp = rand() % p->fPopulation[i]->OrderPosibilities.size();
					p->fPopulation[i]->fOrder[x] = p->fPopulation[i]->OrderPosibilities[tmp];
					p->fPopulation[i]->OrderPosibilities.erase(p->fPopulation[i]->OrderPosibilities.begin()+tmp, p->fPopulation[i]->OrderPosibilities.begin() + tmp + 1);
				}
			}
		}
		//sprawdz czy order sie powtarza w order posibilities 
		//dodaj if.

	}
	void mutation(Population *p) {
		srand(time(NULL));
		
		for (int i = p->fPopSize / 2; i < p->fRefMatrixSize; i++) {
			if ((rand() % 100) < fMutationRate) {
				int l1 = rand() % p->fRefMatrixSize;
				int l2 ;
				do {
					l2 = rand() % p->fRefMatrixSize;
				} while (l2 == l1);
				
				//switch
				int tmp = p->fPopulation[i]->fOrder[l1];
				p->fPopulation[i]->fOrder[l1] = p->fPopulation[i]->fOrder[l2];
				p->fPopulation[i]->fOrder[l2] = tmp;
			}
		}
	}
	void graduation(Population *p) {
		for each (cMember *m in p->fPopulation) {
			m->fLengeth = 0;
			m->mSumLength(p->fRefMatrix);
		}
	}

	
};

