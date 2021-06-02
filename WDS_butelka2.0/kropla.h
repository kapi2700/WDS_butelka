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
	wektor3D wew;	//wspolrzedne po obróceniu
	/**
	 * Promieñ kropli.
	 */
	float r;
	/**
	 * K¹t obrotu kropli wzglêdem œrodka uk³adu wspó³rzêdnych.
	 */
	float kx, ky, kz;
	/**
	 * Zmienna mówi¹ca czy kropla jest wewn¹trz butelki.
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
	 * Obraca krople wzgledem œrodka wspó³rzêdnych.
	 * 
	 * \param x - k¹t x
	 * \param y - k¹t y
	 * \param z - k¹t z
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
	 * Sprawdza czy kropla bêdzie kolidowaæ z inn¹ kropl¹.
	 * 
	 * \param ruch - wokonywany ruch
	 * \param a - kropla, z któr¹ jest sprawdzana kolizja
	 * \return  - true - kolizja, false - brak kolizji
	 */
	bool kolizja(wektor3D ruch, kropla a);
	/**
	 * Wykonuje ruch kropli.
	 * 
	 * \param wek - jak kropla powinna siê ruszyæ
	 */
	void ruch(wektor3D wek);
	/**
	 * Sprawdza, czy kropla bêdzie kolidowaæ z butelk¹.
	 * 
	 * \param ruch - ruch jaki kropla ma wykonaæ
	 * \return - true - kolizja, false - brak kolizji
	 */
	bool kolizja(wektor3D ruch);
};

