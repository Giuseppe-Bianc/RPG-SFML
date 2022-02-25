#pragma once
#include "State.h"


class Game{
private:
	//variables
	sf::ContextSettings settings;
	sf::RenderWindow* window;
	sf::Event sfevent;
	sf::Clock dtClock;
	float dt;
	//intialization
	void initWindow();
	void updateDt();
public:
	//constructors/distructors
	Game();
	virtual ~Game();

	//funcition
	void updateSFMLEvents();
	void update();
	void render();
	void run();
};

