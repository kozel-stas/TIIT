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
	int n, m, h, i1 = 0, i2 = 0, sh = 0;
	vector<edge> list_edges;
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
		list_edges.push_back(a);
	}
	file.close();
	vector<int> dp(n, INT_MIN);
	dp[0] = 0;
	int cnt = 0;
	bool update_flag;
	while (true) {
		update_flag = false;

		for (int i = 0; i < m; i++) {
			int from = list_edges[i].start, to = list_edges[i].finish,
				cost = list_edges[i].cost;

			if (dp[to] > dp[from] + cost) {
				update_flag = true;
				dp[to] = dp[from] + cost;
			}
		}

		cnt++;
		if (cnt == n + 1)
			break;
	}
	ofstream file1("maze.out");
	if (dp[n - 1] == INT_MIN ) file1 << ":(";
	else if (update_flag) file1 << ":)";
	else file1 << -dp[n - 1];
	file1.close();
	return 0;
}