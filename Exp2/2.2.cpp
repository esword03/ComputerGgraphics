//#include <stdlib.h>
//#include <GL/glut.h>
//
//static GLfloat right = 0.0;
//static GLfloat up = 0.0;
//static int flag = 0;
//
//void display(void)
//{
//	glClear(GL_COLOR_BUFFER_BIT);
//	glPushMatrix();
//	glTranslatef(right, up, 0);
//	
//	glColor3f(1.0, 1.0, 1.0);
//	glRectf(-1.0, -1.0, 1.0, 1.0);
//	glPopMatrix();
//	glutSwapBuffers();
//}
//
//void spinDisplay(void)
//{
//	flag = 1;
//	right = right + 0.5;
//	if (right > 50.0)
//		right = right - 100.0;
//	if (up > 50)
//		up = up - 100;
//	if (right < -50)
//		right = right + 100;
//	if (up < -50)
//		up = up + 100;
//	glutPostRedisplay();
//}
//void spinDisplay2(void) {
//	flag = 2;
//	up = up + 0.5;
//	if (right > 50.0)
//		right = right - 100.0;
//	if (up > 50)
//		up = up - 100;
//	if (right < -50)
//		right = right + 100;
//	if (up < -50)
//		up = up + 100;
//	glutPostRedisplay();
//}
//void spinDisplay3(void) {
//	flag = 3;
//	right = right - 0.5;
//	if (right > 50.0)
//		right = right - 100.0;
//	if (up > 50)
//		up = up - 100;
//	if (right < -50)
//		right = right + 100;
//	if (up < -50)
//		up = up + 100;
//	glutPostRedisplay();
//}
//void spinDisplay4(void) {
//	flag = 4;
//	up = up - 0.5;
//	if (right > 50.0)
//		right = right - 100.0;
//	if (up > 50)
//		up = up - 100;
//	if (right < -50)
//		right = right + 100;
//	if (up < -50)
//		up = up + 100;
//	glutPostRedisplay();
//}
//
//void init(void)
//{
//	glClearColor(0.0, 0.0, 0.0, 0.0);
//	glShadeModel(GL_FLAT);
//}
//void reshape(int w, int h)
//{
//	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	glOrtho(-50.0, 50.0, -50.0, 50.0, -1.0, 1.0);
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//}
//
//void mouse(int button, int state, int x, int y)
//{
//	switch (button) {
//	case GLUT_LEFT_BUTTON:
//		if (state == GLUT_DOWN) {
//			if (flag == 0) {
//				glutIdleFunc(spinDisplay3);
//			}
//			else if(flag==1)
//			{
//				glutIdleFunc(spinDisplay2);
//			}
//			else if (flag == 2) {
//				glutIdleFunc(spinDisplay3);
//			}
//			else if (flag == 3) {
//				glutIdleFunc(spinDisplay4);
//			}
//			else if (flag == 4) {
//				glutIdleFunc(spinDisplay);
//			}
//		}
//		
//		break;
//	case GLUT_MIDDLE_BUTTON:
//	case GLUT_RIGHT_BUTTON:
//		if (state == GLUT_DOWN) {
//			if (flag == 0) {
//				glutIdleFunc(spinDisplay);
//			}
//			else if (flag == 1)
//			{
//				glutIdleFunc(spinDisplay4);
//			}
//			else if (flag == 2) {
//				glutIdleFunc(spinDisplay);
//			}
//			else if (flag == 3) {
//				glutIdleFunc(spinDisplay2);
//			}
//			else if (flag == 4) {
//				glutIdleFunc(spinDisplay3);
//			}
//		}
//		break;
//	default:
//		break;
//	}
//}
///*
// *  Request double buffer display mode.
//  *  Register mouse input callback functions
//   */
//int main(int argc, char** argv)
//{
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
//	glutInitWindowSize(500, 500);
//	glutInitWindowPosition(100, 100);
//	glutCreateWindow(argv[0]);
//	init();
//	glutDisplayFunc(display);
//	glutReshapeFunc(reshape);
//	glutMouseFunc(mouse);
//	glutMainLoop();
//	return 0;
//}