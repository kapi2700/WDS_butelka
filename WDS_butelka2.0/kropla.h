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
 * \brief Klasa Kropla
 * 
 * Klasa definiujaca krople, zawiera wszystkie informacje o jej po�o�eniu oraz ostatnich obrotach.
 * Pozwala na wygodne wykonywanie ruch�w oraz sprawdzanie kolizji
 */
class kropla
{
public:
	/**
	 * \brief Wektor polozenia kropli.
	 * 
	 * Zawiera informacje o po�o�eniu kropli, wykorzystuje klas� wektor3D.
	 */
	wektor3D p;
	/**
	 * \biref Wektor polozenia kropli wewnatrz butelki.
	 * 
	 * Zawiera informacje o po�o�eniu kropli, wzgl�dem uk�adu wsp�rz�dnych obr�conego, zgodenie z butelk�,
	 * wykorzystuje klas� wektor3D
	 */
	wektor3D wew;	//wspolrzedne po obr�ceniu
	/**
	 * \brief Promie� kropli.
	 * 
	 * Promie� kropli, jego warto�� jest sta�a i jest ustawiana podczas inicjalizowania kropli.
	 */
	float r;
	/**
	 * \brief K�t x.
	 * 
	 * K�t wzgl�dem osi x, obrotu kropli wzgl�dem �rodka uk�adu wsp�rz�dnych.
	 */
	float kx;
	/**
	 * \brief K�t y.
	 * 
	 * K�t wzgl�dem osi y, obrotu kropli wzgl�dem �rodka uk�adu wsp�rz�dnych.
	 */
	float ky;
	/**
	 * \brief K�t z.
	 * 
	 * K�t wzgl�dem osi z, obrotu kropli wzgl�dem �rodka uk�adu wsp�rz�dnych.
	 */
	float kz;
	/**
	 * \brief Zmienna m�wi�ca, czy kropla jest wewn�trz butelki
	 * 
	 * Zmienna m�wi�ca czy kropla jest wewn�trz butelki, true- kropla znajduje sie wewnatrz butelki, false- kropla znajduje sie na zewnatrz butelki
	 */
	bool wewnatrz;
	/**
	 * \brief Rysuje krople na ekranie.
	 * 
	 * Metoda odpowiadaj�ca, za rysowanie kropli na ekranie. Jej po�o�enie jest definiowane za pomoc� pola p.
	 */
	void rysuj();
	
	/**
	 * \brief Inicjalizuje klas� obiekt kropla.
	 * 
	 * Podczas inicjalizowania, nadaje warto�� r=0.05 oraz sprawdza, czy jej po�o�enie nie b�dzie kolidowa� z pozosta�ymi kroplami
	 */
	kropla();
	~kropla();
	/**
	 * \brief Obraca krople wzgledem �rodka wsp�rz�dnych.
	 * 
	 * Obracanie kropli wykonwane jest, wraz z obrotem butelki, nie potrzeba sprawdza� kolizji podczas wykonywania tej metody.
	 * 
	 * \param x - k�t x
	 * \param y - k�t y
	 * \param z - k�t z
	 */
	void obroc(float x, float y, float z);

	//void grawitacja();
	/**
	 * \brief Sprawdza odleglosc kropli, od podanego wektora.
	 * 
	 * Metoda pozwalaj�ca na �atwe ustalenie odleg�o�ci kroli, wzgl�dem �rodka innego obiektu.
	 * 
	 * \param start - wektor od ktorego sprawdzana jest odleglosc
	 * \return - otrzymana odleglosc
	 */
	float odleglosc(wektor3D start);
	
	/**
	 * \brief Sprawdza czy kropla b�dzie kolidowa� z inn� kropl�.
	 * 
	 * Pozwala na proste sprawdzenie mo�liwo�ci ruchu. Wykorzystywane do symulowania grawitacji
	 * 
	 * \param ruch - wokonywany ruch
	 * \param a - kropla, z kt�r� jest sprawdzana kolizja
	 * \return  informacje o kolizji
	 * \retval true - kolizja
	 * \retval false - brak kolizji
	 * 
	 */
	bool kolizja(wektor3D ruch, kropla a);
	
	/**
	 * \brief Wykonuje ruch kropli.
	 * 
	 * Metoda ta zmienia dane o po�o�eniu kropli zmieniaj�c pola p oraz wew klasy kropla.
	 * 
	 * \param wek - jak kropla powinna si� ruszy�
	 */
	void ruch(wektor3D wek);
	/**
	 * \brief Sprawdza, czy kropla b�dzie kolidowa� z butelk�.
	 * 
	 * Pozwala na proste sprwadzenie mo�liwo�ci ruchu. W tej metodzie, butelka jest przybli�ana do dw�ch po��czonych ze sob� walc�w.
	 * 
	 * \param ruch - ruch jaki kropla ma wykona�
	 * \return  informacje o kolizji
	 * \retval true - kolizja
	 * \retval false - brak kolizji
	 */
	bool kolizja(wektor3D ruch);
};

