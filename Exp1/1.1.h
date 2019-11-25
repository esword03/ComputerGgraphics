#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>
#include<string>
#include<Windows.h>
#include<GL\glut.h>
using namespace std;
static int xf;
static int yf;
class point {
public:
	int x, y, x1, y1;
	string color;
	void line();
	point(int x, int y, int x1, int y1, string color);
	void upzeroUpone(int x, int y, int x1, int y1, string color);
	void judgecolor(string);
};
point::point(int x, int y, int x1, int y1, string color) {
	this-> x = x;
	this-> y = y;
	this-> x1 = x1;
	this-> y1 = y1;
	this-> color = color;
}
void point::line() {
	int a, b, x, y, x1, y1;
	a = y1 - y;
	b = x1 - x;
	if (a / b > 0) {
		if (a / b < 1) {
			upzeroUpone(x, y,x1, y1, color);
		}
	}
}
void point::upzeroUpone(int x1,int y1,int x2,int y2,string color) {
	int x, y, d0, d1, d2, a, b;
	y = y2;
	a = y2 - y1;
	b = x2 - x1;
	d0 = 2 * a + b;
	d1 = 2 * a;
	d2 = 2 * (a + b);
	glClear(GL_COLOR_BUFFER_BIT);
	judgecolor(color);
	for (x = x1; x < x2; x++) {
		glBegin(GL_POINTS);
		glVertex2i(x, y);
		glEnd();
		glFlush();
	}
}

void point:: judgecolor(string a) {
	if (a == "red") {
		glColor3ub(255, 0, 0);
	}
	else if (a == "orange") {
		glColor3ub(255, 97, 0);
	}
	else if (a == "yellow	") {
		glColor3ub(255, 255, 0);
	}
	else if (a == "green") {
		glColor3ub(0, 255, 0);
	}
	else if (a == "qing") {
		glColor3ub(0, 255, 255);
	}
	else if (a == "blue") {
		glColor3ub(0, 0, 255);
	}
	else if (a == "perple") {
		glColor3ub(160, 32, 240);
	}
	else if (a == "black") {
		glColor3ub(0, 0, 0);
	}
}