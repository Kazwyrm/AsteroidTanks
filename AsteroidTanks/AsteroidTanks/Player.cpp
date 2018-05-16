#include "Player.h"
#include <Renderer2D.h>
#include <Texture.h>
#include <Input.h>
#include "Bullets.h"

Player::Player()
{
}

Player::Player(glm::vec2 * pos)
{
	m_texture = new aie::Texture("../bin/textures/ship.png");
	m_pos = pos;

	for (int i = 0; i < 2000; i++)
	{
		m_bullet = new Bullets();
		m_inactiveBullet.push_back(m_bullet);
	} 
}


Player::~Player()
{
	delete m_texture;
	delete m_bullet;
}

float Player::getPosX()
{
	return m_pos->x;
}

float Player::getPosY()
{
	return m_pos->y;
}



void Player::Update(float deltaTime, aie::Input* input)
{
	float timer = deltaTime;

	if (input->isKeyDown(aie::INPUT_KEY_W) && m_pos->y <= 500)
	{
		m_pos->y += p_speedY * deltaTime;
	}
	if (input->isKeyDown(aie::INPUT_KEY_S) && m_pos->y >= 75)
	{
		m_pos->y -= p_speedY * deltaTime;
	}
	if (input->isKeyDown(aie::INPUT_KEY_D) && m_pos->x <= 1500)
	{
		m_pos->x += p_speedX * deltaTime;
	}
	if (input->isKeyDown(aie::INPUT_KEY_A) && m_pos->x >= 100)
	{
		m_pos->x -= p_speedX * deltaTime;
	}

	if (input->isKeyDown(aie::INPUT_KEY_SPACE) && timer <= 3.0f)
	{
		
		Bullets* newBullet;
		newBullet = m_inactiveBullet.at(m_inactiveBullet.size() - 1);
		newBullet->bullPosX = m_pos->x;
		newBullet->bullPosY = m_pos->y;
		m_activeBullet.push_back(newBullet);
		m_inactiveBullet.pop_back();
	}
		timer = 0.0f;

	for (auto i = m_activeBullet.begin(); i != m_activeBullet.end(); i++)
	{
		(*i)->Update(deltaTime);
	}

	if (m_activeBullet.size() >= 2000)
	{
		for (auto it = m_activeBullet.begin(); it != m_activeBullet.end(); it++)
		{
			Bullets* usedBullet;
			if ((*it)->bullPosY >= 720)
			{
				usedBullet = m_activeBullet.at(m_activeBullet.size() - 1);
				usedBullet->bullPosX = m_pos->x;
				usedBullet->bullPosY = m_pos->y;
				m_inactiveBullet.push_back(usedBullet);
				m_activeBullet.pop_back();
			}
		}
	}
}

void Player::Draw(aie::Renderer2D * spriteBatch)
{
	spriteBatch->drawSprite(m_texture, m_pos->x, m_pos->y);

	for (auto it = m_activeBullet.begin(); it != m_activeBullet.end(); ++it)
	{
		(*it)->Draw(spriteBatch);
	}
}
