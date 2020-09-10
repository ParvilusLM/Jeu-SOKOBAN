#include "decor.h"

using namespace std;


Decor::Decor(sf::RenderWindow &fenetre):m_fenetre(0)
{
    m_fenetre=&fenetre;
    m_textures[T_MUR1].loadFromFile("donnees/mur1.png");
    m_textures[T_MUR2].loadFromFile("donnees/mur2.png");
    m_textures[T_CAISSE].loadFromFile("donnees/caisse.png");
    m_textures[T_CAISSE_OK].loadFromFile("donnees/caisse_ok.png");
    m_textures[T_OBJECTIF].loadFromFile("donnees/objectif.png");
    chargementDecor();
}

void Decor::chargementDecor()
{
    m_murs1.clear();
    m_murs2.clear();
    m_caisses.clear();
    m_objectifs.clear();

    int i=0,j=0;

    for(i=0;i<NB_BLOCS_LARGEUR;i++)
    {
        for(j=0;j<NB_BLOCS_HAUTEUR;j++)
        {
            float pos_x=i*TAILLE_BLOC+25;
            float pos_y=j*TAILLE_BLOC+25;

            switch(carte[i][j])
            {
            case MUR1:
                {
                    sf::Sprite nouvMur1;
                    nouvMur1.setOrigin(25,25);
                    nouvMur1.setPosition(pos_x,pos_y);
                    m_murs1.insert(m_murs1.end(),nouvMur1);
                }
                break;

            case CAISSE:
                {
                    Caisse nouvCaisse;
                    nouvCaisse.etat=CAISSE_NORMALE;
                    nouvCaisse.m_caisse.setOrigin(25,25);
                    nouvCaisse.m_caisse.setPosition(pos_x,pos_y);
                    m_caisses.insert(m_caisses.end(),nouvCaisse);

                }
                break;

            case OBJECTIF:
                {
                    sf::Sprite nouvObjectif;
                    nouvObjectif.setOrigin(25,25);
                    nouvObjectif.setPosition(pos_x,pos_y);
                    m_objectifs.insert(m_objectifs.end(),nouvObjectif);
                }
                break;

            case MUR2:
                {
                    sf::Sprite nouvMur;
                    nouvMur.setOrigin(25,25);
                    nouvMur.setPosition(pos_x,pos_y);
                    m_murs2.insert(m_murs2.end(),nouvMur);

                }

                break;

            case CAISSE2:
                {
                    Caisse nouvCaisse;
                    nouvCaisse.etat=CAISSE_NORMALE;
                    nouvCaisse.m_caisse.setOrigin(25,25);
                    nouvCaisse.m_caisse.setPosition(pos_x,pos_y);
                    m_caisses.insert(m_caisses.end(),nouvCaisse);

                    sf::Sprite nouvObjectif;
                    nouvObjectif.setOrigin(25,25);
                    nouvObjectif.setPosition(pos_x,pos_y);
                    m_objectifs.insert(m_objectifs.end(),nouvObjectif);
                }
                break;

            default:
                break;


            }
        }
    }



    selectionTextures();

}


void Decor::deplacementCaisse(sf::Vector2f posCaisse, int direction)
{
    sf::Vector2f nouvPosC;
    int compt=0;
    while(compt<m_caisses.size())
    {
        if(m_caisses.at(compt).m_caisse.getPosition().x==posCaisse.x && m_caisses.at(compt).m_caisse.getPosition().y==posCaisse.y)
        {
            switch(direction)
            {
            case GAUCHE:
                m_caisses.at(compt).m_caisse.move(-TAILLE_BLOC,0);
                nouvPosC.x=posCaisse.x-TAILLE_BLOC;
                nouvPosC.y=posCaisse.y;
                break;

            case DROITE:
                m_caisses.at(compt).m_caisse.move(TAILLE_BLOC,0);
                nouvPosC.x=posCaisse.x+TAILLE_BLOC;
                nouvPosC.y=posCaisse.y;
                break;

            case HAUT:
                m_caisses.at(compt).m_caisse.move(0,-TAILLE_BLOC);
                nouvPosC.x=posCaisse.x;
                nouvPosC.y=posCaisse.y-TAILLE_BLOC;
                break;

            case BAS:
                m_caisses.at(compt).m_caisse.move(0,TAILLE_BLOC);
                nouvPosC.x=posCaisse.x;
                nouvPosC.y=posCaisse.y+TAILLE_BLOC;
                break;
            }

        }
        compt++;
    }

    changementEtatCaisse(nouvPosC);
    selectionTextures();
}


