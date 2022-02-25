#include "GameState.h"

GameState::GameState(sf::RenderWindow* window) : State(window) {

}

GameState::~GameState() {

}

void GameState::endState(){

}

void GameState::update(const float& dt){
	system("cls");
	CORE_TRACE("hello from game state\n");
}

void GameState::render(sf::RenderTarget* target){

}
