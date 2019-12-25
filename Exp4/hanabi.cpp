#pragma comment(lib, "glut32.lib")
#pragma comment(lib, "glu32.lib")
#pragma comment(lib, "opengl32.lib") 

#include<iostream>
#include <list>
using namespace std;

#include <GL/glut.h>
static int ly = 320;

#define MAX_PARTICLES 500  //���������
#define MAX_FIRES 5         //����̻���

#include "particle.h"

GLfloat ambient[] = { 0.8, 0.0, 0.0, 0.5 };        //������
GLfloat diffuse[] = { 0.6, .6, .6, .6 };        //�������
GLfloat specular[] = { .8, .8, .8, .8 };       //�����
GLfloat shininess = 70.0;                         //ϵ��
GLfloat light_position[] = { 300.0 ,300.0 , 300.0 , 1.0 };//��Դλ��

list<one_PARTICLE *> particles;
int nOfFires = 0;
void InitParticle(one_PARTICLE & ep)
{
	ep.b = float(rand() % 100) / 60.0f;//��ʼ��ɫ���
	ep.g = float(rand() % 100) / 60.0f;
	ep.r = float(rand() % 100) / 60.0f;

	ep.life = 1.0f;//��ʼ����ֵ��
	ep.fade = 0.005f + float(rand() % 21) / 10000.0f;//˥���ٶ����
	ep.size = 4 + rand() % 4;//��С
	ep.xpos = 30.0f - float(rand() % 601) / 10.0f;//x��z��λ������Ļ��Χ�ڣ�yֵ�̶�����Ļ�ϲ�
	ep.ypos = 30.0f - float(rand() % 601) / 10.0f;
	ep.zpos = 20.0f - float(rand() % 401) / 10.0f;

	if (!int(ep.xpos))//��ʼ��x�����ٶȣ���֤��Ļ��������Ӷ����м��˶�
	{
		ep.xspeed = 0.0f;
	}
	else
	{
		if (ep.xpos<0)
		{
			ep.xspeed = (rand() % int(-ep.xpos)) / 500.0f;
		}
		else
		{
			ep.xspeed = -(rand() % int(-ep.xpos)) / 500.0f;
		}
	}
	if (!int(ep.ypos))//��ʼ��x�����ٶȣ���֤��Ļ��������Ӷ����м��˶�
	{
		ep.yspeed = 0.0f;
	}
	else
	{
		if (ep.ypos<0)
		{
			ep.yspeed = (rand() % int(-ep.ypos)) / 500.0f;
		}
		else
		{
			ep.yspeed = -(rand() % int(-ep.ypos)) / 500.0f;
		}
	}
	if (!int(ep.zpos))//z������ٶȺ�x����
	{
		ep.zspeed = 0.0f;
	}
	else
	{
		if (ep.zpos<0)
		{
			ep.zspeed = (rand() % int(-ep.zpos)) / 500.0f;
		}
		else
		{
			ep.zspeed = -(rand() % int(ep.zpos)) / 500.0f;
		}
	}

	ep.bAddParts = 1;//��ʼ�̻�������β��
	ep.AddCount = 0.0f;
	ep.AddSpeed = 0.2f;
	nOfFires++;//��ǰ��������1
	particles.push_front(&ep);//������������
}

void init()
{
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
}

void DrawParticles()
{
	//glBindTexture(GL_TEXTURE_2D, textureID); //�󶨵�����
	list<one_PARTICLE *>::iterator par;
	for (par = particles.begin(); par != particles.end(); par++)
	{
		glColor4f((*par)->r, (*par)->g, (*par)->b, (*par)->life);
		glPushMatrix();
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		glTranslatef((*par)->xpos, (*par)->ypos, (*par)->zpos);
		glutSolidSphere((*par)->size, 30, 30);
		glPopMatrix();
	}
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	gluLookAt(0.0, 0.0, 0.0, 0.0, 0.0, -100.0, 0.0, 1.0, 0.0);
	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialf(GL_FRONT, GL_SHININESS, shininess);

	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	DrawParticles();
	glutSwapBuffers();
}

void reshape(int _wid, int _hei)
{
	glViewport(0, 0, (GLsizei)_wid, (GLsizei)_hei);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	if (_wid <= _hei) {
		glOrtho(-300.0, 300.0, -300.0*_hei / _wid, 300.0*_hei / _wid, -300.0, 300.0);
	}
	else {
		glOrtho(-300.0*_wid / _hei, 300.0*_wid / _hei, -300.0, 300.0, -300.0, 300.0);
	}
}

void TimerFunc(int value) {
	list<one_PARTICLE *>::iterator it;
	one_PARTICLE * tmp;
	for (it = particles.begin(); it != particles.end();)
	{
		(*it)->life -= (*it)->fade/10;
		(*it)->size = (*it)->size*(*it)->life;
		(*it)->ypos -= (*it)->yspeed * 100;
		(*it)->xpos -= (*it)->xspeed * 100;
		if ((*it)->life == 0) {
			tmp = *it;
			it = particles.erase(it);
			delete tmp;
			nOfFires--;
		}

		//if ((*it)->ypos >300)
		//{
		//	tmp = *it;
		//	it = particles.erase(it);
		//	delete tmp;
		//	nOfFires--;
		//}
		else
			it++;
	}
	glutPostRedisplay();
	glutTimerFunc(10, TimerFunc, 1); //seconds, func, para
	if (nOfFires < MAX_PARTICLES)
	{
		one_PARTICLE *a_particle;
		a_particle = (one_PARTICLE *)new one_PARTICLE();
		InitParticle(*a_particle);
	}
}

void main()
{
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(600, 600);
	glutCreateWindow("ball");
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutTimerFunc(500, TimerFunc, 1);
	glutMainLoop();
	return;
}
