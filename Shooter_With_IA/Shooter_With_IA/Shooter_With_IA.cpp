#include <SFML/Graphics.hpp>

#include "IComposite.h"
#include "ILeaf.h"
int main()
{
    IComposite cNode;

    auto* grosNode1 = new IComposite(&cNode);
    auto* node1 = new ILeaf{ grosNode1 };
    auto* node2 = new ILeaf{ grosNode1 };

    auto* grosNode2 = new IComposite(&cNode);
    auto* node12 = new ILeaf{ grosNode2 };
    auto* node22 = new ILeaf{ grosNode2 };

    cNode.display();

    IComposite someRoot;
    grosNode2->setParent(&someRoot);

    // Test de détection de cycle
    try {
        cNode.setParent(grosNode1); // Tente de créer un cycle
        std::cout << "ERREUR: La détection de cycle a échoué!" << std::endl;
    }
    catch (const std::logic_error& e) {
        std::cout << "Test de détection de cycle réussi: " << e.what() << std::endl;
    }

    // Test de changement de parent multiple
    IComposite anotherRoot;
    node1->setParent(&anotherRoot); // Déplace node1 de grosNode1 vers anotherRoot
    std::cout << "Node1 a changé de parent" << std::endl;

    // Test de cycle profond
    IComposite* deepNode1 = new IComposite(&someRoot);
    IComposite* deepNode2 = new IComposite(deepNode1);
    try {
        someRoot.setParent(deepNode2); // Tente de créer un cycle profond
        std::cout << "ERREUR: La détection de cycle profond a échoué!" << std::endl;
    }
    catch (const std::logic_error& e) {
        std::cout << "Test de détection de cycle profond réussi: " << e.what() << std::endl;
    }


    std::cout << "Démarrage destruction" << std::endl;
    delete deepNode1; // Ceci devrait également détruire deepNode2
    std::cout << "Après destruction de deepNode1" << std::endl;
}





//int main()
//{
//    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
//    sf::CircleShape shape(100.f);
//    shape.setFillColor(sf::Color::Green);
//
//    while (window.isOpen())
//    {
//        sf::Event event;
//        while (window.pollEvent(event))
//        {
//            if (event.type == sf::Event::Closed)
//                window.close();
//        }
//
//        window.clear();
//        window.draw(shape);
//        window.display();
//    }
//
//    return 0;
//}
