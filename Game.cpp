#include "Game.h"

//static function

//initializer function

void Game::initWindow(){
	settings.antialiasingLevel = 8;
	/*this->window = new sf::RenderWindow( sf::VideoMode(wdta.w, wdta.h), wdta.t, sf::Style::Default, settings);
	this->window->setFramerateLimit(120);
	this->window->setVerticalSyncEnabled(false);*/

	std::ifstream ifs("Config/window.ini");

	std::string title = "None";
	sf::VideoMode window_bounds(800, 600);
	unsigned int framerate_limit = 120;
	bool vertical_sync_enabled = false;

	if (ifs.is_open()){
		std::getline(ifs, title);
		ifs >> window_bounds.width >> window_bounds.height;
		ifs >> framerate_limit;
		ifs >> vertical_sync_enabled;
	}

	ifs.close();

	this->window = new sf::RenderWindow(window_bounds, title.c_str(), sf::Style::Default, settings);
	this->window->setFramerateLimit(framerate_limit);
	this->window->setVerticalSyncEnabled(vertical_sync_enabled);

}

void Game::initstates(){
	this->states.push(new GameState(this->window));
}


void Game::updateDt(){
	this->dt = this->dtClock.restart().asSeconds();
	/*system("cls");
	CORE_TRACE("{}\n",this->dt);*/
}

//constructors/distructors
Game::Game() {
	Log::Init();
	this->initWindow();
	this->initstates();
}

Game::~Game(){
	delete this->window;
	this->window = NULL;
	while (!this->states.empty()){
		delete this->states.top();
		this->states.pop();
	}
}

//function
void Game::endAplication(){
	CORE_TRACE("ciusura Programma\n");
}

void Game::updateSFMLEvents(){
	while (this->window->pollEvent(this->sfevent)) {
		if (this->sfevent.type == sf::Event::Closed) {
			CORE_TIMESN_TRACE(this->window->close(), "chiusura programma in risposta a solleciatazione, tempo chiusura = {} us ({:7.9} ms)", getTime().duration, getTime().ms);
		}
	}
}

void Game::update(){
	updateSFMLEvents();
	if (!this->states.empty()) {
		this->states.top()->update(this->dt);
		if (this->states.top()->getQuit()) {
			this->states.top()->endState();
			delete this->states.top();
			this->states.pop();
		}
	} else {
		this->endAplication();
		CORE_TIMESN_TRACE(this->window->close(), "chiusura programma in risposta a states.top()->getQuit(), tempo chiusura = {} us ({:7.9} ms)", getTime().duration, getTime().ms);
	}
}

void Game::render(){
	this->window->clear();
	if (!this->states.empty()) this->states.top()->render();

	this->window->display();
}

void Game::run(){

	while (this->window->isOpen()) {
		this->updateDt();
		this->update();
		this->render();
	}
}
