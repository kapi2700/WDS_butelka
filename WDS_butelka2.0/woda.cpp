#include "woda.h"

woda::woda(int n)
{
	wektor3D pom;

	pom.p[0] = 0;
	pom.p[1] = 0;
	pom.p[2] = 0;

	l = n;

	kropla* kr;
	for (int i = 0; i < n; i++)
	{
		kr = new kropla;
		k.push_back(*kr);
		delete kr;

		for (int j = 0; j < i - 1; j++)
		{
			if (k[i].kolizja(pom, k[j]))		//jesli nowa kropla koliduje z inna jest ona usuwana, oraz ilosc kropli 
			{									//zmniejszana w celu ponownej proby wylosowania jej polozenia
				i--;
				k.pop_back();
				break;
			}
		}

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
						break;
					}
				}
			}
		}
		if (mozna)
		{
			k[i].ruch(pom);
		}

		if (!mozna)		//jesli nie mozna bezposrednio w dol, sprawdzamy kolejne molzwiosci
		{
			pom.p[0] = 0;
			pom.p[1] = -0.002;
			pom.p[2] = 0.009;

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
							break;
						}
					}
				}
			}
			if (mozna)
			{
				k[i].ruch(pom);
			}
		}

		if (!mozna)		//jesli nie mozna bezposrednio w dol, sprawdzamy kolejne molzwiosci
		{
			pom.p[0] = 0;
			pom.p[1] = -0.002;
			pom.p[2] = 0.009;

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
							break;
						}
					}
				}
			}
			if (mozna)
			{
				k[i].ruch(pom);
			}
		}

		if (!mozna)		//jesli nie mozna bezposrednio w dol, sprawdzamy kolejne molzwiosci
		{
			pom.p[0] = -0.009;
			pom.p[1] = -0.002;
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
							break;
						}
					}
				}
			}
			if (mozna)
			{
				k[i].ruch(pom);
			}
		}

		if (!mozna)		//jesli nie mozna bezposrednio w dol, sprawdzamy kolejne molzwiosci
		{
			pom.p[0] = 0.009;
			pom.p[1] = -0.002;
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
							break;
						}
					}
				}
			}
			if (mozna)
			{
				k[i].ruch(pom);
			}
		}

		if (!mozna)		//jesli nie mozna bezposrednio w dol, sprawdzamy kolejne molzwiosci
		{
			pom.p[0] = 0.002;
			pom.p[1] = 0;
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
							break;
						}
					}
				}
			}
			if (mozna)
			{
				k[i].ruch(pom);
			}
		}

		if (!mozna)		//jesli nie mozna bezposrednio w dol, sprawdzamy kolejne molzwiosci
		{
			pom.p[0] = -0.002;
			pom.p[1] = 0;
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
							break;
						}
					}
				}
			}
			if (mozna)
			{
				k[i].ruch(pom);
			}
		}

		if (!mozna)		//jesli nie mozna bezposrednio w dol, sprawdzamy kolejne molzwiosci
		{
			pom.p[0] = 0;
			pom.p[1] = 0;
			pom.p[2] = 0.002;

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
							break;
						}
					}
				}
			}
			if (mozna)
			{
				k[i].ruch(pom);
			}
		}

		if (!mozna)		//jesli nie mozna bezposrednio w dol, sprawdzamy kolejne molzwiosci
		{
			pom.p[0] = 0;
			pom.p[1] = 0;
			pom.p[2] = -0.002;

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
							break;
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
}
