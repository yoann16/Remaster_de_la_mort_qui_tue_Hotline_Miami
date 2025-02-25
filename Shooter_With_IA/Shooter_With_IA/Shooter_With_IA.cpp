#include "Game.h"

int main()
{
    Window fenetre;
    fenetre.create(800, 600, "CA MARCHE");

    while (fenetre.isOpen())
    {
        sf::Event event;
        while (fenetre.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                fenetre.close();
        }

        fenetre.clear();
        fenetre.display();
    }

    return 0;
}
