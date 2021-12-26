#include "player.h"
#include "variables.h"
#include "bullet.h"
#include <vector>
using namespace std;
int Player::playerhealth = 3;
Player::Player() : Ship(IntRect(160, 32, 32, 32)) {
	setPosition({ Height * .5f, Height - 32.f });
}

void Player::Update(const float& dt) {
	Ship::Update(dt);
	//static vector<Bullet> bullets;
	float direction = 0.0f;
	if (Keyboard::isKeyPressed(controls[0])) {
		direction--;
	}
	if (Keyboard::isKeyPressed(controls[1])) {
		direction++;
	}
	if (getPosition().x + direction * playerspeed * dt >= 0 && getPosition().x + direction * playerspeed * dt <= Width - 32) {
		move(direction * playerspeed * dt, 0);
	}
	static float firetime = 0.0f;
	firetime -= dt;
	if (firetime <= 0 && Keyboard::isKeyPressed(controls[2])) {
		Bullet::Fire(getPosition(), false);
		firetime = 0.3f;
	}

}
