/*****************************************************************//**
 * \file   woda.h
 * \brief  Klasa woda
 * 
 * Klasa sk�adaj�ca si� z kropli wody, reprezentuj�ca wod�
 * 
 * \author kapi2
 * \date   May 2021
 *********************************************************************/
#pragma once
#include <vector>
#include <windows.h>

#include "kropla.h"

using namespace std;

/**
 * \brief Klasa zawierajaca krople wody.
 * 
 * Klasa ta zawiera informacje o ka�dej kroli, sk�adaj�cej si� na wod�.
 */

class woda
{
	/**
	 * \brief Zmienna przechowywujace kat x obrotu wody.
	 * 
	 * K�t obrotu wody wzgl�dem osi x, wzgl�dem pierwotnej pozycji podany w stopniach.
	 */
	float ostatni_kat_x;
	/**
	 * \brief Zmienna przechowywujace kat y obrotu wody.
	 * 
	 * K�t obrotu wody wzgl�dem osi y, wzgl�dem pierwotnej pozycji podany w stopniach.
	 */
	float ostatni_kat_y;
	/**
	 * \brief Zmienna przechowywujace kat z obrotu wody.
	 * 
	 * K�t obrotu wody wzgl�dem osi z, wzgl�dem pierwotnej pozycji podany w stopniach.
	 */
	float ostatni_kat_z;
public:
	/**
	 * \brief Krople wody.
	 * 
	 * Zmienna przechowywujaca kazda krople wody.
	 */
	vector<kropla> krople;
	/**
	 * \brief Ilosc kropli wody.
	 *
	 * Ilosc kropli wody.
	 */
	int ilosc_kropli;
	woda() {}
	/**
	 * \brief Inicjuje krople wody.
	 * 
	 * Zape�nie zmienn� k, odpowiedni� ilo�ci� kropli wody
	 * 
	 * \param[in] n - ilo�� kropli
	 */
	woda(int n);
	/**
	 * \biref Rysowanie wszystkich kropli.
	 * 
	 * Rysuje wszystkie krople sk�adaj�ce si� na wod�.
	 */
	void rysuj();
	/**
	 * \brief Obraca wod� wzgl�dem pierwotnej pozycji.
	 * 
	 * Wykorzystywane do obracania wody, podczas obracania butelki.
	 * 
	 * \param[in] kat_x - kat w osi x podany w radianach
	 * \param[in] kat_y - kat w osi y podany w radianach
	 * \param[in] kat_z - kat w osi z podany w radianach
	 */
	void obroc(float kat_x, float kat_y, float kat_z);
	/**
	 * \brief Grawitacja dzialajaca na wode.
	 * 
	 * Metoda ta pozwala na prost� symulacj� oddzia�ywania grawitacji na wod�. Podczas jej wykonywania
	 * sprawdzane s� kolizje z innymi kroplami oraz butelk�. Woda mo�e porusza� si� w d�, na ukos oraz w poziomie.
	 */
	void grawitacja();
};

