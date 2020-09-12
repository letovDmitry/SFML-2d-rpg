#ifndef GAME_H
#define GAME_H
#include"State.h"




class Game
{
private:
	sf::RenderWindow *window;
	sf::Event sfEvent;

	sf::Clock dtClock;
	float dt;

	void initWindow();
public:
	Game();
	virtual ~Game();
	void updateDt();
	void updateEvents();
	void update();
	void render();
	void run();
};

#endif

