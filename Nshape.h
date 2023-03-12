#pragma once
#include "Shape.h"
#include "Tplansza.h"
class Nshape : public Shape
{
public:
	Nshape(int wspol_x, int wspol_y, Tplansza& tab);
	void rotacja_klocka(int wspol_x, int wspol_y, Tplansza& tab);
	int ruch_prawo(int wspol_x, int wspol_y, Tplansza& tab);
	int ruch_lewo(int wspol_x, int wspol_y, Tplansza& tab);
	int ruch_dol(int wspol_x, int wspol_y, Tplansza& tab);
	bool czy_usmiercic_tetromino(int wspol_x, int wspol_y, Tplansza& tab);
	void szybki_ruch_dol(int wspol_x, int wspol_y, Tplansza& tab);
	void usmiercanie_tetromino(int wspol_x, int wspol_y, Tplansza& tab);
private:
	void rotacja_1(int wspol_x, int wspol_y, Tplansza& tab);
	void rotacja_2(int wspol_x, int wspol_y, Tplansza& tab);
	void rotacja_3(int wspol_x, int wspol_y, Tplansza& tab);
	void rotacja_4(int wspol_x, int wspol_y, Tplansza& tab);
	bool pozycja_1(int wspol_x, int wspol_y, Tplansza& tab);
	bool pozycja_2(int wspol_x, int wspol_y, Tplansza& tab);
	bool pozycja_3(int wspol_x, int wspol_y, Tplansza& tab);
	bool pozycja_4(int wspol_x, int wspol_y, Tplansza& tab);
	bool mozliwosc_rotacji(int wspol_x, int wspol_y, Tplansza& tab);
	bool mozliwosc_ruchu_prawo(int wspol_x, int wspol_y, Tplansza& tab);
	bool mozliwosc_ruchu_lewo(int wspol_x, int wspol_y, Tplansza& tab);
	bool mozliwosc_ruchu_dol(int wspol_x, int wspol_y, Tplansza& tab);
	//void usmiercanie_tetromino(int wspol_x, int wspol_y, Tplansza& tab);



};

