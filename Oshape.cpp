#include "Oshape.h"

Oshape::Oshape(int wspol_x, int wspol_y, Tplansza& tab)
{
    tab.plansza[wspol_y][wspol_x].bloczek_rotacji = true;
    tab.plansza[wspol_y ][wspol_x + 1].jest_tetromino = true;
    tab.plansza[wspol_y + 1][wspol_x].jest_tetromino = true;
    tab.plansza[wspol_y + 1][wspol_x + 1].jest_tetromino = true;
}

void Oshape::rotacja_klocka(int wspol_x, int wspol_y, Tplansza& tab)
{
}

int Oshape::ruch_prawo(int wspol_x, int wspol_y, Tplansza& tab)
{
    if (mozliwosc_ruchu_prawo(wspol_x, wspol_y, tab))
    {
        tab.plansza[wspol_y][wspol_x].bloczek_rotacji = false;
        tab.plansza[wspol_y][wspol_x + 1].jest_tetromino = false;
        tab.plansza[wspol_y + 1][wspol_x].jest_tetromino = false;
        tab.plansza[wspol_y + 1][wspol_x + 1].jest_tetromino = false;

        tab.plansza[wspol_y][wspol_x + 1].bloczek_rotacji = true;
        tab.plansza[wspol_y][wspol_x + 2].jest_tetromino = true;
        tab.plansza[wspol_y + 1][wspol_x + 1].jest_tetromino = true;
        tab.plansza[wspol_y + 1][wspol_x + +2].jest_tetromino = true;

        return wspol_x + 1;
    }
    else return wspol_x;
}

int Oshape::ruch_lewo(int wspol_x, int wspol_y, Tplansza& tab)
{

    if (mozliwosc_ruchu_lewo(wspol_x, wspol_y, tab))
    {
        tab.plansza[wspol_y][wspol_x].bloczek_rotacji = false;
        tab.plansza[wspol_y][wspol_x + 1].jest_tetromino = false;
        tab.plansza[wspol_y + 1][wspol_x].jest_tetromino = false;
        tab.plansza[wspol_y + 1][wspol_x + 1].jest_tetromino = false;

        tab.plansza[wspol_y][wspol_x - 1].bloczek_rotacji = true;
        tab.plansza[wspol_y][wspol_x].jest_tetromino = true;
        tab.plansza[wspol_y + 1][wspol_x].jest_tetromino = true;
        tab.plansza[wspol_y + 1][wspol_x - 1].jest_tetromino = true;

        return wspol_x - 1;
    }
    else return wspol_x;

}

int Oshape::ruch_dol(int wspol_x, int wspol_y, Tplansza& tab)
{
    if (mozliwosc_ruchu_dol(wspol_x, wspol_y, tab))
    {
        tab.plansza[wspol_y][wspol_x].bloczek_rotacji = false;
        tab.plansza[wspol_y][wspol_x + 1].jest_tetromino = false;
        tab.plansza[wspol_y + 1][wspol_x].jest_tetromino = false;
        tab.plansza[wspol_y + 1][wspol_x + 1].jest_tetromino = false;

        tab.plansza[wspol_y + 1][wspol_x].bloczek_rotacji = true;
        tab.plansza[wspol_y + 1][wspol_x + 1].jest_tetromino = true;
        tab.plansza[wspol_y + 2][wspol_x].jest_tetromino = true;
        tab.plansza[wspol_y + 2][wspol_x + 1].jest_tetromino = true;

        return wspol_y + 1;
    }
    else return wspol_y;
}

bool Oshape::czy_usmiercic_tetromino(int wspol_x, int wspol_y, Tplansza& tab)
{
    if (!(mozliwosc_ruchu_dol(wspol_x, wspol_y, tab)))
    {
        usmiercanie_tetromino(wspol_x, wspol_y, tab);
        return true;
    }
    else return false;
   
}

