#include "GameState.h"

GameState::GameState(sf::RenderWindow* window) : State(window) {

}

GameState::~GameState() {

}

void GameState::endState(){
	CORE_TRACE("ending gameState\n");
}

void GameState::updateKeybindigs(const float& dt){
	this->checkForQuit();
}

void GameState::update(const float& dt){
	this->updateKeybindigs(dt);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		CORE_TRACE("A\n");
	}
}

void GameState::render(sf::RenderTarget* target){
	(void)target;
	
}
