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

class woda
{
public:
	vector<kropla> k;
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
};

