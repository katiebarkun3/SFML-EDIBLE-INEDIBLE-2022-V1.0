#include "food.h"
#include "settings.h"

std::string Food::food_file_names[] = {
	"peace.png",   "burger.png",
	"orange.png",  "tomato.png"
};
Food::Food() {
	size_t num = rand() % FOOD_TYPE_QTY;
	texture.loadFromFile(IMAGES_FOLDER + food_file_names[num]);
	sprite.setTexture(texture);
	spawn();
}
void Food::update() {
	sprite.move(speedx, speedy);
	sf::FloatRect g_bound = sprite.getGlobalBounds();
	if (sprite.getPosition().x < 0 - g_bound.width ||
		sprite.getPosition().x > WINDOW_WIDTH ||
		sprite.getPosition().y > WINDOW_HEIGHT + 3.f)
	{
		spawn();
	}
}
void Food::draw(sf::RenderWindow& window) { window.draw(sprite); }
void Food::spawn() {
		sf::FloatRect g_bound = sprite.getGlobalBounds();
		float x = rand() % (static_cast<size_t>(WINDOW_WIDTH) -
			static_cast<size_t>(g_bound.width));
		float y = rand() % (static_cast<size_t>(WINDOW_HEIGHT)) - WINDOW_HEIGHT;
		sprite.setPosition(x, y);
		speedx = 0.f;
		speedy = 3.f;
		}
sf::FloatRect Food::getHitBox() { return sprite.getGlobalBounds(); }
sf::Vector2f Food::getPosition() { return sprite.getPosition(); }
void Food::setDel(bool a) { del = a; }
bool Food::getDel() { return del; }