#include "NmirroredShape.h"

NmirroredShape::NmirroredShape(int wspol_x, int wspol_y, Tplansza& tab)
{
	tab.plansza[wspol_y][wspol_x].jest_tetromino = true;
	tab.plansza[wspol_y + 1][wspol_x].jest_tetromino = true;
	tab.plansza[wspol_y + 1][wspol_x - 1].bloczek_rotacji = true;
	tab.plansza[wspol_y + 2][wspol_x - 1].jest_tetromino = true;
}

void NmirroredShape::rotacja_klocka(int wspol_x, int wspol_y, Tplansza& tab)
{
	if (pozycja_1(wspol_x, wspol_y, tab))
	{
		if (mozliwosc_rotacji(wspol_x, wspol_y, tab))
			rotacja_1(wspol_x, wspol_y, tab);
		else return;
	}

	else if (pozycja_2(wspol_x, wspol_y, tab))
	{
		if (mozliwosc_rotacji(wspol_x, wspol_y, tab))
			rotacja_2(wspol_x, wspol_y, tab);
		else return;
	}
	else if (pozycja_3(wspol_x, wspol_y, tab))
	{
		if (mozliwosc_rotacji(wspol_x, wspol_y, tab))
			rotacja_3(wspol_x, wspol_y, tab);
		else return;
	}
	else if (pozycja_4(wspol_x, wspol_y, tab))
	{
		if (mozliwosc_rotacji(wspol_x, wspol_y, tab))
			rotacja_4(wspol_x, wspol_y, tab);
		else return;
	}
}

int NmirroredShape::ruch_prawo(int wspol_x, int wspol_y, Tplansza& tab)
{
	if (pozycja_1(wspol_x, wspol_y, tab))
	{
		if (mozliwosc_ruchu_prawo(wspol_x, wspol_y, tab))
		{
			tab.plansza[wspol_y][wspol_x].bloczek_rotacji = false;
			tab.plansza[wspol_y - 1][wspol_x + 1].jest_tetromino = false;
			tab.plansza[wspol_y][wspol_x + 1].jest_tetromino = false;
			tab.plansza[wspol_y + 1][wspol_x].jest_tetromino = false;

			tab.plansza[wspol_y][wspol_x + 1].bloczek_rotacji = true;
			tab.plansza[wspol_y - 1][wspol_x + 2].jest_tetromino = true;
			tab.plansza[wspol_y][wspol_x + 2].jest_tetromino = true;
			tab.plansza[wspol_y + 1][wspol_x + 1].jest_tetromino = true;
			return wspol_x + 1;
		}
		else return wspol_x;
	}
	else if (pozycja_2(wspol_x, wspol_y, tab))
	{
		if (mozliwosc_ruchu_prawo(wspol_x, wspol_y, tab))
		{
			tab.plansza[wspol_y][wspol_x].bloczek_rotacji = false;
			tab.plansza[wspol_y - 1][wspol_x - 1].jest_tetromino = false;
			tab.plansza[wspol_y - 1][wspol_x].jest_tetromino = false;
			tab.plansza[wspol_y][wspol_x + 1].jest_tetromino = false;

			tab.plansza[wspol_y][wspol_x + 1].bloczek_rotacji = true;
			tab.plansza[wspol_y - 1][wspol_x ].jest_tetromino = true;
			tab.plansza[wspol_y - 1][wspol_x + 1].jest_tetromino = true;
			tab.plansza[wspol_y][wspol_x + 2].jest_tetromino = true;
			return wspol_x + 1;
		}
		else return wspol_x;
	}
	else if (pozycja_3(wspol_x, wspol_y, tab))
	{
		if (mozliwosc_ruchu_prawo(wspol_x, wspol_y, tab))
		{
			tab.plansza[wspol_y][wspol_x].bloczek_rotacji = false;
			tab.plansza[wspol_y + 1][wspol_x].jest_tetromino = false;
			tab.plansza[wspol_y][wspol_x - 1].jest_tetromino = false;
			tab.plansza[wspol_y - 1][wspol_x - 1].jest_tetromino = false;

			tab.plansza[wspol_y][wspol_x + 1].bloczek_rotacji = true;
			tab.plansza[wspol_y + 1][wspol_x + 1].jest_tetromino = true;
			tab.plansza[wspol_y][wspol_x].jest_tetromino = true;
			tab.plansza[wspol_y - 1][wspol_x].jest_tetromino = true;
			return wspol_x + 1;
		}
		else return wspol_x;
	}
	else if (pozycja_4(wspol_x, wspol_y, tab))
	{
		if (mozliwosc_ruchu_prawo(wspol_x, wspol_y, tab))
		{
			tab.plansza[wspol_y][wspol_x].bloczek_rotacji = false;
			tab.plansza[wspol_y][wspol_x - 1].jest_tetromino = false;
			tab.plansza[wspol_y - 1][wspol_x].jest_tetromino = false;
			tab.plansza[wspol_y - 1][wspol_x + 1].jest_tetromino = false;

			tab.plansza[wspol_y][wspol_x + 1].bloczek_rotacji = true;
			tab.plansza[wspol_y][wspol_x ].jest_tetromino = true;
			tab.plansza[wspol_y - 1][wspol_x + 1].jest_tetromino = true;
			tab.plansza[wspol_y - 1][wspol_x + 2].jest_tetromino = true;
			return wspol_x + 1;
		}
		else return wspol_x;
	}

}

