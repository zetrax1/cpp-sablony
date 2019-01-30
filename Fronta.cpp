#include "pch.h"
#include "Fronta.h"
#include <iostream>


Fronta::Fronta():first(nullptr),last(nullptr),pocet(0)
{
}

void Fronta::presun(int co, int kde)
{
	polozka *pred = first;
	polozka *tmp=first;
	//pre prvu polosku platia ine pravidla :D 

	
	//najdi co :D
	for (int i = 0; i < co; i++) {
		pred = tmp;
		tmp = tmp->next;
	}

}


void Fronta::zmaz(int poradie)
{
	// poradie urcuje pocet od zaciatku ,ktora polozka sa odstrani 
	polozka *tmp=first;
	polozka *pred = first;
	//osetrenie aby sme sa nesnazili zmazat prvok ktory tam nieje
	if (poradie >= this->pocet) {
		return;
	}

	//moznost a) poradie =0;
	if (poradie == 0) {
		
		first = first->next;
		if (last == first) {
			last = nullptr;
		}
		delete(tmp);
		this->pocet--;
		return;
	}
	
	//moznost c) ostatne prvky

	tmp = tmp->next;
	for (int i = 1; i < poradie; i++) {
		tmp = tmp->next;
		pred = pred->next;
	}
	pred->next = tmp->next;
	delete(tmp);
	this->pocet--;
	return;



}


void Fronta::vypis()
{
	//overenie ci zoznam existuje
	if (first == nullptr) {
		std::cout << "neexistuju ziadne poloznky zoznamu";
		return;
	}
	//výpis vsetkych poloziek zoznamu 
	polozka *tmp = first;

	while (tmp != nullptr) {
		std::cout << tmp->cislo << tmp->znak << std::endl;
		tmp = tmp->next;
	}

	return;

}

void Fronta::add(int i, char a)
{
	polozka *nova = new polozka();
	//naplnenie novej structury polozka
	nova->cislo = i;
	nova->znak = a;
	nova->next = nullptr;

	// zretazenie

	if (first == nullptr) {
		first = nova;
		last = nova;	
	}
	else {
		last->next = nova;
		last = last->next;
	}

	this->pocet++;
}

void Fronta::vycisti()
{
	polozka *tmp = first,*pred;

	for (int i = 0; i < pocet; i++) {
		tmp = first;
		for (int j = 0; j < pocet-i; j++) {
			tmp = tmp->next;
		}
		delete(tmp);
		


	}
	delete(first);
	first = nullptr;

	pocet = 0;
}


Fronta::~Fronta()
{
}
