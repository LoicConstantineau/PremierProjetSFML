#include <cmath>
#include <SFML/Graphics.hpp>
#include "Perso.cpp"


int main()
{
	unsigned int largeurFenetre = 1200;
	unsigned int hauteurFenetre = 800;

	sf::RenderWindow window(sf::VideoMode({largeurFenetre, hauteurFenetre}), "Cercle");
 	window.setFramerateLimit(60);

	sf::Vector2f originPerso = {300, 600};

	jeu::Objet perso = creerPerso();
	perso.setPosition(originPerso);


	while (window.isOpen()){

		while (const std::optional event = window.pollEvent()){
      		if (event->is<sf::Event::Closed>()){
        	window.close();
      		}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)){
			perso.courirDroite();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)){
			perso.courirGauche();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)){
			perso.sauter();
		}

		window.clear();
		perso.update();
		perso.move({perso.getVitesseX() * 1/60, perso.getVitesseY() * 1/60});
		window.draw(perso);
		window.display();
	}
	return 0;
}