void Decor::changementEtatCaisse(sf::Vector2f posCaisse)
{
    bool surObjectif=false;
    int compt=0;
    while(compt<m_caisses.size())
    {
        if(m_caisses.at(compt).m_caisse.getPosition().x==posCaisse.x && m_caisses.at(compt).m_caisse.getPosition().y==posCaisse.y)
        {
            int compt2=0;
            while(compt2<m_objectifs.size())
            {
                if(m_objectifs.at(compt2).getPosition().x==posCaisse.x && m_objectifs.at(compt2).getPosition().y==posCaisse.y)
                {
                    surObjectif=true;
                }
                compt2++;
            }

            if(surObjectif)
            {
                m_caisses.at(compt).etat=CAISSE_OK;
            }
            else
                m_caisses.at(compt).etat=CAISSE_NORMALE;
        }
        compt++;
    }
}

std::vector<sf::Sprite> Decor::getMurs2()
{
    return m_murs2;
}

std::vector<Caisse> Decor::getCaisses()
{
    return m_caisses;
}


std::vector<Caisse> Decor::setCaisses(std::vector<Caisse> caisses)
{
    //std::cout<<"Entree dans la fonction setCaisses"<<std::endl;
    m_caisses.clear();
    m_caisses=caisses;
    //std::cout<<"Sortie dans la fonction setCaisses"<<std::endl;
}

void Decor::afficheDecor()
{
    int compt=0;
    while(compt<m_murs1.size())
    {
        m_fenetre->draw(m_murs1.at(compt));
        compt++;
    }

    int compt2=0;
    while(compt2<m_murs2.size())
    {
        m_fenetre->draw(m_murs2.at(compt2));
        compt2++;
    }

    int compt3=0;
    while(compt3<m_objectifs.size())
    {
        m_fenetre->draw(m_objectifs.at(compt3));
        compt3++;
    }

    int compt4=0;
    while(compt4<m_caisses.size())
    {
        m_fenetre->draw(m_caisses.at(compt4).m_caisse);
        compt4++;
    }



}


void Decor::selectionTextures()
{
    int compt=0;
    while(compt<m_murs1.size())
    {
        m_murs1.at(compt).setTexture(m_textures[T_MUR1]);
        compt++;
    }

    int compt1=0;
    while(compt1<m_murs2.size())
    {
        m_murs2.at(compt1).setTexture(m_textures[T_MUR2]);
        compt1++;
    }

    int compt2=0;
    while(compt2<m_objectifs.size())
    {
        m_objectifs.at(compt2).setTexture(m_textures[T_OBJECTIF]);
        compt2++;
    }

    int compt3=0;
    while(compt3<m_caisses.size())
    {
        if(m_caisses.at(compt3).etat==CAISSE_NORMALE)
        {
            m_caisses.at(compt3).m_caisse.setTexture(m_textures[T_CAISSE]);
        }

        if(m_caisses.at(compt3).etat==CAISSE_OK)
        {
            m_caisses.at(compt3).m_caisse.setTexture(m_textures[T_CAISSE_OK]);
        }

        compt3++;
    }

}

Decor::~Decor()
{
    m_murs1.clear();
    m_murs2.clear();
    m_caisses.clear();
    m_objectifs.clear();

}
