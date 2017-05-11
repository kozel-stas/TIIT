// LabAniaQuickSort.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "iostream"
#include "string"
#include "fstream"
#include "iomanip"
#include "cstdlib"
using namespace std;

struct Bus
{
	string NumberOfBus;
	string Place;
	string TimeStart;
	string TimeEnd;
};

int Quantity = 0, Hour, Minute;
Bus *Info = new Bus[Quantity];
Bus *TemporarlyInfo;
ofstream file;
ifstream files;

void TimeStringinInt(string Time);
void Sort();
void AddBus();
void ShowBus();
void WritetoFile();
void ReadingFile();
void FindBus();
void QuickSort(int left, int right);

int main()
{
	setlocale(LC_ALL, "rus");
	bool Cycle = true, Add = true, Order = true;
	int What;
	ReadingFile();
	while (Cycle == true)
	{
		cout << " 1-Режим добавления автобусов \n 2-Заказ билетов \n 3-Выход \n";
		cin >> What;
		switch (What)
		{
		case 1:
			while (Add == true)
			{
				cout << " 1-Добавление автобуса \n 2-Список автобусов \n 3-Сортировка \n 4-Sort \n 5-Выход \n";
				cin >> What;
				switch (What)
				{
				case 1:
					AddBus();
					break;
				case 2:
					ShowBus();
					break;
				case 3:
					Quantity--;
					QuickSort(0, Quantity);
					WritetoFile();
					Quantity++;
					break;
				case 4:
					Sort();
					break;
				case 5:
					Add = false;
					break;
				default:
					cout << "Попробуйте еще раз. \n";
					break;
				}
			}
			Add = true;
			break;
		case 2:
			while (Order == true)
			{
				cout << " 1-Поиск автобуса \n 2-Выход \n";
				cin >> What;
				switch (What)
				{
				case 1:
					FindBus();
					break;
				case 2:
					Order = false;
					break;
				default:
					cout << "Попробуйте еще раз. \n";
					break;
				}
			}
			Order = true;
			break;
		case 3:
			Cycle = false;
			break;
		default:
			cout << "Попробуйте еще раз. \n";
			break;
		}

	}
	return 0;
}

void AddBus()
{
	TemporarlyInfo = new Bus[Quantity];
	for (int i = 0; i < Quantity; i++)
	{
		TemporarlyInfo[i].NumberOfBus = Info[i].NumberOfBus;
		TemporarlyInfo[i].Place = Info[i].Place;
		TemporarlyInfo[i].TimeEnd = Info[i].TimeEnd;
		TemporarlyInfo[i].TimeStart = Info[i].TimeStart;
	}
	Info = new Bus[Quantity + 1];
	for (int i = 0; i < Quantity; i++)
	{
		Info[i].NumberOfBus = TemporarlyInfo[i].NumberOfBus;
		Info[i].Place = TemporarlyInfo[i].Place;
		Info[i].TimeEnd = TemporarlyInfo[i].TimeEnd;
		Info[i].TimeStart = TemporarlyInfo[i].TimeStart;
	}
	delete[] TemporarlyInfo;
	cout << "Номер втобуса" << endl;
	cin >> Info[Quantity].NumberOfBus;
	cout << "Место прибытия" << endl;
	cin >> Info[Quantity].Place;
	cout << "Время отбытия(формат 15.17)" << endl;
	cin >> Info[Quantity].TimeStart;
	cout << "Время прибытия(формат 16.19)" << endl;
	cin >> Info[Quantity].TimeEnd;
	Quantity++;
	WritetoFile();
}

void ShowBus()
{
	cout << setw(20) << "Номер автобуса" << setw(20) << "Место прибытия" << setw(20) << "Время отбытия" << setw(20) << "Время прибытия" << endl;
	for (int i = 0; i < Quantity; i++)
	{
		cout << setw(20) << Info[i].NumberOfBus << setw(20) << Info[i].Place << setw(20) << Info[i].TimeStart << setw(20) << Info[i].TimeEnd << endl;
	}
}

void WritetoFile()
{
	file.open("InfoBus.txt", ios_base::trunc);
	for (int i = 0; i < Quantity; i++)
	{
		file << " " << Info[i].NumberOfBus << ";" << Info[i].Place << ";" << Info[i].TimeStart << ";" << Info[i].TimeEnd << ";";
	}
	file.close();
}

