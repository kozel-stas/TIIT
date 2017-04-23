// Lab2TIITDouble2XXXX.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;


int **vertex, **Graf, **Modif;
int **vertex1;
int Number, height, shet;
int xrxrx=0;
int infinity = 0;
int root = 0;
int y = 0;
 
struct Stek
{
	int a;
	Stek *Head, *Next;
};

Stek *List = new Stek;
Stek *Fantasyisempty = new Stek;
Stek *List1 = new Stek;

void I_want_some_drugs(Stek *List);
int Find22(int f);
void I_want_to_sleep(int start, int end);
int Ostis_top(int x,Stek *List);
int Patience_is_running_out(Stek *Fantasyisempty);
int FindInStek(int x, Stek *List);
int Find(int f);
void Add(int a, Stek *&List);
void Delete(Stek *List);
void Remove(Stek *List);
int Amountofknowledge(Stek *List);
int SoDeep();

int main()
{
	int answer;
	int sh = 0;
	int h = 0;
	int i1,i2;
	int ary = 0;
	int y1;
	string str;
	List->Head = NULL;
	Fantasyisempty->Head = NULL;
	List1->Head = NULL;
	ifstream file("maze.in");
	getline(file, str);
	h = str.length();
	for (int i = 0; i < h; i++)
		if (str[i] == ' ')
		{
			i1 = i;
			break;
		}
	Number=shet = atoi(str.substr(0, i1).c_str());
	height = atoi(str.substr(i1, h).c_str());
	vertex = new int *[shet];
	for (int i = 0; i < shet; i++)
		vertex[i] = new int[2];
	Graf = new int *[height];
	for (int i = 0; i < height; i++)
		Graf[i] = new int[3];
	for (int i = 0; i < height; i++)
	{
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
			if (str[j] == ' ' && sh == 1 && j!=i1)
			{
				i2 = j;
				break;
			}
		}
		Graf[i][0] = atoi(str.substr(0, i1).c_str());
		Graf[i][1] = atoi(str.substr(i1, i2).c_str());
		Graf[i][2] = atoi(str.substr(i2, h).c_str());
	}
	file.close();
	ary = 0;
	for (int i = 0; i < height; i++)
	{
		y1 = 0;
		for (int j = 0; j < ary; j++)
		{
			if (Graf[i][0] != vertex[j][0])
				y1++;
		}
		if (y1 == ary)
		{
			vertex[ary][0] = Graf[i][0];
			vertex[ary][1] = 0;
			ary++;
		}
		y1 = 0;
		for (int j = 0; j < ary; j++)
		{
			if (Graf[i][1] != vertex[j][0])
				y1++;
		}
		if (y1 == ary)
		{
			vertex[ary][0] = Graf[i][1];
			vertex[ary][1] = 0;
			ary++;
		}
	}
	shet = ary;
	ofstream file1("maze.out");
	answer = SoDeep();
	if (root == 1)
	{
		if (infinity == 1)
		{
			file1 << "'':)\"";
		}
		else
		{
			file1 << answer;
		}
	}
	else
	{
		file1 << "'':(\"";
	}
    return 0;
}

void I_want_some_drugs(Stek *List)
{
	xrxrx = 0;
	Stek *dop1 = new Stek;
	Stek *dop2 = new Stek;
	dop1 = List->Head->Next;
	while (dop1->Next != NULL)
	{
		dop2 = dop1->Next;
		while (dop2 != NULL)
		{
			if (dop1->a == dop2->a)
				xrxrx = -58;
			else
			{
				I_want_to_sleep(dop1->a, dop2->a);
			}
			dop2 = dop2->Next;
		}
		if (xrxrx == -58) break;
		else dop1 = dop1->Next;
	}
	for (int i = 0; i < height; i++)
	{
		if (Graf[i][0] == Graf[i][1] && FindInStek(Graf[i][0], List) == 1)
		{
			xrxrx = -58;
			break;
		}
	}
}

void I_want_to_sleep(int start, int end)
{
	int shetchik = 0;
	int answer = 0;
	int min;
	int high = 0;
	int origin;
	int Stoppoint = 0;
	vertex1 = new int*[shet];
	for (int i = 0; i < shet; i++)
		vertex1[i] = new int[2];
	for (int i = 0; i < shet; i++)
	{
		vertex1[i][0] = vertex[i][0];
		vertex1[i][1] = 0;
		if (vertex[i][0] == Number)
			vertex1[i][1] = 1;
	}
	origin = start;
	vertex1[Find22(origin)][1] = 1;
	Add(origin, List1);
	while (Stoppoint != -56)
	{
		min = 0;
		high = 0;
		Remove(Fantasyisempty);
		for (int i = 0; i < height; i++)
		{
			if (Graf[i][0] == origin && vertex1[Find22(Graf[i][1])][1] == 0)
			{
				Add(Graf[i][1], Fantasyisempty);
				high++;
			}
		}
		if (high != 0)
		{
			min = Patience_is_running_out(Fantasyisempty);
		}
		if (min == end)
		{
			Add(min, List1);
			Remove(List1);
			Stoppoint = -56;
			xrxrx = -58;
		}
		else
		{
			if (high != 0)
			{
				origin = min;
				vertex1[Find22(origin)][1] = 1;
				Add(origin, List1);
			}
			else
			{
				if (origin == start)
				{
					Remove(List1);
					Stoppoint = -56;
				}
				else
				{
					Delete(List1);
					for (int i = 0; i < height; i++)
					{
						if (Graf[i][0] == origin)
						{
							if (FindInStek(Graf[i][1], List1) != 1)
							{
								if (Graf[i][1] == Graf[i][0])
								{}
								else
								{
									if (Ostis_top(Graf[i][1], List1) == 0)
										vertex1[Find22(Graf[i][1])][1] = 0;
									vertex1[Find22(Number)][1] = 1;
								}
							}
						}
					}
					origin = List1->Head->a;
				}
			}
		}
	}
}

