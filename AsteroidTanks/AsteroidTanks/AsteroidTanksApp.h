#pragma once

#include "Application.h"
#include "Renderer2D.h"

class Player;
class Asteroids;

class AsteroidTanksApp : public aie::Application {
public:

	AsteroidTanksApp();
	virtual ~AsteroidTanksApp();

	int randomNum(int min, int max);

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:

	float Timer;
	float defValue;
	int activeAst = 0;
	float randnum = 0;

	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;
	Player*				player;
	Asteroids*			asteroid;
};