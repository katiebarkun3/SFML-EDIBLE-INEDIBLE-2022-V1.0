#include "inedible.h"
#include "settings.h"

std::string Inedible::inedible_file_names[] = {     
	"book.png",    "doll.png",       
	"jacket.png",  "ribbon.png"
};
Inedible::Inedible() {
	size_t num = rand() % INEDIBLE_TYPE_QTY;
	texture.loadFromFile(IMAGES_FOLDER + inedible_file_names[num]);
	sprite.setTexture(texture);
	spawn();
}
void Inedible::update() {
	sprite.move(speedx, speedy);
	sf::FloatRect g_bound = sprite.getGlobalBounds();
	if (sprite.getPosition().x < 0 - g_bound.width ||
		sprite.getPosition().x > WINDOW_WIDTH ||
		sprite.getPosition().y > WINDOW_HEIGHT + 3.f)
	{
		spawn();
	}
}
void Inedible::draw(sf::RenderWindow& window) { window.draw(sprite); }
void Inedible::spawn() {
	sf::FloatRect g_bound = sprite.getGlobalBounds();
	float x = rand() % (static_cast<size_t>(WINDOW_WIDTH) -
		static_cast<size_t>(g_bound.width));
	float y = rand() % (static_cast<size_t>(WINDOW_HEIGHT)) - WINDOW_HEIGHT;
	sprite.setPosition(x, y);
	speedx = 0.f;
	speedy = 3.f;
}
sf::FloatRect Inedible::getHitBox() { return sprite.getGlobalBounds(); }
sf::Vector2f Inedible::getPosition() { return sprite.getPosition(); }
void Inedible::setDel(bool a) { del = a; }
bool Inedible::getDel() { return del; }