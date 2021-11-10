#include <SFML/Graphics.hpp>
#include "Animation.h"

Animation::Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime) {
	this->imageCount = imageCount;
	this->switchTime = switchTime;
	this->currentImage.x = currentImage.x;
	totalTime = 0;
	uvRect.width = 16;
	uvRect.height = 16;
};

void Animation::Update(int row, float deltaTime, bool faceRight){
	currentImage.y = row;
	totalTime += deltaTime;

	if (totalTime >= switchTime) {
		totalTime -= switchTime;
		currentImage.x++;
		
		if (currentImage.x >= imageCount.x) {
			currentImage.x = 0;
		}
	}
	
	uvRect.top = currentImage.y * uvRect.height;

	if (faceRight) {
		uvRect.left = currentImage.x * uvRect.width;
		uvRect.width = abs(uvRect.width);
	}
	else {
		uvRect.left = (currentImage.x + 2) * uvRect.width;
		uvRect.width = -abs(uvRect.width);
	}
}