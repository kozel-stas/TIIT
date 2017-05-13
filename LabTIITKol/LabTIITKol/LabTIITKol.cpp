// LabTIITKol.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include "hsh.h"

using namespace std;

int main()
{
	int Num;
	string str1,str2;
	setlocale(LC_ALL, "rus");
	cout << "Введите максимальное количество элементов: " << endl;
	cin >> Num;
	Init(Num);
	while (1)
	{
		cout << " 1-Добавить \n 2-Удалить \n 3-Найти \n 4-Выйти \n";
		cin >> Num;
		switch (Num)
		{
		case 1:
			cout << "Введите ключ \n";
			cin >> str1;
			cout << "Введите информацию \n";
			cin >> str2;
			Add(str1, str2);
			break;
		case 2:
			cout << "Введите ключ \n";
			cin >> str1;
			Delete(str1);
			break;
		case 3:
			cout << "Введите ключ \n";
			cin >> str1;
			View(str1);
			break;
		case 4:
			exit(1);
			break;
		default:
			cout << "Попробуйте еще раз" << endl;
			break;
		}

	}
    return 0;
}
