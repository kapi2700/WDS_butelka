#include "kropla.h"




void kropla::rysuj()
{
	glColor3f(0.4335f, 0.8476f, 1.0);
	glTranslatef(srodek_glob.p[0], srodek_glob.p[1], srodek_glob.p[2]);
	glutSolidSphere(promien, 100, 100);
	glTranslatef(-srodek_glob.p[0], -srodek_glob.p[1], -srodek_glob.p[2]);
}

kropla::kropla()
{
	bool czydobre = false;
	promien = 0.05;						//promien kropli
	ostatni_kat_x = 0;
	ostatni_kat_y = 0;
	ostatni_kat_z = 0;


	while (!czydobre)
	{
		srodek_glob.p[0] = ((float)(rand() % 8000)) / 10000 - 0.4f;
		srodek_glob.p[1] = ((float)(rand() % 8000)) / 10000 - 0.4f;
		srodek_glob.p[2] = ((float)(rand() % 8000)) / 10000 - 0.4f;

		if ((srodek_glob.odlegloscY() < 0.4))
			czydobre = true;
	}

	srodek_wewn = srodek_glob;
	czy_wewnatrz = true;
}

kropla::~kropla()
{
}

void kropla::obroc(float kat_x, float kat_y, float kat_z)
{
	if (!czy_wewnatrz)
		return;

	macierz_rot macx(ostatni_kat_x, 'x');
	macierz_rot macy(ostatni_kat_y, 'y');

    kat_x = kat_x * (float)PI / 180.0f;
    kat_y = kat_y * (float)PI / 180.0f;

	srodek_glob.mnozenie(macy);
	srodek_glob.mnozenie(macx);

	macx = { kat_x, 'x' };
	macy = { kat_y, 'y' };

	srodek_glob.mnozenie(macx);
	srodek_glob.mnozenie(macy);

	ostatni_kat_x = -kat_x;
	ostatni_kat_y = -kat_y;
}

void kropla::ruch(wektor3D wek)
{
	macierz_rot macx(ostatni_kat_x, 'x');
	macierz_rot macy(ostatni_kat_y, 'y');

	srodek_glob = srodek_glob + wek;
	wek.mnozenie(macy);
	wek.mnozenie(macx);

	srodek_wewn = srodek_wewn + wek;
}

bool kropla::kolizja(wektor3D ruch)
{
	wektor3D poruchuwew;
	wektor3D poruchu;
	macierz_rot rotx(ostatni_kat_x, 'x');
	macierz_rot roty(ostatni_kat_y, 'y');

	poruchu = srodek_glob + ruch;

	ruch.mnozenie(roty);
	ruch.mnozenie(rotx);


	poruchuwew = srodek_wewn + ruch;


	if (poruchuwew.p[1] < (-1+promien))												//kropla na spodzie butelki
		return true;
	if ((poruchuwew.p[1] >= (-1+ promien)) && (poruchuwew.p[1] < (1- promien)))				//kropla w g³ównej czêœci butelki
	{
		if (poruchuwew.odlegloscY() > (0.5 - promien -0.05))
		{
			return true;
		}
	}
	else if ((poruchuwew.p[1] >= (1 - promien)) && (poruchuwew.p[1] <= 1.5 + promien))	//kropla w w¹skiej czêœci butelki
	{
		if (poruchuwew.odlegloscY() > (0.15 - promien))
		{
			return true;
		}
	}
	else if ((poruchuwew.p[1] > 1.5 + promien))
	{
		czy_wewnatrz = false;
		return false;
	}	
	return false;
}


bool kropla::kolizja(wektor3D ruch, kropla sprawdzana)
{
	wektor3D poruchu;
	poruchu = srodek_glob + ruch;

	if (sprawdzana.odleglosc(poruchu) < (2 * promien))
		return true;
	return false;
}


float kropla::odleglosc(wektor3D start)
{
	float odl;

	start = start - srodek_glob;

	odl = (float)sqrt(((double)start.p[0] * start.p[0]) + ((double)start.p[1] * start.p[1]) + ((double)start.p[2] * start.p[2]));

	return odl;
}
