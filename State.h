#pragma once
#include <vector>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include "Struct.h"

class State {
private:
	std::vector<sf::Texture> textures;
public:
	State();
	virtual ~State();
};

