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

#define PI 3.14159265


static bool polaczenie = false;

typedef struct Model
{
    int vertices;
    int positions;
    int texels;
    int normals;
    int faces;
}
Model;



class obiekt3D
{
public:
    Model model;

    wektor3D* positions;
    wektor3D* positionsStart;
    float** texels;
    float** normals;
    int** faces;

    float color[3];
    float alpha;

    float ostatnikx;
    float ostatniky;

    float kx[3];
    float ky[3];

    /**
     * Inicjalizacja obiektu3D za pomoc� nazwy pliku.
     * 
     * \param nazwa nazwa pliku .obj
     */
    obiekt3D(string nazwa, float r, float g, float b, float a);

    ~obiekt3D();
    /**
     * Obraca macierz na podstawie danych przekazywanych przez sensory w telefonie.
     */
    void nowyObrot();

    /**
     * Obraca obiekt, o dane k�ty, wzgl�dem pozycji pocz�tkowej.
     * 
     * \param x k�t obrotu w osi x
     * \param y k�t obrotu w osi y
     */
    void obroc(float x, float y);

    /**
     * Rysuje obiekt3D, nale�y umie�ci� pomi�dzy glBegin(GL_TRIANGLES); oraz glEnd();.
     */
    void rysuj();

    /**
     * Obraca obiekt, wykonywana po wczesniejszejj funkcji nowyObrot, inicjalizujacej kx oraz ky
     * odpowiednimi k�tami. Zaimplementowane w celu zmniejszenia skokowosci obrot�w.
     * 
     * Funkcja nie wykorzystywana.
     * 
     * \param stopien od 0 do 2, ile razy zostal juz wykonany dany obrot.
     */
    void stopniuj(int stopien);
};

