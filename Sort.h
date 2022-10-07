#pragma once
#include "C:\Users\ARGO\source\repos\ND_1\mylib.h"

vector<duom> Sort(vector<duom> temp)
{
	for (int k = 0; k < temp.size(); k++)
	{
		for (int i = 0; i < temp.size() - 1; i++)
		{
			string a = temp[i].pav;
			string b = temp[i + 1].pav;
			if ((a.compare(b) > 0))
			{
				duom z;
				z = temp[i];
				temp[i] = temp[i + 1];
				temp[i + 1] = z;
			}
		}
	}
return temp;
}