#include <iostream>

using namespace std;

/*
  Definicja typu wyliczeniowego "Symbol" dla symboli  a, b, c, d, e.
*/
enum Symbol {e, a, b, c, d};

Symbol TabDod[5][5] = {
	{e, a, b, c, d},
	{a, d, e, b, c},
	{b, e, c, d, a},
	{c, b, d, a, e},
	{d, c, a, e, b}
	};

Symbol TabMnoze[5][5] = {
	{e, e, e, e, e},
	{e, a, b, c, d},
	{e, b, a, d, c},
	{e, c, d, b, a},
	{e, d, c, a, b}
	};

/*
  Definicja funkcji: Dodaj, PrzeciwnyDodawania, Odejmij, Mnoz, OdwrotnyMnozenia, Dziel.
*/
Symbol Dodaj(Symbol pierwsza, Symbol druga)
{

	return TabDod[pierwsza][druga];
}

Symbol PrzeciwnyDodawania(Symbol pierwsza)
{
 	Symbol Przeciw[5] = {e, b, a, d, c};
	return Przeciw[pierwsza];
}

Symbol Odejmij(Symbol pierwsza, Symbol druga)
{
	druga = PrzeciwnyDodawania(druga);
	return TabDod[pierwsza][druga];
}

Symbol Mnoz(Symbol pierwsza, Symbol druga)
{

	return TabMnoze[pierwsza][druga];
}

Symbol Odwrotny(Symbol pierwsza)
{ 	
	Symbol Odwr[5] = {e, a, b, d, c};
	return Odwr[pierwsza];
}

Symbol Dziel(Symbol pierwsza, Symbol druga)
{
	druga = Odwrotny(druga);
	return TabMnoze[pierwsza][druga];
}

/*
  Definicja przeciążeń operatorów
*/

void Porownaj(Symbol wynik_alg, Symbol wynik_ope, Symbol wynik_fun)
{
 cout << ((wynik_alg == wynik_fun) ? "Identyczne" : "Rozne") 
      << " wyniki wyrazenia algebraicznego i funkcyjnego." << endl;

 cout << ((wynik_ope == wynik_fun) ? "Identyczne" : "Rozne") 
      << " wyniki wyrazenia operatorowego i funkcyjnego." << endl;

 cout << ((wynik_ope == wynik_alg) ? "Identyczne" : "Rozne") 
      << " wyniki wyrazenia operatorowego i algebraicznego." << endl;
}

int main()
{
 Symbol wynik_alg, wynik_ope, wynik_fun;


	wynik_alg = Dziel(b,b);
	cout << static_cast<int>(wynik_alg) << endl;
/*--------------------
  Po wpisaniu odpowiednich wyrażeń znaki komentujące
  poniższy zestaw instrukcji należy usunąć.

 wynik_alg = WYRAZENIE_ALG_1; // <- Wyrażenie zapisane w sposób zwyczajowy
 wynik_fun = WYRAZENIE_FUN_1; // <- Wyrażenie wykorzystujące funkcje
 wynik_ope = WYRAZENIE_OPE_1; // <- Wyrażenie z jawnym wywołaniem operatorów 

 Porownaj(wynik_alg,wynik_ope,wynik_fun);

 wynik_alg = WYRAZENIE_ALG_2; // <- Wyrażenie zapisane w sposób zwyczajowy
 wynik_fun = WYRAZENIE_FUN_2; // <- Wyrażenie wykorzystujące funkcje
 wynik_ope = WYRAZENIE_OPE_2; // <- Wyrażenie z jawnym wywołaniem operatorów 

 Porownaj(wynik_alg,wynik_ope,wynik_fun);

 wynik_alg = WYRAZENIE_ALG_3; // <- Wyrażenie zapisane w sposób zwyczajowy
 wynik_fun = WYRAZENIE_FUN_3; // <- Wyrażenie wykorzystujące funkcje
 wynik_ope = WYRAZENIE_OPE_3; // <- Wyrażenie z jawnym wywołaniem operatorów 

 Porownaj(wynik_alg,wynik_ope,wynik_fun);

 wynik_alg = WYRAZENIE_ALG_4; // <- Wyrażenie zapisane w sposób zwyczajowy
 wynik_fun = WYRAZENIE_FUN_4; // <- Wyrażenie wykorzystujące funkcje
 wynik_ope = WYRAZENIE_OPE_4; // <- Wyrażenie z jawnym wywołaniem operatorów 

 Porownaj(wynik_alg,wynik_ope,wynik_fun);
 */
	return 0;
}
