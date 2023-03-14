#pragma once

#include <iostream>
#include <functional>
#include <memory>
#include "Component.h"

using namespace std;

class Button : public Component {
	public:
		typedef shared_ptr<Button> Ptr;
		typedef function<void()> Callback;

		Button();
		Button(const sf::Vector2f& position, const string& text);
		void setCallback(Callback callback);
		void setText(const string& text);
		void setToggle(bool flag);
		virtual void handleEvent(const sf::Event& event) override;
		virtual void update(sf::Time dt) override;
		virtual sf::FloatRect getLocalBounds() const override;
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	private:
		sf::RectangleShape m_shape;
		sf::Text m_text;
		sf::Font m_font;
		sf::RectangleShape m_background;
		sf::Color m_textColor;
		bool m_isToggle;
		Callback m_callback;
};
