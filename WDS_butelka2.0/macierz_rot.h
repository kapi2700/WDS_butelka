/*****************************************************************//**
 * \file   macierz_rot.h
 * \brief  Klasa macierz rotacji, wykorzystywana do obracania wektorów/obiektów
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
 * Klasa pozwalaj¹ca na wygodny obracanie obiektów klasy wektor3D.
 */
class macierz_rot
{
public:
	/**
	 * Wartoœci macierzy.
	 */
	float p[3][3];

	/**
	 * \brief Inicjuje macierz wartoœciami do macierzy rotacji w wybranej osi.
	 * 
	 * Macierz ta powinna byæ póŸniej wykorzystana podczas wykonywania metody wektor3D::mnozenie.
	 * 
	 * \param a - k¹t obrotu w stopniach
	 * \param o - oœ obrotu, powinna wynosic 'x', 'y' lub 'z'
	 */
	macierz_rot(float a,char o);
};

