#pragma once
#include "Interfata.h"
#include<string>
#include <iostream>
using namespace std;
class Masina : public Interfata
{
private:
	string marca;
	int viteza = 0;
	int viteza_maxima;
	float  distanta = 0;
	bool stare_motor = false;
public:
	Masina()
	{
		cout << "Ce marca este masina cumparata? "; cin >> this->marca;
		cout << "Care este viteza pe care o poate atinge? "; cin >> this->viteza_maxima;
		this->afisare();
	};

	void afisare()
	{
		cout << "Marca masinii este " << this->marca << " si poate atinge " << this->viteza_maxima << " km/h" << endl;
	};
	void accelerare(int pas)
	{
		if (this->viteza <= this->viteza_maxima - pas)
		{   
			this->viteza += pas;
			
			cout << "Masina acum a accelerat si merge cu viteza " << this->viteza << " km/h ";
			if (this->viteza_maxima-5 <= this->viteza+pas && this->viteza+pas<=this->viteza_maxima)
			{
				cout << endl;
				cout << "Atentie! Daca mai accelerati veti depasi viteza de " << this->viteza_maxima-5 << " km/h";

			}
		}
		else if (this->viteza < this->viteza_maxima && this->viteza_maxima - this->viteza < pas)
		{
			int x = this->viteza_maxima - this->viteza;
			this->viteza += this->viteza_maxima - this->viteza;
			cout << "Nu mai puteti accelera cu pasul initial, se accelereaza cu pasul " << x << " si se atinge viteza maxima ";
		
		}

		else  cout << " ATI ATINS VITEZA MAXIMA!";
	};
	void  decelerare(int pas)
	{
		if (this->viteza != 0 && this->viteza >= pas)
		{
			this->viteza -= pas;
			cout << " Masina acum a decelerat si merge cu viteza " << this->viteza << " km/h";
			
		}
		else if (this->viteza != 0 && this->viteza < pas)
		{
			this->viteza = 0;
		}
		else cout << "Atentie!! Masina a atins deja viteza de stationare";
	};
	void pornire_motor()
	{
		stare_motor = true;
		cout << endl << " S-a pornit motorul masinii" << endl;
	};
	void oprire_motor()
	{
		if (this->viteza == 0)
		{
			cout << endl << " S-a oprit motorul masinii " << endl;
			this->stare_motor = false;
			cout << "Starea motorului este " << this->stare_motor;
		}
		else
		{

			cout << endl;
			cout << "Nu putem opri masina din mers va rugam decelerati" << endl;

		}

	};

	int get_viteza_curenta()
	{
		return this->viteza;
	};

	bool get_stare_motor()
	{
		return this->stare_motor;
	};

	float get_distanta_parcursa()
	{
		return this->distanta;
	};

	void incrementare_distanta(int viteza, int timp_parcurs)
	{
		this->distanta += (timp_parcurs * viteza * 1000) / 3600;
	};



};