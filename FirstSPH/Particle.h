#pragma once

#include <gl\glew.h>
#include <gl\glut.h>

class Particle
{
public:

	//λ��
	GLfloat x;
	GLfloat y;
	//�ٶ�
	GLfloat vx;
	GLfloat vy;
	//����
	GLfloat fx;
	GLfloat fy;
	//�ܶ�
	GLfloat density;
	//�ڲ�ѹ��
	GLfloat pressure;
	//��������

	Particle();

	Particle(GLfloat x, GLfloat y);

	~Particle();

};

