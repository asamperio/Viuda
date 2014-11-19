#pragma once
#include <iostream>
#include "Carta.h"
#include <list>
#include <string>

using namespace std;


class Mano
{
	string nombreJugador;
	list<Carta> cartas;
	int jugada = 0;
	int peso = 0;

	bool CheckHighCard();
	bool CheckPair();
	bool CheckTwoPair();
	bool CheckThreeOfAKind();
	bool CheckStraight();
	bool CheckFlush();
	bool CheckFullHouse();
	bool CheckFourOfAKind();
	bool CheckStraighFlush();
	/*bool CheckRoyalFlush();*/

public:
	Mano(string _nombreJugador);
	~Mano();
	void recibirCarta(Carta _cartaRecibida);
	Carta entregarCarta(int _pos);
	void recibirLista(list<Carta> _cartasRecibidas);
	list<Carta> entregarLista();
	
	void HacerJugada();
	int getJugada(){ return jugada; }
	int getPeso(){ return peso; }
	string getNombreJugador(){ return nombreJugador; }
	friend ostream& operator<<(ostream& os, Mano& mano);
};

