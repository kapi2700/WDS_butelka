/*****************************************************************//**
 * \file   woda.h
 * \brief  Klasa woda
 * 
 * Klasa sk³adaj¹ca siê z kropli wody, reprezentuj¹ca wodê
 * 
 * \author kapi2
 * \date   May 2021
 *********************************************************************/
#pragma once
#include <vector>
#include <windows.h>

#include "kropla.h"

using namespace std;

class woda
{
public:
	vector<kropla> k;
	woda() {}
	/**
	 * Inicjuje krople wody.
	 * 
	 * \param n iloœæ kropli
	 */
	woda(int n);
	/**
	 * Rysuje wszystkie krople sk³adaj¹ce siê na wodê.
	 * 
	 */
	void rysuj();
};

