#pragma once
#include "SFML/Graphics.hpp"

class Food {
private:
	sf::Texture texture;
	sf::Sprite sprite;
	static std::string food_file_names[];
	float speedx, speedy;
	bool del = false;
public:
	Food();
	void update();
	void draw(sf::RenderWindow&);
	void spawn();
	void setDel(bool);
	bool getDel();
	sf::FloatRect getHitBox();
	sf::Vector2f getPosition();
};