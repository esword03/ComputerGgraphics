#include <GL/glut.h>

class one_PARTICLE
{
public:
	GLfloat xpos;//(xpos,ypos,zpos)Ϊ���ӵ�λ��
	GLfloat ypos;
	GLfloat zpos;
	GLfloat xspeed;//(xspeed,yspeed,zspeed)Ϊ���ӵ��ٶ�
	GLfloat yspeed;
	GLfloat zspeed;
	GLfloat r;//(r,g,b)Ϊ���ӵ���ɫ
	GLfloat g;
	GLfloat b;
	GLfloat life;//���ӵ�����
	GLfloat fade;//���ӵ�˥���ٶ�
	GLfloat size;//���Ӵ�С�����Խ������λ�ã������Եֵ

	GLbyte   bAddParts;//�������Ƿ���β������
	GLfloat  AddSpeed;//β�����ӵ������ٶ�
	GLfloat   AddCount;//β�����ӵ�������
	one_PARTICLE(GLfloat x, GLfloat y) { xpos = x, ypos = y; }
	one_PARTICLE(){}
};