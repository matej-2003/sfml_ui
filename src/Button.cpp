#include "./headers/Button.h"

Button::Button() : m_callback(), m_isToggle(false) {
	this->m_shape.setFillColor(sf::Color::Blue);
	this->m_shape.setOutlineThickness(1);
	this->m_shape.setOutlineColor(sf::Color::Black);

	// m_text.setFont(/* your font */);
	this->m_text.setCharacterSize(20);
	this->m_text.setFillColor(sf::Color::Black);
}

Button::Button(const sf::Vector2f& position, const std::string& text) : Component() {
	// Default values for other member variables
	this->setPosition(position);

    if (!this->m_font.loadFromFile("arial.ttf"))
    {
        std::cerr << "Failed to load font file" << std::endl;
    }
    this->m_text.setFont(this->m_font);
	this->m_text.setString(sf::String(text));

	this->m_background.setFillColor(sf::Color::Blue);
	this->m_background.setOutlineColor(sf::Color::Black);
	this->m_background.setOutlineThickness(2.0f);

	this->m_textColor = sf::Color::Black;
	this->m_text.setColor(this->m_textColor);

	// update();
}


void Button::setCallback(Callback callback) {
	m_callback = callback;
}

void Button::setText(const string& text) {
	this->m_text.setString(text);
	// Center the text inside the button
	sf::FloatRect bounds = this->m_text.getLocalBounds();
	this->m_text.setOrigin(round(bounds.left + bounds.width / 2.0f), round(bounds.top + bounds.height / 2.0f));
}

void Button::setToggle(bool flag) {
	this->m_isToggle = flag;
}

void Button::handleEvent(const sf::Event& event) {
	if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
		if (this->getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
			if (this->m_callback)
				this->m_callback();
			if (this->m_isToggle)
				this->m_shape.setFillColor(sf::Color(192, 192, 192));
		}
	}
}

void Button::update(sf::Time dt) {
	// No update necessary
}

sf::FloatRect Button::getLocalBounds() const {
	return this->m_shape.getLocalBounds();
}

void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	states.transform *= this->getTransform();

	target.draw(this->m_background);
	target.draw(this->m_shape);
	target.draw(this->m_text);
}
