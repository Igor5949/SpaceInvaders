#include "bullet.h"
#include "variables.h"
#include <iostream>
using namespace std;
unsigned char Bullet::bulletPointer = 0;
Bullet Bullet::bullets[256] = {};
void Bullet::Update(const float& dt)
{
    for (auto &i:bullets) {
        i._Update(dt);
    }
}

void Bullet::Render(RenderWindow& window)
{
    for (auto i : bullets) {
        window.draw(i);
    }
}

void Bullet::Fire(const Vector2f& pos, const bool mode)
{
    bullets[++bulletPointer] = Bullet(pos, mode);
}

Bullet::Bullet(const Vector2f& pos, const bool mode) : Sprite() {
	setPosition(pos);
    setTexture(spritesheet);
    checked = 0;
    if (!mode) {
        setTextureRect(IntRect(64, 32, 32, 32));
    }
    else {
        setTextureRect(IntRect(32, 32, 32, 32));
    }
	_mode = mode;
}
void Bullet:: _Update(const float& dt) {
	if (getPosition().y < -32 || getPosition().y > Height + 32) {
		return;
	}
    else {
        move(0, dt * 200.0f * (_mode ? 1.0f : -1.0f));
        const FloatRect boundingBox = getGlobalBounds();
        for (auto s : ships) {
            if (_mode) {
                continue;
            }
            if (!s->is_exploded() &&
                s->getGlobalBounds().intersects(boundingBox)) {
                s->Explode();
                setPosition(-100, -100);
                return;
            }
        }
       
        if (player->getGlobalBounds().intersects(boundingBox) && _mode && !checked) {
            player->playerhealth--;
            checked = 1;
            setTextureRect(IntRect(0, 0, 0, 0));
        }
        
    }

}
Bullet::Bullet()
{
}
;
