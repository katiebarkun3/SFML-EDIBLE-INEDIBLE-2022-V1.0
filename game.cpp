#include "game.h"
#include "settings.h"
#include <iostream>

Game::Game():
	window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT),
		WINDOW_TITLE,
		sf::Style::Titlebar | sf::Style::Close),
	splash_screen(IMAGES_FOLDER + SPLASH_FILE_NAME),
	rules_screen(IMAGES_FOLDER + RULES_SCREEN),
	back(IMAGES_FOLDER + BACKGROUND_FILE_NAME),
	player_hp("images/kenvector_future.ttf", 24, 480, 5, sf::Color::Yellow),
	score_text("images/kenvector_future.ttf", 24, 10, 5, sf::Color::Yellow),
	final_score_text("images/kenvector_future.ttf", 40, 70, 550, sf::Color(128, 0, 0)),
	game_over_screen(IMAGES_FOLDER + GAME_OVER_FILE_NAME)
      {
	window.setVerticalSyncEnabled(true);
	for (size_t i = 0; i < FOODS_QTY; i++) {
		Food* food = new Food();
		foods.push_back(food);
	}
	for (size_t i = 0; i < INEDIBLES_QTY; i++) {
		Inedible* inedible = new Inedible();
		inedibles.push_back(inedible);
	}
}

void Game::play() {
	while (window.isOpen()) {
		check_events();
		update();
		draw();
		check_collisions();
	}
}

void Game::check_events() {
	sf::Event event;
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			window.close();
		}
		if (event.type == sf::Event::KeyPressed) {
			if (game_state == INTRO && event.key.code == sf::Keyboard::Space) {
				game_state = RULES;
			}
			if (game_state == RULES && event.key.code == sf::Keyboard::Num1) {
				game_state = PLAY;
			}
		}
	}
}
	
void Game::update() {
	size_t num = 10;
	size_t numdeath = 34;
	sf::Time now_potion = potion_clock.getElapsedTime();
	sf::Time now_death = death_clock.getElapsedTime();
	switch (game_state) {
	case INTRO:
		break;
	case RULES:
		break;
	case PLAY:
		player.update();
		for (size_t i = 0; i < FOODS_QTY; i++) {
			foods[i]->update();
		}
		for (size_t i = 0; i < INEDIBLES_QTY; i++) {
			inedibles[i]->update();
		}
		if (now_potion.asSeconds() > num) {
			potion_clock.restart();
			Potion* potion = new Potion();
			potions.push_back(potion);
		}
		for (auto i = potions.begin(); i != potions.end(); i++) {
			(*i)->update();
		}
		if (now_death.asSeconds() > numdeath) {
			death_clock.restart();
			Death* death = new Death();
			deaths.push_back(death);
		}
    	for (auto i = deaths.begin(); i != deaths.end(); i++) {
			(*i)->update();	
		}
		player_hp.update("HP: " + std::to_string(player.getHp()));
		score_text.update("Score: " + std::to_string(score));
		if (player.getHp() <= 0) {
			game_state = GAME_OVER;
		}
		break;
	case GAME_OVER:
		final_score_text.update("Your score was: " + std::to_string(score));
		break;
	}
}

void Game::draw() {
	switch (game_state) {
	case INTRO:
		window.clear(sf::Color::White);
		window.draw(splash_screen.getSprite());
		break;
	case RULES:
		window.clear(sf::Color(150, 150, 150));
		window.draw(rules_screen.getSprite());
		break;
	case PLAY:
		window.clear(sf::Color(150, 150, 150));
		window.draw(back.getSprite());
		player.draw(window);
		for (size_t i = 0; i < FOODS_QTY; i++) {
			foods[i]->draw(window);
		}
		for (size_t i = 0; i < INEDIBLES_QTY; i++) {
			inedibles[i]->draw(window);
		}
		for (auto i = potions.begin(); i != potions.end(); i++) {
			(*i)->draw(window);
		}
		
		for (auto i = deaths.begin(); i != deaths.end(); i++) {
			(*i)->draw(window);
		}
			window.draw( player_hp.getText());
			window.draw(score_text.getText());
		break;
	case GAME_OVER:
		window.clear(sf::Color(150, 150, 150));
		window.draw(game_over_screen.getSprite());
		window.draw(final_score_text.getText());
		break;
	}
	window.display();
}

void Game::check_collisions() {
	for (auto iter = foods.begin(); iter != foods.end(); iter++) {
		if (player.getHitBox().intersects((*iter)->getHitBox())) {
			(*iter)->spawn();
			player.increaseHp(2);
			score += 1;
		}
		if ((*iter)->getPosition().y > WINDOW_HEIGHT) {
			player.decreaseHp(6);
		}
	}
	for (auto iter = inedibles.begin(); iter != inedibles.end(); iter++) {
		if (player.getHitBox().intersects((*iter)->getHitBox())) {
			(*iter)->spawn();
			player.decreaseHp(4);
		}
	}
	for (auto iter = potions.begin(); iter != potions.end(); iter++) {
		if (player.getHitBox().intersects((*iter)->getHitBox())) {
		(*iter)->notspawn();
			player.increaseHp(10);
			score += 10;
		}
	}
	for (auto iter = deaths.begin(); iter != deaths.end(); iter++) {
		if (player.getHitBox().intersects((*iter)->getHitBox())) {
			(*iter)->notspawn();
			player.decreaseHp(50);
			score -= 40;
		}
	}
}