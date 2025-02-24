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

    // Test de d�tection de cycle
    try {
        cNode.setParent(grosNode1); // Tente de cr�er un cycle
        std::cout << "ERREUR: La d�tection de cycle a �chou�!" << std::endl;
    }
    catch (const std::logic_error& e) {
        std::cout << "Test de d�tection de cycle r�ussi: " << e.what() << std::endl;
    }

    // Test de changement de parent multiple
    IComposite anotherRoot;
    node1->setParent(&anotherRoot); // D�place node1 de grosNode1 vers anotherRoot
    std::cout << "Node1 a chang� de parent" << std::endl;

    // Test de cycle profond
    IComposite* deepNode1 = new IComposite(&someRoot);
    IComposite* deepNode2 = new IComposite(deepNode1);
    try {
        someRoot.setParent(deepNode2); // Tente de cr�er un cycle profond
        std::cout << "ERREUR: La d�tection de cycle profond a �chou�!" << std::endl;
    }
    catch (const std::logic_error& e) {
        std::cout << "Test de d�tection de cycle profond r�ussi: " << e.what() << std::endl;
    }


    std::cout << "D�marrage destruction" << std::endl;
    delete deepNode1; // Ceci devrait �galement d�truire deepNode2
    std::cout << "Apr�s destruction de deepNode1" << std::endl;
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
