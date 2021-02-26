#include "controleur.h"

using namespace std;

Controleur::Controleur(sf::RenderWindow &fenetre):m_fenetre(0),m_decor(0),m_info(0),m_personnage(0),m_menu(0)
{
    m_fenetre=&fenetre;

    m_decor=new Decor(*m_fenetre);
    m_info=new Info(*m_fenetre);
    m_personnage=new Personnage(*m_fenetre);
    m_menu=new Menu(*m_fenetre);

    m_tFelicitations.loadFromFile("donnees/felicit.png");
    m_sFelicitations.setTexture(m_tFelicitations);
    m_sFelicitations.setPosition(200,150);

    m_tPerdu.loadFromFile("donnees/perdu.png");
    m_sPerdu.setTexture(m_tPerdu);
    m_sPerdu.setPosition(200,150);
}


void Controleur::debutJeu()
{
    chargementNiveau(niveau-1);
    m_decor->chargementDecor();
    m_personnage->positionP();
    m_info->initInfo();
    demarrerHorl();
}


int Controleur::chargementNiveau(int noNiveau)
{
    FILE* fichier =NULL;
    char ligneFichier[NB_BLOCS_LARGEUR*NB_BLOCS_HAUTEUR+1] = {0};
    int i=0, j=0,caractereLu=0,nbNiveau=0,noLigneChoisi=0;

    fichier=fopen("donnees/niveaux.lvl","r");
    if(fichier==NULL)
        return 0;


       do
       {
           caractereLu = fgetc(fichier);
        if (caractereLu == '\n')
            nbNiveau++;
       }while(caractereLu != EOF);

       noLigneChoisi=noNiveau;

       rewind(fichier);

       while (noLigneChoisi > 0)
    {
        caractereLu = fgetc(fichier);
        if (caractereLu == '\n')
            noLigneChoisi--;
    }

    fgets(ligneFichier, 200, fichier);

    for (i = 0 ; i < NB_BLOCS_LARGEUR ; i++)
        {
            for (j = 0 ; j < NB_BLOCS_HAUTEUR ; j++)
            {
                switch (ligneFichier[(i * NB_BLOCS_LARGEUR) + j])
                {
                    case '0':
                        carte[j][i] = 0;
                        break;
                    case '1':
                        carte[j][i] = 1;
                        break;
                    case '2':
                        carte[j][i] = 2;
                        break;
                    case '3':
                        carte[j][i] = 3;
                        break;
                    case '4':
                        carte[j][i] = 4;
                        break;
                    case '5':
                        carte[j][i]=5;
                        break;
                    case '6':
                        carte[j][i]=6;
                        break;
                }
            }
        }

    fclose(fichier);
    return 1;
}


void Controleur::changementNiveau(int niveau)
{
    m_capturesJeu.clear();
    chargementNiveau(niveau);
    m_decor->chargementDecor();
    m_personnage->positionP();
}

void Controleur::gestionDeplPers(int directionP)
{
    if(!collisionPM(directionP) && !collisionPC(directionP))
    {
        m_personnage->deplacementP(directionP);
        m_info->compteurDeplacementP();
    }
    else
    {
        if(!collisionPM(directionP) && collisionPC(directionP) && deplCaissePoss(directionP))
        {

            CaptureJeu nvlCapture;
            nvlCapture.caisses=m_decor->getCaisses();
            nvlCapture.posPersonnage=m_personnage->getApparenceP().getPosition();

            m_capturesJeu.insert(m_capturesJeu.end(),nvlCapture);

            sf::Vector2f posCaisse;

            if(directionP==GAUCHE)
            {
                posCaisse.x=m_personnage->getApparenceP().getPosition().x-TAILLE_BLOC;
                posCaisse.y=m_personnage->getApparenceP().getPosition().y;
            }
            else if(directionP==DROITE)
            {
                posCaisse.x=m_personnage->getApparenceP().getPosition().x+TAILLE_BLOC;
                posCaisse.y=m_personnage->getApparenceP().getPosition().y;
            }
            else if(directionP==HAUT)
            {
                posCaisse.x=m_personnage->getApparenceP().getPosition().x;
                posCaisse.y=m_personnage->getApparenceP().getPosition().y-TAILLE_BLOC;
            }
            else
            {
                posCaisse.x=m_personnage->getApparenceP().getPosition().x;
                posCaisse.y=m_personnage->getApparenceP().getPosition().y+TAILLE_BLOC;
            }

            m_decor->deplacementCaisse(posCaisse,directionP);
            m_personnage->deplacementP(directionP);
            m_info->compteurDeplacementP();



        }


    }

}

