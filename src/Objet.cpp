#include "Objet.h"


namespace jeu {
Objet::Objet():
m_triangles(sf::PrimitiveType::Triangles),
m_vitesseX(0), m_vitesseY(0),
m_gravite(980),
m_forcesX(0), m_forcesY(-m_gravite),
m_parTerre(false),
m_masse(10),
m_coursADroite(false),
m_coursAGauche(false),
m_courrait(false)
{}

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

bool Objet::coursADroite(){
    return m_coursADroite;
}
bool Objet::coursAGauche(){
    return m_coursAGauche;
}

void Objet::courirDroite(){
    m_coursADroite = true;
}
void Objet::courirGauche(){
    m_coursAGauche = true;
}


float Objet::getVitesseDeplacement() const{
    return m_vitesseDeplacement;
}
void Objet::asgVitesseDeplacement(float p_vitesse){
    m_vitesseDeplacement = p_vitesse;
}

float Objet::getForcesX() const{
    return m_forcesX;
}
void Objet::asgForcesX(float p_force){
    m_forcesX = p_force;
}
float Objet::getForcesY() const{
    return m_forcesY;
}
void Objet::asgForcesY(float p_force){
    m_forcesY = p_force;
}

float Objet::getVitesseX() const{
    return m_vitesseX;
}
void Objet::asgVitesseX(float p_vitesse){
    m_vitesseX = p_vitesse;
}

float Objet::getVitesseY() const{
    return m_vitesseY;
}
void Objet::asgVitesseY(float p_vitesse){
    m_vitesseY = p_vitesse;
}

void Objet::sauter(){
    m_vitesseY = 2000;
}

void Objet::update(){
    m_vitesseX += m_forcesX/m_masse;
    m_vitesseY -= m_forcesY/m_masse;

    if (this->getPosition().y >= 600){
        m_parTerre = true;
    }
    if (m_parTerre && m_vitesseY >= 0){
        m_vitesseY = 0;
    }

    if (m_coursADroite && !m_courrait){
        m_vitesseX += 400;
    }
    if (m_coursAGauche && !m_courrait){
        m_vitesseX -= 400;
    }
    if (m_coursADroite && m_courrait){
        m_vitesseX -= 400;
    }
    if (m_coursAGauche && m_courrait){
        m_vitesseX += 400;
    }

    if ((m_coursADroite || m_coursAGauche) && !m_courrait){
        m_courrait = true;
    }
    if (!(m_coursADroite || m_coursAGauche) && m_courrait){
        m_courrait = false;
    }
}

} // Namespace jeu