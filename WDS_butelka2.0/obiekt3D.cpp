#include "obiekt3D.h"


obiekt3D::obiekt3D(string nazwa)            //initialize obiekt3D using file with "name".obj
{
	string filepathOBJ = nazwa + ".obj";
    ifstream inOBJ;
    positions = NULL;
    texels = NULL;
    normals = NULL;
    faces = NULL;


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

    positions = new float* [model.positions];
    texels = new float* [model.texels];
    normals = new float* [model.normals];
    faces = new int* [model.faces];


    for (int i = 0; i < model.positions; i++)
    {
        positions[i] = new float[3];
    }


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
                positions[p][i] = atof(strtok(NULL, " "));

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
}

obiekt3D::~obiekt3D()
{

    for (int i = 0; i < model.positions; i++)
    {
        delete[](positions[i]);
    }


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
}
