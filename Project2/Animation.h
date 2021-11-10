#pragma once

class Animation{
public:
	bool isMoving;
	sf::IntRect uvRect;
	void Update(int row, float deltaTime, bool faceRight);
	Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime);

protected:
	sf::Vector2u imageCount , currentImage;
	sf::Vector2i offset, size;
	float totalTime;
	float switchTime;
};