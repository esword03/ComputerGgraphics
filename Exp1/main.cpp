#include"1.1.h"
#include"line.h"
#include"1.2.h"
int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(400, 200);
	glutInitWindowSize(400, 400);
	glutCreateWindow("exp1");
	glClearColor(1.0, 1.0, 1.0,0.0);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-200, 200, -200, 200);

	//gluOrtho2D(0.0, 800.0, 0.0, 600.0);
	glViewport(0.0, 0.0, 400.0, 400.0);
	glClear(GL_COLOR_BUFFER_BIT);
	//glPointSize(4.0);	//试图改变一个点的像素大小
	line *a = new line(1, 1, 10, 5, "red");
	line *a2 = new line(1, 1, 5, 10, "orange");
	line *a3 = new line(-1, 1, -10, 5, "yellow");
	line *a4 = new line(-1, 1, -5, 10, "green");
	line *a5 = new line(-1, -1, -10, -5, "qing");
	line *a6 = new line(-1, -1, -5, -10, "blue");
	line *a7 = new line(1, -1, 10, -5, "purple");
	line *a8 = new line(1, -1, 5, -10, "black");
	line *a9 = new line(0, 0, 10, 0, "black");
	line *a0 = new line(0, 0, 0, 10, "black");
	li.push_back(*a);
	li.push_back(*a2);
	li.push_back(*a3);
	li.push_back(*a4);
	li.push_back(*a5);
	li.push_back(*a6);
	li.push_back(*a7);
	li.push_back(*a8);
	li.push_back(*a9);
	li.push_back(*a0);
	glutDisplayFunc(autoline);

	glutMainLoop();
}