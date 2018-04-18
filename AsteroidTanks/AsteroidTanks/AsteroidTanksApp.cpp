#include "AsteroidTanksApp.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"

AsteroidTanksApp::AsteroidTanksApp() {

}

AsteroidTanksApp::~AsteroidTanksApp() {

}

bool AsteroidTanksApp::startup() {
	
	m_2dRenderer = new aie::Renderer2D();

	// TODO: remember to change this when redistributing a build!
	// the following path would be used instead: "./font/consolas.ttf"
	m_font = new aie::Font("../bin/font/consolas.ttf", 32);

	return true;
}

void AsteroidTanksApp::shutdown() {

	delete m_font;
	delete m_2dRenderer;
}

void AsteroidTanksApp::update(float deltaTime) {

	// input example
	aie::Input* input = aie::Input::getInstance();

	if (input->isKeyDown(aie::INPUT_KEY_W))
	{

	}
	if (input->isKeyDown(aie::INPUT_KEY_S))
	{

	}
	if (input->isKeyDown(aie::INPUT_KEY_A))
	{

	}
	if (input->isKeyDown(aie::INPUT_KEY_D))
	{

	}

	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void AsteroidTanksApp::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	// draw your stuff here!
	
	// output some text, uses the last used colour
	m_2dRenderer->drawText(m_font, "Press ESC to quit", 0, 0);

	// done drawing sprites
	m_2dRenderer->end();
}