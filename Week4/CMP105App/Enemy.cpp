#include "Enemy.h"

Enemy::Enemy(sf::RenderWindow* window, sf::Vector2f startingPos)
{
	this->window = window;
	setPosition(startingPos);
	setVelocity({ 500,500 });
}

Enemy::Enemy()
{
}

void Enemy::update(float dt)
{
	setPosition(getPosition() + velocity * dt);

	if (inWindow())
	{
		velocity = {-velocity.y, velocity.x};
	}
}

bool Enemy::inWindow()
{
	sf::FloatRect r = getGlobalBounds();
	sf::Vector2f w = sf::Vector2f(window->getSize().x, window->getSize().y);
	
	return (r.top < 0 || r.left <0 || r.top + r.height > w.y || r.left + r.width > w.x);
}
