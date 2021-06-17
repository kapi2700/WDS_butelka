/*****************************************************************//**
 * \file   WDS_butelka2.0.cpp
 * \brief  Program wyœwietlaj¹cy butelkê z wod¹
 * 
 * Zadaniem programu jest zczytywanie danych z sensorów znajduj¹cych siê
 * w telefonie, i wyœwietlanie na ich podstawie butelki z wod¹.
 * 
 * \author kapi2
 * \date   May 2021
 *********************************************************************/
#include <windows.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, include glu.h and gl.h

#include "obiekt3D.h"
#include "scena.h"


using namespace std;


char title[] = "Butelka";
obiekt3D butelka("butelka", 0.4335f, 0.8476f, 1.0f, 0.5f);
bool restart = false;
static scena* s=NULL;


GLfloat mat_specular[] = { 1.0, 1.0,1.0,1.0 };
GLfloat mat_shininess[] = { 50.0 };
GLfloat light_position[] = { 1.0,1.0,1.0,0.0 };

int stopienObrotu = 0;
float kat = 0;

/**
 * \brief Funkcja obs³uguj¹ca klawiaturê.
 * 
 * Funkcja obs³guje wciskanie przycisków "a" oraz "d", na tej podstawie
 * obracana jest kamera
 * 
 * \param key - wcisniety przycisk
 */
void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'a':
        kat += 0.1;
        glutPostRedisplay();
        break;

    case 'd':
        kat -= 0.1;
        glutPostRedisplay();
        break;
    //case 'r':       //restart sceny
    //    restart = true;
    //    break;
    }
}

/**
 * \brief Funkcja inicjuj¹ca OpenGL.
 * 
 */

void initGL() {                           //initialize openGL
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
    glClearDepth(1.0f);                   // Set background depth to farthest
    glEnable(GL_DEPTH_TEST);   // Enable depth testing for z-culling
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glDepthFunc(GL_LEQUAL);    // Set the type of depth-test
    glShadeModel(GL_SMOOTH);   // Enable smooth shading
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  // Nice perspective corrections
}


/**
 * \brief Pêtla wyœwietlania
 * 
 * Funkcja s³u¿¹ca za pêtlê wykonywan¹ podczas generowania ka¿dej klatki.
 * W niej wykonywane jest rysowanie, obracanie oraz przesuwanie obiektów.
 * 
 */
void display() {                //What to display

    //if (restart)
    //{
    //    delete s;
    //    s = new scena(100);
    //    s->ob.push_back(butelka);
    //    restart = false;
    //}

    float radius = 5.0f;
    double time = (((double)glutGet(GLUT_ELAPSED_TIME)) / 5000);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers
    glMatrixMode(GL_MODELVIEW);     // To operate on model-view matrix
    glLoadIdentity();

    //gluLookAt(sin(time) * radius, 0, cos(time) * radius, 0, 0, 0, 0, 1, 0); //rotate camera around the objects
    gluLookAt(sin(kat) * radius, 0, cos(kat) * radius, 0, 0, 0, 0, 1, 0); //rucha kamera za pomoca a i d

    if (s != NULL)
    {
        s->rysuj();
        s->obrot();
        s->w.grawitacja();
    }

    glutSwapBuffers();  // Swap the front and back frame buffers (double buffering)
    glutPostRedisplay();
}

/**
 * \brief Zmiana wielkoœci okna
 * 
 * Funkcja pozwala na zmianê wielkoœci okna
 */
void reshape(GLsizei width, GLsizei height) {  // GLsizei for non-negative integer
   // Compute aspect ratio of the new window
    if (height == 0) height = 1;                // To prevent divide by 0
    GLfloat aspect = (GLfloat)width / (GLfloat)height;

    // Set the viewport to cover the new window
    glViewport(0, 0, width, height);

    // Set the aspect ratio of the clipping volume to match the viewport
    glMatrixMode(GL_PROJECTION);  // To operate on the Projection matrix
    glLoadIdentity();             // Reset
    // Enable perspective projection with fovy, aspect, zNear and zFar
    gluPerspective(45.0f, aspect, 0.1f, 100.0f);
}


int main(int argc, char** argv)
{
    s = new scena(150);
    s->obiekty.push_back(butelka);

    glutInit(&argc, argv);            // Initialize GLUT
    glutInitDisplayMode(GLUT_DOUBLE); // Enable double buffered mode
    glutInitWindowSize(640, 480);   // Set the window's initial width & height
    glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
    glutCreateWindow(title);          // Create window with the given title
    glutDisplayFunc(display);       // Register callback handler for window re-paint event
    glutReshapeFunc(reshape);       // Register callback handler for window re-size event
    glutKeyboardFunc(keyboard);
    initGL();                       // Our own OpenGL initialization
    glutMainLoop();                 // Enter the infinite event-processing loop

    return 0;
}