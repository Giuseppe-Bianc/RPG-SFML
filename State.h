#pragma once
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
#include <cstdlib>
#include <stack>
#include <map>
#include "Struct.h"

class State {
private:
	sf::RenderWindow* window;
	std::vector<sf::Texture> textures;
	bool quit;
public:
	State(sf::RenderWindow* window);
	virtual ~State();
	const bool& getQuit() const;
	virtual void checkForQuit();
	virtual void endState() = 0;
	virtual void updateKeybindigs(const float& dt) = 0;
	virtual void update(const float& dt) = 0;
	virtual void render(sf::RenderTarget* target = nullptr) = 0;
};

