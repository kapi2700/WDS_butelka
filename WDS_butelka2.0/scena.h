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

class scena
{
	/**
	 * Ilo�� kropli.
	 */
	int m;		//ilosc kropli
public:
	/**
	 * Obiekty znajdujace sie na scenie (poza wod�).
	 */
	vector<obiekt3D> ob;
	/**
	 * woda znajduj�ca si� na scenie.
	 */
	woda w;

	/**
	 * Inicjuje klase scena.
	 * 
	 * \param n- ilo�� kropli wody
	 */
	scena(int n);
	/**
	 * Obru� wszystko, co znajduje si� na scenie.
	 * 
	 */
	void obrot();

	//void init(int n);
	/**
	 * Rysuje wszystkie obiekty nale��ce do sceny.
	 * 
	 */
	void rysuj();
};

