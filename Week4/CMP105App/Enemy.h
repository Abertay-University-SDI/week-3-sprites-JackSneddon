#pragma once
#include "FrameWork/GameObject.h"
class Enemy : public GameObject
{
public:
	Enemy(sf::RenderWindow* window, sf::Vector2f startingPos);
	Enemy();
	~Enemy() {};
	void update(float dt) override;
	bool inWindow();

private:
	sf::RenderWindow* window;
};