int NmirroredShape::ruch_lewo(int wspol_x, int wspol_y, Tplansza& tab)
{
	if (pozycja_1(wspol_x, wspol_y, tab))
	{
		if (mozliwosc_ruchu_lewo(wspol_x, wspol_y, tab))
		{
			tab.plansza[wspol_y][wspol_x].bloczek_rotacji = false;
			tab.plansza[wspol_y - 1][wspol_x + 1].jest_tetromino = false;
			tab.plansza[wspol_y][wspol_x + 1].jest_tetromino = false;
			tab.plansza[wspol_y + 1][wspol_x].jest_tetromino = false;

			tab.plansza[wspol_y][wspol_x - 1].bloczek_rotacji = true;
			tab.plansza[wspol_y - 1][wspol_x].jest_tetromino = true;
			tab.plansza[wspol_y][wspol_x].jest_tetromino = true;
			tab.plansza[wspol_y + 1][wspol_x - 1].jest_tetromino = true;
			return wspol_x - 1;
		}
		else return wspol_x;
	}
	else if (pozycja_2(wspol_x, wspol_y, tab))
	{
		if (mozliwosc_ruchu_lewo(wspol_x, wspol_y, tab))
		{
			tab.plansza[wspol_y][wspol_x].bloczek_rotacji = false;
			tab.plansza[wspol_y - 1][wspol_x - 1].jest_tetromino = false;
			tab.plansza[wspol_y - 1][wspol_x].jest_tetromino = false;
			tab.plansza[wspol_y][wspol_x + 1].jest_tetromino = false;

			tab.plansza[wspol_y][wspol_x - 1].bloczek_rotacji = true;
			tab.plansza[wspol_y - 1][wspol_x - 2].jest_tetromino = true;
			tab.plansza[wspol_y - 1][wspol_x - 1].jest_tetromino = true;
			tab.plansza[wspol_y][wspol_x].jest_tetromino = true;
			return wspol_x - 1;
		}
		else return wspol_x;
	}
	else if (pozycja_3(wspol_x, wspol_y, tab))
	{
		if (mozliwosc_ruchu_lewo(wspol_x, wspol_y, tab))
		{
			tab.plansza[wspol_y][wspol_x].bloczek_rotacji = false;
			tab.plansza[wspol_y + 1][wspol_x].jest_tetromino = false;
			tab.plansza[wspol_y][wspol_x - 1].jest_tetromino = false;
			tab.plansza[wspol_y - 1][wspol_x - 1].jest_tetromino = false;

			tab.plansza[wspol_y][wspol_x - 1].bloczek_rotacji = true;
			tab.plansza[wspol_y + 1][wspol_x - 1].jest_tetromino = true;
			tab.plansza[wspol_y][wspol_x - 2].jest_tetromino = true;
			tab.plansza[wspol_y - 1][wspol_x - 2].jest_tetromino = true;
			return wspol_x - 1;
		}
		else return wspol_x;
	}
	else if (pozycja_4(wspol_x, wspol_y, tab))
	{
		if (mozliwosc_ruchu_lewo(wspol_x, wspol_y, tab))
		{
			tab.plansza[wspol_y][wspol_x].bloczek_rotacji = false;
			tab.plansza[wspol_y][wspol_x - 1].jest_tetromino = false;
			tab.plansza[wspol_y - 1][wspol_x].jest_tetromino = false;
			tab.plansza[wspol_y - 1][wspol_x + 1].jest_tetromino = false;

			tab.plansza[wspol_y][wspol_x - 1 ].bloczek_rotacji = true;
			tab.plansza[wspol_y][wspol_x - 2].jest_tetromino = true;
			tab.plansza[wspol_y - 1][wspol_x - 1].jest_tetromino = true;
			tab.plansza[wspol_y - 1][wspol_x ].jest_tetromino = true;
			return wspol_x - 1;
		}
		else return wspol_x;
	}
}