int Ostis_top(int x,Stek *List)
{
	int Dan = 0;
	int Vech = 0;
	int ubuntu=1;
	int min=0;
	for (int j = 0; j < height; j++)
	{
		if (Graf[j][1] == x)
		{
			if (FindInStek(Graf[j][0], List) == 1)
			{
				Dan++;
				min = x;
				for (int i = 0; i < height; i++)
				{
					if (Graf[i][0] == Graf[j][0])
					{
						if (min > Graf[i][1])
							min = Graf[i][1];
					}
				}
				if (min == x)
					Vech++;
				min = Graf[j][0];
			}
		}
	}
	if (Dan == Vech)
	{
		ubuntu = 1;
		y = min;
	}
	else
	{
		y = 0;
		ubuntu = 0;
	}
	return ubuntu;
}

int Patience_is_running_out(Stek *Fantasyisempty)
{
	int min = Fantasyisempty->Head->a;
	Stek *dop = new Stek;
	dop = Fantasyisempty->Head;
	while (dop != NULL)
	{
		if (min > dop->a)
			min = dop->a;
		dop = dop->Next;
	}
	return min;
}

void Add(int a, Stek *&List)
{
	Stek *dop = new Stek;
	dop->a = a;
	dop->Next = List->Head;
	List->Head = dop;
}

void Delete(Stek *List)
{
	Stek *dop = new Stek;
	dop = List->Head;
	List->Head = List->Head->Next;
	delete dop;

}

void Remove(Stek *List)
{
	while (List->Head != NULL)
	{
		Stek *dop = new Stek;
		dop = List->Head->Next;
		delete List->Head;
		List->Head = dop;
	}
	List->Head = NULL;
}

int FindInStek(int x, Stek *List)
{
	int y = 0;
	Stek *dop = new Stek;
	dop = List->Head;
	while (dop != NULL)
	{
		if (dop->a == x)
		{
			y = 1;
			break;
		}
		dop = dop->Next;
	}
	return y;
}

int Amountofknowledge(Stek *List)
{
	int max;
	int yshet = 0;
	int ans = 0;
	Stek *dop = new Stek;
	dop = List->Head;
	while (dop->Next != NULL)
	{
		yshet = 0;
		for (int i = 0; i < height; i++)
		{
			if (Graf[i][0] == dop->Next->a && Graf[i][1] == dop->a)
			{
				if (yshet == 0)
				{
					max = Graf[i][2];
					yshet++;
				}
				if (max < Graf[i][2])
					max = Graf[i][2];
			}
		}
		ans += max;
		dop = dop->Next;
	}
	return ans;
}

int Find(int f)
{
	int x = 0;
	for (int i = 0; i < shet; i++)
	{
		if (f == vertex[i][0])
		{
			x = i;
			break;
		}
	}
	return x;
}

int Find22(int f)
{
	int x = 0;
	for (int i = 0; i < shet; i++)
	{
		if (f == vertex1[i][0])
		{
			x = i;
			break;
		}
	}
	return x;
}

int SoDeep()
{
	int shetchik = 0;
	bool altern = false;
	int answer = 0;
	int min;
	int high = 0;
	int origin;
	int Stoppoint = 0;
	origin = 1;
	vertex[Find(origin)][1] = 1;
	Add(origin,List);
	while (Stoppoint != -56)
	{
		min = 0;
		high = 0;
		Remove(Fantasyisempty);
		if (altern == true)
		{
			for (int i = 0; i < height; i++)
			{
				if (Graf[i][0] == origin && vertex[Find(Graf[i][1])][1] == 0)
				{
					if (Graf[i][1] == Number)
					{}
					else
					{
						Add(Graf[i][1], Fantasyisempty);
						high++;
					}
				}
			}
			altern = false;
		}
		else
		{
			for (int i = 0; i < height; i++)
			{
				if (Graf[i][0] == origin && vertex[Find(Graf[i][1])][1] == 0)
				{
					Add(Graf[i][1],Fantasyisempty);
					high++;
				}        
			}
		}
		if (high != 0)
		{
			min=Patience_is_running_out(Fantasyisempty);
		}
		if (min == Number)
		{
			root = 1;
			Add(min,List);
			if (shetchik == 0)
			{
				answer = Amountofknowledge(List);
				shetchik++;
			}
			else
			{
				if (answer < Amountofknowledge(List))
					answer = Amountofknowledge(List);
				shetchik++;
			}
			I_want_some_drugs(List);
			if (xrxrx == -58)
			{
				infinity = 1;
				Stoppoint = -56;
			}
			altern = true;
			Delete(List);
			origin = List->Head->a;
		}
		else
		{
			if (high != 0)
			{
				origin = min;
				vertex[Find(origin)][1] = 1;
				Add(origin, List);
			}
			else
			{
				if (origin == 1)
				{
					Remove(List);
					Stoppoint = -56;
				}
				else
				{
					Delete(List);
					for (int i = 0; i < height; i++)
					{
						if (Graf[i][0] == origin)
						{
							if (FindInStek(Graf[i][1], List) != 1)
							{
								if (Graf[i][1] == Graf[i][0])
								{}
								else
								{
									if (Ostis_top(Graf[i][1], List) == 0)
										vertex[Find(Graf[i][1])][1] = 0;
								}
							}
						}
					}
					origin = List->Head->a;
				}
			}
		}
	}
	return answer;
}