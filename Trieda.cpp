#include "pch.h"
#include "Trieda.h"


Trieda::Trieda(char b ,std::string meno):a(3)
{
	this->b = b;
	this->meno = meno;
}


int Trieda::geta()
{
	return this->a;
}

Trieda::~Trieda()
{
}
