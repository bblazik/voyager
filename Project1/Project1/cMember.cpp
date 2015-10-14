#pragma once
#include "cMember.h"



cMember::cMember()
{
}

cMember::cMember(int tId, int s)
{
	fId = tId;

	for (int i = 0; i < s; i++)
		fOrder.push_back(0);
	fLengeth = 0;

	for (int i = 0; i < s; i++)
		OrderPosibilities.push_back(i);
	

}


cMember::~cMember()
{
}
