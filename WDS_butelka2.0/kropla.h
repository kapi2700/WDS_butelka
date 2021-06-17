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
 * \brief Klasa Kropla
 * 
 * Klasa definiujaca krople, zawiera wszystkie informacje o jej po³o¿eniu oraz ostatnich obrotach.
 * Pozwala na wygodne wykonywanie ruchów oraz sprawdzanie kolizji
 */
class kropla
{
public:
	/**
	 * \brief Wektor polozenia kropli.
	 * 
	 * Zawiera informacje o po³o¿eniu kropli, wykorzystuje klasê wektor3D.
	 */
	wektor3D srodek_glob;
	/**
	 * \biref Wektor polozenia kropli wewnatrz butelki.
	 * 
	 * Zawiera informacje o po³o¿eniu kropli, wzglêdem uk³adu wspó³rzêdnych obróconego, zgodenie z butelk¹,
	 * wykorzystuje klasê wektor3D
	 */
	wektor3D srodek_wewn;	//wspolrzedne po obróceniu
	/**
	 * \brief Promieñ kropli.
	 * 
	 * Promieñ kropli, jego wartoœæ jest sta³a i jest ustawiana podczas inicjalizowania kropli.
	 */
	float promien;
	/**
	 * \brief K¹t x (stopnie).
	 * 
	 * K¹t wzglêdem osi x, obrotu kropli wzglêdem œrodka uk³adu wspó³rzêdnych podany w stopniach.
	 */
	float ostatni_kat_x;
	/**
	 * \brief K¹t y (stopnie).
	 * 
	 * K¹t wzglêdem osi y, obrotu kropli wzglêdem œrodka uk³adu wspó³rzêdnych podany w stopniach.
	 */
	float ostatni_kat_y;
	/**
	 * \brief K¹t z (stopnie).
	 * 
	 * K¹t wzglêdem osi z, obrotu kropli wzglêdem œrodka uk³adu wspó³rzêdnych podany w stopniach.
	 */
	float ostatni_kat_z;
	/**
	 * \brief Zmienna mówi¹ca, czy kropla jest wewn¹trz butelki
	 * 
	 * Zmienna mówi¹ca czy kropla jest wewn¹trz butelki, true- kropla znajduje sie wewnatrz butelki, false- kropla znajduje sie na zewnatrz butelki
	 */
	bool czy_wewnatrz;
	/**
	 * \brief Rysuje krople na ekranie.
	 * 
	 * Metoda odpowiadaj¹ca, za rysowanie kropli na ekranie. Jej po³o¿enie jest definiowane za pomoc¹ pola p.
	 */
	void rysuj();
	
	/**
	 * \brief Inicjalizuje klasê obiekt kropla.
	 * 
	 * Podczas inicjalizowania, nadaje wartoœæ r=0.05 oraz sprawdza, czy jej po³o¿enie nie bêdzie kolidowaæ z pozosta³ymi kroplami
	 */
	kropla();
	~kropla();
	/**
	 * \brief Obraca krople wzgledem œrodka wspó³rzêdnych.
	 * 
	 * Obracanie kropli wykonwane jest, wraz z obrotem butelki, nie potrzeba sprawdzaæ kolizji podczas wykonywania tej metody.
	 * 
	 * \param kat_x - k¹t obrotu w osi x podany w radianach
	 * \param kat_y - k¹t obrotu w osi y  podany w radianach
	 * \param kat_z - k¹t obrotu w osi z podany w radianach
	 */
	void obroc(float kat_x, float kat_y, float kat_z);

	//void grawitacja();
	/**
	 * \brief Sprawdza odleglosc kropli, od podanego wektora.
	 * 
	 * Metoda pozwalaj¹ca na ³atwe ustalenie odleg³oœci kroli, wzglêdem œrodka innego obiektu.
	 * 
	 * \param start - wektor od ktorego sprawdzana jest odleglosc
	 * \return - otrzymana odleglosc
	 */
	float odleglosc(wektor3D start);
	
	/**
	 * \brief Sprawdza czy kropla bêdzie kolidowaæ z inn¹ kropl¹.
	 * 
	 * Pozwala na proste sprawdzenie mo¿liwoœci ruchu. Wykorzystywane do symulowania grawitacji
	 * 
	 * \param ruch - wokonywany ruch
	 * \param sprawdzana - kropla, z któr¹ jest sprawdzana kolizja
	 * \return  informacje o kolizji
	 * \retval true - kolizja
	 * \retval false - brak kolizji
	 * 
	 */
	bool kolizja(wektor3D ruch, kropla sprawdzana);
	
	/**
	 * \brief Wykonuje ruch kropli.
	 * 
	 * Metoda ta zmienia dane o po³o¿eniu kropli zmieniaj¹c pola p oraz wew klasy kropla.
	 * 
	 * \param wek - jak kropla powinna siê ruszyæ
	 */
	void ruch(wektor3D wek);
	/**
	 * \brief Sprawdza, czy kropla bêdzie kolidowaæ z butelk¹.
	 * 
	 * Pozwala na proste sprwadzenie mo¿liwoœci ruchu. W tej metodzie, butelka jest przybli¿ana do dwóch po³¹czonych ze sob¹ walców.
	 * 
	 * \param ruch - ruch jaki kropla ma wykonaæ
	 * \return  informacje o kolizji
	 * \retval true - kolizja
	 * \retval false - brak kolizji
	 */
	bool kolizja(wektor3D ruch);
};

