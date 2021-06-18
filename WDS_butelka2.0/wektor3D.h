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

/**
 * \brief Klasa wektor3D.
 * 
 * Klasa ta zawiera informacje o po³o¿eniu wektora oraz pozwala na ³atwe wyliczenie wektora po obrocie. 
 * Dodatkowo istnieje mo¿liwoœæ obliczenia odleg³oœci wektora od osi Y.
 */
class wektor3D
{
public:
	/**
	 * \brief Wspó³rzêdne 3D.
	 * 
	 * Wspó³rzêdne wektora w kolejnoœci x, y oraz z. W programie oœ y jest osi¹ pionow¹.
	 */
	float p[3];
	/**
	 * \brief Obracanie wektora
	 * 
	 * Mno¿y wektor przez macierz rotacji 3x3.
	 * 
	 * \param[in] m - macierz rotacji
	 */
	void mnozenie(macierz_rot m);
	/**
	 * \brief Inicjuje wektor3D
	 * 
	 * Ustawia jego po³o¿enie na (0,0,0)
	 */
	wektor3D();

	/**
	 * \bief Odleg³oœæ od osi Y.
	 * 
	 * Metoda ta wylicza odleg³oœæ wektora od osi Y.
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
 * \brief Porównywanie wektorów.
 * 
 * Porównywanie wektorów.
 */
bool operator == (wektor3D a, wektor3D b);
