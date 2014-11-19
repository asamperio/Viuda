#pragma once
#include <iostream>
#include <string>
using namespace std;

class Carta
{
	string valor; // As=1, Rey=13 (1 al 13)
	string palo; // Espadas=1, Corazones=2, Diamantes=3, Treboles=4
public:
	Carta();
	Carta(string _valor, string _palo);
	~Carta();
	int getPeso();
	int getPalo();
	friend ostream& operator <<(ostream& os, Carta& carta);
};

