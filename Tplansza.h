#ifndef TETRIS_TPLANSZA_H
#define TETRIS_TPLANSZA_H
#pragma once
#include <iostream>
#include <string>



#define WYSOKOSC_PLANSZY 22
#define SZEROKOSC_PLANSZY 18

struct board
{
    bool jest_tetromino;
    bool zewnetrzna_warstwa;
    bool bloczek_rotacji;
    int wspol_x;
    int wspol_y;
};

class Tplansza
{
public:
    Tplansza();// konstruktor
    void rysuj();// rysuje tablice
    int get_wysokosc(); //ustawia wysokosc planszy
    int get_szerokosc(); //ustawia szerokosc planszy
    int get_pkty();
    int pp_pkty();
    void zewnetrzna_warstwa();
    int zapelniona_linia();
    void linia_w_dol(int wspol_y);
    board plansza[WYSOKOSC_PLANSZY][SZEROKOSC_PLANSZY];//plansza
    int pobierz_X();
    int pobierz_Y();
    int punkty;
   
private:
    
    int szerokosc;
    int wysokosc;
    int set_wysokosc(int wys);
    int set_szerokosc(int szer);
    void set_false();
    void set_wspolrzedne();
};
#endif //TETRIS_TPLANSZA_H

