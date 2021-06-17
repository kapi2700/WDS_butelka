/*****************************************************************//**
 * \file   scena.h
 * \brief  * Klasa zawieraj�ca wszystkie wy�wietlane obiekty
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
 * Klasa scena zawiera wszystkie wy�wietlane obiekty. Pozwala na �atwe obracanie obietk�w znajduj�ych si� w niej
 * oraz wy�wietlanie ich.
 */
class scena
{
	/**
	 * \brief ilosc kropli
	 * 
	 * Zmienna informuj�ca o ilo�ci kropli na scenie
	 */
	int ilosc_kropli;		//ilosc kropli
public:
	/**
	 * \brief Obiekty znajdujace sie na scenie (poza wod�).
	 * 
	 * Obiekty znajdujace sie na scenie (poza wod�).
	 */
	vector<obiekt3D> obiekty;
	/**
	 * \bief Woda znajduj�ca si� na scenie.
	 * 
	 * Woda znajduj�ca si� na scenie.
	 */
	woda w;

	/**
	 * \brief Inicjuje klase scena.
	 * 
	 * Inicjuje klase scena. Nie zmienia informacji dotycz�cych pola ob. Inicjuje ona tylko warto�� m oraz w.
	 * 
	 * \param n - ilo�� kropli wody
	 */
	scena(int n);
	/**
	 * \brief Obrot obiektow na scenie
	 * 
	 * Pozwala na proste zczytanie z odpowiedniego pliku danych dotycz�cych obrotu oraz obr�t na ich podstawie
	 * wszystkich obiekt�w znajduj�cych si� na scenie, poza kroplami znajduj�cymi si� poza butelk�.
	 * 
	 */
	void obrot();

	/**
	 * \brief Rysuje wszystkie obiekty nale��ce do sceny.
	 * 
	 * Rysuje wszystkie obiekty nale��ce do sceny.
	 */
	void rysuj();
};

