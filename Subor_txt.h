#pragma once
#include<iostream>
#include <fstream>
class Subor_txt
{
private:

	std::ifstream file;
	std::string name, temp;
	int age;

public:

	void nacitaj();
	Subor_txt();
	~Subor_txt();
};

