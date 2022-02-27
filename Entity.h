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
public:
	Entity();
	
	virtual ~Entity();
	virtual void update(const float& dt) = 0;
	virtual void render(sf::RenderTarget* target = nullptr) = 0;
private:

};


