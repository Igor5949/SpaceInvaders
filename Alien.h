#pragma once
#include "ship.h"
class Alien : public Ship {
public:
	static bool direction;
	float fadetime;
	static float speed;
	static int aliensnum;
	Alien(IntRect img, Vector2f pos);
	Alien();
	void Update(const float& dt) override;
	void Explode()override;
};
