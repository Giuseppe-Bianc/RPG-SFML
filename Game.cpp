#include "Game.h"

//static function

//initializer function

void Game::initWindow(){
	settings.antialiasingLevel = 8;
	window = new sf::RenderWindow( sf::VideoMode(wdta.w, wdta.h), wdta.t, sf::Style::Default, settings);
}

//constructors/distructors
Game::Game() {
	Log::Init();
	this->initWindow();
}

Game::~Game(){
	delete this->window;
	this->window = NULL;
}

//function

void Game::updateSFMLEvents(){
	while (this->window->pollEvent(this->sfevent)) {
		if (this->sfevent.type == sf::Event::Closed) {
			TIME_ITSNL(this->window->close());
			CORE_INFO("chiusura programma in risposta a solleciatazione, tempo chiusura = {} us ({:7.9} ms)", getTime().duration, getTime().ms);
		}
	}
}

void Game::update(){
	updateSFMLEvents();
}

void Game::render(){
	this->window->clear();

	this->window->display();
}

void Game::run(){

	while (this->window->isOpen()) {
		this->update();
		this->render();
	}
}
