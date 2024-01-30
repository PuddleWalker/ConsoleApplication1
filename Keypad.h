#pragma once
#include "Button2.h"
class KeyPad {
	Button2 **button;
	int row;
	int column;
public:
	KeyPad(int row, int column, int width, int hieght) :row{ row }, column{column} {
		button = new Button2*[row];
		for (size_t i = 0; i < row; i++)
		{
			button[i] = new Button2[column];
			for (size_t j = 0; j < column; j++)
			{
				button[i][j].resize(width, hieght, row, column, i, j, 400);
			}
		}
		nump();

	}

	void print(RenderWindow& win) {
		for (size_t i = 0; i < row; i++)
		{
			for (size_t j = 0; j < column; j++) {
				button[i][j].printButton2(win);
			}
		}
	}
	void mousePresKeyPad(RenderWindow& win, Event& event, Strok& strok) {
		for (size_t i = 0; i < row; i++)
		{
			for (size_t j = 0; j < column; j++) {
				button[i][j].mousePresBut(win, event, strok);
			}
		}
	}

	void nump() {
		int k = 1;
		for (size_t i = 0; i < 3; i++)
		{
			for(size_t j = 0; j < 3; j++) {
				button[i + 1][2 - j].rename(to_string(10 - k));
				k++;
			}
		}
		button[4][0].rename("00");
		button[4][1].rename("0");//вот так объявляем отдельные кнопки...
		button[3][3].rename("+");
		button[2][3].rename("-");
		button[4][3].rename("=");
		button[0][2].rename("C");
		button[1][3].rename("*");
		button[0][3].rename("/");
		button[0][0].rename("%");
		button[0][1].rename("^");
		button[4][2].rename(".");

		//переходим в Strok
	}

	~KeyPad(){
		for (size_t i = 0; i < row; i++)
		{
			delete[] button[i];
		}
		delete[] button;
	}
};