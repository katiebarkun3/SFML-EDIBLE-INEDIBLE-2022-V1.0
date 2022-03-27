#pragma once
#include "SFML/Graphics.hpp"

class Potion {
private:
	sf::Texture texture;
	sf::Sprite sprite;
	static std::string potion_file_names[];
	float speedx, speedy;
	bool del = false;
public:
	Potion();
	void update();
	void draw(sf::RenderWindow&);
	void spawn();
	void notspawn();
	void setDel(bool);
	bool getDel();
	sf::FloatRect getHitBox();
	sf::Vector2f getPosition();
};