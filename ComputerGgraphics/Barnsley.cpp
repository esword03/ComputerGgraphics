///*
//The iterated function system fern.
//
//Source file to be used with
//Cunningham, Computer Graphics: Programming in OpenGL for Visual Communication, Prentice-Hall, 2007
//
//Intended for class use only
//*/
//#define GLUT_DISABLE_ATEXIT_HACK
//
//#include <stdlib.h>
//#include <stdio.h>
//#include <math.h>
//#include <time.h>
//#include <GL/glut.h>
//#define XMIN 0.
//#define XMAX 5.//2.
//#define YMIN -1.0//-1.0
//#define YMAX 1.0//1.0
//#define NPOINTS 100000//100000
//#define GRAIN 32767//32767
//#define WS 800
//
//float myPoints[NPOINTS][2];
//
//void myinit(void)
//{
//	int i;
//
//	glClearColor(1., 1., 1., 1.);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluOrtho2D(XMIN, XMAX, YMIN, YMAX);
//
//	srand(clock());
//	//	generate NPOINTS random points in the domain
//	for (i = 0; i<NPOINTS; i++) {
//		myPoints[i][0] = XMIN + 2.0*(XMAX - XMIN)*(float)(rand() % GRAIN) / (float)GRAIN;
//		myPoints[i][1] = YMIN + 2.0*(YMAX - YMIN)*(float)(rand() % GRAIN) / (float)GRAIN;
//	}
//}
//
//void makeFern(void)
//{
//	int i;
//	float x, y, select;
//
//	glColor3f(0., 1., 0.);
//	glBegin(GL_POINTS);
//	for (i = 0; i<NPOINTS; i++) {
//		x = myPoints[i][0]; y = myPoints[i][1];
//		select = (float)(rand() % GRAIN) / (float)GRAIN;
//		if (select < .01) {
//			x = 0.; y = .16*y;
//		}
//		else
//		{
//			if (select < .86) {
//				x = .85*x + .04*y; y = -.04*x + .85*y + 1.6;
//			}
//			else {
//				if (select < .93) {
//					x = .20*x - .26*y; y = .23*x + .22*y + 1.6;
//				}
//				else {
//					x = -.15*x + .28*y; y = .26*x + .24*y + .44;
//				}
//			}
//		}
//		glVertex2f(x, y);
//		myPoints[i][0] = x; myPoints[i][1] = y;
//	}
//	glEnd();
//}
//
//void display(void)
//{
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//	makeFern();
//	glutSwapBuffers();
//}
//
//void reshape(int w, int h)
//{
//	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluOrtho2D(-5., 5., 0., 10.);
//}
//
//void keyboard(unsigned char key, int x, int y)
//// NOTE: might be interesting to move around the space...
//{
//	glutPostRedisplay();
//}
//
//int main(int argc, char** argv)
//{
//	/* Standard GLUT initialization */
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
//	glutInitWindowSize(WS, WS);
//	glutInitWindowPosition(0, 0);
//	glutCreateWindow("Fern IFS");
//	glutDisplayFunc(display);
//	glutReshapeFunc(reshape);
//	glutKeyboardFunc(keyboard);
//
//	myinit();
//
//	glutMainLoop();
//}