#pragma once
#include <iostream>
#include "Object.h"
#include "Magazin.h"
using namespace std;

class Tree
{
public:
	Tree();
	Tree(int);
public:

	~Tree(void);
	void Add();
	void Add(Object*);
	void Del();
	void Show();
	int operator()();
	void HandleEvent(const TEvent& e);
protected:
	Object** beg;
	int size;
	int cur;
};