int NmirroredShape::ruch_dol(int wspol_x, int wspol_y, Tplansza& tab)
{
	if (pozycja_1(wspol_x, wspol_y, tab))
	{
		if (mozliwosc_ruchu_dol(wspol_x, wspol_y, tab))
		{
			tab.plansza[wspol_y][wspol_x].bloczek_rotacji = false;
			tab.plansza[wspol_y - 1][wspol_x + 1].jest_tetromino = false;
			tab.plansza[wspol_y][wspol_x + 1].jest_tetromino = false;
			tab.plansza[wspol_y + 1][wspol_x].jest_tetromino = false;

			tab.plansza[wspol_y + 1][wspol_x].bloczek_rotacji = true;
			tab.plansza[wspol_y][wspol_x + 1].jest_tetromino = true;
			tab.plansza[wspol_y + 1][wspol_x + 1].jest_tetromino = true;
			tab.plansza[wspol_y + 2][wspol_x].jest_tetromino = true;
			return wspol_x - 1;
		}
		else return wspol_x;
	}
	else if (pozycja_2(wspol_x, wspol_y, tab))
	{
		if (mozliwosc_ruchu_dol(wspol_x, wspol_y, tab))
		{
			tab.plansza[wspol_y][wspol_x].bloczek_rotacji = false;
			tab.plansza[wspol_y - 1][wspol_x - 1].jest_tetromino = false;
			tab.plansza[wspol_y - 1][wspol_x].jest_tetromino = false;
			tab.plansza[wspol_y][wspol_x + 1].jest_tetromino = false;

			tab.plansza[wspol_y + 1][wspol_x].bloczek_rotacji = true;
			tab.plansza[wspol_y ][wspol_x - 1].jest_tetromino = true;
			tab.plansza[wspol_y][wspol_x].jest_tetromino = true;
			tab.plansza[wspol_y + 1][wspol_x + 1].jest_tetromino = true;
			return wspol_x - 1;
		}
		else return wspol_x;
	}
	else if (pozycja_3(wspol_x, wspol_y, tab))
	{
		if (mozliwosc_ruchu_dol(wspol_x, wspol_y, tab))
		{
			tab.plansza[wspol_y][wspol_x].bloczek_rotacji = false;
			tab.plansza[wspol_y + 1][wspol_x].jest_tetromino = false;
			tab.plansza[wspol_y][wspol_x - 1].jest_tetromino = false;
			tab.plansza[wspol_y - 1][wspol_x - 1].jest_tetromino = false;


			tab.plansza[wspol_y + 1][wspol_x].bloczek_rotacji = true;
			tab.plansza[wspol_y + 2][wspol_x].jest_tetromino = true;
			tab.plansza[wspol_y + 1][wspol_x - 1].jest_tetromino = true;
			tab.plansza[wspol_y][wspol_x - 1].jest_tetromino = true;
			return wspol_x - 1;
		}
		else return wspol_x;
	}
	else if (pozycja_4(wspol_x, wspol_y, tab))
	{
		if (mozliwosc_ruchu_dol(wspol_x, wspol_y, tab))
		{
			tab.plansza[wspol_y][wspol_x].bloczek_rotacji = false;
			tab.plansza[wspol_y][wspol_x - 1].jest_tetromino = false;
			tab.plansza[wspol_y - 1][wspol_x].jest_tetromino = false;
			tab.plansza[wspol_y - 1][wspol_x + 1].jest_tetromino = false;

			tab.plansza[wspol_y + 1][wspol_x].bloczek_rotacji = true;
			tab.plansza[wspol_y + 1][wspol_x - 1].jest_tetromino = true;
			tab.plansza[wspol_y][wspol_x].jest_tetromino = true;
			tab.plansza[wspol_y][wspol_x + 1].jest_tetromino = true;
			return wspol_x - 1;
		}
		else return wspol_x;
	}
	return wspol_y + 1;
}

