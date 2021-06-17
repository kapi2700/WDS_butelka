#include "woda.h"

woda::woda(int n)
{
	wektor3D pom;

	pom.p[0] = 0;
	pom.p[1] = 0;
	pom.p[2] = 0;

	ilosc_kropli = n;

	kropla* kr;
	for (int i = 0; i < n; i++)
	{
		kr = new kropla;
		krople.push_back(*kr);
		delete kr;

		for (int j = 0; j < i - 1; j++)
		{
			if (krople[i].kolizja(pom, krople[j]))		//jesli nowa kropla koliduje z inna jest ona usuwana, oraz ilosc kropli 
			{									//zmniejszana w celu ponownej proby wylosowania jej polozenia
				i--;
				krople.pop_back();
				break;
			}
		}

	}

}

void woda::rysuj()
{
	for (int i = 0; i < ilosc_kropli; i++)
	{
		krople[i].rysuj();
	}
}

void woda::obroc(float x, float y, float z)
{
	for (int i = 0; i < ilosc_kropli; i++)
	{
		krople[i].obroc(x, y, z);
	}
	x = x * (float)PI / 180.0f;
	y = y * (float)PI / 180.0f;
	ostatni_kat_x = -x;
	ostatni_kat_y = -y;
}

void woda::grawitacja()
{
	wektor3D pom;
	bool mozna = false;


	for (int i = 0; i < ilosc_kropli; i++)
	{
		pom.p[0] = 0;
		pom.p[1] = -0.1;
		pom.p[2] = 0;

		mozna = !krople[i].kolizja(pom);
		if (mozna)
		{
			for (int j = 0; j < ilosc_kropli; j++)
			{
				if (i != j)
				{
					if (krople[i].kolizja(pom, krople[j]))
					{
						mozna = false;
						break;
					}
				}
			}
		}
		if (mozna)
		{
			krople[i].ruch(pom);
		}

		if (!mozna)		//jesli nie mozna bezposrednio w dol, sprawdzamy kolejne molzwiosci
		{
			pom.p[0] = 0;
			pom.p[1] = -0.02;
			pom.p[2] = 0.09;

			mozna = !krople[i].kolizja(pom);
			if (mozna)
			{
				for (int j = 0; j < ilosc_kropli; j++)
				{
					if (i != j)
					{
						if (krople[i].kolizja(pom, krople[j]))
						{
							mozna = false;
							break;
						}
					}
				}
			}
			if (mozna)
			{
				krople[i].ruch(pom);
			}
		}

		if (!mozna)		//jesli nie mozna bezposrednio w dol, sprawdzamy kolejne molzwiosci
		{
			pom.p[0] = 0;
			pom.p[1] = -0.02;
			pom.p[2] = 0.09;

			mozna = !krople[i].kolizja(pom);
			if (mozna)
			{
				for (int j = 0; j < ilosc_kropli; j++)
				{
					if (i != j)
					{
						if (krople[i].kolizja(pom, krople[j]))
						{
							mozna = false;
							break;
						}
					}
				}
			}
			if (mozna)
			{
				krople[i].ruch(pom);
			}
		}

		if (!mozna)		//jesli nie mozna bezposrednio w dol, sprawdzamy kolejne molzwiosci
		{
			pom.p[0] = -0.09;
			pom.p[1] = -0.02;
			pom.p[2] = 0;

			mozna = !krople[i].kolizja(pom);
			if (mozna)
			{
				for (int j = 0; j < ilosc_kropli; j++)
				{
					if (i != j)
					{
						if (krople[i].kolizja(pom, krople[j]))
						{
							mozna = false;
							break;
						}
					}
				}
			}
			if (mozna)
			{
				krople[i].ruch(pom);
			}
		}

		if (!mozna)		//jesli nie mozna bezposrednio w dol, sprawdzamy kolejne molzwiosci
		{
			pom.p[0] = 0.09;
			pom.p[1] = -0.02;
			pom.p[2] = 0;

			mozna = !krople[i].kolizja(pom);
			if (mozna)
			{
				for (int j = 0; j < ilosc_kropli; j++)
				{
					if (i != j)
					{
						if (krople[i].kolizja(pom, krople[j]))
						{
							mozna = false;
							break;
						}
					}
				}
			}
			if (mozna)
			{
				krople[i].ruch(pom);
			}
		}

		if (!mozna)		//jesli nie mozna bezposrednio w dol, sprawdzamy kolejne molzwiosci
		{
			pom.p[0] = 0.02;
			pom.p[1] = 0;
			pom.p[2] = 0;

			mozna = !krople[i].kolizja(pom);
			if (mozna)
			{
				for (int j = 0; j < ilosc_kropli; j++)
				{
					if (i != j)
					{
						if (krople[i].kolizja(pom, krople[j]))
						{
							mozna = false;
							break;
						}
					}
				}
			}
			if (mozna)
			{
				krople[i].ruch(pom);
			}
		}

		if (!mozna)		//jesli nie mozna bezposrednio w dol, sprawdzamy kolejne molzwiosci
		{
			pom.p[0] = -0.02;
			pom.p[1] = 0;
			pom.p[2] = 0;

			mozna = !krople[i].kolizja(pom);
			if (mozna)
			{
				for (int j = 0; j < ilosc_kropli; j++)
				{
					if (i != j)
					{
						if (krople[i].kolizja(pom, krople[j]))
						{
							mozna = false;
							break;
						}
					}
				}
			}
			if (mozna)
			{
				krople[i].ruch(pom);
			}
		}

		if (!mozna)		//jesli nie mozna bezposrednio w dol, sprawdzamy kolejne molzwiosci
		{
			pom.p[0] = 0;
			pom.p[1] = 0;
			pom.p[2] = 0.02;

			mozna = !krople[i].kolizja(pom);
			if (mozna)
			{
				for (int j = 0; j < ilosc_kropli; j++)
				{
					if (i != j)
					{
						if (krople[i].kolizja(pom, krople[j]))
						{
							mozna = false;
							break;
						}
					}
				}
			}
			if (mozna)
			{
				krople[i].ruch(pom);
			}
		}

		if (!mozna)		//jesli nie mozna bezposrednio w dol, sprawdzamy kolejne molzwiosci
		{
			pom.p[0] = 0;
			pom.p[1] = 0;
			pom.p[2] = -0.02;

			mozna = !krople[i].kolizja(pom);
			if (mozna)
			{
				for (int j = 0; j < ilosc_kropli; j++)
				{
					if (i != j)
					{
						if (krople[i].kolizja(pom, krople[j]))
						{
							mozna = false;
							break;
						}
					}
				}
			}
			if (mozna)
			{
				krople[i].ruch(pom);
			}
		}
	}
}
