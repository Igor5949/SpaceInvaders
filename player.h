#pragma once
#include "ship.h"
class Player : public Ship {
public:
	static int playerhealth;
	Player();
	void Update(const float& dt) override;
};