#include <GL/glut.h>

class one_PARTICLE
{
public:
	GLfloat xpos;//(xpos,ypos,zpos)为粒子的位置
	GLfloat ypos;
	GLfloat zpos;
	GLfloat xspeed;//(xspeed,yspeed,zspeed)为粒子的速度
	GLfloat yspeed;
	GLfloat zspeed;
	GLfloat r;//(r,g,b)为粒子的颜色
	GLfloat g;
	GLfloat b;
	GLfloat life;//粒子的寿命
	GLfloat fade;//粒子的衰减速度
	GLfloat size;//粒子大小，可以结合粒子位置，计算边缘值

	GLbyte   bAddParts;//该粒子是否含有尾巴粒子
	GLfloat  AddSpeed;//尾巴粒子的增加速度
	GLfloat   AddCount;//尾巴粒子的增加量
	one_PARTICLE(GLfloat x, GLfloat y) { xpos = x, ypos = y; }
	one_PARTICLE(){}
};