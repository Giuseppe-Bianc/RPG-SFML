#pragma once
#include "State.h"
class GameState : public State{
public:
	GameState(sf::RenderWindow* window);
	virtual ~GameState();
	//function
	void endState();
	void updateKeybindigs(const float& dt);
	void update(const float& dt);
	void render(sf::RenderTarget* target = nullptr);
private:

};