bool Controleur::collisionPM(int directionP)
{
    bool collision=false;

    sf::Vector2f futurPosP;

    if(directionP==GAUCHE)
    {
        futurPosP.x=m_personnage->getApparenceP().getPosition().x-TAILLE_BLOC;
        futurPosP.y=m_personnage->getApparenceP().getPosition().y;
    }
    else if(directionP==DROITE)
    {
        futurPosP.x=m_personnage->getApparenceP().getPosition().x+TAILLE_BLOC;
        futurPosP.y=m_personnage->getApparenceP().getPosition().y;
    }
    else if(directionP==HAUT)
    {
        futurPosP.x=m_personnage->getApparenceP().getPosition().x;
        futurPosP.y=m_personnage->getApparenceP().getPosition().y-TAILLE_BLOC;
    }
    else
    {
        futurPosP.x=m_personnage->getApparenceP().getPosition().x;
        futurPosP.y=m_personnage->getApparenceP().getPosition().y+TAILLE_BLOC;
    }

    int compt=0;
    while(compt<m_decor->getMurs2().size())
    {
        if(m_decor->getMurs2().at(compt).getPosition().x==futurPosP.x && m_decor->getMurs2().at(compt).getPosition().y==futurPosP.y)
        {
            collision=true;
        }
        compt++;
    }

    return collision;

}

