#include "stdafx.h"
#include "MyRand.h"

#include <time.h>
#include <stdio.h>

CMyRand::CMyRand()
{
	static int i = Init();
}

int CMyRand::Rand(UINT uiMin, UINT uiMax)
{
	++uiMax;

	return (rand() + rand()) % (uiMax - uiMin)  + uiMin;
}

int CMyRand::Init()
{
	srand((UINT)time(0));
	return 0;
}