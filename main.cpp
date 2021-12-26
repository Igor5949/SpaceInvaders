#include "ship.h"
#include"player.h"
#include "Alien.h"
#include "bullet.h"
#include "variables.h"
#include <vector>
#include <iostream>
#include <string>
using namespace std;
Texture spritesheet;
RenderWindow window(VideoMode(Width, Height), "Space Invadors");
Player* player = new Player();
vector<Ship*> ships;
Font font;
void Load() {
	if (!spritesheet.loadFromFile("sprites.png")) {
		cerr<< "Failed to load spritesheet!" << std::endl;
	}
	for (int i = 0; i < aliens_rows; i++) {
		auto rect = IntRect(0, 0, 32, 32);
		for (int j = 0; j < aliens_columns; j++){

			Vector2f pos = { 100+j*33.f, 16+25.f*i };
			Alien* alien = new Alien(rect, pos);
			ships.push_back(alien);
		}
	}
}

void Render() {
	window.clear();
	Text txt("", font, 20);
	txt.setStyle(sf::Text::Bold);
	txt.setString("HP: " + to_string(player->playerhealth) +"  left: " + to_string(Alien::aliensnum));
	txt.setPosition(0, 0);
	for (const auto s : ships) {
		window.draw(*s);
	}
	window.draw(*player);
	window.draw(txt);
	Bullet::Render(window);
	window.display();
}

void Update(double dt) {
	for (auto& s : ships) {
		s->Update(dt);
	}
	Bullet::Update(dt);
	player->Update(dt);
}

int main() {
	window.setVerticalSyncEnabled(true);
	Load();
	Text text("", font, 20);
	font.loadFromFile("GorgeousPixel.ttf");
	//text.setColor(Color::White);
	text.setStyle(sf::Text::Bold | sf::Text::Underlined);
	text.setPosition(Width / 2 - 50,Height/2);
	while (window.isOpen())
	{
		if (player->playerhealth > 0 && Alien::aliensnum > 0) {
			Event event;
			while (window.pollEvent(event))
			{
				if (event.type == Event::Closed)
					window.close();
			}
			static sf::Clock clock1;
			const float dt = clock1.restart().asSeconds();
			Render();
			Update(dt);
		}
		else {
			if (Alien::aliensnum == 0) {
				text.setString("You win");
			}
			else {
				text.setString("You lost");
			}
			window.clear();
			window.draw(text);
			window.display();
			Event event;
			while (window.pollEvent(event))
			{
				if (event.type == Event::Closed)
					window.close();
			}

		}
	}
}