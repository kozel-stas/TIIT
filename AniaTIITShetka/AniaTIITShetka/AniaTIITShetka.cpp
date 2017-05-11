// AniaTIITShetka.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#include <string>

using namespace std;

int NumberofVertex=0, NumberofEdge=0;
int **Graf;
queue<int> Joint;

void ReadGraf(string str);
int Connect(int Niga,int start, int end);
void JustDoIt();

int main()
{
	int num;
	setlocale(LC_ALL, "rus");
	while (true)
	{
		NumberofEdge = 0;
		NumberofVertex = 0;
		cout << "Выберите номер теста (1-5) \n";
		cin >> num;
		switch (num)
		{
		case 1:
			ReadGraf("1.txt");
			break;
		case 2:
			ReadGraf("2.txt");
			break;
		case 3:
			ReadGraf("3.txt");
			break;
		case 4:
			ReadGraf("4.txt");
			break;
		case 5:
			ReadGraf("5.txt");
			break;
		default:
			cout << "Попробуйте еще раз \n";
			break;
		}
		for (int i = 0; i < NumberofVertex; i++)
		{
			for (int j = 0; j < NumberofEdge; j++)
			{
				cout << Graf[i][j];
			}
			cout << endl;
		}
		JustDoIt();
		if (!Joint.empty())
		{
			while (!Joint.empty())
			{
				cout << Joint.front() << " ";
				Joint.pop();
			}
		}
		else {
			cout << "Точки сочленения не найдены";
		}
		cout << "\nЖелаете продолжить (1-да,2-нет)\n";
		cin >> num;
		if (num == 2)
			exit(0);
	}
    return 0;
}

void ReadGraf(string str)
{
	ifstream in(str);
	if (in.is_open())
	{
		string st;
		while (getline(in, st))
		{
			NumberofVertex++;
		}
		in.close();
		NumberofEdge = (st.length() + 1) / 2;
		Graf = new int*[NumberofVertex];
		for (int i = 0; i < NumberofVertex; i++)
			Graf[i] = new int[NumberofEdge];
		ifstream in(str);
		int sh = 0;
		int s = 0;
		while (getline(in, st))
		{
			s = 0;
			for (int i = 0; i < st.length(); i += 2)
			{
				Graf[sh][s] = st[i]-48;
				s++;
			}
			sh++;
		}
		in.close();
	}
}

int Connect(int Niga,int start,int end)
{
	int Or = 0;
	queue<int> weight;
	vector<bool> UsedVer(NumberofVertex, false);
	if (Niga != -56)
	{
		UsedVer[Niga] = true;
	}
	weight.push(start);
	UsedVer[start] = true;
	while (!weight.empty())
	{
		int v = weight.front();
		weight.pop();
		for (int i = 0; i < NumberofEdge; i++)
		{
			if (Graf[v][i] == 1)
			{
				for (int j = 0; j < NumberofVertex; j++)
				{
					if (Graf[j][i] == 1 && UsedVer[j] == false)
					{
						if (j == end)
							Or = 1;
						weight.push(j);
						UsedVer[j] = true;
						break;
					}
				}
			}
			if (Or == 1)
				break;
		}
		if (Or == 1)
			break;
	}
	return Or;
}

void JustDoIt()
{
	bool arr = false;
	for (int i = 0; i < NumberofVertex;i++)
	{
		arr = false;
		for (int j = 0; j < NumberofVertex-1;j++)
		{
			for (int g = j+1; g < NumberofVertex;g++)
			{
				if (j != i && g != i)
				{
					if (Connect(i, j, g) == 0)
					{
						Joint.push(i+1);
						arr = true;
						break;
					}
				}
				if (arr == true)
					break;
			}
			if (arr == true)
				break;
		}
	}
}