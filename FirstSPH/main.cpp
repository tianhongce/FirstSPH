#pragma once
#pragma execution_character_set("utf-8")

#include <stdio.h>
#include <gl\glew.h>
#include <gl\glut.h>
#include "Particle.h"
#include <windows.h>
#include <vector>
#include <iostream>

//const float GRAVITY = 0.5;//重力系数
//const float RANGE = 60;//光滑核半径
//const float RANGE2 = RANGE*RANGE;//光滑核半径的平方
//const float DENSITY = 1;//密度
//const float PRESSUER = 2;//压力系数
//const float VISCOSITY = 0.075;//粘度系数

#define GRAVITY 0.5
#define RANGE 60.f
#define DENSITY 1.f
#define PRESSURE 2.f
#define VISCOSITY 0.075

using namespace std;

std::vector<Particle> particles;
int numParticles = 10;

void initParticle()
{
	Particle p;

	for (int i = 0; i < 3; i++)
	{
		p.x = 0.2*i;
		p.y = 0.5;
		particles.push_back(p);
	}

}

void movePartical()
{
	//a = a - 0.0001;
	//a = a*0.6;
	//b = b*0.9;
	//a = 0.0;
	//p1.x = a;
	//p1.y = b;
}

void initBottle()
{
	glBegin(GL_LINE_STRIP);
	glVertex2f(0.4f, 0.6f);
	glVertex2f(0.4f, -0.4f);
	glVertex2f(-0.4f, -0.4f);
	glVertex2f(-0.4f, 0.6f);
	glEnd();
}

void drawParticle()
{
	//Particle p1;
	//initParticle();
	glPointSize(10.0f);
	glBegin(GL_POINTS);

	//glVertex2f(a, b);

	//std::vector<Particle>::iterator it;
	//for (it = particles.begin(); it != particles.end(); it++)
	//{
	//	std::cout << "aaa";
	//	std::cout <<"aaa"<< (*it).x << std::endl;
	//	glVertex2f((*it).x, (*it).y);
	//}

	for (int i = 0; i < particles.size(); i++)
	{
		//printf("%d", particles[i]);
		glVertex2f((particles[i]).x, (particles[i]).y);
	}

	glEnd();
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);

	//glEnable(GL_POINT_SMOOTH);
	//glPointSize(10.0f);
	//glBegin(GL_LINE_STRIP);//必须是加上s，要不然显示不了
	//glVertex2f(0.0f, 0.0f);
	//glVertex2f(0.5f, 0.8f);
	//glVertex2f(-0.5f, 0.8f);
	//glVertex2f(-0.5f, -0.8f);
	//glEnd();
	//initBottle();
	initParticle();
	drawParticle();
	//Sleep(0.01);
	//movePartical();
	glFlush();
	glutSwapBuffers();
}

void idle(void)
{
	glutPostRedisplay();
}

void reshape(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

//void reshape(int w, int h)
//{
//	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	glFrustum(-1.0, 1.0, -1.0, 1.0, 1.5, 200.0);
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//	glTranslatef(0.0f, -20.0f, -150.0f);
//}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);

	glutInitWindowSize(600, 600);
	glutInitWindowPosition(300, 100);
	glutCreateWindow("SPH");

	glutDisplayFunc(display);

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	glutReshapeFunc(reshape);
	glutIdleFunc(idle);

	glutMainLoop();

	return 0;


}