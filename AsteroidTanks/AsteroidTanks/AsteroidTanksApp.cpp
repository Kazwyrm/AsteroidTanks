#include "AsteroidTanksApp.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "Player.h"
#include <imgui.h>

AsteroidTanksApp::AsteroidTanksApp() {

}

AsteroidTanksApp::~AsteroidTanksApp() {

}

bool AsteroidTanksApp::startup() {
	
	m_2dRenderer = new aie::Renderer2D();

	// TODO: remember to change this when redistributing a build!
	// the following path would be used instead: "./font/consolas.ttf"
	m_font = new aie::Font("../bin/font/consolas.ttf", 32);
	Timer = 0;
	//player = new Player();
	return true;
}

void AsteroidTanksApp::shutdown() {

	delete m_font;
	delete m_2dRenderer;
}

void AsteroidTanksApp::update(float deltaTime) {

	Timer = deltaTime;
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
	ImGui::Begin("sample ");
	ImGui::Text("Timer:  (%0.1F)", Timer);
	static float defValue = 50;
	ImGui::SliderFloat("test ", &defValue, 0.0f, 100.f, "%.1f");
	ImGui::End();
	// draw your stuff here!
	
	// output some text, uses the last used colour
	m_2dRenderer->drawText(m_font, "Press ESC to quit", 0, 0);

	// done drawing sprites
	m_2dRenderer->end();
}