#pragma once

#include "Strok.h";
#include <SFML/Graphics.hpp>
using namespace sf;
class Disp {
	RectangleShape rekt;
	RectangleShape rect;
	Strok str;
	Text txt;
	Font font;
	Texture TextRect;
	Texture TextRekt;
public:
	Disp() {
		font.loadFromFile("BankGothic Md BT Medium.otf");
		txt.setPosition(0, 75);
		txt.setFont(font);
		txt.setCharacterSize(60);
		txt.setString(str.getStr());
		rekt.setPosition(0, 0);
		rekt.setSize(Vector2f(600, 250));
		rekt.setOutlineColor(Color::White);
		rect.setPosition(0, 200);
		rect.setSize(Vector2f(600, 600));
		rect.setOutlineColor(Color::White);
		TextRect.loadFromFile("Grey.jpg");
		TextRekt.loadFromFile("Gree.jpg");
		rect.setTexture(&TextRect);
		rekt.setTexture(&TextRekt);
	}
	Strok& getStrok() {
		return str;
	}
	void printDisp(RenderWindow& win) {
		txt.setString(str.getStr());
		win.draw(rect);
		win.draw(rekt);
		win.draw(txt);
	}
};