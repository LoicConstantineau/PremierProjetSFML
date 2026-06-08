#include "Objet.h"


namespace jeu {
Objet::Objet():
m_triangles (sf::PrimitiveType::Triangles){}

void Objet::ajouterTriangles(sf::VertexArray p_triangles){
    for (int i = 0; i < p_triangles.getVertexCount(); i+= 3){
        m_triangles.append(p_triangles[i]);
        m_triangles.append(p_triangles[i + 1]);
        m_triangles.append(p_triangles[i + 2]);
    }
}
void Objet::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    states.transform *= getTransform();
    target.draw(m_triangles, states);
}
} // Namespace jeu