bool NmirroredShape::czy_usmiercic_tetromino(int wspol_x, int wspol_y, Tplansza& tab)
{
	if (pozycja_1(wspol_x, wspol_y, tab))
		if (!(mozliwosc_ruchu_dol(wspol_x, wspol_y, tab)))
		{
			usmiercanie_tetromino(wspol_x, wspol_y, tab);
			return true;
		}
		else return false;
	else if (pozycja_2(wspol_x, wspol_y, tab))
		if (!(mozliwosc_ruchu_dol(wspol_x, wspol_y, tab)))
		{
			usmiercanie_tetromino(wspol_x, wspol_y, tab);
			return true;
		}
		else return false;
	else if (pozycja_3(wspol_x, wspol_y, tab))
		if (!(mozliwosc_ruchu_dol(wspol_x, wspol_y, tab)))
		{
			usmiercanie_tetromino(wspol_x, wspol_y, tab);
			return true;
		}
		else return false;
	else if (pozycja_4(wspol_x, wspol_y, tab))
		if (!(mozliwosc_ruchu_dol(wspol_x, wspol_y, tab)))
		{
			usmiercanie_tetromino(wspol_x, wspol_y, tab);
			return true;
		}
		else return false;
}

void NmirroredShape::rotacja_1(int wspol_x, int wspol_y, Tplansza& tab)
{
	tab.plansza[wspol_y][wspol_x].bloczek_rotacji = false;
	tab.plansza[wspol_y - 1][wspol_x + 1].jest_tetromino = false;
	tab.plansza[wspol_y][wspol_x + 1].jest_tetromino = false;
	tab.plansza[wspol_y + 1][wspol_x].jest_tetromino = false;

	tab.plansza[wspol_y][wspol_x].bloczek_rotacji = true;
	tab.plansza[wspol_y - 1][wspol_x - 1].jest_tetromino = true;
	tab.plansza[wspol_y - 1][wspol_x].jest_tetromino = true;
	tab.plansza[wspol_y][wspol_x + 1].jest_tetromino = true;
	return;

}

void NmirroredShape::rotacja_2(int wspol_x, int wspol_y, Tplansza& tab)
{
	tab.plansza[wspol_y][wspol_x].bloczek_rotacji = false;
	tab.plansza[wspol_y - 1][wspol_x - 1].jest_tetromino = false;
	tab.plansza[wspol_y - 1][wspol_x].jest_tetromino = false;
	tab.plansza[wspol_y][wspol_x + 1].jest_tetromino = false;

	tab.plansza[wspol_y][wspol_x].bloczek_rotacji = true;
	tab.plansza[wspol_y + 1][wspol_x].jest_tetromino = true;
	tab.plansza[wspol_y][wspol_x - 1].jest_tetromino = true;
	tab.plansza[wspol_y - 1][wspol_x - 1].jest_tetromino = true;

	return;
}

