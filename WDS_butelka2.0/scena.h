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

class scena
{
	/**
	 * Iloœæ kropli.
	 */
	int m;		//ilosc kropli
public:
	/**
	 * Obiekty znajdujace sie na scenie (poza wod¹).
	 */
	vector<obiekt3D> ob;
	/**
	 * woda znajduj¹ca siê na scenie.
	 */
	woda w;

	/**
	 * Inicjuje klase scena.
	 * 
	 * \param n- iloœæ kropli wody
	 */
	scena(int n);
	/**
	 * Obruæ wszystko, co znajduje siê na scenie.
	 * 
	 */
	void obrot();

	//void init(int n);
	/**
	 * Rysuje wszystkie obiekty nale¿¹ce do sceny.
	 * 
	 */
	void rysuj();
};

