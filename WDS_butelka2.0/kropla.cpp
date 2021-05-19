#include "kropla.h"

void kropla::rysuj()
{
	glColor3f(0.4335f, 0.8476f, 1.0);
	glTranslatef(p[0], p[1], p[2]);
	glutSolidSphere(r, 100, 100);
	glTranslatef(-p[0], -p[1], -p[2]);
}

kropla::kropla()
{
	r = 0.1;
	for (int i = 0; i < 3; i++)
	{
		p[i] = ((float)(rand() % 3000))/1000 - 1.5f;
	}
}
