#include "wektor3D.h"

void wektor3D::mnozenie(macierz_rot m)
{
	wektor3D tmp = *this;

	for (int i = 0; i < 3; i++)
	{
		p[i] = 0;
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			p[i] += (m.p[i][j] * tmp.p[j]);
		}
	}
}

wektor3D::wektor3D()
{
	for (int i = 0; i < 3; i++)
	{
		p[i] = 0;
	}
}


