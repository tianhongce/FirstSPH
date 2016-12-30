#include "Particle.h"


Particle::Particle()
{
	this->x = 0;
	this->y = 0;
}

Particle::Particle(GLfloat x, GLfloat y)
{
	this->x = x;
	this->y = y;
}


Particle::~Particle()
{
}
