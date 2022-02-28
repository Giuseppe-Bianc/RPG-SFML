#pragma once
#include "State.h"
class GameState : public State{
private:
	Entity player;
	void initKeybinds() override;
public:
	GameState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys);
	~GameState();

	//function
	void endState() override;

	void updateInput(const float& dt) override;
	void update(const float& dt);
	void render(sf::RenderTarget* target = nullptr);
};


