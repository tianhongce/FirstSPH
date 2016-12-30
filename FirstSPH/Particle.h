#pragma once

#include <gl\glew.h>
#include <gl\glut.h>

class Particle
{
public:

	//位置
	GLfloat x;
	GLfloat y;
	//速度
	GLfloat vx;
	GLfloat vy;
	//受力
	GLfloat fx;
	GLfloat fy;
	//密度
	GLfloat density;
	//内部压力
	GLfloat pressure;
	//附近粒子

	Particle();

	Particle(GLfloat x, GLfloat y);

	~Particle();

};