void NmirroredShape::rotacja_3(int wspol_x, int wspol_y, Tplansza& tab)
{
	tab.plansza[wspol_y][wspol_x].bloczek_rotacji = false;
	tab.plansza[wspol_y + 1][wspol_x].jest_tetromino = false;
	tab.plansza[wspol_y][wspol_x - 1].jest_tetromino = false;

	tab.plansza[wspol_y - 1][wspol_x - 1].jest_tetromino = false;

	tab.plansza[wspol_y][wspol_x].bloczek_rotacji = true;
	tab.plansza[wspol_y][wspol_x - 1].jest_tetromino = true;
	tab.plansza[wspol_y - 1][wspol_x].jest_tetromino = true;
	tab.plansza[wspol_y - 1][wspol_x + 1].jest_tetromino = true;

	return;
}

void NmirroredShape::rotacja_4(int wspol_x, int wspol_y, Tplansza& tab)
{
	tab.plansza[wspol_y][wspol_x].bloczek_rotacji = false;
	tab.plansza[wspol_y][wspol_x - 1].jest_tetromino = false;
	tab.plansza[wspol_y - 1][wspol_x].jest_tetromino = false;
	tab.plansza[wspol_y - 1][wspol_x + 1].jest_tetromino = false;

	tab.plansza[wspol_y][wspol_x].bloczek_rotacji = true;
	tab.plansza[wspol_y - 1][wspol_x + 1].jest_tetromino = true;
	tab.plansza[wspol_y][wspol_x + 1].jest_tetromino = true;
	tab.plansza[wspol_y + 1][wspol_x].jest_tetromino = true;

	return;
}

bool NmirroredShape::pozycja_1(int wspol_x, int wspol_y, Tplansza& tab)
{
	if ((tab.plansza[wspol_y][wspol_x].bloczek_rotacji)
		&& (tab.plansza[wspol_y - 1][wspol_x + 1].jest_tetromino)
		&& (tab.plansza[wspol_y][wspol_x + 1].jest_tetromino)
		&& (tab.plansza[wspol_y + 1][wspol_x].jest_tetromino))
		return true;
	else return false;
}

bool NmirroredShape::pozycja_2(int wspol_x, int wspol_y, Tplansza& tab)
{
	if ((tab.plansza[wspol_y][wspol_x].bloczek_rotacji)
		&& (tab.plansza[wspol_y - 1][wspol_x - 1].jest_tetromino)
		&& (tab.plansza[wspol_y - 1][wspol_x].jest_tetromino)
		&& (tab.plansza[wspol_y][wspol_x + 1].jest_tetromino))
		return true;
	else return false;
}

bool NmirroredShape::pozycja_3(int wspol_x, int wspol_y, Tplansza& tab)
{
	if ((tab.plansza[wspol_y][wspol_x].bloczek_rotacji)
		&& (tab.plansza[wspol_y + 1][wspol_x].jest_tetromino)
		&& (tab.plansza[wspol_y - 1][wspol_x - 1].jest_tetromino)
		&& (tab.plansza[wspol_y][wspol_x - 1].jest_tetromino))
		return true;
	else return false;
}

bool NmirroredShape::pozycja_4(int wspol_x, int wspol_y, Tplansza& tab)
{
	if ((tab.plansza[wspol_y][wspol_x].bloczek_rotacji)
		&& (tab.plansza[wspol_y - 1][wspol_x].jest_tetromino)
		&& (tab.plansza[wspol_y - 1][wspol_x + 1].jest_tetromino)
		&& (tab.plansza[wspol_y][wspol_x - 1].jest_tetromino))
		return true;
	else return false;
}

