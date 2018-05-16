#pragma once
#include <glm\vec2.hpp>
#include "Bullets.h"

namespace aie {
	class Texture;
	class Renderer2D;
	class Input;
}

class Player
{
public:
	Player();
	Player(glm::vec2* pos);
	~Player();

	float getPosX();
	float getPosY();

	void Update(float deltaTime, aie::Input* input);
	void Draw(aie::Renderer2D* spriteBatch);


private:
	float p_speedX = 750;
	float p_speedY = 500;
	glm::vec2* m_pos;
	aie::Texture* m_texture;

	Bullets* m_bullet;
	std::vector<Bullets*> m_activeBullet;
	std::vector<Bullets*> m_inactiveBullet;
};