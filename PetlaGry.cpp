#include "PetlaGry.h"

PetlaGry::PetlaGry()
{
	nastepny_klocek = 0;
	natepne_Tetromino = nullptr;
	Tetromino = nullptr;
	Plansza.rysuj();
	GRA();
}

void PetlaGry::nowy_Tshape()
{
	Tetromino = new Tshape(TETROMINOS_START_POSITION_X, TETROMINOS_START_POSITION_Y, Plansza);
	return;
}

void PetlaGry::nowy_Oshape()
{
	Tetromino = new Oshape(TETROMINOS_START_POSITION_X, TETROMINOS_START_POSITION_Y, Plansza);
	return;
}

void PetlaGry::nowy_Ishape()
{
	Tetromino = new Ishape(TETROMINOS_START_POSITION_X, TETROMINOS_START_POSITION_Y, Plansza);
	return;
}

void PetlaGry::nowy_Nshape()
{
	Tetromino = new Nshape(TETROMINOS_START_POSITION_X, TETROMINOS_START_POSITION_Y, Plansza);
	return;
}

void PetlaGry::nowy_Lshape()
{
	Tetromino = new Lshape(TETROMINOS_START_POSITION_X, TETROMINOS_START_POSITION_Y, Plansza);
	return;
}

void PetlaGry::nowy_NmirroredShape()
{
	Tetromino = new NmirroredShape(TETROMINOS_START_POSITION_X, TETROMINOS_START_POSITION_Y, Plansza);
	return;
}

void PetlaGry::nowy_LmirroredShape()
{
	Tetromino = new LmirroeredShape(TETROMINOS_START_POSITION_X, TETROMINOS_START_POSITION_Y, Plansza);
	return;
}

int PetlaGry::losowanie_liczby()
{
	srand(time(NULL));
	nastepny_klocek = rand() % 7;
	switch (nastepny_klocek)
	{
	case 0:
		return nastepny_klocek;
		break;
	case 1:
		return nastepny_klocek;
		break;
	case 2:
		return nastepny_klocek;
		break;
	case 3:
		return nastepny_klocek;
		break;
	case 4:
		return nastepny_klocek;
		break;
	case 5:
		return nastepny_klocek;
		break;
	case 6:
		return nastepny_klocek;
		break;







	}
}

void PetlaGry::update_gry()
{
	system("cls");
	Plansza.rysuj();
	std::cout << "\t\t\tWynik :" << Plansza.punkty;
	std::cout << "\n\t\t\tSterowanie: S-szybki ruch dol, W-Rotacja\n\t\t\tA-ruch lewo, A-ruch prawo";
	nastepny_shape(nastepny_klocek);
}

void PetlaGry::GRA()
{
	char klawisz;
	losowanie_liczby();
	nowy_Shape(nastepny_klocek);
	losowanie_liczby();

	while (koniec_gry())
	{
		update_gry();
		if (Tetromino->czy_usmiercic_tetromino(Plansza.pobierz_X(), Plansza.pobierz_Y(), Plansza))
		{
			nowy_Shape(nastepny_klocek);
			losowanie_liczby();
			update_gry();
		}
		if (_kbhit())
		{
			klawisz = _getch();
			if (klawisz == 'a' || klawisz == 'A')
			{
				Tetromino->ruch_lewo(Plansza.pobierz_X(), Plansza.pobierz_Y(), Plansza);
				update_gry();
			}
			else if (klawisz == 'd' || klawisz == 'D')
			{
				Tetromino->ruch_prawo(Plansza.pobierz_X(), Plansza.pobierz_Y(), Plansza);
				update_gry();
			}
			else if (klawisz == 's' || klawisz == 'S')
			{
				Tetromino->szybki_ruch_dol(Plansza.pobierz_X(), Plansza.pobierz_Y(), Plansza);
				update_gry();
			}
			else if (klawisz == 'w' || klawisz == 'W')
			{
				Tetromino->rotacja_klocka(Plansza.pobierz_X(), Plansza.pobierz_Y(), Plansza);
				update_gry();
			}
			else continue;
		}
		Tetromino->ruch_dol(Plansza.pobierz_X(), Plansza.pobierz_Y(), Plansza);
		if (Plansza.zapelniona_linia())
		{
			Plansza.pp_pkty();
		}
		Sleep(750);

	}
	std::cout << "\n\t\t\tkoniec gry graczu ";
	
	
}

bool PetlaGry::koniec_gry()
{
	for (int i = 1; i < Plansza.get_szerokosc() - 1; i++)
	{
		if (((Plansza.plansza[1][i].bloczek_rotacji)
			||(Plansza.plansza[0][i].bloczek_rotacji)
			|| (Plansza.plansza[2][i].bloczek_rotacji))
			&& ((Tetromino->czy_usmiercic_tetromino(Plansza.pobierz_X(), Plansza.pobierz_Y(), Plansza))))
			return false;
		
	}
	return true;
	
}

void PetlaGry::Sterowanie_w()
{
		char klawisz;
		klawisz = _getch();
		if (klawisz == 'w' || klawisz == 'W')
		{
			Tetromino->rotacja_klocka(Plansza.pobierz_X(), Plansza.pobierz_Y(), Plansza);
			update_gry();
		}
		else return;

	
}

void PetlaGry::Sterowanie_a()
{
	
		char klawisz;
		klawisz = _getch();
		if (klawisz == 'a' || klawisz == 'A')
		{
			Tetromino->ruch_lewo(Plansza.pobierz_X(), Plansza.pobierz_Y(), Plansza);
			update_gry();
		}
		else return;

}

void PetlaGry::Sterowanie_d()
{
		char klawisz;
		klawisz = _getch();
		if (klawisz == 'd' || klawisz == 'D')
		{
			Tetromino->ruch_prawo(Plansza.pobierz_X(), Plansza.pobierz_Y(), Plansza);
			update_gry();
		}
		else return;

}

void PetlaGry::nowy_Shape(int random)
{
	

	switch (random)
	{
	case 0:
		nowy_Ishape();
		break;
	case 1:
		nowy_LmirroredShape();
		break;
	case 2:
		nowy_Lshape();
		break;
	case 3:
		nowy_NmirroredShape();
		break;
	case 4:
		nowy_Nshape();
		break;
	case 5:
		nowy_Oshape();
		break;
	case 6:
		nowy_Tshape();
		break;
	}
	return;
}

void PetlaGry::nastepny_shape(int random)
{
	switch (random)
	{
	case 0:
		std::cout << "\nNstepny Shape:\nX\nX\nX\nX";
		break;
	case 1:
		std::cout << "\nNstepny Shape:\n X\n X\nXX";
		break;
	case 2:
		std::cout << "\nNstepny Shape:\nX\nX\nXX";
		break;
	case 3:
		std::cout << "\nNstepny Shape:\n X\nXX\nX";
		break;
	case 4:
		std::cout << "\nNstepny Shape:\nX\nXX\n X";
		break;
	case 5:
		std::cout << "\nNstepny Shape:\nXX\nXX";
		break;
	case 6:
		std::cout << "\nNstepny Shape:\nX\nXX\nX";
		break;
	}
	return;
}

