#include "AsteroidTanksApp.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "Player.h"
#include "Asteroids.h"
#include <imgui.h>
#include <string>
#include <random>


AsteroidTanksApp::AsteroidTanksApp() {

}

AsteroidTanksApp::~AsteroidTanksApp() {

}

int AsteroidTanksApp::randomNum(int min, int max)
{
	std::mt19937 rng;
	rng.seed(std::random_device()());
	std::uniform_int_distribution<int>dist10(min, max);

	int ranNum = dist10(rng);
	return ranNum;
}

bool AsteroidTanksApp::startup() {
	
	m_2dRenderer = new aie::Renderer2D();

	// TODO: remember to change this when redistributing a build!
	// the following path would be used instead: "./font/consolas.ttf"
	m_font = new aie::Font("../bin/font/consolas.ttf", 32);
	Timer = 0.0f;
	defValue = 100;

	randnum = randomNum(100.0f, 1500.0f);
	player = new Player(new glm::vec2(800, 200));
	asteroid = new Asteroids(new glm::vec2(randnum, 900.0f));
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
	if (asteroid->IsCollision(asteroid->getPosX(), asteroid->getPosY(), player->getPosX(), player->getPosY()) == true && defValue >= 0)
	{
		defValue--;
	}

	player->Update(deltaTime, input);
	asteroid->Update(deltaTime);

	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void AsteroidTanksApp::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();


	ImGui::Begin("Player");
	ImGui::Text("HP : ");
	ImGui::ProgressBar(defValue/100.0f, ImVec2(250.0f, 20.0f));
	
	ImGui::End();

	
	ImGui::Begin("Menu");
	ImGui::Text("Position :");
	ImGui::Text("Player X (%0.01F)", player->getPosX());
	ImGui::Text("Player Y (%0.01F)", player->getPosY());

	ImGui::Text("Ast Pos :");
	ImGui::Text("Player X (%0.01F)", asteroid->getPosX());
	ImGui::Text("Player Y (%0.01F)", asteroid->getPosY());

	ImGui::Text("\nPress ESC to exit");
	ImGui::End();


	// draw your stuff here!
	player->Draw(m_2dRenderer);
	asteroid->Draw(m_2dRenderer);
	// output some text, uses the last used colour


	// done drawing sprites
	m_2dRenderer->end();
}