void Oshape::usmiercanie_tetromino(int wspol_x, int wspol_y, Tplansza& tab)
{
    tab.plansza[wspol_y][wspol_x].bloczek_rotacji = false;
    tab.plansza[wspol_y][wspol_x].jest_tetromino = true;
    return;
}

void Oshape::rotacja_1(int wspol_x, int wspol_y, Tplansza& tab)
{
}

void Oshape::rotacja_2(int wspol_x, int wspol_y, Tplansza& tab)
{
}

void Oshape::rotacja_3(int wspol_x, int wspol_y, Tplansza& tab)
{
}

void Oshape::rotacja_4(int wspol_x, int wspol_y, Tplansza& tab)
{
}

bool Oshape::pozycja_1(int wspol_x, int wspol_y, Tplansza& tab)
{
    return false;
}

bool Oshape::pozycja_2(int wspol_x, int wspol_y, Tplansza& tab)
{
    return false;
}

bool Oshape::pozycja_3(int wspol_x, int wspol_y, Tplansza& tab)
{
    return false;
}

bool Oshape::pozycja_4(int wspol_x, int wspol_y, Tplansza& tab)
{
    return false;
}

bool Oshape::mozliwosc_rotacji(int wspol_x, int wspol_y, Tplansza& tab)
{
    return false;
}

bool Oshape::mozliwosc_ruchu_prawo(int wspol_x, int wspol_y, Tplansza& tab)
{
    
    if ((tab.plansza[wspol_y][wspol_x + 2].jest_tetromino)
        || (tab.plansza[wspol_y][wspol_x + 2].zewnetrzna_warstwa)
        || (tab.plansza[wspol_y + 1][wspol_x + 2].jest_tetromino)
        || (tab.plansza[wspol_y + 1][wspol_x + 2].zewnetrzna_warstwa))
        return false;
    
        else return true;
}

bool Oshape::mozliwosc_ruchu_lewo(int wspol_x, int wspol_y, Tplansza& tab)
{
    if ((tab.plansza[wspol_y][wspol_x - 1].jest_tetromino)
        || (tab.plansza[wspol_y][wspol_x - 1].zewnetrzna_warstwa)
        || (tab.plansza[wspol_y + 1][wspol_x - 1].jest_tetromino)
        || (tab.plansza[wspol_y + 1][wspol_x - 1].zewnetrzna_warstwa))
        return false;
    else return true;
}

bool Oshape::mozliwosc_ruchu_dol(int wspol_x, int wspol_y, Tplansza& tab)
{
    
   
    if ((tab.plansza[wspol_y + 2][wspol_x].jest_tetromino)
        || (tab.plansza[wspol_y + 2][wspol_x].zewnetrzna_warstwa)
        || (tab.plansza[wspol_y + 2][wspol_x + 1].jest_tetromino)
        || (tab.plansza[wspol_y + 2][wspol_x + 1].zewnetrzna_warstwa))
        return false;
    else return true;

}

void Oshape::szybki_ruch_dol(int wspol_x, int wspol_y, Tplansza& tab)
{
    while (mozliwosc_ruchu_dol(wspol_x, wspol_y, tab))
    {
        tab.plansza[wspol_y][wspol_x].bloczek_rotacji = false;
        tab.plansza[wspol_y][wspol_x + 1].jest_tetromino = false;
        tab.plansza[wspol_y + 1][wspol_x].jest_tetromino = false;
        tab.plansza[wspol_y + 1][wspol_x + 1].jest_tetromino = false;

        tab.plansza[wspol_y + 1][wspol_x].bloczek_rotacji = true;
        tab.plansza[wspol_y + 1][wspol_x + 1].jest_tetromino = true;
        tab.plansza[wspol_y + 2][wspol_x].jest_tetromino = true;
        tab.plansza[wspol_y + 2][wspol_x + 1].jest_tetromino = true;
        wspol_y++;
    }

}
