#include "Player.h"

Player::Player(Input* input)
{
	this->input = input;
}

Player::Player()
{
	input = nullptr;
}

void Player::handleInput(float dt)
{
	sf::Vector2f v;
	float speed = 500;
	v.y += input->isKeyDown(sf::Keyboard::W) ? -speed : 0;
	v.y += input->isKeyDown(sf::Keyboard::S) ? speed : 0;
	v.x += input->isKeyDown(sf::Keyboard::A) ? -speed : 0;
	v.x += input->isKeyDown(sf::Keyboard::D) ? speed : 0;

	setVelocity(v*dt);
}

void Player::update(float dt)
{
	setPosition(getPosition() + velocity);
}
