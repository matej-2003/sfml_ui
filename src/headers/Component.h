#pragma once

#include <SFML/Graphics.hpp>
#include <math.h>

class Component : public sf::Transformable, public sf::Drawable {
	public:
		virtual void handleEvent(const sf::Event& event) = 0;
		virtual void update(sf::Time dt) = 0;
		virtual sf::FloatRect getLocalBounds() const = 0;
		virtual sf::FloatRect getGlobalBounds() const;
		virtual void setOrigin(float x, float y);

	protected:
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;
};
