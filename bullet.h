#pragma once
#include <SFML/Graphics.hpp>
class Bullet : public sf::Sprite {
public:
	Bullet(const sf::Vector2f& pos, const bool mode);
	static void Update(const float& dt);
	static void Render(sf::RenderWindow& window);
	static  void Fire(const sf::Vector2f& pos, const bool mode);
	bool checked;
	~Bullet() = default;
	Bullet();
	static unsigned char bulletPointer;
 protected:
	void _Update(const float& dt);
	bool _mode;
	static Bullet bullets[256];
};