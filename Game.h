#pragma once
#include "GameState.h"


class Game{
private:
	//variables
	sf::ContextSettings settings;
	sf::RenderWindow* window;
	sf::Event sfevent;
	sf::Clock dtClock;
	float dt;

	std::stack<State*> states;
	//intialization
	void initWindow();
	void initstates();
public:
	//constructors/distructors
	Game();
	virtual ~Game();

	//funcition
	void endAplication();
	void updateDt();
	void updateSFMLEvents();
	void update();
	void render();
	void run();
};

