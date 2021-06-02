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
 * Klasa macierz rotacji.
 */
class macierz_rot
{
public:
	/**
	 * Wartoœci macierzy.
	 */
	float p[3][3];

	/**
	 * Inicjuje macierz wartoœciami do macierzy rotacji w wybranej osi.
	 * 
	 * \param a- k¹t obrotu
	 * \param o- oœ obrotu
	 */
	macierz_rot(float a,char o);
};

