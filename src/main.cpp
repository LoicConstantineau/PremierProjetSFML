#include <cmath>
#include <SFML/Graphics.hpp>


int main()
{
	unsigned int largeurFenetre = 1200;
	unsigned int hauteurFenetre = 800;

	sf::RenderWindow window(sf::VideoMode({largeurFenetre, hauteurFenetre}), "Cercle");
 	window.setFramerateLimit(60);

	sf::ConvexShape tete(8);
	tete.setPoint(0, sf::Vector2f(10, 10));
	tete.setPoint(1, sf::Vector2f(60, 10));
	tete.setPoint(2, sf::Vector2f(60, 60));
	tete.setPoint(3, sf::Vector2f(45, 60));
	tete.setPoint(4, sf::Vector2f(45, 80));
	tete.setPoint(5, sf::Vector2f(25, 80));
	tete.setPoint(6, sf::Vector2f(25, 60));
	tete.setPoint(7, sf::Vector2f(10, 60));
	tete.setFillColor(sf::Color::White);
	tete.setPosition({10, 10});

	sf::ConvexShape corps(4);
	sf::ConvexShape bras(4);
	sf::ConvexShape jambe(4);

	while (window.isOpen()){

		while (const std::optional event = window.pollEvent()){
      		if (event->is<sf::Event::Closed>()){
        	window.close();
      		}
		}
		window.clear();
		window.draw(tete);
		window.display();
	}
	return 0;
}


