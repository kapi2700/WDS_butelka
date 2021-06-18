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
	 * 
	 * K¹t obrotu wody wzglêdem osi x, wzglêdem pierwotnej pozycji podany w stopniach.
	 */
	float ostatni_kat_x;
	/**
	 * \brief Zmienna przechowywujace kat y obrotu wody.
	 * 
	 * K¹t obrotu wody wzglêdem osi y, wzglêdem pierwotnej pozycji podany w stopniach.
	 */
	float ostatni_kat_y;
	/**
	 * \brief Zmienna przechowywujace kat z obrotu wody.
	 * 
	 * K¹t obrotu wody wzglêdem osi z, wzglêdem pierwotnej pozycji podany w stopniach.
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
	 * Zape³nie zmienn¹ k, odpowiedni¹ iloœci¹ kropli wody
	 * 
	 * \param[in] n - iloœæ kropli
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
	 * \param[in] kat_x - kat w osi x podany w radianach
	 * \param[in] kat_y - kat w osi y podany w radianach
	 * \param[in] kat_z - kat w osi z podany w radianach
	 */
	void obroc(float kat_x, float kat_y, float kat_z);
	/**
	 * \brief Grawitacja dzialajaca na wode.
	 * 
	 * Metoda ta pozwala na prost¹ symulacjê oddzia³ywania grawitacji na wodê. Podczas jej wykonywania
	 * sprawdzane s¹ kolizje z innymi kroplami oraz butelk¹. Woda mo¿e poruszaæ siê w dó³, na ukos oraz w poziomie.
	 */
	void grawitacja();
};

