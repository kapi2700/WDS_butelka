#include "woda.h"

woda::woda(int n)
{
	l = n;

	kropla* kr;
	for (int i = 0; i < n; i++)
	{
		kr = new kropla;
		k.push_back(*kr);
		delete kr;
	}
	
}

void woda::rysuj()
{
	for (int i = 0; i < l; i++)
	{
		k[i].rysuj();
	}
}

void woda::obroc(float x, float y, float z)
{
	for (int i = 0; i < l; i++)
	{
		k[i].obroc(x, y, z);
	}
	x = x * (float)PI / 180.0f;
	y = y * (float)PI / 180.0f;
	kx = -x;
	ky = -y;
}

void woda::grawitacja()
{
	wektor3D pom;
	bool mozna = false;


	for (int i = 0; i < l; i++)
	{
		pom.p[0] = 0;
		pom.p[1] = -0.01;
		pom.p[2] = 0;
		
		mozna = !k[i].kolizja(pom);
		if (mozna)
		{
			for (int j = 0; j < l; j++)
			{
				if (i != j)
				{
					if (k[i].kolizja(pom, k[j]))
					{
						mozna = false;
					}
				}
			}
		}
		if (mozna)
		{
			k[i].ruch(pom);
		}
	}
}
