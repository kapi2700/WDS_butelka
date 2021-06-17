/*****************************************************************//**
 * \file   macierz_rot.h
 * \brief  Klasa macierz rotacji, wykorzystywana do obracania wektor�w/obiekt�w
 * 
 * \author kapi2
 * \date   May 2021
 *********************************************************************/
#pragma once
#include <math.h>

#define PI 3.14159265


/**
 * \brief Klasa macierz rotacji.
 * 
 * Klasa pozwalaj�ca na wygodny obracanie obiekt�w klasy wektor3D.
 */
class macierz_rot
{
public:
	/**
	 * Warto�ci macierzy.
	 */
	float p[3][3];

	/**
	 * \brief Inicjuje macierz warto�ciami do macierzy rotacji w wybranej osi.
	 * 
	 * Macierz ta powinna by� p�niej wykorzystana podczas wykonywania metody wektor3D::mnozenie.
	 * 
	 * \param a - k�t obrotu w stopniach
	 * \param o - o� obrotu, powinna wynosic 'x', 'y' lub 'z'
	 */
	macierz_rot(float a,char o);
};

