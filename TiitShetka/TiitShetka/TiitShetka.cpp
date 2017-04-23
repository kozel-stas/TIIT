// TiitShetka.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct stek {
	int List[4000];
	int top = -58;
} lis;

int minpotok = 10000000;
int hhhhh;
int lin, len, lyn, shet;
int Stopoint = 0;
int width[1000][2];
int vertex[500][2];
int Graf[1000][2], Modif[2000][3];

void Trans(string str);
void Add(int x);
void Delete();
void Remove();
int Find(int f);
int Arc(int elem, int point, int lenght);
int Lol(int origin, int point,int start,int end);
int Algoritm2(int start, int end);
int Algoritm(int start, int end);

int main()
{// лен модиф лун вертекс
	int nym;
	string str;
	setlocale(LC_ALL, "rus");
	ifstream fout;
		cout << "Выберите тест \n 1 \n 2\n 3\n 4\n 5 \n";
		cin >> nym;
		switch (nym)
		{
		case 1:
			fout.open("Test1.txt");
			getline(fout, str);
			fout.close();
			Trans(str);
			break;
		case 2:
			fout.open("Test2.txt");
			getline(fout, str);
			fout.close();
			Trans(str);
			break;
		case 3:
			fout.open("Test3.txt");
			getline(fout, str);
			fout.close();
			Trans(str);
			break;
		case 4:
			fout.open("Test4.txt");
			getline(fout, str);
			fout.close();
			Trans(str);
			break;
		case 5:
			fout.open("Test5.txt");
			getline(fout, str);
			fout.close();
			Trans(str);
			break;
		default: 
			cout << "Попробуйте еще раз\n";
			break;
		}
		shet = 0;
		for (int i = 0; i < len; i++)
		{
			Modif[shet][0] = Graf[i][0];
			Modif[shet][1] = Graf[i][1];
			Modif[shet][2] = 0;
			shet++;
			Modif[shet][0] = Graf[i][1];
			Modif[shet][1] = Graf[i][0];
			Modif[shet][2] = 0;
			shet++;
		}
		for (int g = 0; g < lyn; g++)
		{
			for (int i = 0; i < lyn; i++)
			{
				Stopoint = 0;
				for (int j = 0; j < len; j++)
				{
					if (Graf[j][0] == vertex[i][0] && Graf[j][1] == vertex[g][0])
					{
						Stopoint = 58;
						break;
					}
					if (Graf[j][0] == vertex[g][0] && Graf[j][1] == vertex[i][0])
					{
						Stopoint = 58;
						break;
					}
				}
				if (vertex[g][0] != vertex[i][0] && Stopoint != 58)
				{
					hhhhh = Algoritm(vertex[i][0], vertex[g][0]);
					if (hhhhh != 0)
					{
						if (minpotok > hhhhh)
							minpotok = hhhhh;
					}
				}
			}
		}
		cout << minpotok<<endl;
		system("pause");
    return 0;
}
  
void Add(int x)
{
	if (lis.top == -58)
	{
		lis.top = 0;
		lis.List[lis.top] = x;
		lis.top++;
	}
	else
	{
		lis.List[lis.top] = x;
		lis.top++;
	}
}

void Delete()
{
	lis.top--;
}

void Remove()
{
	lis.top = -58;
}

int Find( int f)
{
	int x = 0;
	for (int i = 0; i < lyn; i++)
	{
		if (f == vertex[i][0])
		{
			x = i;
			break;
		}
	}
	return x;
}

int Arc(int elem,int point,int lenght)
{
	int lol=0,origin; 
	int point2 = lenght-1;
	origin = elem;
	while (point2 > -1)
	{
		if (width[point2][0] == origin)
		{
			origin = width[point2][1];
			lol++;
		}
		point2--;
	} 
	return lol;
}

int Lol(int origin, int point, int start, int end)
{
	int lol;
	int poi = point;
	int vertex1[500][2];
	memcpy(vertex1, vertex, sizeof(vertex1));
	while (point > -1)
	{
		if (origin != start)
		{
			if (width[point][0] == origin)
			{
				if (vertex1[Find(width[point][1])][1] != 1)
				{
					if (origin != start && origin != end)
					{
						vertex1[Find(width[point][0])][1] = 1;
						origin = width[point][1];
					}
					else
					{
						origin = width[point][1];
					}
				}
			}
		}
		point--;
    }
	if (origin == start)
	{
		lol = 1;
		memcpy(vertex, vertex1, sizeof(vertex));
	}
	else
	{

		lol = 0;
	}
	return lol;
}