void ReadingFile()
{
	int DopNumber = -1, Shetchik = 0, LengthStr, Index, IndexStart, IndexEnd;
	string str;
	Quantity = 0;
	files.open("InfoBus.txt", ios::in);
	getline(files, str);
	files.close();
	LengthStr = str.length();
	for (int i = 0; i < LengthStr; i++)
	{
		if (str[i] == ' ')
			Quantity++;
	}
	Info = new Bus[Quantity];
	for (int i = 0; i < LengthStr; i++)
	{
		if (str[i] == ' ')
		{
			DopNumber++;
			Shetchik = 0;
			IndexStart = i;
		}
		if (str[i] == ';')
		{
			if (Shetchik != 0)
			{
				Index = IndexEnd;
			}
			IndexEnd = i;
			if (Shetchik == 0)
			{
				Info[DopNumber].NumberOfBus = str.substr(IndexStart + 1, IndexEnd - IndexStart - 1);
				Shetchik++;
			}
			else
			{
				if (Shetchik == 1)
				{
					Info[DopNumber].Place = str.substr(Index + 1, IndexEnd - Index - 1);
					Shetchik++;
				}
				else
				{
					if (Shetchik == 2)
					{
						Info[DopNumber].TimeStart = str.substr(Index + 1, IndexEnd - Index - 1);
						Shetchik++;
					}
					else
					{
						if (Shetchik == 3)
						{
							Info[DopNumber].TimeEnd = str.substr(Index + 1, IndexEnd - Index - 1);
							Shetchik++;
						}
					}
				}
			}
		}
	}
	
}

void Sort()
{
	for (int i = 1; i<Quantity; i++)
		for (int j = i; j>0 && atoi(Info[j - 1].NumberOfBus.c_str()) >= atoi(Info[j].NumberOfBus.c_str()); j--)
			swap(Info[j - 1], Info[j]);
	WritetoFile();
}

void TimeStringinInt(string Time)
{
	Hour = atoi(Time.substr(0, 2).c_str());
	Minute = atoi(Time.substr(3, 2).c_str());
}

void FindBus()
{
	string DesirablePlace, PreferredTime;
	int DopHour, DopMinute;
	int Counter = 0;
	cout << "Введите пункт назначения: " << endl;
	cin >> DesirablePlace;
	cout << "Введите время прибытия(формат 16.04): " << endl;
	cin >> PreferredTime;
	TimeStringinInt(PreferredTime);
	DopHour = Hour;
	DopMinute = Minute;
	for (int i = 0; i < Quantity; i++)
	{
		if (Info[i].Place == DesirablePlace)
		{
			TimeStringinInt(Info[i].TimeEnd);
			if (Hour < DopHour || (Hour == DopHour && Minute <= DopMinute))
			{
				if (Counter == 0)
				{
					cout << setw(20) << "Номер автобуса" << setw(20) << "Место прибытия" << setw(20) << "Время отбытия" << setw(20) << "Время прибытия" << endl;
				}
				Counter++;
				cout << setw(20) << Info[i].NumberOfBus << setw(20) << Info[i].Place << setw(20) << Info[i].TimeStart << setw(20) << Info[i].TimeEnd << endl;
			}
		}
	}
	if (Counter == 0)
	{
		cout << "К сожалению мы ничего не нашли. Попробуйте еще раз." << endl;
	}
}

void QuickSort(int left, int right)
{
	int i = left, j = right;
	int DopHour, DopMinute;
	TimeStringinInt(Info[(left + right) / 2].TimeEnd);
	DopHour = Hour;
	DopMinute = Minute;
	while (i <= j) {
		while (atoi(Info[i].TimeEnd.substr(0, 2).c_str()) < DopHour || (atoi(Info[i].TimeEnd.substr(0, 2).c_str()) == DopHour && atoi(Info[i].TimeEnd.substr(3, 2).c_str()) < DopMinute))
			i++;
		while (atoi(Info[j].TimeEnd.substr(0, 2).c_str()) > DopHour || (atoi(Info[j].TimeEnd.substr(0, 2).c_str()) == DopHour && atoi(Info[j].TimeEnd.substr(3, 2).c_str()) > DopMinute))
			j--;
		if (i <= j) {
			swap(Info[i], Info[j]);
			i++;
			j--;
		}
	};
	if (left < j)
		QuickSort(left, j);
	if (i < right)
		QuickSort(i, right);

}