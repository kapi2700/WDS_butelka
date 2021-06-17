/*****************************************************************//**
 * \file   obiekt3D.h
 * \brief   * Klasa obiektu 3D, pozwala na wyœwietlanie obiektów zapisanych w 
 * formacie .obj, z³o¿onych z samych trójk¹tów.
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
 * Klasa ta zawiera informacje na temat po³o¿enia wierzcho³ków obiektu3D (butelki). Pozwala ona
 * na wygodne obracanie oraz rysowanie obiektu3D (butelki).
 */
class obiekt3D
{
public:
    /**
     * \brief Struktura wykorzystywana podczas zczytywania danych z pliku .obj.
     * 
     * Struktura wykorzystywana podczas zczytywania danych z pliku .obj. Zawiera informacje o iloœci danych
     */
    Model model;

    /**
     * \brief Aktualne pozycje wszystkich wierzcho³ków trójk¹tów.
     * 
     * Aktualne pozycje wszystkich wierzcho³ków trójk¹tów. zmieniane s¹ podczas wykonywania metody obroc.
     */
    wektor3D* positions;
    /**
     * \brief Pozycje pocz¹tkowe wszystkich wieszcho³ków trójk¹tów.
     * 
     * Pozycje pocz¹tkowe wszystkich wieszcho³ków trójk¹tów. Ich wartoœæ siê nie zmienia. S¹ one wykorzystywane do obliczenia
     * nowego po³o¿enia wierzcho³ków obiektu.
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
     * Zmienna zawieraj¹ca informacje o kolorze obiektu3D. Wartoœæ jest ustalana podczas inicjalizacji obiektu. Format danych: RGB
     */
    float color[3];
    /**
     * \brief Przezroczystoœæ obiektu.
     * 
     * Zmienna informuj¹ca o przezroczystoœci obiektu3D. Wartoœæ jest ustalana podczas inicjalizacji obiektu.
     */
    float alpha;

    /**
     * \brief Ostatni k¹t obrotu w osi x.
     * 
     * Zawiera informacje o wartoœci k¹tu podczas poprzedniego obrotu w stopniach wzglêdem osi x.
     */
    float ostatnikx;
    /**
     * \brief Ostatni k¹t obrotu w osi y.
     * 
     * Zawiera informacje o wartoœci k¹tu podczas poprzedniego obrotu w stopniach wzglêdem osi y.
     */
    float ostatniky;

    /**
     * \brief Inicjalizacja obiektu3D za pomoc¹ nazwy pliku.
     * 
     * Inicjalizuje obiekt na podstawie pliku w formacie .obj. Podawana jest równie¿ informacja o kolorze i
     * przezroczystoœci obiektu.
     * 
     * \param nazwa - nazwa pliku .obj
     * \param r - kolor czerwony 0-1
     * \param g - kolor zielony 0-1
     * \param b - kolor niebieski 0-1
     * \param a - przeroczystoœæ obiektu 0-1
     */
    obiekt3D(string nazwa, float r, float g, float b, float a);

    ~obiekt3D();

    /**
     * \brief Obraca obiekt o podane k¹ty, wzglêdem pozycji pocz¹tkowej.
     * 
     * Obraca obbiekt o podane k¹ty, wzglêdem pozycji pocz¹tkowej.
     * 
     * \param kat_x - k¹t obrotu w osi x podany w radianach
     * \param kat_y - k¹t obrotu w osi y  podany w radianach
     * \param kat_z - k¹t obrotu w osi z podany w radianach
     */
    void obroc(float kat_x, float kat_y, float kat_z);

    /**
     * \brief Rysuje obiekt3D.
     * 
     * Rysuje obiekt3D, nale¿y umieœciæ pomiêdzy glBegin(GL_TRIANGLES); oraz glEnd();.
     */
    void rysuj();
};

