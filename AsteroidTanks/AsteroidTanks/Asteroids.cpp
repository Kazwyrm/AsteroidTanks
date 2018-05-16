#include "Asteroids.h"
#include <Renderer2D.h>
#include <Texture.h>
#include <Input.h>


Asteroids::Asteroids()
{
}

Asteroids::Asteroids(glm::vec2 * pos)
{
	m_texture = new aie::Texture("../bin/textures/rock_medium.png");
	a_pos = pos;
}


Asteroids::~Asteroids()
{
	delete m_texture;
}



float Asteroids::getPosX()
{
	return a_pos->x;
}

float Asteroids::getPosY()
{
	return a_pos->y;
}

bool Asteroids::IsCollision(float a_x, float a_y, float p_x, float p_y)
{
	float xDist = a_x - p_x;
	float yDist = a_y - p_y;


	if (yDist <= 50 && yDist >= -50 && xDist >= -50 && xDist <= 50)
	{
		return true;
	}
	else
	{
		return false;
	}
}


void Asteroids::Update(float deltaTime)
{
	a_pos->y--;
}

void Asteroids::Draw(aie::Renderer2D * spriteBatch)
{
	spriteBatch->drawSprite(m_texture, a_pos->x, a_pos->y);
}
