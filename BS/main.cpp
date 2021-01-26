#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>
#include "Menu.h"
#include "Menu.cpp"
using namespace std;

int main() {
    //Properties

    setlocale(LC_ALL, "");
    sf::RenderWindow W(sf::VideoMode(800, 600, 32), "Battleship");
    W.setActive(true);

    W.setFramerateLimit(60);
    int horizontal = sf::VideoMode::getDesktopMode().width/2 - 400;
    int vertical = sf::VideoMode::getDesktopMode().height/2 - 300;
    W.setPosition(sf::Vector2i(horizontal, vertical));
    sf::Event Event;

    Menu menu(W.getSize().x, W.getSize().y);

    //Main Loop
    while (W.isOpen()) {
        while (W.pollEvent(Event))
        {
			switch (Event.type)
			{
				case sf::Event::KeyReleased:
					switch (Event.key.code)
					{
						case sf::Keyboard::Up:
							menu.MoveUp();
							break;

						case sf::Keyboard::Down:
							menu.MoveDown();
							break;

						case sf::Keyboard::Return:
							switch (menu.GetPressedItem())
							{
								case 0:
									std::cout << "Play button has been pressed" << std::endl;
									break;
								case 1:
									std::cout << "Option button has been pressed" << std::endl;
									break;
								case 2:
                                    std::cout << "Multiplayer button has been pressed" << std::endl;
                                    break;
								case 3:
									W.close();
									break;
							}

							break;
					}

					break;
				case sf::Event::Closed:
					W.close();

					break;

				}
        }



        W.clear();
		menu.draw(W);
        W.display();
    }

    system("pause");
}

