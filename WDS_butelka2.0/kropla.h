/*****************************************************************//**
 * \file   kropla.h
 * \brief  Klasa reprezentuj¹ca krople
 * 
 * Klasa reprezentuj¹ca pojedyncz¹ krople, wykorzystywana w klasie woda
 * 
 * \author kapi2
 * \date   May 2021
 *********************************************************************/
#pragma once
#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include <time.h>
#include <stdlib.h>

class kropla
{
	float p[3];
	float r;
public:
	/**
	 * Rysuje krople na ekranie.
	 * 
	 */
	void rysuj();
	kropla();
};

