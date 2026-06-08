#include <SFML/Graphics.hpp>

namespace jeu {
class Objet : public sf::Drawable, public sf::Transformable{
public:
    Objet();
    ~Objet() override = default;

    void ajouterTriangles(sf::VertexArray p_triangles);
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
    sf::VertexArray m_triangles;

}; // Classe Objet
} //Namespace jeu