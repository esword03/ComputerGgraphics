#pragma once
#include"1.1.h"

void autoline(void) {
	glBegin(GL_LINES);
	for (auto p : li) {
		fx = p.fx; fy = p.fy; fx1 = p.fx1; fy1 = p.fy1;
		color = p.color;
		judgecolor(color);
		glVertex2i(fx, fy);
		glVertex2i(fx1, fy1);
	}
	glEnd();
	glFlush();
}