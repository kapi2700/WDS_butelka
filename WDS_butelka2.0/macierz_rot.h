/*****************************************************************//**
 * \file   macierz_rot.h
 * \brief  Klasa macierz rotacji, wykorzystywana do obracania wektor�w/obiekt�w
 * 
 * \author kapi2
 * \date   May 2021
 *********************************************************************/
#pragma once
#include <math.h>


/**
 * Klasa macierz rotacji.
 */
class macierz_rot
{
public:
	float p[3][3];

	/**
	 * Inicjuje macierz warto�ciami do macierzy rotacji w wybranej osi.
	 * 
	 * \param a- k�t obrotu
	 * \param o- o� obrotu
	 */
	macierz_rot(float a,char o);
};

