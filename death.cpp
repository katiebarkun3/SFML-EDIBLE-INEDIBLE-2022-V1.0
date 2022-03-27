#include "death.h"
#include "settings.h"

std::string Death::death_file_names[] = {
	"potiondeath.png"
};
Death::Death() {
	size_t num = rand() % DEATH_TYPE_QTY;
	texture.loadFromFile(IMAGES_FOLDER + death_file_names[num]);
	sprite.setTexture(texture);
	spawn();
}
void Death::update() {
	sprite.move(speedx, speedy);
}
void Death::draw(sf::RenderWindow& window) { window.draw(sprite); }
void Death::spawn() {
	sf::FloatRect g_bound = sprite.getGlobalBounds();
	float x = rand() % (static_cast<size_t>(WINDOW_WIDTH) -
		static_cast<size_t>(g_bound.width));
	float y = rand() % (static_cast<size_t>(WINDOW_HEIGHT)) - WINDOW_HEIGHT;
	sprite.setPosition(x, y);
	speedx = 0.f;
	speedy = 3.f;
}

void Death::notspawn() {
	sf::FloatRect g_bound = sprite.getGlobalBounds();
	float x = rand() % (static_cast<size_t>(WINDOW_WIDTH) -
		static_cast<size_t>(g_bound.width));
	float y = rand() % (static_cast<size_t>(WINDOW_HEIGHT)) - WINDOW_HEIGHT;
	sprite.setPosition(x, y);
	speedx = 0.f;
	speedy = 0.f;
	getDel();
}
sf::FloatRect Death::getHitBox() { return sprite.getGlobalBounds(); }
sf::Vector2f Death::getPosition() { return sprite.getPosition(); }
void Death::setDel(bool a) { del = a; }
bool Death::getDel() { return del; }