#pragma once
#include "Tplansza.h"


class Shape
{
public:
	virtual void rotacja_klocka(int wspol_x, int wspol_y, Tplansza& tab)=0;
	virtual int ruch_prawo(int wspol_x, int wspol_y, Tplansza& tab)=0;
	virtual int ruch_lewo(int wspol_x, int wspol_y, Tplansza& tab)=0;
	virtual int ruch_dol(int wspol_x, int wspol_y, Tplansza& tab)=0;
	virtual bool czy_usmiercic_tetromino(int wspol_x, int wspol_y, Tplansza& tab)=0;
	virtual void szybki_ruch_dol(int wspol_x, int wspol_y, Tplansza& tab) = 0;
	virtual void usmiercanie_tetromino(int wspol_x, int wspol_y, Tplansza& tab) = 0;
private:
	virtual void rotacja_1(int wspol_x, int wspol_y, Tplansza& tab)=0;
	virtual void rotacja_2(int wspol_x, int wspol_y, Tplansza& tab)=0;
	virtual void rotacja_3(int wspol_x, int wspol_y, Tplansza& tab)=0;
	virtual void rotacja_4(int wspol_x, int wspol_y, Tplansza& tab)=0;
	virtual bool pozycja_1(int wspol_x, int wspol_y, Tplansza& tab)=0;
	virtual bool pozycja_2(int wspol_x, int wspol_y, Tplansza& tab)=0;
	virtual bool pozycja_3(int wspol_x, int wspol_y, Tplansza& tab)=0;
	virtual bool pozycja_4(int wspol_x, int wspol_y, Tplansza& tab)=0;
	virtual bool mozliwosc_rotacji(int wspol_x, int wspol_y, Tplansza& tab)=0;
	virtual bool mozliwosc_ruchu_prawo(int wspol_x, int wspol_y, Tplansza& tab)=0;
	virtual bool mozliwosc_ruchu_lewo(int wspol_x, int wspol_y, Tplansza& tab)=0;
	virtual bool mozliwosc_ruchu_dol(int wspol_x, int wspol_y, Tplansza& tab)=0;
	
};

