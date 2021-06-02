#include "kropla.h"




void kropla::rysuj()
{
	glColor3f(0.4335f, 0.8476f, 1.0);
	glTranslatef(p.p[0], p.p[1], p.p[2]);
	glutSolidSphere(r, 100, 100);
	glTranslatef(-p.p[0], -p.p[1], -p.p[2]);
}

kropla::kropla()
{
	bool czydobre = false;
	r = 0.05;
	kx = 0;
	ky = 0;
	kz = 0;


	while (!czydobre)
	{
		p.p[0] = ((float)(rand() % 8000)) / 10000 - 0.4f;
		p.p[2] = ((float)(rand() % 8000)) / 10000 - 0.4f;

		if ((p.odlegloscY() < 0.4))
			czydobre = true;
	}

	p.p[1] = 0;

	wew = p;
	wewnatrz = true;
}

kropla::~kropla()
{
}

void kropla::obroc(float x, float y, float z)
{
	if (!wewnatrz)
		return;

	macierz_rot macz(kz, 'z');
	macierz_rot macx(kx, 'x');
	macierz_rot macy(ky, 'y');

    x = x * (float)PI / 180.0f;
    y = y * (float)PI / 180.0f;
    
	//p = pstart;
	p.mnozenie(macy);
	p.mnozenie(macx);
	//p.mnozenie(macz);

	macx = { x, 'x' };
	macy = { y, 'y' };

	//p.mnozenie(macz);
	p.mnozenie(macx);
	p.mnozenie(macy);

	kx = -x;
	ky = -y;
	//kz = -z;
}

void kropla::ruch(wektor3D wek)
{
	macierz_rot macx(-kx, 'x');
	macierz_rot macy(-ky, 'y');

	p = p + wek;
	wek.mnozenie(macx);
	wek.mnozenie(macy);

	wew = wew + wek;
}

bool kropla::kolizja(wektor3D ruch)
{
	wektor3D poruchuwew;
	wektor3D poruchu;
	macierz_rot rotx(kx, 'x');
	macierz_rot roty(ky, 'y');

	poruchu = p + ruch;

	ruch.mnozenie(rotx);
	ruch.mnozenie(roty);

	poruchuwew = wew + ruch;



	if (poruchuwew.p[1] < (-1+r))										//sprawdzanie butelki
		return true;
	if ((poruchuwew.p[1] >= (-1+r)) && (poruchuwew.p[1] < (1.1-r)))
	{
		if (poruchuwew.odlegloscY() > (0.5 - r))
		{
			return true;
		}
	}
	else if ((poruchuwew.p[1] >= (1.1 - r)) && (poruchuwew.p[1] <= 1.5 + r))
	{
		if (poruchuwew.odlegloscY() > (0.15 - r))
		{
			return true;
		}
	}
	else if ((poruchuwew.p[1] > 1.5 + r))
	{
		wewnatrz = false;
		return false;
	}	
	return false;
}


bool kropla::kolizja(wektor3D ruch, kropla a)
{
	wektor3D poruchu;
	poruchu = p + ruch;

	if (a.odleglosc(poruchu) < (2 * r))
		return true;
	return false;
}


float kropla::odleglosc(wektor3D start)
{
	float odl;

	start = start - p;

	odl = (float)sqrt(((double)start.p[0] * start.p[0]) + ((double)start.p[1] * start.p[1]) + ((double)start.p[2] * start.p[2]));

	return odl;
}
