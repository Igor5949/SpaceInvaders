#include "ship.h"
#include "variables.h"
using namespace sf;
using namespace std;

Ship::Ship() { _exploded = false; };
Ship::Ship(IntRect img) : Sprite() {
	_sprite = img;
	setTexture(spritesheet);
	setTextureRect(_sprite);
	_exploded = false;
}
void Ship::Update(const float& dt) {}
bool Ship::is_exploded() const
{
	return _exploded;
}
Ship::~Ship() = default;
void Ship::Explode() {
	setTextureRect(IntRect(128, 32, 32, 32));
	//aliensnum--;
	_exploded = true;
	//setTextureRect(IntRect(0, 0, 0, 0));
}



