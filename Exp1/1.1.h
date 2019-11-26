#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>
#include<string>
#include<Windows.h>
#include<GL\glut.h>
#include<vector>
#include"line.h"
using namespace std;

vector<line> li;

static int a, b, fx, fy, fx1, fy1;
string color;


void  judgecolor(string);
void upzeroUpone(void);
void upzeroDownone();
void downzeroUpone();
void downzeroDownone();
void point(void);



void point(void) {
	glBegin(GL_POINTS);
	for (auto p : li) {
		fx = p.fx; fy = p.fy; fx1 = p.fx1; fy1 = p.fy1;
		color=p.color;
		
		judgecolor(color);
		a = fy1 - fy;
		b = fx - fx1;
		double c = (double)a / b;
		if (c < 0) {
			if (c > -1) {
				upzeroUpone();
			}
			else if (c < -1) {
				upzeroDownone();
			}
		}
	}
	glEnd();
	glFlush();

}
void upzeroUpone(void) {

	int x, y, d0, d1, d2;
	y = fy;
	//a = y2 - y1;
	//b = x2 - x1;
	d0 = 2 * a + b;
	d1 = 2 * a;
	d2 = 2 * (a + b);
	


	for (x = fx; x <= fx1; x++) {

		
		glVertex2i(x, y);

		if (d0 < 0) {
			y++;
			d0 += d2;
		}
		else {
			d0 += d1;
		}
	}

}
void upzeroDownone() {
	int x, y, d0, d1, d2;
	x = fx;
	//a = y2 - y1;
	//b = x2 - x1;
	d0 = a + 2 * b;
	d1 = 2 * b;
	d2 = 2 * (a + b);

	for (y = fy; y <= fy1; y++) {

		glVertex2i(x, y);
		if (d0 < 0) {
			x++;
			d0 += d2;
		}
		else {
			d0 += d1;
		}
	}
}

void  judgecolor(string a) {
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