#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	window->setMouseCursorVisible(false);
	// initialise game objects
	texture.loadFromFile("gfx/Mushroom.png");
	goomba.loadFromFile("gfx/Goomba.png");
	sonic.loadFromFile("gfx/sonic.png");
	bg.loadFromFile("gfx/Level1_1.png");
	glove.loadFromFile("gfx/icon.png");

	cursor.setTexture(&glove);
	cursor.setSize({ 16, 16 });

	background.setTexture(&bg);
	background.setSize({11038,675});

	player = Player(input);
	player.setTexture(&texture);
	player.setSize(sf::Vector2f(60, 60));
	player.setPosition(100, 100);

	enemy = Enemy(window, { 200, 200 });
	enemy.setTexture(&goomba);
	enemy.setSize(sf::Vector2f(60, 60));

	evilEnemy = Enemy(window, { 500, 500 });
	evilEnemy.setTexture(&sonic);
	evilEnemy.setSize(sf::Vector2f(60, 60));

	view = sf::View(sf::Vector2f(window->getSize().x, window->getSize().y)/2.f, sf::Vector2f(window->getSize().x, window->getSize().y));
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	// Close window on Escape pressed.
	if (input->isKeyDown(sf::Keyboard::Escape))
	{
		window->close();
	}
	player.handleInput(dt);
}

// Update game objects
void Level::update(float dt)
{
	const sf::Vector2f camPos = view.getCenter();
	sf::Vector2f lerp = camPos + (player.getPosition() - camPos) * dt * 0.95f;
	lerp.y = window->getSize().y/2;
	lerp.x = (lerp.x < 0) ? 0 : lerp.x;
	lerp.x = (lerp.x > 11038) ? 11038 : lerp.x;
	view.setCenter(lerp);

	cursor.setPosition(window->mapPixelToCoords(sf::Vector2i(input->getMouseX(), input->getMouseY())));
	player.update(dt);
	enemy.update(dt);
	evilEnemy.update(dt);
}

// Render level
void Level::render()
{
	beginDraw();

	//window->draw(testSprite);
	window->setView(view);
	window->draw(background);
	window->draw(player);
	window->draw(enemy);
	window->draw(evilEnemy);
	window->draw(cursor);
	endDraw();
}
