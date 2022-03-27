#include "potion.h"
#include "settings.h"

std::string Potion::potion_file_names[] = {   
	"potionlife.png"
};
Potion::Potion() {
	size_t num = rand() % POTION_TYPE_QTY;
	texture.loadFromFile(IMAGES_FOLDER + potion_file_names[num]);
	sprite.setTexture(texture);
	spawn();
}
void Potion::update() {
	sprite.move(speedx, speedy);

}
void Potion::draw(sf::RenderWindow& window) { window.draw(sprite); }
void Potion::spawn() {
	sf::FloatRect g_bound = sprite.getGlobalBounds();
	float x = rand() % (static_cast<size_t>(WINDOW_WIDTH) -
		static_cast<size_t>(g_bound.width));
	float y = rand() % (static_cast<size_t>(WINDOW_HEIGHT)) - WINDOW_HEIGHT;
	sprite.setPosition(x, y);
	speedx = 0.f;
	speedy = 3.f;
}
void Potion::notspawn() {
	sf::FloatRect g_bound = sprite.getGlobalBounds();
	float x = rand() % (static_cast<size_t>(WINDOW_WIDTH) -
		static_cast<size_t>(g_bound.width));
	float y = rand() % (static_cast<size_t>(WINDOW_HEIGHT)) - WINDOW_HEIGHT;
	sprite.setPosition(x, y);
	speedx = 0.f;
	speedy = 0.f;
	getDel();
}
sf::FloatRect Potion::getHitBox() { return sprite.getGlobalBounds(); }
sf::Vector2f Potion::getPosition() { return sprite.getPosition(); }
void Potion::setDel(bool a) { del = a; }
bool Potion::getDel() { return del; }