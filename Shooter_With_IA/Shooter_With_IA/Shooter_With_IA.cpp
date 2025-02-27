#include<iostream>
#include "Window.h"

int main()
{
    // Création de la fenêtre avec des paramètres initiaux
    Window window;
    window.create(800, 600, "Test de la classe Window");

    // Configuration d'un callback pour les événements
    window.setEventCallback([](sf::Event event) {
        // Affiche des informations sur les événements reçus
        if (event.type == sf::Event::KeyPressed) {
            std::cout << "Touche appuyée: " << event.key.code << std::endl;
        }
        else if (event.type == sf::Event::MouseButtonPressed) {
            std::cout << "Clic de souris en position: ("
                << event.mouseButton.x << ", "
                << event.mouseButton.y << ")" << std::endl;
        }
        });

    // Variables pour le test
    bool fullscreenToggle = false;
    int counter = 0;
    sf::Clock clock;

    // Boucle de jeu simple
    while (window.isOpen())
    {
        // Gestion des événements
        window.handleEvents();

        // Test périodique des fonctionnalités (toutes les 2 secondes)
        if (clock.getElapsedTime().asSeconds() > 2.0f) {
            counter++;
            clock.restart();

            switch (counter % 4) {
            case 0: // Test de setSize
                std::cout << "Test: Changement de taille" << std::endl;
                window.setSize(1200, 400);
                window.setSize(800, 600);
                break;

            case 1: // Test de setTitle
                std::cout << "Test: Changement de titre" << std::endl;
                window.setTitle("Nouveau titre - Test " + std::to_string(counter));
                break;

            case 2: // Test de setFullscreen
                fullscreenToggle = !fullscreenToggle;
                std::cout << "Test: Mode plein écran - " << (fullscreenToggle ? "ON" : "OFF") << std::endl;
                window.setFullscreen(fullscreenToggle);
                break;

            case 3: // Test de getPosition
                sf::Vector2i pos = window.getPosition();
                std::cout << "Test: Position de la fenêtre - (" << pos.x << ", " << pos.y << ")" << std::endl;
                // Optionnel: déplacer la fenêtre
                window.setPosition(pos.x  50, pos.y);
                break;
            }
        }

        // Rendu simple
        window.clear();  // Efface avec la couleur d'arrière-plan

        // Ici vous pourriez dessiner des éléments si vous avez une méthode pour cela

        window.display();  // Affiche le contenu
    }

    return 0;
}
