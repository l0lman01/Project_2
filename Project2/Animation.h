#pragma once

class Animation {
public:
	bool isMoving;
	sf::IntRect uvRect;
	void Update(int row, float deltaTime, int maxImage, int minImage);
	Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime);

protected:
	sf::Vector2u currentImage;
	float totalTime;
	float switchTime;
};