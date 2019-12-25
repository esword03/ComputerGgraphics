//#include <stdlib.h>
//#include <iostream>
//
//#include <gl/GLUT.H>
//
//
//
//#define ROTATION_SPEED	0.1
//
//static int year = 0, day = 0;
//
//GLuint texture_id1;
//GLuint texture;
//
//
//int start = 0;
//
//int ori_x;
//int ori_y;
//
//
//
//struct Planet
//{
//	float size, sections, posX, posY, posZ, SolarAngle, OwnAxisAngle;
//	int TextureID;
//};
//
//struct Planet Plants1;
//struct Planet Plants2;
//struct Planet Plants3;
//
//
//float R = 8;
//
//float a = 0;
//float b = 0;
//
//
//int load_texture(char *file_name, int width, int height, int depth, GLenum colour_type, GLenum filter_type)
//{
//	GLubyte *raw_bitmap;
//	FILE *file;
//
//	if ((0 != fopen_s(&file, file_name, "rb")))
//	{
//		return 1;
//	}
//
//	raw_bitmap = (GLubyte *)malloc(width * height * depth * (sizeof(GLubyte)));
//
//	if (raw_bitmap == NULL)
//	{
//		fclose(file);
//		return 2;
//	}
//
//	fread(raw_bitmap, width * height * depth, 1, file);
//	fclose(file);
//
//	//  设置过滤类型
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, filter_type);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, filter_type);
//
//	//  设置纹理环境
//	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
//
//	gluBuild2DMipmaps(GL_TEXTURE_2D, 3, width, height, colour_type,
//		GL_UNSIGNED_BYTE, raw_bitmap);
//
//	free(raw_bitmap);
//
//	return 0;
//}
//
//void LoadTextures(GLuint texture_id, int MaxNrOfTextures)
//{
//	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
//	glGenTextures(MaxNrOfTextures, &texture_id);
//
//	glBindTexture(GL_TEXTURE_2D, 2);
//	if (load_texture("D:\\texture\\moon.bmp", 128, 128, 3, GL_BGR_EXT, GL_NEAREST)) {
//
//	}
//	glBindTexture(GL_TEXTURE_2D, 3);
//	if (load_texture("D:\\texture\\sun.bmp", 128, 128, 3, GL_BGR_EXT, GL_NEAREST)) {
//
//	}
//
//	glBindTexture(GL_TEXTURE_2D, 1);
//	if (load_texture("D:\\texture\\ear.bmp", 128, 128, 3, GL_BGR_EXT, GL_NEAREST)) {
//
//	}
//
//}
//
//void init(void)
//{
//	glClearColor(0.0, 0.0, 0.0, 0.0);
//	glShadeModel(GL_FLAT);
//
//	LoadTextures(texture_id1, 1);
//	LoadTextures(texture_id1, 2);
//	LoadTextures(texture_id1, 3);
//
//
//	glEnable(GL_TEXTURE_2D);
//
//	glClearDepth(1.0f);													// 设置深度缓存
//	glDepthFunc(GL_LEQUAL);												// 选择深度测试方式
//	glEnable(GL_DEPTH_TEST);											// 开启深度测试
//	glShadeModel(GL_SMOOTH);											// 阴暗处理采用平滑方式
//	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);					// 最精细的透视计算
//
//
//
//	Plants1.size = 0.2f;
//	Plants1.sections = 16.0f;
//	Plants1.posX = 0.0f;
//	Plants1.posY = 0.0f;
//	Plants1.posZ = 1.4f;
//	Plants1.OwnAxisAngle = 0.0f;
//	Plants1.SolarAngle = 60.0f;
//	Plants1.TextureID = 1;
//
//	Plants2.size = 0.7f;
//	Plants2.sections = 16.0f;
//	Plants2.posX = 0.0f;
//	Plants2.posY = 0.0f;
//	Plants2.posZ = 0.0f;
//	Plants2.OwnAxisAngle = 0.0f;
//	Plants2.SolarAngle = 0.0f;
//	Plants2.TextureID = 2;
//
//	Plants3.size = 0.05f;
//	Plants3.sections = 16.0f;
//	Plants3.posX = 0.0f;
//	Plants3.posY = 0.0f;
//	Plants3.posZ = 0.5f;
//	Plants3.OwnAxisAngle = 0.0f;
//	Plants3.SolarAngle = 20.0f;
//	Plants3.TextureID = 3;
//	return;
//}
//void display(void)
//{
//
//	Plants1.SolarAngle += 1.0f * ROTATION_SPEED;
//	if (Plants1.SolarAngle >= 360) { Plants1.SolarAngle -= 360; }
//
//	// axis rotation
//
//	Plants1.OwnAxisAngle += 0.1f;
//	if (Plants1.OwnAxisAngle >= 360) { Plants1.OwnAxisAngle -= 360; }
//
//
//
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);					// 清除颜色和深度缓存
//	glColor3f(1.0, 0.0, 0.0);
//	glBindTexture(GL_TEXTURE_2D, 3);
//	GLUquadricObj*  s = gluNewQuadric();
//
//	gluQuadricDrawStyle(s, GLU_FILL);
//	gluQuadricNormals(s, GLU_SMOOTH);
//	gluQuadricTexture(s, GL_TRUE);
//	gluSphere(s, Plants2.size, 50, 40);
//	gluDeleteQuadric(s);
//	glBindTexture(GL_TEXTURE_2D, 0);
//
//
//	glColor3f(1.0, 1.0, 1.0);
//
//	glColor3f(0.7f, 0.7f, 0.7f);
//
//	glBegin(GL_LINE_LOOP);
//	for (int l = 0; l < 360; l++)
//	{
//		glVertex3f((float)cos(l* ((float)3.14159 / (float)180))* Plants1.posZ, 0.0f, (float)sin(l* ((float)3.14159 / (float)180))*Plants1.posZ);
//	}
//	glEnd();
//
//	glPushMatrix();//地球栈口
//
//	glRotatef(Plants1.SolarAngle, 0, -1, 0);
//	glTranslatef(Plants1.posX, Plants1.posY, Plants1.posZ);
//
//	glRotatef(Plants1.OwnAxisAngle, 0, -1, 0);
//	glRotatef(90.0, 1.0, 0.0, 0.0);
//
//	glBindTexture(GL_TEXTURE_2D, 1);
//	GLUquadricObj*  q = gluNewQuadric();
//
//	gluQuadricDrawStyle(q, GLU_FILL);
//	gluQuadricNormals(q, GLU_SMOOTH);
//	gluQuadricTexture(q, GL_TRUE);
//	gluSphere(q, Plants1.size, 50, 40);
//	gluDeleteQuadric(q);
//	glBindTexture(GL_TEXTURE_2D, 0);
//
//	Plants3.SolarAngle += 1.0f * ROTATION_SPEED;
//	if (Plants3.SolarAngle >= 360) { Plants3.SolarAngle -= 360; }
//
//
//
//	Plants3.OwnAxisAngle += 1.5f;
//	if (Plants3.OwnAxisAngle >= 360) { Plants3.OwnAxisAngle -= 360; }
//	glRotatef(-90.0, 1.0, 0.0, 0.0);
//
//	glBegin(GL_LINE_LOOP);
//	for (int l = 0; l < 360; l++)
//	{
//		glVertex3f((float)cos(l* ((float)3.14159 / (float)90))* Plants3.posZ, 0.0f, (float)sin(l* ((float)3.14159 / (float)90))*Plants3.posZ);
//	}
//	glEnd();
//
//	glRotatef(Plants3.SolarAngle, 0, -1, 0);
//	glTranslatef(Plants3.posX, Plants3.posY, Plants3.posZ);
//
//	glRotatef(Plants3.OwnAxisAngle, 0, -1, 0);
//	glRotatef(90.0, 1.0, 0.0, 0.0);
//
//	glBindTexture(GL_TEXTURE_2D, 2);
//	GLUquadricObj*  w = gluNewQuadric();
//
//	gluQuadricDrawStyle(w, GLU_FILL);
//	gluQuadricNormals(w, GLU_SMOOTH);
//	gluQuadricTexture(w, GL_TRUE);
//	gluSphere(w, Plants3.size, 50, 40);
//	gluDeleteQuadric(w);
//	glBindTexture(GL_TEXTURE_2D, 0);
//
//	glPopMatrix();//地球出栈
//
//	glLoadIdentity();
//
//	gluLookAt(R*cos(b / 180 * 3.1415926)*sin(a / 180 * 3.1415926), R*sin(b / 180 * 3.1415926), R*cos(b / 180 * 3.1415926)*cos(a / 180 * 3.1415926), 0.0, 0.0, 0.0, cos((90 - b) / 180 * 3.1415926)*sin((a + 180) / 180 * 3.1415926), sin((90 - b) / 180 * 3.1415926), cos((90 - b) / 180 * 3.1415926)*cos((a + 180) / 180 * 3.1415926));
//
//	glutSwapBuffers();
//}
//void reshape(int w, int h)
//{
//	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluPerspective(45.0, (GLfloat)w / (GLfloat)h, 0.1, 20.0);
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//
//}
//
//
//
//
//
//void keyboard(unsigned char key, int x, int y)
//{
//	switch (key) {
//
//	case 'w':
//		R -= 0.1;
//		break;
//	case 's':
//		R += 0.1;
//		break;
//	case 27:
//		exit(0);
//		break;
//	default:
//		break;
//	}
//}
//
//
//void processMouse(int button, int state, int x, int y)
//{
//	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
//	{
//		start = 1;
//		ori_x = x;
//		ori_y = y;
//
//	}
//	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
//	{
//		start = 0;
//
//
//	}
//
//}
//void onMouseMove(int x, int y)
//{
//	if (start == 1)
//	{
//		a -= (x - ori_x) / 2;
//		b += (y - ori_y) / 2;
//
//		ori_x = x;
//		ori_y = y;
//
//	}
//
//
//}
//
//int main(int argc, char** argv)
//{
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
//	glutInitWindowSize(1000, 600);
//	glutInitWindowPosition(100, 100);
//	glutCreateWindow(argv[0]);
//	init();
//	glutDisplayFunc(display);
//	glutIdleFunc(display);
//	glutReshapeFunc(reshape);
//	glutKeyboardFunc(keyboard);
//	glutMouseFunc(processMouse);
//	glutMotionFunc(onMouseMove);
//
//	glutMainLoop();
//	return 0;
//}