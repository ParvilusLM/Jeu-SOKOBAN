#include "personnage.h"


Personnage::Personnage(sf::RenderWindow &fenetre):m_fenetre(0)
{
    m_fenetre=&fenetre;
    //chargement des textures
    m_textures[P_GAUCHE].loadFromFile("donnees/perso_gauche.png");
    m_textures[P_DROITE].loadFromFile("donnees/perso_droite.png");
    m_textures[P_HAUT].loadFromFile("donnees/perso_haut.png");
    m_textures[P_BAS].loadFromFile("donnees/perso_bas.png");

    //config initial du sprite
    m_personnage.setTexture(m_textures[P_DROITE]);
    m_personnage.setOrigin(25,25);
    positionP();

    //sel
}

void Personnage::positionP()
{
    int j=0,i=0;
    for(i=0;i<14;i++)
    {
        for(j=0;j<14;j++)
        {
            float pos_x=i*TAILLE_BLOC+25;
            float pos_y=j*TAILLE_BLOC+25;

            switch(carte[i][j])
            {
            case PERSONNAGE:
                m_personnage.setPosition(pos_x,pos_y);
                break;

            default:
                break;
            }
        }
    }
}

void Personnage::deplacementP(int direction)
{
    switch(direction)
    {
    case GAUCHE:
        m_personnage.move(-m_depl_en_X,0);
        break;

    case DROITE:
        m_personnage.move(m_depl_en_X,0);
        break;

    case HAUT:
        m_personnage.move(0,-m_depl_en_Y);
        break;

    case BAS:
        m_personnage.move(0,m_depl_en_Y);
        break;

    default:
        break;

    }
    changementTextureP(direction);
}

sf::Sprite Personnage::getApparenceP()
{
    return m_personnage;
}

void Personnage::setApparenceP(sf::Vector2f apparenceP)
{
    //std::cout<<"Entree dans la fonction setApparenceP"<<std::endl;
    m_personnage.setPosition(apparenceP);
    //std::cout<<"Sortie dans la fonction setApparenceP"<<std::endl;
}

void Personnage::changementTextureP(int orientationP)
{
    switch(orientationP)
    {
    case GAUCHE:
        m_personnage.setTexture(m_textures[P_GAUCHE]);
        break;

    case DROITE:
        m_personnage.setTexture(m_textures[P_DROITE]);
        break;

    case HAUT:
        m_personnage.setTexture(m_textures[P_HAUT]);
        break;

    case BAS:
        m_personnage.setTexture(m_textures[P_BAS]);
        break;

    default:
        break;
    }
}

void Personnage::afficheP()
{
    m_fenetre->draw(m_personnage);
}

Personnage::~Personnage()
{

}


