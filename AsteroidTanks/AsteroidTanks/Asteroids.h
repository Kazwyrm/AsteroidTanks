#pragma once
#include <glm\vec2.hpp>

namespace aie {
	class Texture;
	class Renderer2D;
	class Input;
}

class Asteroids
{
public:
	Asteroids();
	Asteroids(glm::vec2* pos);
	~Asteroids();

	float getPosX();
	float getPosY();

	bool IsCollision(float a_x, float a_y, float p_x, float p_y);

	void Update(float deltaTime);
	void Draw(aie::Renderer2D* spriteBatch);


private:
	glm::vec2* a_pos;
	float a_speedX = 750;
	float a_speedY = 500;
	aie::Texture* m_texture;



	

};

