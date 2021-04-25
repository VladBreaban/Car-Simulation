
#include <stdlib.h>
#include <iostream>
#include "Masina.h"
#include <ctime>
#include <cmath>
#define pas_accelerare 3
#define pas_decelerare 5
//using namespace std;

int main()
{
	//initializarea masinii
	Masina* m = new Masina();
	//system("cls");
	cout << endl << " FELICITARI ACUM AVETI O MASINA " << endl << endl;
	char varianta;
	cout << "Apasati tasta P pentru a porni masina "; cin >> varianta;

	//masina fiind oprita, singura varianta este sa o pornesti(nu poti accelera, decelera cu masina oprita)
	while (varianta != 'P')
	{
		cout << "Masina porneste doar cu tasta P, va rugam reintroduceti";
		cin >> varianta;
	}
	m->pornire_motor();
	cout << "Viteza curenta: " << m->get_viteza_curenta() << endl;

	clock_t time_prev = clock();
	

	while (varianta != 'S' || m->get_viteza_curenta() != 0)
	{
		
		cout << endl;
		cout << "Ce doriti sa faceti?(A=accelerare,  D=decelerare, S=oprire motor  " << endl; cin >> varianta;

		//imediat dupa ce utilizatorul a apasat alt buton, calculam intervalul de timp scurs, updatam time_prev si adaugam distanta parcursa in intervalul respectiv
		int time_dif = clock() - time_prev; //timpul scurs intre apasarea celor 2 butoane
		time_prev = clock();				//memorez timpul la care s-a facut a doua apasare
		m->incrementare_distanta(m->get_viteza_curenta(), time_dif / CLOCKS_PER_SEC); //incrementarea distantei totale cu distanta parcursa in intervalul de timp 																					
		
		cout << "De la comanda anterioara au trecut " << time_dif / CLOCKS_PER_SEC  << " secunde si ati mai parcurs " << time_dif / CLOCKS_PER_SEC * m->get_viteza_curenta() * 1000 / 3600 << " metri" << endl;
		
		switch (varianta)
		{

		case 'S':
			m->oprire_motor();
			cout << endl;
			cout << "Viteza curenta: " << m->get_viteza_curenta();
			break;
		case 'A':
			m->accelerare(pas_accelerare);
			cout << endl;
			cout << "Viteza curenta: " << m->get_viteza_curenta();
			break;
		case 'D':
			m->decelerare(pas_decelerare);
			cout << endl;
			cout << "Viteza curenta: " << m->get_viteza_curenta();
			break;
		default:
			cout << "In timp ce masina este pornita puteti apasa doar A D S ";


		}
	 // timpul trimis ca parametru va fi diferenta dintre timpul actual si cel intial(cand am ales instructiunea)
		
		
		//system("cls");
		//system("pause");
	}
	cout << endl;
	cout << "Calatoria s-a terminat. Doriti sa vedeti cat ati parcurs? Daca da, apasati E, in caz contrar apasati orice tasta " << endl;
	cin >> varianta;
	cout << endl;
	if (m->get_stare_motor() == false && varianta == 'E')
	{
		cout << " Masina stationeaza si a parcurs " << m->get_distanta_parcursa() << " metri";
	}

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
