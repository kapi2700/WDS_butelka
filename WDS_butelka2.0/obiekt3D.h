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
 * Klasa obiektow zczytywanych z plikow .obj.
 */
class obiekt3D
{
public:
    /**
     * Struktura wykorzystywana podczas zczytywania danych z pliku .obj.
     */
    Model model;

    /**
     * Aktualne pozycje wszystkich wierzcho�k�w tr�jk�t�w.
     */
    wektor3D* positions;
    /**
     * Pozycje pocz�tkowe wszystkich wieszcho�k�w tr�jk�t�w.
     */
    wektor3D* positionsStart;

    /**
     * Zmiena wykorzytywana do zbierania danych z pliku .obj.
     */
    float** texels;
    /**
     * Zmiena wykorzytywana do zbierania danych z pliku .obj.
     */
    float** normals;
    /**
     * Zmiena wykorzytywana do zbierania danych z pliku .obj.
     */
    int** faces;

    
    /**
     * Kolor obiektu, RGB.
     */
    float color[3];
    /**
     * Przezroczysto�� obiektu.
     */
    float alpha;

    /**
     * Ostatni k�t obrotu w osi x.
     */
    float ostatnikx;
    /**
     * Ostatni k�t obrotu w osi y.
     */
    float ostatniky;

    ///**
    // * .
    // */
    //float kx[3];
    //float ky[3];

    /**
     * Inicjalizacja obiektu3D za pomoc� nazwy pliku.
     * 
     * \param nazwa nazwa pliku .obj
     */
    obiekt3D(string nazwa, float r, float g, float b, float a);

    ~obiekt3D();

    /**
     * Obraca obiekt, o dane k�ty, wzgl�dem pozycji pocz�tkowej.
     * 
     * \param x k�t obrotu w osi x
     * \param y k�t obrotu w osi y
     * \param z k�t obrotu w osi z
     */
    void obroc(float x, float y, float z);

    /**
     * Rysuje obiekt3D, nale�y umie�ci� pomi�dzy glBegin(GL_TRIANGLES); oraz glEnd();.
     */
    void rysuj();
};

