
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

	//ͨ�������

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



	//ͨ���������

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

	//���ô��ڵĻ������ɫģ��

	//����ָ�����ǣ�����ʹ�õ������沢��ʹ��RGB��ɫģ�����趨��ɫֵ��

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	//���ô������Ͻǵ�λ��

	glutInitWindowPosition(400, 200);

	//���ô��ڵĿ��

	glutInitWindowSize(800, 600);

	glutCreateWindow("Test OpenGL Program");



	//������ʾ���ڵı���Ϊ��ɫ������˳��Ϊ���졢�̡�����͸���ȡ�

	glClearColor(1.0, 1.0, 1.0, 0.0);

	//����ͶӰ���ͣ���ͶӰ

	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();

	//�۲������x����ֵ��0��200��y�Ǵ�0��150

	gluOrtho2D(0.0, 800.0, 0.0, 600.0);



	glutDisplayFunc(piontSegment);

	glutMainLoop();



	system("pause");

	return 0;

}
