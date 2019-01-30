#pragma once
#include "pch.h"
#include<vector>
#include <iostream>


class Vectory
{
private:
	
	struct oblast {
		int a;
		int b;
		char c;
		
	};
	typedef struct oblast oblast;

	std::vector<int> skupina;
	std::vector<oblast> vect;
	

public:
	struct Interval {
		int a;
		int b;
		char c;

	};

	void pridaj(char b, int a);
	void od_najv();
	void vypis();
	void vlastne_sorty();
	
	Vectory();
	~Vectory();
};

