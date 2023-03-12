#include <iostream>
#include <string>
#include "Tplansza.h"


Tplansza::Tplansza()
{
    punkty = 0;// punty
    set_wysokosc(WYSOKOSC_PLANSZY);// ustawia wysokosc
    set_szerokosc(SZEROKOSC_PLANSZY);// ustawia szerokosc
    zewnetrzna_warstwa();// tworze zewnetrzna warstwe
    
}

void Tplansza::rysuj()
{
    std::string builder;// string ktory tworzy plansze

    for (int y = 0; y < get_wysokosc(); y++)
    {
        for (int x = 0; x < get_szerokosc(); x++)
        {
            if (plansza[y][x].jest_tetromino)
            {
                builder += "A";
            }
            if (plansza[y][x].bloczek_rotacji)
            {
                builder += "O";
            }

            if (plansza[y][x].zewnetrzna_warstwa)
            {
                builder += "X";
            }
            
            if (!(plansza[y][x].jest_tetromino || plansza[y][x].zewnetrzna_warstwa|| plansza[y][x].bloczek_rotacji))
            {
                builder += " ";
            }
        }
        builder += "\n";
    }
    std::cout << builder;
}

int Tplansza::get_wysokosc()// pobiera wyskosc
{
    return wysokosc;
}

int Tplansza::get_szerokosc()// pobiera szeroskosc
{
    return szerokosc;
}

int Tplansza::set_wysokosc(int wys)// ustwia wlasciowa wysokosc
{
    wysokosc = wys;
    return wysokosc;
}

int Tplansza::set_szerokosc(int szer)// ustawia wlasciwa szrokosc
{
    szerokosc = szer;
    return szerokosc;
}

void Tplansza::zewnetrzna_warstwa()// ustawia zewnetrzna warstwe
{
    set_false();
    set_wspolrzedne();
    for (int wysokosc = 0; wysokosc < get_wysokosc(); wysokosc++)
        for (int szerokosc = 0; szerokosc < get_szerokosc(); szerokosc++)
        {
            if (szerokosc == 0)
            {
                plansza[wysokosc][szerokosc].zewnetrzna_warstwa = true;
                plansza[wysokosc][szerokosc].jest_tetromino = false;
            }

            if (szerokosc == get_szerokosc() - 1)
            {
                plansza[wysokosc][szerokosc].zewnetrzna_warstwa = true;
                plansza[wysokosc][szerokosc].jest_tetromino = false;
            }

            if (wysokosc == get_wysokosc() - 1)
            {
                plansza[wysokosc][szerokosc].zewnetrzna_warstwa = true;
                plansza[wysokosc][szerokosc].jest_tetromino = false;
            }
        }
}

int Tplansza::zapelniona_linia()
{
    int licznik = 0;
    for (int wysokosc = 0; wysokosc < get_wysokosc() - 1; wysokosc++)
    {
        licznik = 0;
        for (int szerokosc = 1; szerokosc < get_szerokosc() - 1; szerokosc++)
        {
            if (plansza[wysokosc][szerokosc].jest_tetromino)
                licznik++;
            if (licznik == (get_szerokosc() - 2))
            {
                
                for (int szerokosc1 = 1; szerokosc1 < get_szerokosc() - 1; szerokosc1++)
                {
                    plansza[wysokosc][szerokosc1].jest_tetromino = false;
                   
                }
                linia_w_dol(wysokosc);
                return wysokosc;
            }
            
        }
    }
    return 0;
}

void Tplansza::linia_w_dol(int wspol_y)
{
    for (int i = wspol_y; i >= 5; i--)
        for (int y = 1; y < get_szerokosc() - 1; y++)
        {
            
            plansza[i + 1][y].jest_tetromino = plansza[i][y].jest_tetromino;
        }


}

void Tplansza::set_false()// ustawia jest_tetromino i zewnetrzna_warstwa na falsz na falsz 
{
    for (int wysokosc = 0; wysokosc < get_wysokosc(); wysokosc++)
        for (int szerokosc = 0; szerokosc < get_szerokosc(); szerokosc++)
        {
            plansza[wysokosc][szerokosc].zewnetrzna_warstwa = false;
            plansza[wysokosc][szerokosc].jest_tetromino = false;
            plansza[wysokosc][szerokosc].bloczek_rotacji = false;
        }
}

void Tplansza::set_wspolrzedne()// ustawiai wspolrzedne x i y
{
    for (int wysokosc = 0; wysokosc < get_wysokosc(); wysokosc++)
        for (int szerokosc = 0; szerokosc < get_szerokosc(); szerokosc++)
        {
            plansza[wysokosc][szerokosc].wspol_y = wysokosc;
            plansza[wysokosc][szerokosc].wspol_x = szerokosc;
        }
}

int Tplansza::pobierz_X()
{
    for (int wysokosc = 0; wysokosc < get_wysokosc(); wysokosc++)
        for (int szerokosc = 0; szerokosc < get_szerokosc(); szerokosc++)
            if (plansza[wysokosc][szerokosc].bloczek_rotacji == true)
                return szerokosc;
}

int Tplansza::pobierz_Y()
{
    for (int wysokosc = 0; wysokosc < get_wysokosc(); wysokosc++)
        for (int szerokosc = 0; szerokosc < get_szerokosc(); szerokosc++)
            if (plansza[wysokosc][szerokosc].bloczek_rotacji == true)
                return wysokosc;
}

int Tplansza::get_pkty() // pobiera punkty
{
    return punkty;
}

int Tplansza::pp_pkty() // zwraca podwyzszone punkty
{
    punkty += 100;
    return punkty;
}