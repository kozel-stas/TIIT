// Test.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <queue>
#include <iostream>
#include <vector>
#include <climits>
#include <fstream>
#include <string>
using namespace std;
struct edge
{
	int start, finish, cost;
};
int main()
{
	int Cy = -86;
	int s = 0, n, m, h, i1, sh, i2;
	vector<edge>e;
	string str;
	ifstream file("maze.in");
	getline(file, str);
	h = str.length();
	for (int i = 0; i < h; i++)
		if (str[i] == ' ')
		{
			i1 = i;
			break;
		}
	n = atoi(str.substr(0, i1).c_str());
	m = atoi(str.substr(i1, h).c_str());
	for (int i = 0; i < m; i++)
	{
		edge a;
		getline(file, str);
		h = str.length();
		sh = 0;
		for (int j = 0; j < h; j++)
		{
			if (str[j] == ' ' && sh == 0)
			{
				i1 = j;
				sh++;
			}
			if (str[j] == ' ' && sh == 1 && j != i1)
			{
				i2 = j;
				break;
			}
		}
		a.start = atoi(str.substr(0, i1).c_str());
		a.finish = atoi(str.substr(i1, i2).c_str());
		a.cost = atoi(str.substr(i2, h).c_str());
		a.start--;
		a.finish--;
		e.push_back(a);
	}
	file.close();
	queue<int> q;
	q.push(s);
	vector<bool> used(n);
	used[s] = true;
	while (!q.empty()) {
		if (Cy==5) break;
		int v = q.front();
		q.pop();
		for (int i = 0; i<m; ++i) {
			if (e[i].start==v)
			{
				int to = e[i].finish;
				if (!used[to]) {
					used[to] = true;
					q.push(to);
					if (to == n-1)
					{
						Cy = 5;
						continue;
					}
				}
			}
		}
	}
	cout << Cy;
	system("pause");
    return 0;
}

