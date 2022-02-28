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

class Entity{
private:

protected:
	sf::RectangleShape shape;
	float movementSpeed = 0;
public:
	Entity();
	
	virtual ~Entity();
	virtual void move(const float& dt, const float dir_x, const float dir_y);
	virtual void update(const float& dt);
	virtual void render(sf::RenderTarget* target = nullptr);
};


