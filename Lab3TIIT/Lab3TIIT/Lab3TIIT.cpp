// Lab3TIIT.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

string *Source, *dopSource,*CutStr1,*CutStr2;
int NumberofSource = 0;

void Add (string str);
void Cut(string str1, string str2);
string *Cutting(string str);

int main()
{
	setlocale(LC_ALL, "rus");
	bool Cycle = true;
	int What;
	string str;
	CutStr1=Cutting("{151561,55,69}");
	while (Cycle == true)
	{
		cout << " 1-Добавление множества\n 2-Выход\n";
		cin >> What;
		switch (What)
		{
		case 1:
			cout << "Введите множество ({1,2,6})\n";
			cin >> str;
			Add(str);
			break;
		case 2:
			Cycle = false;
			break;
		default:
			cout << "Попробуйте еще раз.";
			break;
		}
	}
}

void Add(string str)
{
	dopSource = new string[NumberofSource];
	for (int i = 0; i < NumberofSource; i++)
	{
		dopSource[i] = Source[i];
	}
	Source = new string[NumberofSource + 1];
	for (int i = 0; i < NumberofSource; i++)
	{
		Source[i] = dopSource[i];
	}
	dopSource = new string[0];
	Source[NumberofSource] = str;
	NumberofSource++;
}

string *Cutting(string str)
{
	string *Info;
	int i1, i2, shet, height, Number = 0;
	i1 = i2 = 0;
	height = str.length();
	shet = 0;
	for (int i = 0; i < height; i++)
	{
		if (str[i] == ',')
			shet++;
	}
	shet++;
	Info = new string[shet];
	for (int i = 0; i < shet; i++)
	{
		if (i == 0)
		{
			for (int g = 1; g < height; g++)
			{
				if (str[g] == ',')
				{
					i1 = g;
					break;
				}
			}
			Info[Number] = str.substr(1, i1 - 1);
			Number++;
		}
		if (i != shet - 1 && i != 0)
		{
			for (int g = i1+1; g < height; g++)
			{
				if (str[g] == ',')
				{
					i2 = i1;
					i1 = g;
					break;
				}
			}
			Info[Number] = str.substr(i1+1, i2-i1-1);
			Number++;
		}
		if (i == shet - 1)
		{
			for (int g = i1+1; g < height; g++)
			{
				if (str[g] == ',')
				{
					i2 = g;
					break;
				}
			}
			Info[Number] = str.substr(i2+1, height-i2-1);
			Number++;
		}
	}
	return Info;
}

void Cut(string str1, string str2)
{

}