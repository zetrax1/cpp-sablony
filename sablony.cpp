// sablony.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include<vector>
#include <iostream>
#include "Trieda.h"
#include <string>
#include "Fronta.h"
#include "Vectory.h"
#include <algorithm>   
#include "Subor_txt.h"

// strukt˙ra pre sp·jan˝ zoznam 
struct nazov {
	int a;
	char b;
	std::string  meno;
	struct nazov *dalsi;
};
typedef struct nazov nazov;



void polia() 
{
//inicializuj vûdy na zaËiatku , kompil·tor vo windowse je svina 

	std::string s0("Initial string");
	//pole structur :
	nazov pole[32];
	nazov *pole2 = (nazov*)malloc(sizeof(nazov) * 32);
	nazov *pole3 = new nazov;

	pole[30].a = 2;
	pole2[33].a = 2;
	pole3[32].a = 2;


//	printf("%d\n", pole[30].a);
//	printf("%d\n", pole2[33].a);
//	printf("%d\n", pole3[32].a);

//pole tried;
// zbav n·s zlÈho - windows je smrù 
	char a = 'a';

	Trieda *jedna = new Trieda(a,s0);
//	Trieda *pole4[32];
	

	Trieda **pole4 = new Trieda*;
	for (int i = 0; i < 32; i++) {
		pole4[i] = new Trieda(a, s0);
	}
	
	printf("%d\n", pole4[4]->geta());
	printf("%d\n", pole4[5]->geta());

	return;



}



void test_fronta() {

	Fronta *test = new Fronta();

	test->add(1, 'd');
	test->add(2, 'g');
	test->add(3, 'h');

	test->vycisti();


	test->vypis();
	printf("podarilo sa");
}




void test_vector()
{

	Vectory *vec = new Vectory();

	vec->pridaj('a',1);
	vec->vypis();
	vec->od_najv();
    vec->vlastne_sorty();
	vec->vypis();

}

void test_subory() 
{
	std::ifstream inFile;
	std::string name, temp,prva, druha, tretie;
	int age;

	inFile.open("sub.txt");


	getline(inFile, prva, ' '); // Now temp is "Smith"
	getline(inFile, druha, ' '); // Now temp is "Smith"
	getline(inFile, tretie, '\n'); // Now temp is "Smith"
	getline(inFile, temp, '\n'); // Now temp is "Smith"
	
	inFile >> age;
	name += temp;
	


	std::cout << prva << druha << tretie << name << age << std::endl;

	// zapis easy

	inFile.close();
	std::ofstream myfile;

	myfile.open("sub.txt");
	myfile << "Writing this to a file.\n";
	myfile.close();



}



//generovanie random cisel do 32 bez 32
int random_cislo(int i) {
	srand(i);

	return (rand() % 32);
}

// zabezpecenie rozsahu 0-31 bez opakovanie
bool over(int tmp, int *pole, int i) {

	for (int j = 0; j < i; j++) {
		if (tmp == pole[j]) {
			return true;
		}
	}
	return false;
}


 // funkcia na vytvorenie nahodne umiestnenych cisel v poli 
void zamiesaj(int **pole) {

	int tmp;
	int l = 0;
	for (int i = 0; i < 32; i++) {
		tmp = random_cislo(l);
		//	printf("%d \n", tmp);
		if (over(tmp, *pole, i)) {
			i--;
			//	printf("zhoda\n");
		}
		else {
			(*pole)[i] = tmp;
			printf("%d \n", tmp);
		}


		l++;
	}
}

void test_random() {

	int *pole = (int*)malloc(32 * sizeof(int));
	zamiesaj(&pole);
}

int main()
{
	//test_subory();
   // test_vector
	//test_fronta();
	test_random();
	return 0;
	
	


}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
