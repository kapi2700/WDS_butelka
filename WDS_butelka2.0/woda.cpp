#include "woda.h"

woda::woda(int n)
{
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
	for (int i = 0; i < k.size(); i++)
	{
		k[i].rysuj();
	}
}
