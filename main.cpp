#include <iostream>
#include <SFML/Graphics.hpp>
#include "Struct.h"

int main(){
	Log::Init();
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(wdta.w, wdta.h), wdta.t, sf::Style::Default, settings);

	sf::CircleShape shape(50.0f, 50);
	shape.setFillColor(sf::Color::Red);
	shape.setPosition(sf::Vector2f(100, 100));
	shape.setOutlineThickness(10);
	shape.setOutlineColor(sf::Color::Green);

	sf::RectangleShape rectangle(sf::Vector2f(200, 20));
	rectangle.setPosition(sf::Vector2f(300, 100));
	rectangle.setFillColor(sf::Color::Blue);
	
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				TIME_ITSNL(window.close());
				CORE_INFO("chiusura programma in risposta a solleciatazione, tempo chiusura = {} us ({:7.9} ms)",getTime().duration, getTime().ms);
			}
		}

		window.clear(sf::Color::Black);
		window.draw(shape);
		window.draw(rectangle);
		window.display();
	}
	return 0;
}