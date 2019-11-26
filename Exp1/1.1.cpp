#include"1.1.h"
#include"line.h"
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
	line *a2 = new line(-2, -1,11, 5, "black");
	li.push_back(*a);
	li.push_back(*a2);
	point();
	glutDisplayFunc(upzeroUpone);

	glutMainLoop();
}