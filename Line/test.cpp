
#include <stdio.h>

#include <stdlib.h>

#include <math.h>

#include <iostream>

#include <string>  



#include <windows.h>

#include <GL\glut.h>



using namespace std;



void piontSegment(void)

{

	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(1.0, 0.0, 0.0);

	//通过点绘制

	glBegin(GL_POINTS);

	glVertex2i(25, 25);

	glVertex2i(50, 50);

	glVertex2i(100, 100);

	glEnd();
	glBegin(GL_LINES);
	glVertex2i(30, 30);
	glVertex2i(200, 200);
	glVertex2i(30, 30);
	glVertex2i(200, 30);
	glEnd();



	//通过矩阵绘制

	/*int p1[]{25, 25};

	int p2[]{50, 50};

	int p3[]{100, 100};



	glBegin(GL_POINTS);

	glVertex2iv(p1);

	glVertex2iv(p2);

	glVertex2iv(p3);

	glEnd();*/



	glFlush();

}



int main(int argc, char **argv)

{

	glutInit(&argc, argv);

	//设置窗口的缓存和颜色模型

	//下面指定的是：窗口使用单个缓存并且使用RGB颜色模型来设定颜色值。

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	//设置窗口左上角的位置

	glutInitWindowPosition(400, 200);

	//设置窗口的宽高

	glutInitWindowSize(800, 600);

	glutCreateWindow("Test OpenGL Program");



	//设置显示窗口的背景为白色。参数顺序为：红、绿、蓝、透明度。

	glClearColor(1.0, 1.0, 1.0, 0.0);

	//设置投影类型：正投影

	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();

	//观察参数：x坐标值从0到200，y是从0到150

	gluOrtho2D(0.0, 800.0, 0.0, 600.0);



	glutDisplayFunc(piontSegment);

	glutMainLoop();



	system("pause");

	return 0;

}
