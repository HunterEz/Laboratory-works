#pragma once
#include <iostream>
#include "Event.h"
#include "Tree.h"
using namespace std;
class Dialog :
	public Tree
{
public:
	Dialog(void);
public:
	virtual ~Dialog(void);
	virtual void GetEvent(TEvent& event);
	virtual int Execute();
	virtual void HandleEvent(TEvent& event);
	virtual void ClearEvent(TEvent& event);
	int Valid();
	void EndExec();
protected:
	int EndState;
};

