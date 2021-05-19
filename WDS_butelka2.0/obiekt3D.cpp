#include "obiekt3D.h"


obiekt3D::obiekt3D(string nazwa, float r, float g, float b, float a)            //initialize obiekt3D using file with "name".obj
{
	string filepathOBJ = nazwa + ".obj";
    ifstream inOBJ;
    positions = NULL;
    texels = NULL;
    normals = NULL;
    faces = NULL;
    positionsStart = NULL;

    color[0] = r;
    color[1] = g;
    color[2] = b;

    alpha = a;

    ostatnikx = 0;
    ostatniky = 0;


    // Counters
    int p = 0;
    int t = 0;
    int n = 0;
    int f = 0;

    inOBJ.open(filepathOBJ);
    if (!inOBJ.good())
    {
        cout << "ERROR OPENING OBJ FILE" << endl;
        exit(1);
    }

    while (!inOBJ.eof())
    {
        // 5
        string line;
        getline(inOBJ, line);
        string type = line.substr(0, 2);

        // 6
        if (type.compare("v ") == 0)
            model.positions++;
        else if (type.compare("vt") == 0)
            model.texels++;
        else if (type.compare("vn") == 0)
            model.normals++;
        else if (type.compare("f ") == 0)
            model.faces++;
    }

    // 7
    model.vertices = model.faces * 3;

    // 8
    // Close OBJ file
    inOBJ.close();

    // Creating variables to store obj data

    positions = new wektor3D [model.positions];
    positionsStart = new wektor3D[model.positions];
    texels = new float* [model.texels];
    normals = new float* [model.normals];
    faces = new int* [model.faces];

    for (int i = 0; i < model.texels; i++)
    {
        texels[i] = new float[2];
    }


    for (int i = 0; i < model.normals; i++)
    {
        normals[i] = new float[3];
    }

    for (int i = 0; i < model.faces; i++)
    {
        faces[i] = new int[9];
    }



    // Open OBJ file
    inOBJ.open(filepathOBJ);
    if (!inOBJ.good())
    {
        cout << "ERROR OPENING OBJ FILE" << endl;
        exit(1);
    }

    // Read OBJ file
    while (!inOBJ.eof())
    {
        string line;
        getline(inOBJ, line);
        string type = line.substr(0, 2);

        // Positions
        if (type.compare("v ") == 0)
        {
            // 1
            // Copy line for parsing
            char* l = new char[line.size() + 1];
            memcpy(l, line.c_str(), line.size() + 1);

            // 2
            // Extract tokens
            strtok(l, " ");
            for (int i = 0; i < 3; i++)
                positions[p].p[i] = atof(strtok(NULL, " "));

            // 3
            // Wrap up
            delete[] l;
            p++;
        }

        // Texels
        else if (type.compare("vt") == 0)
        {
            char* l = new char[line.size() + 1];
            memcpy(l, line.c_str(), line.size() + 1);

            strtok(l, " ");
            for (int i = 0; i < 2; i++)
                texels[t][i] = atof(strtok(NULL, " "));

            delete[] l;
            t++;
        }

        // Normals
        else if (type.compare("vn") == 0)
        {
            char* l = new char[line.size() + 1];
            memcpy(l, line.c_str(), line.size() + 1);

            strtok(l, " ");
            for (int i = 0; i < 3; i++)
                normals[n][i] = atof(strtok(NULL, " "));

            delete[] l;
            n++;
        }

        // Faces
        else if (type.compare("f ") == 0)
        {
            char* l = new char[line.size() + 1];
            memcpy(l, line.c_str(), line.size() + 1);

            strtok(l, " ");
            for (int i = 0; i < 9; i++)
                faces[f][i] = atof(strtok(NULL, " /"));

            delete[] l;
            f++;
        }
    }

    // Close OBJ file
    inOBJ.close();

    for (int i = 0; i < model.positions; i++)
    {
        positionsStart[i] = positions[i];
    }
}

obiekt3D::~obiekt3D()
{

    delete[](positions);


    for (int i = 0; i < model.texels; i++)
    {
        delete[](texels[i]);
    }


    for (int i = 0; i < model.normals; i++)
    {
        delete[](normals[i]);
    }

    for (int i = 0; i < model.faces; i++)
    {
        delete[](faces[i]);
    }
    delete[](texels);
    delete[](normals);
    delete[](faces);
}

void obiekt3D::obroc(float x, float y)
{
    x = x * (float)PI / 180.0f;
    y = y * (float)PI / 180.0f;

    macierz_rot macx(x, 'x');
    macierz_rot macy(y, 'y');
    

    for (int i = 0; i < model.positions; i++)
    {
        positions[i] = positionsStart[i];
        positions[i].mnozenie(macx);
        positions[i].mnozenie(macy);
    }
}

void obiekt3D::rysuj()
{
    int w[3];

    glColor4f(color[0], color[1], color[2], alpha);
    for (int j = 0; j < model.faces; j++)
    {
        w[0] = faces[j][0] - 1;
        w[1] = faces[j][3] - 1;
        w[2] = faces[j][6] - 1;
        for (unsigned int k = 0; k < 3; k++)
        {
            glVertex3f(positions[w[k]].p[0], positions[w[k]].p[1], positions[w[k]].p[2]);
        }
    }
}

void obiekt3D::nowyObrot()
{
    ifstream plikDane("Node/orientation.txt");
    string line;
    string vars[3];
    int iloscDanych = 0;
    float* x = new float[10];
    float* y = new float[10];
    float obrx, obry;
    int whichVar = 0;
    float tmpx = 0, tmpy = 0;

    for (int i = 0; i < 10; i++)
    {
        x[i] = 0;
        y[i] = 0;
    }

    iloscDanych = 0;
    while (getline(plikDane, line)&&(iloscDanych<9))
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
            //z = stof(vars[2]);
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
        for (int i = 0; i < iloscDanych; i++)
        {
            obrx += x[i];
            obry += y[i];
        }

        obrx = obrx / iloscDanych;
        obry = obry / iloscDanych;

        obroc(obrx + 90.0f, obry);
        /*
        tmpx = ((ostatnikx - obrx) / 3);
        tmpy = ((ostatniky - obry) / 3);

        for (int i = 1; i <= 3; i++)
        {
            kx[i-1] = (ostatnikx + tmpx * i);
            ky[i-1] = (ostatniky + tmpy * i);
        }

        ostatnikx = obrx;
        ostatniky = obry;
        */

    }



    delete[](x);
    delete[](y);
}

void obiekt3D::stopniuj(int stopien)
{
    obroc(kx[stopien] - 90.0f, -ky[stopien]);
}
