// TiiTLab2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int end1=5;
int len = 5;
int Graf[4][3];

int Iyda(int start);

int main()
{
	int max;
	Graf[0][0] = 1;
	Graf[0][1] = 3;
	Graf[0][2] = 1;
	Graf[1][0] = 3;
	Graf[1][1] = 3;
	Graf[1][2] = 2;
	cout << Iyda(1)<<endl;
	system("pause");
    return 0;
}

int Iyda(int start)
{
	int max[4];
	int mix;
	int shet = 0;
	int y = 0;
	if (start == end1)
		return 0;
	else
	{
		for (int i = 0; i < len; i++)
		{
			if (Graf[i][0] == start)
			{
				y = Graf[i][2] + Iyda(Graf[i][1]);
				max[shet] = y;
				shet++;
			}
		}
		if (shet != 0)
			mix = max[0];
		else
			mix = -369852147;
		for (int j = 0; j < shet; j++)
		{
			if (mix < max[j])
				mix = max[j];
		}
		return mix;
	}
}
