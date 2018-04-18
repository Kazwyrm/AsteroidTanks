#pragma once

#include "Application.h"
#include "Renderer2D.h"

class AsteroidTanksApp : public aie::Application {
public:

	AsteroidTanksApp();
	virtual ~AsteroidTanksApp();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;
};