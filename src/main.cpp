#include <cmath>
#include <SFML/Graphics.hpp>
#include "Perso.cpp"


int main()
{
	unsigned int largeurFenetre = 1200;
	unsigned int hauteurFenetre = 800;

	sf::RenderWindow window(sf::VideoMode({largeurFenetre, hauteurFenetre}), "Cercle");
 	window.setFramerateLimit(60);

	sf::Vector2f originPerso = {300, 300};
	float vitesseDeplacement = 10;

	jeu::Objet perso = creerPerso();


	while (window.isOpen()){

		while (const std::optional event = window.pollEvent()){
      		if (event->is<sf::Event::Closed>()){
        	window.close();
      		}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)){
			perso.move({vitesseDeplacement, 0});
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)){
			perso.move({-vitesseDeplacement, 0});
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)){
			perso.move({0, -vitesseDeplacement});
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)){
			perso.move({0, vitesseDeplacement});
		}

		window.clear();
		window.draw(perso);
		window.display();
	}
	return 0;
}


