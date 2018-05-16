#pragma once
#include <glm\vec2.hpp>
#include <vector>

namespace aie {
	class Texture;
	class Renderer2D;
	class Input;
}

class Bullets
{
public:
	Bullets();
	~Bullets();


	void Update(float deltaTime);
	void Draw(aie::Renderer2D* m_2dRenderer);


	float bullPosY;
	float bullPosX;

private:
	aie::Texture* m_bulletTex;
};

