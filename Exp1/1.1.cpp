#include"1.1.h"
int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(400, 200);
	glutInitWindowSize(800, 800);
	glutCreateWindow("exp1");
	glClearColor(1.0, 1.0, 1.0, 0.0);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-15, 15, -15, 15);

	//gluOrtho2D(0.0, 800.0, 0.0, 600.0);
	glViewport(0.0, 0.0, 800.0, 800.0);

	glPointSize(4.0);	//试图改变一个点的像素大小


	point a(1,10,1,5,"red");
	glutDisplayFunc();


	glutMainLoop();
}