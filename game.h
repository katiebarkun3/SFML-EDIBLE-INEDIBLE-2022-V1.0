#pragma once
#include "SFML/Graphics.hpp"
#include "splash.h"
#include "player.h"
#include "food.h"
#include "text.h"
#include "inedible.h"
#include "potion.h"
#include "death.h"
#include <list>

class Game {
public:
	enum GameState { INTRO, RULES, PLAY, GAME_OVER };
	Game();
	void play();
private:
	sf::RenderWindow window;
	GameState game_state { INTRO };
	Player player;
	std::vector <Food*> foods;
	std::vector <Inedible*> inedibles;
	std::list <Potion*> potions;
	std::list <Death*> deaths;
	sf::Clock potion_clock;
	sf::Clock death_clock;
	SplashScreen splash_screen, game_over_screen, rules_screen;
	SplashScreen back;
	TextObject player_hp;
	TextObject score_text;
	TextObject final_score_text;
	size_t score = 0;
	void check_events();
	void update();
	void draw();
	void check_collisions();
};