#pragma once
#include "SFML/Graphics.hpp"

class Inedible {
private:
	sf::Texture texture;
	sf::Sprite sprite;
	static std::string inedible_file_names[];
	float speedx, speedy;
	bool del = false;
public:
	Inedible();
	void update();
	void draw(sf::RenderWindow&);
	void spawn();
	void setDel(bool);
	bool getDel();
	sf::FloatRect getHitBox();
	sf::Vector2f getPosition();
};