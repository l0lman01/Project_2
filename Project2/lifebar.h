#pragma once


class lifebar : public sf::Drawable {
	lifebar();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

};