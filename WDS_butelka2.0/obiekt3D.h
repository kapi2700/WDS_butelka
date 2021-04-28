#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

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


    obiekt3D(string nazwa);

    ~obiekt3D();
};

