#include <iostream>
#include <string>
#include <forward_list>
#include <stack>
#include <vector>
#include <algorithm>
#include "Carta.h"
#include "Mano.h"
#include <list>
using namespace std;
const int numJugadores = 3;

stack<Carta> crearDeck()
{
	vector<Carta> deckVector = vector<Carta>();

	deckVector.push_back(Carta("A", "Espadas"));
	deckVector.push_back(Carta("2", "Espadas"));
	deckVector.push_back(Carta("3", "Espadas"));
	deckVector.push_back(Carta("4", "Espadas"));
	deckVector.push_back(Carta("5", "Espadas"));
	deckVector.push_back(Carta("6", "Espadas"));
	deckVector.push_back(Carta("7", "Espadas"));
	deckVector.push_back(Carta("8", "Espadas"));
	deckVector.push_back(Carta("9", "Espadas"));
	deckVector.push_back(Carta("10", "Espadas"));
	deckVector.push_back(Carta("J", "Espadas"));
	deckVector.push_back(Carta("Q", "Espadas"));
	deckVector.push_back(Carta("K", "Espadas"));

	deckVector.push_back(Carta("A", "Corazones"));
	deckVector.push_back(Carta("2", "Corazones"));
	deckVector.push_back(Carta("3", "Corazones"));
	deckVector.push_back(Carta("4", "Corazones"));
	deckVector.push_back(Carta("5", "Corazones"));
	deckVector.push_back(Carta("6", "Corazones"));
	deckVector.push_back(Carta("7", "Corazones"));
	deckVector.push_back(Carta("8", "Corazones"));
	deckVector.push_back(Carta("9", "Corazones"));
	deckVector.push_back(Carta("10", "Corazones"));
	deckVector.push_back(Carta("J", "Corazones"));
	deckVector.push_back(Carta("Q", "Corazones"));
	deckVector.push_back(Carta("K", "Corazones"));

	deckVector.push_back(Carta("A", "Diamantes"));
	deckVector.push_back(Carta("2", "Diamantes"));
	deckVector.push_back(Carta("3", "Diamantes"));
	deckVector.push_back(Carta("4", "Diamantes"));
	deckVector.push_back(Carta("5", "Diamantes"));
	deckVector.push_back(Carta("6", "Diamantes"));
	deckVector.push_back(Carta("7", "Diamantes"));
	deckVector.push_back(Carta("8", "Diamantes"));
	deckVector.push_back(Carta("9", "Diamantes"));
	deckVector.push_back(Carta("10", "Diamantes"));
	deckVector.push_back(Carta("J", "Diamantes"));
	deckVector.push_back(Carta("Q", "Diamantes"));
	deckVector.push_back(Carta("K", "Diamantes"));

	deckVector.push_back(Carta("A", "Treboles"));
	deckVector.push_back(Carta("2", "Treboles"));
	deckVector.push_back(Carta("3", "Treboles"));
	deckVector.push_back(Carta("4", "Treboles"));
	deckVector.push_back(Carta("5", "Treboles"));
	deckVector.push_back(Carta("6", "Treboles"));
	deckVector.push_back(Carta("7", "Treboles"));
	deckVector.push_back(Carta("8", "Treboles"));
	deckVector.push_back(Carta("9", "Treboles"));
	deckVector.push_back(Carta("10", "Treboles"));
	deckVector.push_back(Carta("J", "Treboles"));
	deckVector.push_back(Carta("Q", "Treboles"));
	deckVector.push_back(Carta("K", "Treboles"));

	random_shuffle(deckVector.begin(), deckVector.end());

	stack<Carta> deckStack;

	for (auto i = deckVector.begin(); i != deckVector.end(); i++)
	{
		deckStack.push(*i);
	}

	return deckStack;
}

int menuPrimeraRonda(Mano jugador)
{
	int opcion;
	cout << "1.- Cambiar mano completa" << endl;
	cout << "2.- Pasar" << endl;
	cin >> opcion;
	return opcion;
}

int main()
{
	//Inscribir Jugadores
	list<Mano> listaDeJugadores;
	string nombreJugador;
	for (int i = 0; i < numJugadores; i++)
	{
		cout << "Nombre del jugador " << i+1 << ": "; cin >> nombreJugador; cout << endl;
		listaDeJugadores.push_back(Mano(nombreJugador));
	}

	//Generar Deck
	stack<Carta> deck = crearDeck();

	//Repartir cartas
	Mano viuda=Mano("Viuda");
	for (auto it = listaDeJugadores.begin(); it != listaDeJugadores.end(); it++)
	{
		for (int i = 0; i < 5; i++)
		{
			(*it).recibirCarta(deck.top()); deck.pop();
		}
	}
	for (int i = 0; i < 5; i++)
	{
		viuda.recibirCarta(deck.top()); deck.pop();
	}


	//Primera Ronda
	bool deckVolteado = false;
	auto it = listaDeJugadores.begin();
	while (it != listaDeJugadores.end() && !deckVolteado)
	{
		int opcion = menuPrimeraRonda(*it);
		if (opcion == 1)
		{
			deckVolteado = true;
			list<Carta> aux = (*it).entregarLista();
			(*it).recibirLista(viuda.entregarLista());
			viuda.recibirLista(aux);
		}
		it++;
	}
	if (it == listaDeJugadores.end())
	{
		it = listaDeJugadores.begin();
	}


	//Rondas normales
	bool tocar = false;
	auto it = listaDeJugadores.begin();
	while (it != listaDeJugadores.end() && !deckVolteado)
	{
		int opcion = menuPrimeraRonda(*it);
		if (opcion == 1)
		{
			deckVolteado = true;
			list<Carta> aux = (*it).entregarLista();
			(*it).recibirLista(viuda.entregarLista());
			viuda.recibirLista(aux);
		}
		it++;
	}
	if (it == listaDeJugadores.end())
	{
		it = listaDeJugadores.begin();
	}
	








	/*for (auto it = listaDeJugadores.begin(); it != listaDeJugadores.end(); it++)
	{
		cout << *it << endl;
	}*/


	/*bool bocaAbajo = false;
	int numTurno = 1;
	while (bocaAbajo && numTurno < 2)
	{

	}*/

	
}

