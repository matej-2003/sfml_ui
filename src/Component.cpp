#include "./headers/Component.h"

sf::FloatRect Component::getGlobalBounds() const {
	return getTransform().transformRect(getLocalBounds());
}

void Component::setOrigin(float x, float y) {
	sf::Transformable::setOrigin(x, y);
}
