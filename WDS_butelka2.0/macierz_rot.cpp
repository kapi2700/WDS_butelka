#include "macierz_rot.h"

macierz_rot::macierz_rot(float a, char o)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			p[i][j] = 0;
		}
	}

	switch (o)
	{
	case 'x':
		p[0][0] = 1;
		p[0][1] = 0;
		p[0][2] = 0;

		p[1][0] = 0;
		p[1][1] = cos(a);
		p[1][2] = -sin(a);

		p[2][0] = 0;
		p[2][1] = sin(a);
		p[2][2] = cos(a);
		break;
	case 'y':
		p[0][0] = cos(a);
		p[0][1] = 0;
		p[0][2] = sin(a);

		p[1][0] = 0;
		p[1][1] = 1;
		p[1][2] = 0;

		p[2][0] = -sin(a);
		p[2][1] = 0;
		p[2][2] = cos(a);
		break;
	case 'z':
		p[0][0] = cos(a);
		p[0][1] = -sin(a);
		p[0][2] = 0;

		p[1][0] = sin(a);
		p[1][1] = cos(a);
		p[1][2] = 0;

		p[2][0] = 0;
		p[2][1] = 0;
		p[2][2] = 1;
		break;
	}
}