bool NmirroredShape::mozliwosc_rotacji(int wspol_x, int wspol_y, Tplansza& tab)
{
	if (pozycja_1(wspol_x, wspol_y, tab))
		if (
			(tab.plansza[wspol_y][wspol_x - 1].jest_tetromino)
			|| (tab.plansza[wspol_y][wspol_x - 1].zewnetrzna_warstwa)
			|| (tab.plansza[wspol_y + 1][wspol_x - 1].jest_tetromino)
			|| (tab.plansza[wspol_y + 1][wspol_x - 1].zewnetrzna_warstwa))
			return false;
		else return true;

	else if (pozycja_2(wspol_x, wspol_y, tab))
		if ((tab.plansza[wspol_y + 1][wspol_x].jest_tetromino)
			|| (tab.plansza[wspol_y + 1][wspol_x].zewnetrzna_warstwa)
			|| (tab.plansza[wspol_y - 1][wspol_x + 1].jest_tetromino)
			|| (tab.plansza[wspol_y - 1][wspol_x + 1].zewnetrzna_warstwa))
			return false;
		else return true;

	else if (pozycja_3(wspol_x, wspol_y, tab))
		if ((tab.plansza[wspol_y - 1][wspol_x + 1].jest_tetromino)
			|| (tab.plansza[wspol_y - 1][wspol_x + 1].zewnetrzna_warstwa)
			|| (tab.plansza[wspol_y - 1][wspol_x].jest_tetromino)
			|| (tab.plansza[wspol_y - 1][wspol_x].zewnetrzna_warstwa))
			return false;
		else return true;

	else if (pozycja_4(wspol_x, wspol_y, tab))
		if ((tab.plansza[wspol_y][wspol_x + 1].jest_tetromino)
			|| (tab.plansza[wspol_y ][wspol_x + 1].zewnetrzna_warstwa)
			|| (tab.plansza[wspol_y + 1][wspol_x +  1].jest_tetromino)
			|| (tab.plansza[wspol_y + 1][wspol_x + 1].zewnetrzna_warstwa))
			return false;
		else return true;
}

bool NmirroredShape::mozliwosc_ruchu_prawo(int wspol_x, int wspol_y, Tplansza& tab)
{
	if (pozycja_1(wspol_x, wspol_y, tab))
		if ((tab.plansza[wspol_y][wspol_x + 2].jest_tetromino)
			|| (tab.plansza[wspol_y][wspol_x + 2].zewnetrzna_warstwa)
			|| (tab.plansza[wspol_y - 1][wspol_x + 2].jest_tetromino)
			|| (tab.plansza[wspol_y - 1][wspol_x + 2].zewnetrzna_warstwa)
			|| (tab.plansza[wspol_y + 1][wspol_x + 1].jest_tetromino)
			|| (tab.plansza[wspol_y + 1][wspol_x + 1].zewnetrzna_warstwa))
			return false;
		else return true;

	else if (pozycja_2(wspol_x, wspol_y, tab))
		if ((tab.plansza[wspol_y][wspol_x + 2].jest_tetromino)
			|| (tab.plansza[wspol_y][wspol_x + 2].zewnetrzna_warstwa)
			|| (tab.plansza[wspol_y - 1][wspol_x + 1].jest_tetromino)
			|| (tab.plansza[wspol_y - 1][wspol_x + 1].zewnetrzna_warstwa))
			return false;
		else return true;

	else if (pozycja_3(wspol_x, wspol_y, tab))
		if ((tab.plansza[wspol_y][wspol_x + 1].jest_tetromino)
			|| (tab.plansza[wspol_y][wspol_x + 1].zewnetrzna_warstwa)
			|| (tab.plansza[wspol_y - 1][wspol_x].jest_tetromino)
			|| (tab.plansza[wspol_y - 1][wspol_x].zewnetrzna_warstwa)
			|| (tab.plansza[wspol_y + 1][wspol_x + 1].jest_tetromino)
			|| (tab.plansza[wspol_y + 1][wspol_x + 1].zewnetrzna_warstwa))
			return false;
		else return true;

	else if (pozycja_4(wspol_x, wspol_y, tab))
		if ((tab.plansza[wspol_y][wspol_x + 1].jest_tetromino)
			|| (tab.plansza[wspol_y][wspol_x + 1].zewnetrzna_warstwa)
			|| (tab.plansza[wspol_y - 1][wspol_x + 2].jest_tetromino)
			|| (tab.plansza[wspol_y - 1][wspol_x + 2].zewnetrzna_warstwa))
			return false;
		else return true;
}

