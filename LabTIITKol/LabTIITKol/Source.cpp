#include "stdafx.h"
#include "hsh.h"
#include <string>
#include <iostream>

using namespace std;

int Number = 0;//���� ��� ���������
int Used = 0;//��� ������������

struct Hash_table
{
	string Key = "";
	string Info = "";
};

Hash_table *Hash;

void Init(int Num)
{
	Hash = new Hash_table[Num];
	Number = Num;
}//������ ������ ������� ��������

void Delete(string key)
{
	int Num;
	Num = Find(key);
	if (Num != -56)
	{
		Hash[Num].Key = "";
		Hash[Num].Info = "";
		Used--;
		cout << "�������" << endl;
	}
	else
		cout << "������ �� �������"<<endl;
}//��������

void View(string key)
{
	int Num = Find(key);
	if (Num != -56)
		cout << Hash[Num].Key << " " << Hash[Num].Info << endl;
	else
		cout << "������ �� �������"<<endl;
}//������� �� ����� ���������

int Find(string key)
{
	int Num = -56;
	int i = 0;
	while (i<Number)
	{
		Num = (Function1(key) + i*Function2(key))%Number;
		if (Hash[Num].Key == key)
			break;
		else
			Num = -56;
		i++;
	}
	return Num;
}//���� �� ����� ����

void Add(string key, string info)
{
	int Num = 0;
	int i = 0;
	if (Used < Number)
	{
		while(1)
		{
			Num = (Function1(key) + i*Function2(key)) % Number;
			if (Hash[Num].Key == "")
			{
				Hash[Num].Info = info;
				Hash[Num].Key = key;
				Used++;
				cout << "���������" << endl;
				break;
			}
			i++;
		}
	}
	else
		cout << "���������� �������� �������." << endl;
}//���������

int Function1(string str)
{
	int key = 0;
	for (int i = 0; i < str.length(); i++)
	{
		key += (int)str[i] * (str.length() - i);
	}
	key %= Number;
	return key;
}//��� �������, ������� ����������� ������ � ����

int Function2(string str)
{
	int key = 0;
	for (int i = 0; i < str.length(); i++)
	{
		key += (int)str[i] * Number / (i + 59);
	}
	key %= Number;
	return key;
}//��� �������, ������� ����������� ������ � ����