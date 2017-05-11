// LabTIITDouble5XXX.cpp: определяет точку входа для консольного приложения.
//
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <climits>
#include <fstream>
#include <string>
#include <queue>
using namespace std;
struct edge
{
	int start, finish, cost;
};
int main()
{
	int Cy = -86, s = 0;
	int n, m, h, i1 = 0, i2 = 0, sh = 0;
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
		if (Cy == 5) break;
		int v = q.front();
		q.pop();
		for (int i = 0; i<m; ++i) {
			if (e[i].start == v)
			{
				int to = e[i].finish;
				if (!used[to]) {
					used[to] = true;
					q.push(to);
					if (to == n - 1)
					{
						Cy = 5;
						continue;
					}
				}
			}
		}
	}
	if (Cy == -86)
	{
		ofstream file1("maze.out");
		file1 << ":(";
		file1.close();
	}
	else
	{
		vector<int> length(n, INT_MIN);
		vector<int> p(n, -1);
		bool any;
		length[0] = 0;
		int x;
		for (int i = 0; i < n; i++)
		{
			x = -1;
			any = false;
			for (int j = 0; j < m; j++)
				if ((length[e[j].start] > INT_MIN) && (length[e[j].finish] < length[e[j].start] + e[j].cost))
				{
					length[e[j].finish] = length[e[j].start] + e[j].cost;
					p[e[j].finish] = e[j].start;
					x = 1;
					any = true;
				}
			if (!any) break;
		}
		vector<int> path;
		int k = 0;
		ofstream file1("maze.out");
		for (int i = n - 1; i != -1; i = p[i])
		{
			k++;
			path.push_back(i);
			if (k > n) break;
		}
		if (length[n - 1] == INT_MIN) file1 << ":(";
		else
			if ((x != -1) && ((path.back() != 0) || (path.front() != n - 1) || (k > n))) file1 << ":)";
			else file1 << length[n - 1];
			file1.close();
	}
		return 0;
}