#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>
#include "Timer.h"

typedef struct WDATA {
	static const unsigned int w = 800, h = 600;
	const char* t = "RPG Game";
} WDATA;

const WDATA wdta;
