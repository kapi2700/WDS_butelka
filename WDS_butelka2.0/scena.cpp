#include "scena.h"

scena::scena(int n)
{
    m = n;
    w = n;
}

void scena::obrot()
{
    ifstream plikDane("Node/orientation.txt");
    string line;
    string vars[3];
    int iloscDanych = 0;
    float* x = new float[10];
    float* y = new float[10];
    float* z = new float[10];
    float obrx, obry, obrz;
    int whichVar = 0;
    float tmpx = 0, tmpy = 0;




    ////////////////////////////////////////////////////////

    ////=====================Do Testow=====================
    ////================Butelka do gory nogami=============
    //obrx = 90.0f;
    //obry = 0.0f;
    //obrz = 0.0f;
    //for (int i = 0; i < ob.size(); i++)
    //{
    //    ob[i].obroc(obrx + 90.0f, obry, obrz);
    //}
    //w.obroc(obrx + 90.0f, obry, obrz);
    //
    //return;
    ////===================================================

    ////////////////////////////////////////////////////////

    ////=====================Do Testow=====================
    ////================Butelka do na boku=================
    //obrx = 0.0f;
    //obry = 0.0f;
    //obrz = 0.0f;
    //for (int i = 0; i < ob.size(); i++)
    //{
    //    ob[i].obroc(obrx + 90.0f, obry, obrz);
    //}
    //w.obroc(obrx + 90.0f, obry, obrz);

    //return;
    ////===================================================

    ////////////////////////////////////////////////////////



    for (int i = 0; i < 10; i++)
    {
        x[i] = 0;
        y[i] = 0;
        z[i] = 0;
    }

    iloscDanych = 0;
    while (getline(plikDane, line) && (iloscDanych < 1))
    {
        whichVar = 0;
        if (line != "")
        {
            for (unsigned int i = 0; i < line.size(); i++)      //Podzia³ stringa na 3
            {
                if (line[i] != ',')
                {
                    vars[whichVar] += line[i];
                }
                else
                {
                    whichVar++;
                }

            }


            x[iloscDanych] = stof(vars[1]);
            y[iloscDanych] = -stof(vars[0]);
            z[iloscDanych] = stof(vars[2]);
            iloscDanych++;



            polaczenie = true;

        }
    }
    if (iloscDanych == 0)
    {
        polaczenie = false;
    }

    plikDane.close();

    plikDane.open("Node/orientation.txt", std::ofstream::out | std::ofstream::trunc); //wyczyszczenie pliku
    plikDane.close();

    if (polaczenie)
    {
        obrx = 0;
        obry = 0;
        obrz = 0;
        for (int i = 0; i < iloscDanych; i++)
        {
            obrx += x[i];
            obry += y[i];
            obrz += z[i];
        }

        obrx = obrx / iloscDanych;
        obry = obry / iloscDanych;
        obrz = obrz / iloscDanych;

        for (int i = 0; i < ob.size(); i++)
        {
            ob[i].obroc(obrx + 90.0f, obry, obrz);
        }
        w.obroc(obrx + 90.0f, obry, obrz);
    }
}

void scena::rysuj()
{
    w.rysuj();
    glBegin(GL_TRIANGLES);            //Begin drawing the bottle as traingles
    for (unsigned int i = 0; i < ob.size(); i++)
    {
        ob[i].rysuj();
    }
    glEnd();
}
