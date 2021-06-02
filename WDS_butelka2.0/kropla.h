/*****************************************************************//**
 * \file   kropla.h
 * \brief  Klasa reprezentuj�ca krople
 * 
 * Klasa reprezentuj�ca pojedyncz� krople, wykorzystywana w klasie woda
 * 
 * \author kapi2
 * \date   May 2021
 *********************************************************************/
#pragma once
#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include <time.h>
#include <stdlib.h>
#include <vector>

#include "wektor3D.h"

using namespace std;

/**
 * Klasa definiujaca krople.
 */
class kropla
{
public:
	/**
	 * Wektor polozenia kropli.
	 */
	wektor3D p;
	/**
	 * Wektor polozenia kropli wewnatrz butelki.
	 */
	wektor3D wew;	//wspolrzedne po obr�ceniu
	/**
	 * Promie� kropli.
	 */
	float r;
	/**
	 * K�t obrotu kropli wzgl�dem �rodka uk�adu wsp�rz�dnych.
	 */
	float kx, ky, kz;
	/**
	 * Zmienna m�wi�ca czy kropla jest wewn�trz butelki.
	 */
	bool wewnatrz;
	/**
	 * Rysuje krople na ekranie.
	 * 
	 */
	void rysuj();
	kropla();
	~kropla();
	/**
	 * Obraca krople wzgledem �rodka wsp�rz�dnych.
	 * 
	 * \param x - k�t x
	 * \param y - k�t y
	 * \param z - k�t z
	 */
	void obroc(float x, float y, float z);

	//void grawitacja();
	/**
	 * Sprawdza odleglosc kropli, od podanego wektora.
	 * 
	 * \param start - wektor od ktorego sprawdzana jest odleglosc
	 * \return - otrzymana odleglosc
	 */
	float odleglosc(wektor3D start);
	/**
	 * Sprawdza czy kropla b�dzie kolidowa� z inn� kropl�.
	 * 
	 * \param ruch - wokonywany ruch
	 * \param a - kropla, z kt�r� jest sprawdzana kolizja
	 * \return  - true - kolizja, false - brak kolizji
	 */
	bool kolizja(wektor3D ruch, kropla a);
	/**
	 * Wykonuje ruch kropli.
	 * 
	 * \param wek - jak kropla powinna si� ruszy�
	 */
	void ruch(wektor3D wek);
	/**
	 * Sprawdza, czy kropla b�dzie kolidowa� z butelk�.
	 * 
	 * \param ruch - ruch jaki kropla ma wykona�
	 * \return - true - kolizja, false - brak kolizji
	 */
	bool kolizja(wektor3D ruch);
};

