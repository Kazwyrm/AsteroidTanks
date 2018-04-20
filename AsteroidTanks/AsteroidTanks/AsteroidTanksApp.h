#pragma once

#include "Application.h"
#include "Renderer2D.h"

class Player;

class AsteroidTanksApp : public aie::Application {
public:

	AsteroidTanksApp();
	virtual ~AsteroidTanksApp();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:

	float Timer;
	float defValue;
	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;
	Player*				player;
};