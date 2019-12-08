#include <iostream>
#include <gl/GLUT.h>
#include <map>
#include <vector>
#include<cmath>
#include <list>
#include <algorithm>
using namespace std;

struct Point {
	float x, y;
	Point(float _x, float _y) :x(_x), y(_y) {}
	Point() {}
	void operator =(Point& r) {
		x = r.x; y = r.y;
	}
};

Point vertex[2];
int down_cnt = 1;               //记录点击的次数
int choice_id = -1;
int window_size = 800;
float XL = 200, XR = 600, YB = 200, YT = 600;

void draw_rectangle();
void grey_line(float x1, float y1, float x2, float y2);
void green_line(float x1, float y1, float x2, float y2);
void draw_rp(float x, float y);
void OnMouse(int button, int state, int x, int y);
void InitEnvironment();
bool ClipT(float p, float q, float* u1, float* u2);
void LB_LineClip(float x1, float y1, float x2, float y2);
void myMotion(int x, int y);

int main(int argc, char* argv[]) {
	glutInit(&argc, argv);   //初始化GLUT
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowPosition(300, 100);
	glutInitWindowSize(window_size, window_size);
	glutCreateWindow("liang_Barskey");
	InitEnvironment();   //初始化
	glutMotionFunc(&myMotion);   //回调函数
	glutMouseFunc(&OnMouse);  //注册鼠标事件
	glutDisplayFunc(draw_rectangle);
	glutMainLoop();    //持续显示，当窗口改变会重新绘制图形

	return 0;
}

void InitEnvironment() {
	glClearColor(0.0, 0.0, 0.0, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPointSize(6);
	glLineWidth(3);
	gluOrtho2D(0, window_size, 0, window_size);

	draw_rectangle();
}

void myMotion(int x, int y) {
	if (choice_id != -1) {
		vertex[choice_id].x = float(x);
		vertex[choice_id].y = float(y);
		LB_LineClip(vertex[0].x, vertex[0].y, vertex[1].x, vertex[1].y);
	}
}

void draw_rectangle() {
	glBegin(GL_LINES);
	glColor3f(1, 1, 0);
	glVertex2f(XL, window_size - YB);
	glVertex2f(XR, window_size - YB);
	glVertex2f(XL, window_size - YT);
	glVertex2f(XR, window_size - YT);
	glVertex2f(XL, window_size - YB);
	glVertex2f(XL, window_size - YT);
	glVertex2f(XR, window_size - YB);
	glVertex2f(XR, window_size - YT);
	glEnd();
	glFlush();
}

void draw_rp(float x, float y) {
	glBegin(GL_POINTS);
	glColor3f(1, 0, 0);
	glVertex2f(x, window_size - y);
	glEnd();
	glFlush();
}
void OnMouse(int button, int state, int x, int y)
//OnMouse坐标系x从左向右，y从上到下
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		if (down_cnt == 1) {
			vertex[0].x = float(x); vertex[0].y = float(y);
			draw_rp(x, y);
		}
		else if (down_cnt == 2) {
			vertex[1].x = float(x); vertex[1].y = float(y);
			draw_rp(x, y);
			LB_LineClip(vertex[0].x, vertex[0].y, vertex[1].x, vertex[1].y);
		}
		else {
			choice_id = -1;
			for (int i = 0; i < 2; i++) {
				if (abs(x - vertex[i].x) < 8 && abs(y - vertex[i].y) < 8) {//选中一个点
					choice_id = i; break;
				}
			}
		}
		down_cnt++;
	}
	else if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{   //点击右键，选择顶点拖动

	}
}

void grey_line(float x1, float y1, float x2, float y2) {
	glBegin(GL_LINES);
	glColor3f(0.5, 0.5, 0.5);
	glVertex2f(x1, window_size - y1);
	glVertex2f(x2, window_size - y2);
	glEnd();
	glFlush();
}

void green_line(float x1, float y1, float x2, float y2) {
	glBegin(GL_LINES);
	glColor3f(0, 1, 0);
	glVertex2f(x1, window_size - y1);
	glVertex2f(x2, window_size - y2);
	glEnd();
	glFlush();
}

bool ClipT(float p, float q, float* u1, float* u2) {
	float r;
	if (p < 0) {
		r = q / p;
		if (r > * u2)return false;
		if (r > * u1)* u1 = r;
	}
	else if (p > 0) {
		r = q / p;
		if (r < *u1)return false;
		if (r < *u2)* u2 = r;
	}
	else return (q >= 0);
	return true;
}

void LB_LineClip(float x1, float y1, float x2, float y2) {
	float dx, dy, u1, u2;
	u1 = 0, u2 = 1;
	dx = x2 - x1;
	dy = y2 - y1;
	glClear(GL_COLOR_BUFFER_BIT);
	draw_rectangle();
	draw_rp(x1, y1);
	draw_rp(x2, y2);
	grey_line(x1, y1, x2, y2);
	if (ClipT(-dx, x1 - XL, &u1, &u2))
		if (ClipT(dx, XR - x1, &u1, &u2))
			if (ClipT(-dy, y1 - YB, &u1, &u2))
				if (ClipT(dy, YT - y1, &u1, &u2)) {
					green_line(x1 + u1 * dx, y1 + u1 * dy, x1 + u2 * dx, y1 + u2 * dy);
				}
}
