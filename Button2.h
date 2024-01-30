#pragma once
#include "Button.h"

class Button2 : public Butt {
	Texture textButt;
public:
	Button2() {
		textButt.loadFromFile("Gree.jpg");
		butt.setTexture(&textButt);
	}
	void printButton2(RenderWindow& win){
		printButt(win);
	}
};