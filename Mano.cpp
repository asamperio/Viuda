#include "Mano.h"


Mano::Mano(string _nombreJugador)
{
	nombreJugador = _nombreJugador;
}

Mano::~Mano()
{
}

void Mano::recibirCarta(Carta _cartaRecibida)
{
	cartas.push_front(_cartaRecibida);
}

Carta Mano::entregarCarta(int _pos)
{
	Carta auxParaEntregar;
	
	list<Carta>::iterator it;

	it = cartas.begin();
	advance(it, _pos-1);
	auxParaEntregar = *it;
	cartas.erase(it);
	
	return auxParaEntregar;
		
}

void Mano::recibirLista(list<Carta> _cartasRecibidas)
{
	cartas = _cartasRecibidas;
}

list<Carta> Mano::entregarLista()
{
	auto listaAux = cartas;
	cartas.clear();
	return listaAux;
}

bool Mano::CheckHighCard()
{
	int aux = 0;
	for (auto i = cartas.begin(); i != cartas.end(); i++)
	{
		if ((*i).getPeso() > aux)
		{
			aux = (*i).getPeso();
		}
	}
	peso = aux;
	jugada = 1;
	return true;
}

bool Mano::CheckPair()
{
	for (auto it1 = cartas.begin(); it1 != cartas.end(); it1++)
	{
		for (auto it2 = cartas.begin(); it2 != cartas.end(); it2++)
		{
			if (  ((*it1).getPeso() == (*it2).getPeso())  && it1!=it2)
			{
				peso = (*it1).getPeso();
				jugada = 2;
				return true;
			}
		}		
	}

}

bool Mano::CheckTwoPair()
{
	for (auto it1 = cartas.begin(); it1 != cartas.end(); it1++)
	{
		for (auto it2 = cartas.begin(); it2 != cartas.end(); it2++)
		{
			if (((*it1).getPeso() == (*it2).getPeso()) && (it1 != it2) )
			{
				for (auto it3 = cartas.begin(); it3 != cartas.end(); it3++)
				{
					for (auto it4 = cartas.begin(); it4 != cartas.end(); it4++)
					{
						if (((*it3).getPeso() == (*it4).getPeso()) && (it3 != it4) && (it1 != it3) && (it1 != it4) && (it2 != it3) && (it2 != it4))
						{
							if ((*it1).getPeso() > (*it3).getPeso())
							{
								peso = (*it1).getPeso();
							}
							else
							{
								peso = (*it3).getPeso();
							}
							jugada = 3;
							return true;
						}
					}
				}
			}
		}
	}

	
}

bool Mano::CheckThreeOfAKind()
{
	for (auto it1 = cartas.begin(); it1 != cartas.end(); it1++)
	{
		for (auto it2 = cartas.begin(); it2 != cartas.end(); it2++)
		{
			for (auto it3 = cartas.begin(); it3 != cartas.end(); it3++)
			{
				if (((*it1).getPeso() == (*it2).getPeso()) && ((*it1).getPeso() == (*it3).getPeso()) && (it1 != it2) && (it1 != it3) && (it2 != it3))
				{
					peso = (*it1).getPeso();
					jugada = 4;
					return true;
				}
			}
			
		}
	}
}

bool Mano::CheckStraight()
{
	list<Carta> aux;

	for (auto i1 = cartas.begin(); i1 != cartas.end(); i1++)
	{
		if (!aux.empty())
		{
			for (auto i2 = aux.begin(); i2 != aux.end(); i2++)
			{
				if ((*i2).getPeso() >= (*i1).getPeso())
				{
					aux.insert(i2, *i1);
					break;
				}
				else 
				{ 
					i2++;
					aux.insert(i2,*i1); 
					break; 
				}
				
			}
		}
		else { aux.push_front(*i1); }
	}
		

	list<Carta>::iterator it1, it2, it3, it4, it5;
	it1 = it2 = it3 = it4 = it5 = aux.begin();
	advance(it2, 1); advance(it3, 2); advance(it4, 3); advance(it5, 4);

	//cout << *it1 << *it2 << *it3 << *it4 << *it5 << endl << endl;
	if (((*it2).getPeso() == ((*it1).getPeso() + 1)) && ((*it3).getPeso() == ((*it2).getPeso() + 1)) && ((*it4).getPeso() == ((*it3).getPeso() + 1)) && ((*it5).getPeso() == ((*it4).getPeso() + 1)))
	{
		peso = (*it5).getPeso();
		jugada = 5;
		return true;
	}
	else { return false; }
}