bool Controleur::collisionPC(int directionP)
{
    bool collision=false;

    sf::Vector2f futurPosP;

    if(directionP==GAUCHE)
    {
        futurPosP.x=m_personnage->getApparenceP().getPosition().x-TAILLE_BLOC;
        futurPosP.y=m_personnage->getApparenceP().getPosition().y;
    }
    else if(directionP==DROITE)
    {
        futurPosP.x=m_personnage->getApparenceP().getPosition().x+TAILLE_BLOC;
        futurPosP.y=m_personnage->getApparenceP().getPosition().y;
    }
    else if(directionP==HAUT)
    {
        futurPosP.x=m_personnage->getApparenceP().getPosition().x;
        futurPosP.y=m_personnage->getApparenceP().getPosition().y-TAILLE_BLOC;
    }
    else
    {
        futurPosP.x=m_personnage->getApparenceP().getPosition().x;
        futurPosP.y=m_personnage->getApparenceP().getPosition().y+TAILLE_BLOC;
    }

    int compt=0;
    while(compt<m_decor->getCaisses().size())
    {
        if(m_decor->getCaisses().at(compt).m_caisse.getPosition().x==futurPosP.x && m_decor->getCaisses().at(compt).m_caisse.getPosition().y==futurPosP.y)
        {
            collision=true;
        }
        compt++;
    }

    return collision;

}

        bool Controleur::deplCaissePoss(int directionP)
        {
            bool deplCPoss=false;
            bool caseVide=true;
            sf::Vector2f futurPosC;

            if(directionP==GAUCHE)
            {
                futurPosC.x=m_personnage->getApparenceP().getPosition().x-(TAILLE_BLOC*2);
                futurPosC.y=m_personnage->getApparenceP().getPosition().y;
            }
            else if(directionP==DROITE)
            {
                futurPosC.x=m_personnage->getApparenceP().getPosition().x+(TAILLE_BLOC*2);
                futurPosC.y=m_personnage->getApparenceP().getPosition().y;
            }
            else if(directionP==HAUT)
            {
                futurPosC.x=m_personnage->getApparenceP().getPosition().x;
                futurPosC.y=m_personnage->getApparenceP().getPosition().y-(TAILLE_BLOC*2);
            }
            else
            {
                futurPosC.x=m_personnage->getApparenceP().getPosition().x;
                futurPosC.y=m_personnage->getApparenceP().getPosition().y+(TAILLE_BLOC*2);
            }

            int compt=0;
            while(compt<m_decor->getCaisses().size())
            {
                if(m_decor->getCaisses().at(compt).m_caisse.getPosition().x==futurPosC.x && m_decor->getCaisses().at(compt).m_caisse.getPosition().y==futurPosC.y)
                {
                    caseVide=false;
                }
                compt++;
            }

            int compt2=0;
            while(compt2<m_decor->getMurs2().size())
            {
                if(m_decor->getMurs2().at(compt2).getPosition().x==futurPosC.x && m_decor->getMurs2().at(compt2).getPosition().y==futurPosC.y)
                {
                    caseVide=false;
                }
                compt2++;
            }

            if(caseVide)
            {
                deplCPoss=true;
            }

            return deplCPoss;

        }

                    bool Controleur::finPartie()
                    {
                        int nbCaisses=m_decor->getCaisses().size();
                        int nbCaissesOk=0;
                        int compt=0;
                        while(compt<nbCaisses)
                        {
                            if(m_decor->getCaisses().at(compt).etat==CAISSE_OK)
                            {
                                nbCaissesOk++;
                            }
                            compt++;
                        }

                        if(nbCaisses==nbCaissesOk)
                        {
                            jeuGagne=true;
                        }


                        if(m_menu->getTypeJeu()==CHRONO)
                        {
                            if(m_info->getTemps()>=120.f)
                            {
                                jeuPerdu=true;
                            }
                        }
                        else if(m_menu->getTypeJeu()==COUPSRESTREINTS)
                        {
                            if(m_info->getNbDplP()==20)
                            {
                                jeuPerdu=true;
                            }
                        }
                        else
                        {

                        }

                    }

                            void Controleur::compteurTemps()
                            {
                                m_info->gestionTemps();
                            }

                    void Controleur::demarrerHorl()
                    {
                        m_info->demarrerH();
                    }

        void Controleur::gestionDplSouris(sf::Vector2f posSouris)
        {
            m_menu->elementActif(posSouris);
        }

void Controleur::gestionSelectionSouris()
{
    m_menu->selectionElActif();
}

        void Controleur::afficheJeu()
        {
            m_decor->afficheDecor();
            m_info->afficheInfo();
            m_personnage->afficheP();
            if(jeuGagne)
            {
                m_fenetre->draw(m_sFelicitations);

            }

            if(jeuPerdu)
            {
                m_fenetre->draw(m_sPerdu);
            }
        }

                    void Controleur::afficheMenu()
                    {
                        m_menu->affficheMenu();
                    }

                            void Controleur::niveauPrecedent()
                            {
                                if(niveau != 1)
                                {
                                    niveau--;
                                    changementNiveau(niveau-1);
                                    m_info->reinitInfo();

                                }
                            }

                    void Controleur::niveauSuivant()
                    {
                        if(niveau != 20)
                        {
                            niveau++;
                            changementNiveau(niveau-1);
                            m_info->reinitInfo();

                        }
                    }

        void Controleur::rejouerPartie()
        {
            changementNiveau(niveau-1);
            m_info->reinitInfo();
        }

void Controleur::retourSurCoups()
{
    if(m_capturesJeu.size()!=0)
    {
        int indic_dern_el=m_capturesJeu.size()-1;
        m_decor->setCaisses(m_capturesJeu.at(indic_dern_el).caisses);
        m_personnage->setApparenceP(m_capturesJeu.at(indic_dern_el).posPersonnage);

        m_capturesJeu.pop_back();
    }
}

void Controleur::retourMenu()
{
    m_menu->retourMenuP();
    jeuEnCours=false;
    niveau=1;

}

Controleur::~Controleur()
{
    delete m_decor;
    delete m_info;
    delete m_personnage;
    delete m_menu;
}
