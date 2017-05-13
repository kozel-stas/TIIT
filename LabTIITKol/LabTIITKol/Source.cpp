#include "stdafx.h"
#include "hsh.h"
#include <string>
#include <iostream>

using namespace std;

int Number = 0;//макс кол элементов
int Used = 0;//кол используемых

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
}//задает размер массива структур

void Delete(string key)
{
	int Num;
	Num = Find(key);
	if (Num != -56)
	{
		Hash[Num].Key = "";
		Hash[Num].Info = "";
		Used--;
		cout << "Удалено" << endl;
	}
	else
		cout << "Ничего не найдено"<<endl;
}//удаление

void View(string key)
{
	int Num = Find(key);
	if (Num != -56)
		cout << Hash[Num].Key << " " << Hash[Num].Info << endl;
	else
		cout << "Ничего не найдено"<<endl;
}//выводит на экран найденный

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
}//ищет по ключу инфу

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
				cout << "Добавлено" << endl;
				break;
			}
			i++;
		}
	}
	else
		cout << "Невозможно добавить элемент." << endl;
}//ДОБАЛЕНИЕ

int Function1(string str)
{
	int key = 0;
	for (int i = 0; i < str.length(); i++)
	{
		key += (int)str[i] * (str.length() - i);
	}
	key %= Number;
	return key;
}//хеш функции, которые преобразует строку в ключ

int Function2(string str)
{
	int key = 0;
	for (int i = 0; i < str.length(); i++)
	{
		key += (int)str[i] * Number / (i + 59);
	}
	key %= Number;
	return key;
}//хеш функции, которые преобразует строку в ключ