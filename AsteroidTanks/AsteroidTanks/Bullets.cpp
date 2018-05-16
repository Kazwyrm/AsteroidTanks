#include "Bullets.h"
#include <Texture.h>
#include <Renderer2D.h>



Bullets::Bullets()
{
	bullPosX = 0.0f;
	bullPosY = 0.0f;
	m_bulletTex = new aie::Texture("../bin/textures/bullet.png");
}


Bullets::~Bullets()
{
	delete m_bulletTex;
}

void Bullets::Update(float deltaTime)
{
	bullPosY += 500.0f * deltaTime;
}

void Bullets::Draw(aie::Renderer2D * m_2dRenderer)
{
	m_2dRenderer->drawSprite(m_bulletTex, bullPosX, bullPosY);
}