int Algoritm2(int start, int end)
{
	int lenght,num;
	int potok=0,origin;
	int point;
	potok = lenght = point = 0;
	for (int i = 0; i < lyn; i++)
		vertex[i][1] = 0;
	width[lenght][0] = start;
	lenght++;
	vertex[Find(start)][1] = 2;
	do
	{
		for (int i = 0; i < len * 2; i++)
		{
			if (Modif[i][0] == width[point][0])
			{
				if (vertex[Find(Modif[i][1])][1] == 0)
				{
					if (Modif[i][1] == end)
					{
						width[lenght][0] = Modif[i][1];
						width[lenght][1] = width[point][0];
						vertex[Find(Modif[i][1])][1] = 2;
						lenght++;
						point = lenght - 2;
						break;
					}
					else
					{
						width[lenght][0] = Modif[i][1];
						width[lenght][1] = width[point][0];
						vertex[Find(Modif[i][1])][1] = 2;
						lenght++;
					}
				}
			}
		}
		point++;
	} while (point!=lenght);
	point = lenght-1;
	origin = end;
	num = 0;
	while (point > -1)
	{
			if (width[point][0] == origin)
			{
				origin = width[point][1];
				vertex[Find(width[point][0])][1] = 1;
			}
			if (origin == start)
			{
				vertex[Find(end)][1] = 0;
				num = -58;
			}
		point--;
	}
	if (num == -58)
	{
		potok = 1;
	}
	else
		potok = 0;
	for (int i = 0; i < lyn; i++)
	{
		if (vertex[i][1] == 2)
			vertex[i][1] = 0;
	}
	return potok;
}

void Trans(string str)
{
	int k;
	string st;
	int i1, i2,i3;
	int helpme = 0;
	int begi = 0;
	int h;
	shet = 0;
	int x = 1;
	h = str.length();
	for (int i = 0; i < h; i++)
	{
		if (str[i] == ' ')
		{
			len++;
		}
	}
	for (int i = 0; i < h; i++)
	{
		if (x % 2 == 0)
		{
			i1 = i3;
			if (str[i] == ' ')
			{
				i3 = i2 = i;
				x++;
				st = str.substr(i1, i2 - i1);
				Graf[begi][1] = atoi(st.c_str());
				begi++;
			}
		}
		else
		{
			if (shet == 0)
			{
				i1 = 0;
			}
			else
			{
				i1 = i3;
			}
			if (str[i] == '-')
			{
				i3 = i2 = i+1;
				st = str.substr(i1, i2 - i1);
				Graf[begi][0] = atoi(st.c_str());
				x++;
				shet++;
			}
		}
	}
	lyn = 0;
	shet = 0;
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			if (shet == 0)
			{
				vertex[lyn][0] = Graf[i][j];
				vertex[lyn][1] = 0;
				lyn++;
				shet++;
			}
			else
			{
				begi = 0;
				k = 0;
				do
				{
					if (vertex[k][0] != Graf[i][j])
						begi++;
					k++;
				} while (k != lyn);
				if (begi == lyn)
				{
					vertex[lyn][0] = Graf[i][j];
					lyn++;
				}
			}
		}
	}
}

int Algoritm(int start, int end)
{
	int potok = 0;
	int shetchik = 0;
	int num, nym = 0;
	int k;
	int origin;
	int data[999];
	int sheti = 0;
	int min = NULL;
	for (int i = 0; i < lyn; i++)
		vertex[i][1] = 0;
	num=Algoritm2(start, end);
	if (num == 0)
	{}
	else
	{
		potok = 1;
	}
	Add(start);
	num = Find(start);
	vertex[num][1] = 1;
	origin = start;
	while (nym != 58)
	{
		sheti = 0;
		min = start;
		for (int i = 0; i < len * 2; i++)
		{
			if (Modif[i][0] == origin)
			{
				num = Find(Modif[i][1]);
				if (vertex[num][1] == 0 && Modif[i][1] != start)
				{
					min = data[sheti] = Modif[i][1];
					sheti++;
				}
			}
		}
		for (int j = 0; j < sheti; j++)
		{
			if (min > data[j])
				min = data[j];
		}
		if (min == end)
		{
			Add(min);
			potok++;
			Remove();
			origin = start;
		}
		else
		{
			if (sheti != 0)
			{
				Add(min);
				num = Find(min);
				vertex[num][1] = 1;
				origin = min;
			}
			else
			{
				if (origin != start)
				{

					Delete();
					origin = lis.List[lis.top-1];
				}
				else
				{
					origin = start;
					nym = 58;
				}
			}
		}
	}
	return potok;
}