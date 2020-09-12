#include "Game.h"

void Game::initWindow()
{
    std::ifstream ifs("Config/window_cfg.ini");

    std::string windowTitle = "nope";
    sf::VideoMode windowSize(800, 600);
    unsigned int framerateLimit = 120;
    bool isVerticalSyncEnabled = false;

    if (ifs.is_open())
    {
        std::getline(ifs, windowTitle);
        ifs >> windowSize.width >> windowSize.height;
        ifs >> framerateLimit;
        ifs >> isVerticalSyncEnabled;
    }

    ifs.close();

    this->window = new sf::RenderWindow(windowSize, windowTitle);
    this->window->setFramerateLimit(framerateLimit);
    this->window->setVerticalSyncEnabled(isVerticalSyncEnabled);
};

Game::Game()
{
    this->initWindow();
};

Game::~Game()
{
    delete this->window;
}

//funcs.

void Game::updateEvents()
{
    sf::Event event;
    while (this->window->pollEvent(this->sfEvent))
    {
            if (this->sfEvent.type == sf::Event::Closed)
                this->window->close();
    }
}

void Game::update()
{
    this->updateEvents();
};

void Game::render()
{
    this->window->clear();
    //render sth
    this->window->display();
};

void Game::run()
{
    while (this->window->isOpen())
    {
        this->updateDt();
        this->update();
        this->render();
    }
};

void Game::updateDt()
{
    this->dt = this->dtClock.restart().asSeconds();
    system("cls");
    std::cout << this->dt;
}


