/*****************************************************************//**
 * \file   obiekt3D.h
 * \brief   * Klasa obiektu 3D, pozwala na wy�wietlanie obiekt�w zapisanych w 
 * formacie .obj, z�o�onych z samych tr�jk�t�w.
 * 
 * \author Kacper Grabowski
 * \date   April 2021
 *********************************************************************/

#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <GL/glut.h>
#include <vector>

#include "macierz_rot.h"
#include "wektor3D.h"




using namespace std;

static bool polaczenie = false;


/**
 * \brief Struktura wykorzystywana podczas zczytywania danych z pliku .obj.
 * 
 * Struktura wykorzystywana podczas zczytywania danych z pliku .obj.
 */
typedef struct Model
{
    int vertices;
    int positions;
    int texels;
    int normals;
    int faces;
}
Model;


/**
 * \brief Klasa obiektow zczytywanych z plikow .obj.
 * 
 * Klasa ta zawiera informacje na temat po�o�enia wierzcho�k�w obiektu3D (butelki). Pozwala ona
 * na wygodne obracanie oraz rysowanie obiektu3D (butelki).
 */
class obiekt3D
{
public:
    /**
     * \brief Struktura wykorzystywana podczas zczytywania danych z pliku .obj.
     * 
     * Struktura wykorzystywana podczas zczytywania danych z pliku .obj. Zawiera informacje o ilo�ci danych
     */
    Model model;

    /**
     * \brief Aktualne pozycje wszystkich wierzcho�k�w tr�jk�t�w.
     * 
     * Aktualne pozycje wszystkich wierzcho�k�w tr�jk�t�w. zmieniane s� podczas wykonywania metody obroc.
     */
    wektor3D* positions;
    /**
     * \brief Pozycje pocz�tkowe wszystkich wieszcho�k�w tr�jk�t�w.
     * 
     * Pozycje pocz�tkowe wszystkich wieszcho�k�w tr�jk�t�w. Ich warto�� si� nie zmienia. S� one wykorzystywane do obliczenia
     * nowego po�o�enia wierzcho�k�w obiektu.
     */
    wektor3D* positionsStart;

    /**
     * \brief Zmiena wykorzytywana do zbierania danych z pliku .obj.
     * 
     * Zmiena wykorzytywana do zbierania danych z pliku .obj.
     */
    float** texels;
    /**
     * \brief Zmiena wykorzytywana do zbierania danych z pliku .obj.
     * 
     * Zmiena wykorzytywana do zbierania danych z pliku .obj.
     */
    float** normals;
    /**
     * \biref Zmiena wykorzytywana do zbierania danych z pliku .obj.
     * 
     * Zmiena wykorzytywana do zbierania danych z pliku .obj.
     */
    int** faces;

    
    /**
     * \biref Kolor obiektu, RGB.
     * 
     * Zmienna zawieraj�ca informacje o kolorze obiektu3D. Warto�� jest ustalana podczas inicjalizacji obiektu. Format danych: RGB
     */
    float color[3];
    /**
     * \brief Przezroczysto�� obiektu.
     * 
     * Zmienna informuj�ca o przezroczysto�ci obiektu3D. Warto�� jest ustalana podczas inicjalizacji obiektu.
     */
    float alpha;

    /**
     * \brief Ostatni k�t obrotu w osi x.
     * 
     * Zawiera informacje o warto�ci k�tu podczas poprzedniego obrotu w stopniach wzgl�dem osi x.
     */
    float ostatnikx;
    /**
     * \brief Ostatni k�t obrotu w osi y.
     * 
     * Zawiera informacje o warto�ci k�tu podczas poprzedniego obrotu w stopniach wzgl�dem osi y.
     */
    float ostatniky;

    /**
     * \brief Inicjalizacja obiektu3D za pomoc� nazwy pliku.
     * 
     * Inicjalizuje obiekt na podstawie pliku w formacie .obj. Podawana jest r�wnie� informacja o kolorze i
     * przezroczysto�ci obiektu.
     * 
     * \param nazwa - nazwa pliku .obj
     * \param r - kolor czerwony 0-1
     * \param g - kolor zielony 0-1
     * \param b - kolor niebieski 0-1
     * \param a - przeroczysto�� obiektu 0-1
     */
    obiekt3D(string nazwa, float r, float g, float b, float a);

    ~obiekt3D();

    /**
     * \brief Obraca obiekt o podane k�ty, wzgl�dem pozycji pocz�tkowej.
     * 
     * Obraca obbiekt o podane k�ty, wzgl�dem pozycji pocz�tkowej.
     * 
     * \param kat_x - k�t obrotu w osi x podany w radianach
     * \param kat_y - k�t obrotu w osi y  podany w radianach
     * \param kat_z - k�t obrotu w osi z podany w radianach
     */
    void obroc(float kat_x, float kat_y, float kat_z);

    /**
     * \brief Rysuje obiekt3D.
     * 
     * Rysuje obiekt3D, nale�y umie�ci� pomi�dzy glBegin(GL_TRIANGLES); oraz glEnd();.
     */
    void rysuj();
};

