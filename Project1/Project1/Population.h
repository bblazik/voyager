#pragma once
#include "cMember.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <vector>
#include <algorithm>

class Population
{
public:
	Population();
	Population::Population(int Size);
	Population(int PopSize, int **fRefMat, int RefMatsize) {
		fPopSize = PopSize;
		fRefMatrix = fRefMat;
		fRefMatrixSize = RefMatsize;
		mInitializeMembers();
	}

	int fPopSize;
	int **fRefMatrix;
	int fRefMatrixSize;
	
	float fMaxMember;
	float fAvarangeMember;
	float fMinMember;

	vector <cMember*> fPopulation;
	vector <bool> OrderFlag;


	void mDrawMembers() {
		srand(time(NULL));
		for each (cMember *m in fPopulation) {
			for (int i = 0; i < fRefMatrixSize; i++) {
				int val = 0;
				val = rand() % m->OrderPosibilities.size();
				m->fOrder[i] = m->OrderPosibilities[val];
				m->OrderPosibilities.erase(m->OrderPosibilities.begin() + val, m->OrderPosibilities.begin() + val + 1);
			}
			m->mSumLength(fRefMatrix);
		}
	}
		
	vector<bool> setFlag(vector<bool> v, bool value) {
		for (int i = 0; i < fRefMatrixSize; i++) {
			v[i] = value;
		}
		return v;
	}
	/*
	void mChoseBestMember() {
		for each (cMember *m in fPopulation) {
			if (m->fLengeth < fBestMemberRef.fLengeth)
				fBestMemberRef.fLengeth = m->fLengeth;
		}
	}
	*/

	void ClearVector() {
	
		for (auto it = fPopulation.begin(); it != fPopulation.end(); ++it)
		{
			delete *it;
		}
		fPopulation.clear();
	}

	void mPrintMembers(std::string m) {
		cout << "\n\n -------------Wypisuje wszystkich: -----------\n";
		cout << "\n" << m << endl;
		for each (cMember * m in fPopulation){
			cout << m->fLengeth << endl;
		}
	}

	void mInitializeMembers() {
		
		
		for (int i = 0; i < fPopSize; i++) {
			fPopulation.push_back(new cMember(i, fRefMatrixSize));	
		}
		mDrawMembers();
	}
	
	void mRemoveHalf() {
		for (int i = fPopSize / 2; i < fPopSize; i++)
			fPopulation.pop_back();
	}

	void mAddNew() {
		for (int i = fPopSize/2; i < fPopSize; i++) {
			fPopulation.push_back(new cMember(i, fRefMatrixSize));
		}
	}

	bool isIn(vector<int> v, int l) {
		for (int i = 0; i < v.size(); i++) {
			if (v[i] == l) { return true; }
		}
		return false;
	};

	void mFindMax() {
		fMaxMember = fPopulation[0]->fLengeth;
		for each(cMember * m in fPopulation) {
			if (m->fLengeth > fMaxMember)
				fMaxMember = m->fLengeth;
		}
	}

	void mFindMin() {
		fMinMember = fPopulation[0]->fLengeth;
		for each(cMember * m in fPopulation) {
			if (m->fLengeth < fMinMember)
				fMinMember = m->fLengeth;
		}
	}

	void mFindAvarange() {
		fAvarangeMember = 0;

		fAvarangeMember = fPopulation[0]->fLengeth;
		for each(cMember * m in fPopulation) {
				fAvarangeMember += m->fLengeth;
		}
		fAvarangeMember /= fPopSize;
	}
	void mPrint() {
		cout << "Max: " << fMaxMember << " Avarange: " << fAvarangeMember << " Min: " << fMinMember << endl;
	}

};

