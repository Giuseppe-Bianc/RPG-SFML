#pragma once

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include "Struct.h"


class Game{
private:
	//variables
	sf::ContextSettings settings;
	sf::RenderWindow* window;
	sf::Event sfevent;
	//intialization
	void initWindow();
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
