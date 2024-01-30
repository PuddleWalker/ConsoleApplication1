#pragma once
#include <cmath>
#include "iostream"
#include <string>
using namespace std;
class Strok {
	string str;
	string a;
	string b;
	string z;
	bool chitst = false;
public:
	Strok() {
		str = "";
	}

	void add(string str) {
		if (chitst) { 
			this->str = ""; 
			chitst = false;
		}
		if (str == "C") {//Обнуление ввода на С
			a = "";
			b = "";
			z = "";
			this->str = "";
			return;
		}
		
		if (str != "="//здесь //добавить по аналогии
			and str != "+"// Проверка на ввод первого числа
			and str != "-"
			and str != "*"
			and str != "/"
			and str != "^"
			and str != "%"
			and str != "."
			and z.empty() ){
			a += str;
			this->str += str;
		}
		else if (str == "-" and a.empty()) {
				a += str;
				this->str += str;
		}
		else if (str == "."
			and not z.empty()) {
			if (b.find(".") == string::npos) {
				b += str;
				this->str += str;
			}
		}

		else if (str == "."
			and not a.empty()) {
			if (a != "-"
			and a.find(".") == string::npos){
				a += str;
				this->str += str;
			}
		}

		else if ((str == "+"//добавить по аналогии
			or str == "-"//Проверка на ввод мат операции
			or str == "*"
			or str == "/"
			or str == "^"
			or str == "%")
			and b.empty()
			and !a.empty()
			and a != "-") {
			if (z.empty()) {
				z = str;
				this->str += str;
			}
			else {
				z = str;
				this->str[this->str.length() - 1] = str[0];
			}
			

		}
		else if (str != "="//добавить по аналогии
			and str != "+"// Проверка на ввод второго числа
			and str != "-"
			and str != "*"
			and str != "/"
			and str != "^"
			and str != "%"
			and str != "."
			and !z.empty()) {
			b += str;
			this->str += str;

		}
		else if (str == "=") {
			if (b.empty()) {
				this->str = a;//Обнулени строки и значений при нажатии = без второга числа
				a = "";
				b = "";
				z = "";
				chitst = true;
			}
			else {
				int c = stoi(a); int d = stoi(b);
				float e = stof(a); float f = stof(b);
				switch (z[0])//добавить по аналогии->
				{
				case '+'://Проведение операций
					if (c + d == e + f) {
						this->str = to_string(c + d);
					}
					else this->str = to_string(e + f);
					break;
				case '-':
					if (c - d == e - f) {
						this->str = to_string(c - d);
					}
					else this->str = to_string(e - f);
					break;
				case '*':
					if (c * d == e * f or int(e * f) == e * f) {
						this->str = to_string(int(e * f));
					}
					else this->str = to_string(e * f);
					break;
				case '^':
					if (pow(c, d) == pow(e, f)) {
						this->str = to_string(pow(c, d));
					}
					else this->str = to_string(pow(e, f));
					break;
				case '%':
					if (c * 100 / d == e * 100 / f) {
						this->str = to_string(c * 100 / d);
					}
					else this->str = to_string(e * 100 / f);
					break;
				case '/':
					if (stof(b) == 0) {
						this->str = "ERROR";
						break;
					}
					if (c / d == e / f) {
						this->str = to_string(c / d);
					}
					else this->str = to_string(e / f);
					break;
				default:
					break;
				}
				//Обнуление строки посе операций
				
				a = "";
				b = "";
				z = "";
				chitst = true;
			}
		}

		cout << this->str << endl;
	}
	string getStr() {
		return " " + this->str;
	}
};