bool Mano::CheckFlush()
{
	list<Carta>::iterator it1, it2, it3, it4, it5;
	it1=it2=it3=it4=it5 = cartas.begin();
	advance(it2, 1); advance(it3, 2); advance(it4, 3); advance(it5, 4);
	
	if (((*it1).getPalo() == (*it2).getPalo()) && ((*it1).getPalo() == (*it3).getPalo()) && ((*it1).getPalo() == (*it4).getPalo()) && ((*it1).getPalo() == (*it5).getPalo()))
	{
		int aux = 0;
		for (auto i = cartas.begin(); i != cartas.end(); i++)
		{
			if ((*i).getPeso() > aux)
			{
				aux = (*i).getPeso();
			}
		}
		peso = aux;
		jugada = 6;
		return true;
	}
}

bool Mano::CheckFullHouse()
{
	for (auto it1 = cartas.begin(); it1 != cartas.end(); it1++)
	{
		for (auto it2 = cartas.begin(); it2 != cartas.end(); it2++)
		{
			for (auto it3 = cartas.begin(); it3 != cartas.end(); it3++)
			{
				if (((*it1).getPeso() == (*it2).getPeso()) && ((*it1).getPeso() == (*it3).getPeso()) && (it1!=it2) &&(it1!=it3)&&(it2!=it3))
				{
					for (auto it4 = cartas.begin(); it4 != cartas.end(); it4++)
					{
						for (auto it5 = cartas.begin(); it5 != cartas.end(); it5++)
						{
							if (((*it4).getPeso() == (*it5).getPeso()) && (it4 != it5) && ((*it1).getPeso() != (*it4).getPeso()))
							{
								peso = (*it1).getPeso();
								jugada = 7;
								return true;
							}
						}
					}
				}
			}
		}
	}
}

bool Mano::CheckFourOfAKind()
{
	for (auto it1 = cartas.begin(); it1 != cartas.end(); it1++)
	{
		for (auto it2 = cartas.begin(); it2 != cartas.end(); it2++)
		{
			for (auto it3 = cartas.begin(); it3 != cartas.end(); it3++)
			{
				for (auto it4 = cartas.begin(); it4 != cartas.end(); it4++)
				{
					if (((*it1).getPeso() == (*it2).getPeso()) && ((*it1).getPeso() == (*it3).getPeso()) && ((*it1).getPeso() == (*it4).getPeso()) && (it1 != it2) && (it1 != it3) && (it1 != it4) && (it2 != it3) && (it2 != it4) && (it3 != it4))
					{
						peso = (*it1).getPeso();
						jugada = 8;
						return true;
					}
				}
			}
		}
	}

}

bool Mano::CheckStraighFlush()
{
	list<Carta> aux;

	for (auto i1 = cartas.begin(); i1 != cartas.end(); i1++)
	{
		if (!aux.empty())
		{
			for (auto i2 = aux.begin(); i2 != aux.end(); i2++)
			{
				if ((*i2).getPeso() >= (*i1).getPeso())
				{
					aux.insert(i2, *i1);
					break;
				}
				else
				{
					i2++;
					aux.insert(i2, *i1);
					break;
				}

			}
		}
		else { aux.push_back(*i1); }
	}


	list<Carta>::iterator it1, it2, it3, it4, it5;
	it1 = it2 = it3 = it4 = it5 = aux.begin();
	advance(it2, 1); advance(it3, 2); advance(it4, 3); advance(it5, 4);
	//cout << *it1 << *it2 << *it3 << *it4 << *it5 << endl << endl;
	if (((*it2).getPeso() == ((*it1).getPeso() + 1)) && ((*it3).getPeso() == ((*it2).getPeso() + 1)) && ((*it4).getPeso() == ((*it3).getPeso() + 1)) && ((*it5).getPeso() == ((*it4).getPeso() + 1))&& ((*it1).getPalo() == (*it2).getPalo()) && ((*it1).getPalo() == (*it3).getPalo()) && ((*it1).getPalo() == (*it4).getPalo())&&((*it1).getPalo() == (*it5).getPalo()))
	{
		peso = (*it5).getPeso();
		jugada = 9;
		return true;
	}
	else { return false; }
}

//bool Mano::CheckRoyalFlush()
//{
//
//}
//

void Mano::HacerJugada()
{
	if (!CheckStraighFlush())
	{
		if (!CheckFourOfAKind())
		{
			if (!CheckFullHouse())
			{
				if (!CheckFlush())
				{
					if (!CheckStraight())
					{
						if (!CheckThreeOfAKind())
						{
							if (!CheckTwoPair())
							{
								if (!CheckPair())
								{
									if (!CheckHighCard())
									{
										void;
									}
								}
							}
						}
					}
				}
			}
		}
	}
}

ostream& operator<<(ostream& os, Mano& mano)
{
	int j = 1;
	for (auto i = mano.cartas.begin(); i != mano.cartas.end(); i++)
	{
		os << "Carta "<<j<<endl << *i << endl; j++;
	}
	return os;
}


