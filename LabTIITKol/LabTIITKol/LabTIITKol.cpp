// LabTIITKol.cpp: ���������� ����� ����� ��� ����������� ����������.
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
	cout << "������� ������������ ���������� ���������: " << endl;
	cin >> Num;
	Init(Num);
	while (1)
	{
		cout << " 1-�������� \n 2-������� \n 3-����� \n 4-����� \n";
		cin >> Num;
		switch (Num)
		{
		case 1:
			cout << "������� ���� \n";
			cin >> str1;
			cout << "������� ���������� \n";
			cin >> str2;
			Add(str1, str2);
			break;
		case 2:
			cout << "������� ���� \n";
			cin >> str1;
			Delete(str1);
			break;
		case 3:
			cout << "������� ���� \n";
			cin >> str1;
			View(str1);
			break;
		case 4:
			exit(1);
			break;
		default:
			cout << "���������� ��� ���" << endl;
			break;
		}

	}
    return 0;
}
