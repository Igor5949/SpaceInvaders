#include "Alien.h"
#include "variables.h"
bool Alien::direction = 1.0f;
float Alien::speed = 100.f;
int Alien::aliensnum = aliens_columns * aliens_rows;
Alien::Alien() : Ship() {}
Alien::Alien(IntRect img, Vector2f pos) : Ship(img) {
	setOrigin(16, 16);
	setPosition(pos);
	fadetime = 0.3f;
}

void Alien::Update(const float& dt) {
	Ship::Update(dt);
	move(dt * (direction ? 1.0f : -1.0f) * speed, 0);
	if (((direction && getPosition().x > Width - 16) ||
		(!direction && getPosition().x < 16)) && !is_exploded()) {
		direction = !direction;
		for (int i = 0; i < ships.size(); i++) {
			ships[i]->move(0, 24);
		}
	}
	if (is_exploded()) {
		fadetime -= dt;
		if (fadetime < 0) {
			setTextureRect(IntRect(0, 0, 0, 0));
			//fadetime = 1.0f;
		}
	}
	static float firetime = 0.0f;
	firetime -= dt;
	if(!is_exploded() && firetime <= 0 && rand() % 100 == 0) {
		Bullet::Fire(getPosition(), true);
		firetime = 4.0f + (rand() % 60);
	}

}

void Alien::Explode()
{
	Ship::Explode();
	aliensnum--;
}
