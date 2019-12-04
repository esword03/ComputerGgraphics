//#include <stdlib.h>
//#include<GL\glut.h>
//
//
//void init(void)
//{
//	glClearColor(0.0, 0.0, 0.0, 0.0);
//	glShadeModel(GL_FLAT);
//}
//
//void draw_triangle(void)
//{ //绘制一个三角形
//	glBegin(GL_LINE_LOOP);
//	glVertex2f(0.0, 25.0);
//	glVertex2f(25.0, -25.0);
//	glVertex2f(-25.0, -25.0);
//	glEnd();
//}
//
//void mydisplay() {
//	glClear(GL_COLOR_BUFFER_BIT);
//	glLoadIdentity();
//	glColor3f(1.0, 1.0, 1.0);
//	draw_triangle();
//
//	glEnable(GL_LINE_STIPPLE);
//	glLineStipple(1, 0xF0F0);
//	glLoadIdentity();
//	glTranslatef(0, -80, 0);
//	glRotatef(180, 0, 0, 1);
//	draw_triangle();
//
//	glLineStipple(1, 0xF00F);
//	glLoadIdentity();
//	glTranslatef(25, -25, 0);
//	glRotated(30, 0, 0, 1);
//	glTranslatef(-25, 25, 0);
//	draw_triangle();
//
//	glLineStipple(1, 0x8888);
//	glLoadIdentity();
//	glScalef(1.0, 1.732/2, 1.0);
//	draw_triangle();
//
//	glDisable(GL_LINE_STIPPLE);
//	glFlush();
//}
//
//void translation() {
//
//}
//
//void reshape(int w, int h)
//{
//	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	if (w <= h)
//		gluOrtho2D(-150.0, 150.0, -150.0*(GLfloat)h / (GLfloat)w, 150.0*(GLfloat)h / (GLfloat)w);
//	else
//		gluOrtho2D(-150.0*(GLfloat)w / (GLfloat)h,
//			150.0*(GLfloat)w / (GLfloat)h, -150.0, 150.0);
//	glMatrixMode(GL_MODELVIEW);
//}
//int main(int argc, char** argv)
//{
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//	glutInitWindowSize(500, 500);
//	glutInitWindowPosition(100, 100);
//	glutCreateWindow(argv[0]);
//	init();
//	glutDisplayFunc(mydisplay);
//	glutReshapeFunc(reshape);
//	glutMainLoop();
//	return 0;
//}