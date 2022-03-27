#pragma once
#include "SFML/Graphics.hpp"

class Death {
private:
	sf::Texture texture;
	sf::Sprite sprite;
	static std::string death_file_names[];
	float speedx, speedy;
	bool del = false;
public:
	Death();
	void update();
	void draw(sf::RenderWindow&);
	void spawn();
	void notspawn();
	void setDel(bool);
	bool getDel();
	sf::FloatRect getHitBox();
	sf::Vector2f getPosition();
};