#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class cMember
{
public:
	cMember();
	cMember(int tId, int s);
	~cMember(); 

	int fId;
	float fLengeth;
	vector<int> fOrder;

};

