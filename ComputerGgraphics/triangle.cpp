//#include <GL/glut.h>
//
//// a point data type 
//
//typedef GLfloat point2d[2];
//
////initial triangle 
//point2d v[3] = { { -1.0, -0.58 },{ 1.0, -0.58 },{ 0.0, 1.15 } };
//
//int n;
//// number of recursive steps 
//// display one triangle 
//
//void triangle(point2d a, point2d b, point2d c)
//{
//	glBegin(GL_TRIANGLES);
//	glVertex2fv(a);
//	glVertex2fv(b);
//	glVertex2fv(c);
//	glEnd();
//}
//// triangle subdivision using vertex numbers 
//void divide_triangle(point2d a, point2d b, point2d c, int m)
//{
//	point2d v0, v1, v2;
//	int j;
//	if (m>0)
//	{
//		for (j = 0; j<2; j++) v0[j] = (a[j] + b[j]) / 2;
//
//		for (j = 0; j<2; j++) v1[j] = (a[j] + c[j]) / 2;
//		for (j = 0; j<2; j++) v2[j] = (b[j] + c[j]) / 2;
//		divide_triangle(a, v0, v1, m - 1);
//		divide_triangle(c, v1, v2, m - 1);
//		divide_triangle(b, v2, v0, m - 1);
//	}
//	else(triangle(a, b, c));
//	// draw triangle at end of recursion
//
//}
//void mydisplay(void)
//{
//	glClear(GL_COLOR_BUFFER_BIT);
//	divide_triangle(v[0], v[1], v[2], n);
//	glFlush();
//}
//void init() {
//	glClearColor(1.0, 1.0, 1.0, 1.0);
//	glColor3f(0.0, 0.0, 0.0);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	glOrtho(-2.0, 2.0, -2.0, 2.0, -1.0, 1.0);
//}
//void main(int argc, char **argv)
//
//{
//	n = 8;
//	glutInit(&argc, argv);
//
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//	glutInitWindowSize(500, 500);
//	glutInitWindowPosition(50, 50);
//	glutCreateWindow("2D Sierpinski");
//	glutDisplayFunc(mydisplay);
//	init();
//	glutMainLoop();
//}