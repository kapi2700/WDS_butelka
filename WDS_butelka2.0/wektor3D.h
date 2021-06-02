/*****************************************************************//**
 * \file   wektor3D.h
 * \brief  Klasa wektor3D
 * 
 * Wykorzystywana do zapisywania po�o�enia obiekt�w
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
	 * Wsp�rz�dne 3D.
	 */
	float p[3];
	/**
	 * Mno�y wektor przez macierz rotacji 3x3.
	 * 
	 * \param m - macierz rotacji
	 */
	void mnozenie(macierz_rot m);
	wektor3D();

	/**
	 * Odleg�o�� punktu od osi Y.
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
 * Por�wnywanie wektor�w.
 */
bool operator == (wektor3D a, wektor3D b);
