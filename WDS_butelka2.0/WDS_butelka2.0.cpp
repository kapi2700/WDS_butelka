#include <string>
#include <iostream>
#include <fstream>
#include <windows.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, include glu.h and gl.h

#include "obiekt3D.h"
#include "scena.h"

using namespace std;


char title[] = "Butelka";
scena s;



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

void display() {                //What to display
    int w[3];                   //Variable to store verticie data
    float radius = 5.0f;
    double time=(((double)glutGet(GLUT_ELAPSED_TIME))/500);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers
    glMatrixMode(GL_MODELVIEW);     // To operate on model-view matrix
    glLoadIdentity();

    gluLookAt(sin(time) * radius, 0, cos(time) * radius, 0, 0, 0, 0, 1, 0); //rotate camera around the objects


    glBegin(GL_QUADS);                // Begin drawing square

    glColor3f(1.0f, 0.0f, 0.0f);     // Red
    glVertex3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);

    glEnd();

    
    
    glBegin(GL_TRIANGLES);            //Begin drawing the bottle as traingles
    
    glColor4f(0.4335f, 0.8476f, 1.0f, 0.5f);
    for (unsigned int i = 0; i < s.ob.size(); i++)
    {
        for (int j = 0; j < s.ob[i].model.faces; j++)
        {
            w[0] = s.ob[i].faces[j][0]-1;
            w[1] = s.ob[i].faces[j][3]-1;
            w[2] = s.ob[i].faces[j][6]-1;
            for (unsigned int k = 0; k < 3; k++)
            {
                glVertex3f(s.ob[i].positions[w[k]][0], s.ob[i].positions[w[k]][1], s.ob[i].positions[w[k]][2]);
            }
        }
    }
    
    glEnd();   // Done drawing the bottle

    
    
    glutSwapBuffers();  // Swap the front and back frame buffers (double buffering)
    glutPostRedisplay();
}


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
    obiekt3D butelka("butelka");
    s.ob.push_back(butelka);

    glutInit(&argc, argv);            // Initialize GLUT
    glutInitDisplayMode(GLUT_DOUBLE); // Enable double buffered mode
    glutInitWindowSize(640, 480);   // Set the window's initial width & height
    glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
    glutCreateWindow(title);          // Create window with the given title
    glutDisplayFunc(display);       // Register callback handler for window re-paint event
    glutReshapeFunc(reshape);       // Register callback handler for window re-size event
    initGL();                       // Our own OpenGL initialization
    glutMainLoop();                 // Enter the infinite event-processing loop

    return 0;
}