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

	player = new Player(new glm::vec2(100, 200));
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

	player->Update(deltaTime, input);
	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void AsteroidTanksApp::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();
	ImGui::Begin("Timer");
	ImGui::Text("Player X (%0.01F)", player->getPosX());
	ImGui::Text("Player Y (%0.01F)", player->getPosY());
	static float defValue = 3;
	ImGui::SliderFloat("Health", &defValue, 0.0f, 3.f, "%.1f");
	ImGui::End();
	// draw your stuff here!
	player->Draw(m_2dRenderer);
	// output some text, uses the last used colour
	m_2dRenderer->drawText(m_font, "Press ESC to quit", 0, 0);

	// done drawing sprites
	m_2dRenderer->end();
}