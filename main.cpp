#include <iostream>
#include <ctime>
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include "Struct.h"

int main(){
	Log::Init();
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(wdta.w, wdta.h), wdta.t, sf::Style::Default, settings);

	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				TIME_ITSNL(window.close()); 
				CORE_INFO("chiusura programma in risposta a solleciatazione, tempo chiusura = {} us ({:7.9} ms)",getTime().duration, getTime().ms);
			}
		}

		window.clear();
		window.draw(shape);
		window.display();
	}
	return 0;
}