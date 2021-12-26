// заголовочный файл для абстрактного класса корбаля
// будет использоваться как родительский класс для Пришельца и игрока
#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
class Ship : public Sprite {
protected:
	IntRect _sprite;
	Ship();
	bool _exploded;
public:
	explicit Ship(IntRect img);
	virtual ~Ship() = 0;
	virtual void Update(const float& dt);
	bool is_exploded() const;
	virtual void Explode();
};

