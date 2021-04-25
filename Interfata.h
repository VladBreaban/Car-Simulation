#pragma once

class Interfata
{
public:
	virtual void accelerare(int) = 0;
	virtual void decelerare(int) = 0;
	virtual void pornire_motor() = 0;
	virtual void oprire_motor() = 0;
	virtual void incrementare_distanta(int,int) = 0;
};