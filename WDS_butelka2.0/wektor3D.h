/*****************************************************************//**
 * \file   wektor3D.h
 * \brief  Klasa wektor3D
 * 
 * Wykorzystywana do zapisywania po³o¿enia obiektów
 * 
 * \author kapi2
 * \date   May 2021
 *********************************************************************/
#pragma once
#include "macierz_rot.h"

class wektor3D
{
public:
	/**
	 * Wspó³rzêdne 3D.
	 */
	float p[3];
	/**
	 * Mno¿y wektor przez macierz rotacji 3x3.
	 * 
	 * \param m - macierz rotacji
	 */
	void mnozenie(macierz_rot m);
	wektor3D();

	/**
	 * Odleg³oœæ punktu od osi Y.
	 * 
	 * \return - odleglosc od osi Y
	 */
	float odlegloscY();
};

/**
 * Dodawanie wektorow.
 */
wektor3D operator + (wektor3D a, wektor3D b);
/**
 * Odejmowanie wektorow.
 */
wektor3D operator - (wektor3D a, wektor3D b);
/**
 * Porównywanie wektorów.
 */
bool operator == (wektor3D a, wektor3D b);
