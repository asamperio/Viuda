#include "Carta.h"


Carta::Carta()
{
}

Carta::Carta(string _valor, string _palo)
{
	valor = _valor;
	palo = _palo;
}

Carta::~Carta()
{
}

int Carta::getPeso()
{
	if (valor == "A")
	{
		return 14;
	}
	else if (valor == "J")
	{
		return 11;
	}
	else if (valor == "Q")
	{
		return 12;
	}
	else if (valor == "K")
	{
		return 13;
	}
	else
	{
		stoi(valor);
	}
}

int Carta::getPalo()
{
	if (palo == "Espadas")
	{
		return 1;
	}
	else if (palo == "Corazones")
	{
		return 2;
	}
	else if (palo == "Diamantes")
	{
		return 3;
	}
	else if (palo == "Treboles")
	{
		return 4;
	}
}

ostream& operator <<(ostream& os, Carta& carta)
{
	os << "Valor: " << carta.valor << endl;
	os << "Palo: " << carta.palo << endl;
	return os;
}
