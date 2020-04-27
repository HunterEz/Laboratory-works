#pragma once
const int evNothung = 0;
const int evMessage = 100;
const int cmAdd = 1;
const int cmDel = 2;
const int cmGet = 3;
const int cmShow = 4;
const int cmMake = 6;
const int cmQuit = 101;

struct TEvent
{
	int what;
	union
	{
		int command;
		struct
		{
			int message;
			int a;
		};
	};
};