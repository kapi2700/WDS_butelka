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

using namespace std;

/**
 * Struktura pomocnicza pozwalaj�ca na zapisywanie w niej parametr�w
 * plik�w w formacie .obj.
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



class obiekt3D
{
public:
    Model model;

    float** positions;
    float** texels;
    float** normals;
    int** faces;

    /**
     * Inicjalizacja obiektu3D za pomoc� nazwy pliku.
     * 
     * \param nazwa nazwa pliku .obj
     */
    obiekt3D(string nazwa);

    ~obiekt3D();
};