bool NmirroredShape::mozliwosc_ruchu_lewo(int wspol_x, int wspol_y, Tplansza& tab)
{
	if (pozycja_1(wspol_x, wspol_y, tab))
		if ((tab.plansza[wspol_y - 1][wspol_x].jest_tetromino)
			|| (tab.plansza[wspol_y - 1][wspol_x].zewnetrzna_warstwa)
			|| (tab.plansza[wspol_y][wspol_x - 1].jest_tetromino)
			|| (tab.plansza[wspol_y][wspol_x - 1].zewnetrzna_warstwa)
			|| (tab.plansza[wspol_y + 1][wspol_x - 1].jest_tetromino)
			|| (tab.plansza[wspol_y + 1][wspol_x - 1].zewnetrzna_warstwa))
			return false;
		else return true;

	else if (pozycja_2(wspol_x, wspol_y, tab))
		if ((tab.plansza[wspol_y - 1][wspol_x - 2].jest_tetromino)
			|| (tab.plansza[wspol_y - 1][wspol_x - 2].zewnetrzna_warstwa)
			|| (tab.plansza[wspol_y][wspol_x - 1].jest_tetromino)
			|| (tab.plansza[wspol_y][wspol_x - 1].zewnetrzna_warstwa))
			return false;
		else return true;

	else if (pozycja_3(wspol_x, wspol_y, tab))
		if ((tab.plansza[wspol_y - 1][wspol_x - 2].jest_tetromino)
			|| (tab.plansza[wspol_y - 1][wspol_x - 2].zewnetrzna_warstwa)
			|| (tab.plansza[wspol_y][wspol_x - 2].jest_tetromino)
			|| (tab.plansza[wspol_y][wspol_x - 2].zewnetrzna_warstwa)
			|| (tab.plansza[wspol_y + 1][wspol_x - 1].jest_tetromino)
			|| (tab.plansza[wspol_y + 1][wspol_x - 1].zewnetrzna_warstwa))
			return false;
		else return true;

	else if (pozycja_4(wspol_x, wspol_y, tab))
		if ((tab.plansza[wspol_y][wspol_x - 2].jest_tetromino)
			|| (tab.plansza[wspol_y][wspol_x - 2].zewnetrzna_warstwa)
			|| (tab.plansza[wspol_y - 1][wspol_x - 1].jest_tetromino)
			|| (tab.plansza[wspol_y - 1][wspol_x - 1].zewnetrzna_warstwa))
			return false;
		else return true;
}

bool NmirroredShape::mozliwosc_ruchu_dol(int wspol_x, int wspol_y, Tplansza& tab)
{
	if (pozycja_1(wspol_x, wspol_y, tab))
		if ((tab.plansza[wspol_y + 2][wspol_x].jest_tetromino)
			|| (tab.plansza[wspol_y + 2][wspol_x].zewnetrzna_warstwa)
			|| (tab.plansza[wspol_y + 1][wspol_x + 1].jest_tetromino)
			|| (tab.plansza[wspol_y + 1][wspol_x + 1].zewnetrzna_warstwa))
			return false;
		else return true;

	else if (pozycja_2(wspol_x, wspol_y, tab))
		if ((tab.plansza[wspol_y + 1][wspol_x].jest_tetromino)
			|| (tab.plansza[wspol_y + 1][wspol_x].zewnetrzna_warstwa)
			|| (tab.plansza[wspol_y + 1][wspol_x + 1].jest_tetromino)
			|| (tab.plansza[wspol_y + 1][wspol_x + 1].zewnetrzna_warstwa)
			|| (tab.plansza[wspol_y][wspol_x - 1].jest_tetromino)
			|| (tab.plansza[wspol_y][wspol_x - 1].zewnetrzna_warstwa))
			return false;
		else return true;

	else if (pozycja_3(wspol_x, wspol_y, tab))
		if ((tab.plansza[wspol_y + 1][wspol_x - 1].jest_tetromino)
			|| (tab.plansza[wspol_y + 1][wspol_x - 1].zewnetrzna_warstwa)
			|| (tab.plansza[wspol_y + 2][wspol_x].jest_tetromino)
			|| (tab.plansza[wspol_y + 2][wspol_x].zewnetrzna_warstwa))
			return false;
		else return true;

	else if (pozycja_4(wspol_x, wspol_y, tab))
		if ((tab.plansza[wspol_y + 1][wspol_x].jest_tetromino)
			|| (tab.plansza[wspol_y + 1][wspol_x].zewnetrzna_warstwa)
			|| (tab.plansza[wspol_y + 1][wspol_x - 1].jest_tetromino)
			|| (tab.plansza[wspol_y + 1][wspol_x - 1].zewnetrzna_warstwa)
			|| (tab.plansza[wspol_y][wspol_x + 1].jest_tetromino)
			|| (tab.plansza[wspol_y][wspol_x + 1].zewnetrzna_warstwa))
			return false;
		else return true;
}

