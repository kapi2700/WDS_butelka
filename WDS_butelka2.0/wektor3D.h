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

/**
 * \brief Klasa wektor3D.
 * 
 * Klasa ta zawiera informacje o po�o�eniu wektora oraz pozwala na �atwe wyliczenie wektora po obrocie. 
 * Dodatkowo istnieje mo�liwo�� obliczenia odleg�o�ci wektora od osi Y.
 */
class wektor3D
{
public:
	/**
	 * \brief Wsp�rz�dne 3D.
	 * 
	 * Wsp�rz�dne wektora w kolejno�ci x, y oraz z. W programie o� y jest osi� pionow�.
	 */
	float p[3];
	/**
	 * \brief Obracanie wektora
	 * 
	 * Mno�y wektor przez macierz rotacji 3x3.
	 * 
	 * \param[in] m - macierz rotacji
	 */
	void mnozenie(macierz_rot m);
	/**
	 * \brief Inicjuje wektor3D
	 * 
	 * Ustawia jego po�o�enie na (0,0,0)
	 */
	wektor3D();

	/**
	 * \bief Odleg�o�� od osi Y.
	 * 
	 * Metoda ta wylicza odleg�o�� wektora od osi Y.
	 * 
	 * \return - odleglosc od osi Y
	 */
	float odlegloscY();
};

/**
 * \brief Dodawanie wektorow.
 * 
 * Dodawanie wektorow.
 */
wektor3D operator + (wektor3D a, wektor3D b);
/**
 * \biref Odejmowanie wektorow.
 * 
 * Odejmowanie wektorow.
 */
wektor3D operator - (wektor3D a, wektor3D b);
/**
 * \brief Por�wnywanie wektor�w.
 * 
 * Por�wnywanie wektor�w.
 */
bool operator == (wektor3D a, wektor3D b);
