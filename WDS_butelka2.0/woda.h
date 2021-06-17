/*****************************************************************//**
 * \file   woda.h
 * \brief  Klasa woda
 * 
 * Klasa sk³adaj¹ca siê z kropli wody, reprezentuj¹ca wodê
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
 * Klasa ta zawiera informacje o ka¿dej kroli, sk³adaj¹cej siê na wodê.
 */

class woda
{
	/**
	 * \brief Zmienna przechowywujace kat x obrotu wody.
	 * K¹t obrotu wody wzglêdem osi x, wzglêdem pierwotnej pozycji.
	 */
	float kx;
	/**
	 * \brief Zmienna przechowywujace kat y obrotu wody.
	 * K¹t obrotu wody wzglêdem osi y, wzglêdem pierwotnej pozycji.
	 */
	float ky;
	/**
	 * \brief Zmienna przechowywujace kat z obrotu wody.
	 * K¹t obrotu wody wzglêdem osi z, wzglêdem pierwotnej pozycji.
	 */
	float kz;
public:
	/**
	 * \brief Krople wody.
	 * 
	 * Zmienna przechowywujaca kazda krople wody.
	 */
	vector<kropla> k;
	/**
	 * \brief Ilosc kropli wody.
	 *
	 * Ilosc kropli wody.
	 */
	int l;
	woda() {}
	/**
	 * \brief Inicjuje krople wody.
	 * 
	 * Zape³nie zmienn¹ k, odpowiedni¹ iloœci¹ kropli wody
	 * 
	 * \param n - iloœæ kropli
	 */
	woda(int n);
	/**
	 * \biref Rysowanie wszystkich kropli.
	 * 
	 * Rysuje wszystkie krople sk³adaj¹ce siê na wodê.
	 */
	void rysuj();
	/**
	 * \brief Obraca wodê wzglêdem pierwotnej pozycji.
	 * 
	 * Wykorzystywane do obracania wody, podczas obracania butelki.
	 * 
	 * \param x - kat w osi x
	 * \param y - kat w osi y
	 * \param z - kat w osi z
	 */
	void obroc(float x, float y, float z);
	/**
	 * \brief Grawitacja dzialajaca na wode.
	 * 
	 * Metoda ta pozwala na prost¹ symulacjê oddzia³ywania grawitacji na wodê. Podczas jej wykonywania
	 * sprawdzane s¹ kolizje z innymi kroplami oraz butelk¹. Woda mo¿e poruszaæ siê w dó³, na ukos oraz w poziomie.
	 */
	void grawitacja();
};

