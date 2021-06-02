/*****************************************************************//**
 * \file   woda.h
 * \brief  Klasa woda
 * 
 * Klasa sk�adaj�ca si� z kropli wody, reprezentuj�ca wod�
 * 
 * \author kapi2
 * \date   May 2021
 *********************************************************************/
#pragma once
#include <vector>
#include <windows.h>

#include "kropla.h"

using namespace std;

/**
 * Klasa zawierajaca krople wody.
 */

class woda
{
	/**
	 * Zmienne przechowywujace kat obrotu wody.
	 */
	float kx, ky, kz;
public:
	/**
	 * Zmienna przechowywujaca kazda krople wody.
	 */
	vector<kropla> k;
	/**
	 * Ilosc kropli wody.
	 */
	int l;
	woda() {}
	/**
	 * Inicjuje krople wody.
	 * 
	 * \param n ilo�� kropli
	 */
	woda(int n);
	/**
	 * Rysuje wszystkie krople sk�adaj�ce si� na wod�.
	 * 
	 */
	void rysuj();
	/**
	 * Obraca woda wzgledem 0,0,0.
	 * 
	 * Wykorzystywane do obracania wody, podczas obracania butelki
	 * 
	 * \param x - kat w osi x
	 * \param y - kat w osi y
	 * \param z - kat w osi z
	 */
	void obroc(float x, float y, float z);
	/**
	 * Grawitacja dzialajaca na wode.
	 * 
	 */
	void grawitacja();
};

