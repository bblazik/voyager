#pragma once
#include <iostream>
#include <string>

using namespace std;

class cMember
{
public:
	cMember();
	cMember(int tId);
	~cMember(); 

	int fId;
	float fLengeth;
	string fOrder;

};

