#pragma once
#include "MainMenuState.h"


class Game{
private:
	//variables
	sf::ContextSettings settings;
	sf::RenderWindow* window;
	sf::Event sfevent;
	sf::Clock dtClock;
	float dt;

	std::stack<State*> states;
	std::map<std::string, int> supportedKeys;
	//intialization
	void initWindow();
	void initKeys();
	void initStates();

public:
	//constructors/distructors
	Game();
	virtual ~Game();

	//funcition
	void endApplication();
	void updateDt();
	void updateSFMLEvents();
	void update();
	void render();
	void run();
};

