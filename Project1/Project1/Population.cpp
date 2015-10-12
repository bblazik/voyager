#pragma once
#include "Population.h"


Population::Population() {}
Population::Population(int Size)
{
	Population::fRefMatrix  = new int*[Size];
	for (int i = 0; i < Size; ++i)
		Population::fRefMatrix[i] = new int[Size];


}


Population::~Population()
{
}
