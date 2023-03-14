#include <stdio.h>
#include <SFML/Graphics.hpp>
#include "./headers/Component.h"
#include "./headers/Button.h"

using namespace std;

void onButtonClicked()
{
	cout << "Button clicked!" << endl;
}

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Button Example");
	Button::Ptr button = make_shared<Button>(sf::Vector2f(100.0f, 100.0f), "Click me!");

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}

			button->handleEvent(event);
		}

		window.clear(sf::Color::White);
		button->draw(window, sf::RenderStates::Default);
		window.display();
	}

	return 0;
}
