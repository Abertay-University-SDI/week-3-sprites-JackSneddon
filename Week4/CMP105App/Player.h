#pragma once
#include "Framework/GameObject.h"

class Player : public GameObject
{
public:
	Player(Input* input);
	Player();
	~Player() {};
	void handleInput(float dt) override;
	void update(float dt) override;

private:
	Input* input;
};

