#pragma once
#include <iostream>
#include <string>
#include <conio.h>
#include <Windows.h>
#include <ctime>
#include "Tplansza.h"
#include "Shape.h"
#include "Oshape.h"
#include "Ishape.h"
#include "Nshape.h"
#include "NmirroredShape.h"
#include "Lshape.h"
#include "LmirroeredShape.h"
#include "Tshape.h"

#define TETROMINOS_START_POSITION_X 8
#define TETROMINOS_START_POSITION_Y 0

class PetlaGry
{
public:
	PetlaGry();
	Shape* natepne_Tetromino;
	Shape* Tetromino;
	Tplansza Plansza;
	int nastepny_klocek;
private:
	void GRA();
	bool koniec_gry();
	void nowy_Shape(int random);
	void nastepny_shape(int random);
	void update_gry();
	void Sterowanie_w();
	void Sterowanie_a();
	void Sterowanie_d();
	void nowy_Tshape();
	void nowy_Oshape();
	void nowy_Ishape();
	void nowy_Nshape();
	void nowy_Lshape();
	void nowy_NmirroredShape();
	void nowy_LmirroredShape();
	int losowanie_liczby();
};

