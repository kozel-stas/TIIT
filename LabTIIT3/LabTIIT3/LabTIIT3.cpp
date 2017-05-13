// LabTIIT3.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

string *Sets;
string Answer="{";
int NumberofSets = 0, shet;

void Add(string str);
string* CutThis(string str);
int Test(int start,string str);
void Dekartovo(int now,string ans);

int main()
{
	setlocale(LC_ALL, "rus");
	int num;
	bool sir = true;
	string str;
	Sets = new string[0];
	while (sir==true)
	{
		cout << " 1-Добавить множество \n 2-Выход \n";
		cin >> num;
		switch (num)
		{
		case 1:
			cout << "Введите множество({7,8,9}): \n";
			cin >> str;
			Add(str);
			break;
		case 2:
			sir = false;
			break;
		default:
			cout << "Попробуйте еще раз.\n";
			break;
		}
	}
	Dekartovo(0, "");
	Answer = Answer.substr(0, Answer.length() - 1);
	Answer += '}';
	cout << Answer<<endl;
	system("pause");
    return 0;
}

void Add(string str)
{
	string *Setd = new string[NumberofSets];
	for (int i = 0; i < NumberofSets; i++)
	{
		Setd[i] = Sets[i];
	}
	Sets = new string[NumberofSets+1];
	for (int i = 0; i < NumberofSets; i++)
	{
		Sets[i] = Setd[i];
	}
	delete[] Setd;
	Sets[NumberofSets] = str;
	NumberofSets++;
}

string* CutThis(string str)
{
	string *st;
	int i1 = 0, i2 = 0;
	if (str == "{}")
	{
		st = new string[1];
		st[0] = "empty";
		shet = 1;
	}
	else
	{
		shet = 0;
		int height = str.length();
		while (i1 != height - 1)
		{
			i1 = Test(i1 + 1, str);
			shet++;
		}
		shet++;
		int num = 0;
		st = new string[shet];
		i1 = i2 = 0;
		while (i1 != height - 1)
		{
			i2 = Test(i1 + 1, str);
			st[num] = str.substr(i1 + 1, i2 - i1 - 1);
			i1 = i2;
			num++;
		}
	}
	return st;
}

int Test(int start, string str)
{
	int i;
	int ans = 0;
	if (str[start] == '{' || str[start] == '<')
	{
		int sum = 1;
		i = start + 1;
		while (sum != 0)
		{
			if (str[i] == '{' || str[i] == '<')
				sum++;
			if (str[i] == '}' || str[i] == '>')
				sum--;
			i++;
		}
		ans = i;
	}
	else
	{
		i = start;
		while (1)
		{
			if (str[i] == ',' || str[i] == '}' || str[i] == '>')
			{
				ans = i;
				break;
			}
			i++;
		}
	}
	return ans;
}

void Dekartovo(int now,string ans)
{
	int leng;
	string *temp, ter;
	temp = CutThis(Sets[now]);
	leng = shet-1;
	if (now == NumberofSets - 1)
	{
		for (int i = 0; i < leng; i++)
		{
			ter = ans;
			ter += temp[i];
			ter += '>';
			Answer += '<';
			Answer += ter;
			Answer += ',';
		}
	}
	else
	{
			for (int i = 0; i < leng; i++)
			{
				ter = ans;
				ter += temp[i];
				ter += ',';
				Dekartovo(now + 1, ter);
			}
	}
}
