/*****************************************************************//**
 * \file   scena.h
 * \brief  * Klasa zawieraj¹ca wszystkie wyœwietlane obiekty
 * 
 * \author kapi2
 * \date   April 2021
 *********************************************************************/
#pragma once
#include <vector>
#include "obiekt3D.h"
#include "woda.h"

/**
 * \brief Klasa scena.
 * 
 * Klasa scena zawiera wszystkie wyœwietlane obiekty. Pozwala na ³atwe obracanie obietków znajduj¹ych siê w niej
 * oraz wyœwietlanie ich.
 */
class scena
{
	/**
	 * \brief ilosc kropli
	 * 
	 * Zmienna informuj¹ca o iloœci kropli na scenie
	 */
	int ilosc_kropli;		//ilosc kropli
public:
	/**
	 * \brief Obiekty znajdujace sie na scenie (poza wod¹).
	 * 
	 * Obiekty znajdujace sie na scenie (poza wod¹).
	 */
	vector<obiekt3D> obiekty;
	/**
	 * \bief Woda znajduj¹ca siê na scenie.
	 * 
	 * Woda znajduj¹ca siê na scenie.
	 */
	woda w;

	/**
	 * \brief Inicjuje klase scena.
	 * 
	 * Inicjuje klase scena. Nie zmienia informacji dotycz¹cych pola ob. Inicjuje ona tylko wartoœæ m oraz w.
	 * 
	 * \param n - iloœæ kropli wody
	 */
	scena(int n);
	/**
	 * \brief Obrot obiektow na scenie
	 * 
	 * Pozwala na proste zczytanie z odpowiedniego pliku danych dotycz¹cych obrotu oraz obrót na ich podstawie
	 * wszystkich obiektów znajduj¹cych siê na scenie, poza kroplami znajduj¹cymi siê poza butelk¹.
	 * 
	 */
	void obrot();

	/**
	 * \brief Rysuje wszystkie obiekty nale¿¹ce do sceny.
	 * 
	 * Rysuje wszystkie obiekty nale¿¹ce do sceny.
	 */
	void rysuj();
};

