#include <cmath>
#include <SFML/Graphics.hpp>



int main()
{
	unsigned int largeurFenetre = 1200;
	unsigned int hauteurFenetre = 800;

	sf::RenderWindow window(sf::VideoMode({largeurFenetre, hauteurFenetre}), "Cercle");
 	window.setFramerateLimit(60);

	while (window.isOpen()){

		while (const std::optional event = window.pollEvent()){
      		if (event->is<sf::Event::Closed>()){
        	window.close();
      		}
		}
		window.clear();
		window.display();
	}
	return 0;
}


