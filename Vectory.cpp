#include "pch.h"
#include<vector>
#include <iostream>
#include <string>
#include "Vectory.h"
#include <algorithm>   

Vectory::Vectory()
{
	
}


bool compareInterval(Vectory::Interval i1, Vectory::Interval i2)
{
	return (i1.a < i2.a);
}


void Vectory::od_najv() {

	std::vector<Interval> v{ { 6, 8,'d' }, { 1, 9 ,'d'}, { 2, 4 ,'d'}, { 4, 7 ,'d'} };
	sort(v.begin(), v.end(),compareInterval);


	std::cout << "Intervals sorted by start time : \n";
	for (auto x : v)
		std::cout << "[" << x.a << ", " << x.b << "] ";


}


void Vectory::pridaj(char b, int a)
{
	oblast nova ;
	nova.a = a;
	nova.b = b;

	vect.push_back(nova);
	nova.a = 2;
	vect.push_back(nova);
	nova.a = 3;
	vect.push_back(nova);
	//std::swap(vect[0], vect[1]);

}




void  Vectory::vlastne_sorty()
{
	//pracuj ako s polom : bouble sort easy 	
	for (int i = 0; i < (int)vect.size() - 1; i++) {

		// Last i elements are already in place    
		for (int j = 0; j < (int)vect.size() - i - 1; j++) {
			if (vect[j].a < vect[j+1].a) {
				std::swap(vect[j], vect[j+1]);
			}
		}
	}
}



void Vectory::vypis() {
	
	for (int i = 0; i < vect.size(); i++) {
		std::cout << vect[i].a << '\n';
	}
}


Vectory::~Vectory()
{
	vect.clear();

}
