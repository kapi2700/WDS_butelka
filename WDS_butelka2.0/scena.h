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
public:
	vector<obiekt3D> ob;
	woda w;

	/**
	 * Inicjuje klase scena.
	 * 
	 * \param n- ilo�� kropli wody
	 */
	scena(int n);
};