void NmirroredShape::szybki_ruch_dol(int wspol_x, int wspol_y, Tplansza& tab)
{
	while (mozliwosc_ruchu_dol(wspol_x, wspol_y, tab))
	{
		if (pozycja_1(wspol_x, wspol_y, tab))
		{

			tab.plansza[wspol_y][wspol_x].bloczek_rotacji = false;
			tab.plansza[wspol_y - 1][wspol_x + 1].jest_tetromino = false;
			tab.plansza[wspol_y][wspol_x + 1].jest_tetromino = false;
			tab.plansza[wspol_y + 1][wspol_x].jest_tetromino = false;

			tab.plansza[wspol_y + 1][wspol_x].bloczek_rotacji = true;
			tab.plansza[wspol_y][wspol_x + 1].jest_tetromino = true;
			tab.plansza[wspol_y + 1][wspol_x + 1].jest_tetromino = true;
			tab.plansza[wspol_y + 2][wspol_x].jest_tetromino = true;
			wspol_y++;

		}
		else if (pozycja_2(wspol_x, wspol_y, tab))
		{

			tab.plansza[wspol_y][wspol_x].bloczek_rotacji = false;
			tab.plansza[wspol_y - 1][wspol_x - 1].jest_tetromino = false;
			tab.plansza[wspol_y - 1][wspol_x].jest_tetromino = false;
			tab.plansza[wspol_y][wspol_x + 1].jest_tetromino = false;

			tab.plansza[wspol_y + 1][wspol_x].bloczek_rotacji = true;
			tab.plansza[wspol_y][wspol_x - 1].jest_tetromino = true;
			tab.plansza[wspol_y][wspol_x].jest_tetromino = true;
			tab.plansza[wspol_y + 1][wspol_x + 1].jest_tetromino = true;
			wspol_y++;


		}
		else if (pozycja_3(wspol_x, wspol_y, tab))
		{

			tab.plansza[wspol_y][wspol_x].bloczek_rotacji = false;
			tab.plansza[wspol_y + 1][wspol_x].jest_tetromino = false;
			tab.plansza[wspol_y][wspol_x - 1].jest_tetromino = false;
			tab.plansza[wspol_y - 1][wspol_x - 1].jest_tetromino = false;


			tab.plansza[wspol_y + 1][wspol_x].bloczek_rotacji = true;
			tab.plansza[wspol_y + 2][wspol_x].jest_tetromino = true;
			tab.plansza[wspol_y + 1][wspol_x - 1].jest_tetromino = true;
			tab.plansza[wspol_y][wspol_x - 1].jest_tetromino = true;
			wspol_y++;


		}
		else if (pozycja_4(wspol_x, wspol_y, tab))
		{

			tab.plansza[wspol_y][wspol_x].bloczek_rotacji = false;
			tab.plansza[wspol_y][wspol_x - 1].jest_tetromino = false;
			tab.plansza[wspol_y - 1][wspol_x].jest_tetromino = false;
			tab.plansza[wspol_y - 1][wspol_x + 1].jest_tetromino = false;

			tab.plansza[wspol_y + 1][wspol_x].bloczek_rotacji = true;
			tab.plansza[wspol_y + 1][wspol_x - 1].jest_tetromino = true;
			tab.plansza[wspol_y][wspol_x].jest_tetromino = true;
			tab.plansza[wspol_y][wspol_x + 1].jest_tetromino = true;
			wspol_y++;

		}
	}
}

void NmirroredShape::usmiercanie_tetromino(int wspol_x, int wspol_y, Tplansza& tab)
{
	tab.plansza[wspol_y][wspol_x].bloczek_rotacji = false;
	tab.plansza[wspol_y][wspol_x].jest_tetromino = true;
	return;
}
