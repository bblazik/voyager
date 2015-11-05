#pragma once
#include <vector>
#include <iostream>
#include "cMember.h"
#include "Population.h"

using namespace std;

class cGA
{
public:
	cGA(int cross, int mutate, int size) { fCrossingRate = cross; fMutationRate = mutate; fGroupSize = size; };
	~cGA() {};

	int fMutationRate;
	int fCrossingRate;
	int fGroupSize;

	void selection(Population *p) {
		// method turnament
		srand(time(NULL));
		vector <cMember*> TournamentResult;

		for (int j = 0; j < p->fPopulation.size() / 2; j++) {
			//Dodaj do grup turniejowych
			vector <cMember*> TournamentGroup;
			for (int i = 0; i < fGroupSize; i++) {
				int temp = rand() % p->fPopulation.size();
				TournamentGroup.push_back(p->fPopulation[temp]);

				//Bez zwracania
				//p->fPopulation.erase(p->fPopulation.begin() + temp, p->fPopulation.begin() + temp + 1);
			}
			// Wybierz najlepszego
			cMember *tmp = TournamentGroup[0];
			for (int i = 1; i < fGroupSize; i++) {
				if (tmp->fLengeth > TournamentGroup[i]->fLengeth)
					tmp = TournamentGroup[i];
			}
			TournamentResult.push_back(new cMember(*tmp));
		}
		// Przypisz wybrane osobniki do nowej populacji
		
		p->ClearVector();
		p->fPopulation = std::move(TournamentResult);
		p->mAddNew();
		
	}
	void crossing(Population *p) {
		srand(time(NULL));

		// dodaj osobniki do ktorych bedziemy przypisywac wyniki krzyzowania
		//p->mAddNew();
		//Dla wszystkich osobnikow

		for (int i = 0; i < p->fPopSize / 2 - 1; i += 2) {
			if (rand() % 100 < fCrossingRate) {
				// wylosuj liczbe podzialu
				int l, k;
				do {
					l = rand() % p->fRefMatrixSize;
				} while (l == 0 || l == p->fRefMatrixSize);

				do {
					k = rand() % p->fRefMatrixSize;
				} while (k == 0 || k == p->fRefMatrixSize);

				// krzy¿owanie jednopunktowe z naprawianiem. 
				///*
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
				
				//*/
				/*
				for (int j = l>k? k:l ; j < (l>k?l:k); j++) {
					// Wez kolejnosc z pierwszego osobnika
					p->fPopulation[i + p->fPopSize / 2]->fOrder[j] = p->fPopulation[i]->fOrder[j];
					p->fPopulation[i + 1 + p->fPopSize / 2]->fOrder[j] = p->fPopulation[i + 1]->fOrder[j];
				}
				//*/
				// Naprawianie OX
				///*
				///*

				/*
				for (int x = 0; x < p->fRefMatrixSize; x++) {

					if (p->fPopulation[i + p->fPopSize / 2]->fOrder[x] == -1) {
						for (int y = 0; y < p->fRefMatrixSize; y++) {
							if (!(p->isIn(p->fPopulation[i + p->fPopSize / 2]->fOrder, p->fPopulation[i + 1]->fOrder[y]))) {
								p->fPopulation[i + p->fPopSize / 2]->fOrder[x] = p->fPopulation[i + 1]->fOrder[y];
								break;
							}
						}
					}
				}
				
				for (int x = 0; x < p->fRefMatrixSize; x++) {
					if (p->fPopulation[i + 1 + p->fPopSize / 2]->fOrder[x] == -1){
						for (int y = 0; y < p->fRefMatrixSize; y++) {
							if (!(p->isIn(p->fPopulation[i +1+ p->fPopSize / 2]->fOrder, p->fPopulation[i]->fOrder[y]))) {
								p->fPopulation[i +1+ p->fPopSize / 2]->fOrder[x] = p->fPopulation[i]->fOrder[y];
								break;
							}
						}
					}
				}//*/

			}
			else {
				p->fPopulation[i + p->fPopSize / 2]->fOrder = p->fPopulation[i]->fOrder;
				///cout << "\nPo tym jest bl¹d ?\n";
				p->fPopulation[i + 1 + p->fPopSize / 2]->fOrder = p->fPopulation[i + 1]->fOrder;
			}
		}




		//find doubles
		//dla kazdego z nowo powstalych
//Naprawianie dla jednopunktowego z naprawianiem.

		///*
		for (int i = p->fPopSize / 2; i < p->fPopSize; i++) {
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
				//Losowe naprawianie
				if (p->fPopulation[i]->fOrder[x] == -1) {
					//Losuj z mozliwosci ktore zostaly;
					int tmp = rand() % p->fPopulation[i]->OrderPosibilities.size();
					p->fPopulation[i]->fOrder[x] = p->fPopulation[i]->OrderPosibilities[tmp];
					p->fPopulation[i]->OrderPosibilities.erase(p->fPopulation[i]->OrderPosibilities.begin() + tmp, p->fPopulation[i]->OrderPosibilities.begin() + tmp + 1);
				}
			}
		}
	//*/

		//sprawdz czy order sie powtarza w order posibilities 
		//dodaj if.

	}
	

	void mutation(Population *p) {
		srand(time(NULL));
		
		for (int i = p->fPopSize / 2; i < p->fPopSize; i++) {
			for (int j = 0; j < p->fPopulation[i]->fOrder.size(); j++)
			{
				if ((rand() % 100) < fMutationRate) {

					int l1 = j;//rand() % p->fRefMatrixSize;
					int l2;
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
	}
	void graduation(Population *p) {
		for each (cMember *m in p->fPopulation) {
			m->fLengeth = 0;
			m->mSumLength(p->fRefMatrix);
		}
	}

	
};

