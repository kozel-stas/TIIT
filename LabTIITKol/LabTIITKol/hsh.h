#pragma once
#include <string>//заголовочный файл, который сожержит все вызываемые функции
using namespace std;
#ifndef hsh_H
#define hsh_H

struct Hash_table;
void Init(int Num);
void View(string key);
void Add(string key, string info);
int Find(string key);
int Function1(string str);
int Function2(string str);
void View(string str);
void Delete(string str);
#endif