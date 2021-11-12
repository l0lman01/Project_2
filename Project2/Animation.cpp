#include <SFML/Graphics.hpp>
#include "Animation.h"

Animation::Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime) {
	this->switchTime = switchTime;
	totalTime = 0;
	currentImage.x = 3;
	uvRect.width = 16;
	uvRect.height = 16;
};

void Animation::Update(int row, float deltaTime, int minImage, int maxImage){
	currentImage.y = row; //Directions en ligne
	totalTime += deltaTime;

	if (totalTime >= switchTime) {
		totalTime -= switchTime;
		currentImage.x++;
		
		if (currentImage.x >= maxImage){
			currentImage.x = minImage;
		}
	}
	uvRect.top = currentImage.y * uvRect.height;
	uvRect.left = currentImage.x * uvRect.width;
}