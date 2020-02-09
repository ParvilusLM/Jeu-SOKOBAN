#include "menu.h"


Menu::Menu(sf::RenderWindow &fenetre):m_fenetre(0)
{
    m_fenetre=&fenetre;
    m_font.loadFromFile("donnees/forte.ttf");
    m_font2.loadFromFile("donnees/ALGER.ttf");
    m_font3.loadFromFile("donnees/rod.ttf");

    m_tFondEc.loadFromFile("donnees/cadre_menu.png");
    m_tFondEc2.loadFromFile("donnees/cadre_menu2.png");


    m_txtTypeMenu.setFont(m_font2);
    m_txtTypeMenu.setCharacterSize(35);
    m_txtTypeMenu.setFillColor(sf::Color::Black);
    m_txtTypeMenu.setPosition(355,225);


    m_txtRetour.setFont(m_font);
    m_txtRetour.setCharacterSize(33);
    m_txtRetour.setFillColor(sf::Color::Black);
    m_txtRetour.setPosition(23,35);
    m_txtRetour.setString("RETOUR");

    m_typeMenu=MenuPrincipale;
    initMenuP();
    initMenuNP();
    initMenuI();
    initMenuAp();


}


void Menu::initMenuP()
{


    m_sFondEc.setTexture(m_tFondEc);
    m_sFondEc.setPosition(0,0);

    m_txtNouvlPartie.setFont(m_font);
    m_txtNouvlPartie.setCharacterSize(40);
    m_txtNouvlPartie.setFillColor(sf::Color::Black);
    m_txtNouvlPartie.setPosition(360,340);
    m_txtNouvlPartie.setString("Nouvelle Partie");

    m_txtInstructions.setFont(m_font);
    m_txtInstructions.setCharacterSize(40);
    m_txtInstructions.setFillColor(sf::Color::Black);
    m_txtInstructions.setPosition(400,420);
    m_txtInstructions.setString("Instructions");

    m_txtAPropos.setFont(m_font);
    m_txtAPropos.setCharacterSize(40);
    m_txtAPropos.setFillColor(sf::Color::Black);
    m_txtAPropos.setPosition(420,500);
    m_txtAPropos.setString("A propos");

    m_txtQuitter.setFont(m_font);
    m_txtQuitter.setCharacterSize(40);
    m_txtQuitter.setFillColor(sf::Color::Black);
    m_txtQuitter.setPosition(440,580);
    m_txtQuitter.setString("Quitter");



}

void Menu::initMenuNP()
{
     m_txtJLibre.setFont(m_font);
     m_txtJLibre.setCharacterSize(40);
     m_txtJLibre.setFillColor(sf::Color::Black);
     m_txtJLibre.setPosition(460,340);
     m_txtJLibre.setString("Libre");

     m_txtJChrono.setFont(m_font);
     m_txtJChrono.setCharacterSize(40);
     m_txtJChrono.setFillColor(sf::Color::Black);
     m_txtJChrono.setPosition(360,460);
     m_txtJChrono.setString("Contre la montre");

     m_txtJDplRest.setFont(m_font);
     m_txtJDplRest.setCharacterSize(40);
     m_txtJDplRest.setFillColor(sf::Color::Black);
     m_txtJDplRest.setPosition(360,580);
     m_txtJDplRest.setString("Coups restreints");
}

void Menu::initMenuI()
{
    m_txtTMI.setFont(m_font3);
    m_txtTMI.setCharacterSize(40);
    m_txtTMI.setFillColor(sf::Color::Black);
    m_txtTMI.setPosition(580,340);
    m_txtTMI.setString("             REGLES DU JEU");


    m_txtMI.setFont(m_font3);
    m_txtMI.setCharacterSize(25);
    m_txtMI.setFillColor(sf::Color::Black);
    m_txtMI.setPosition(10,410);


    m_stream_txtMI.str("");
    m_stream_txtMI<<" Le joueur doit ranger des caisses sur des cases cibles. Il peut se déplacer dans les quatre\n"
                  <<"directions, et pousser une seule caisse à la fois. Une fois toutes les caisses rangées,\n"
                  <<"le niveau est réussi et le joueur passe au niveau suivant, plus difficile en général.\n\n"
                  <<"Type jeu Libre            :Le temps et le nombre de deplacements sont limites\n"
                  <<"Type jeu Contre la montre : Le temps est limite\n"
                  <<"Type jeu Depl restreints  : Le nombre de deplacement est restreint";

    m_txtMI.setString(m_stream_txtMI.str());
}

void Menu::initMenuAp()
{

}


void Menu::affficheMenu()
{
    m_fenetre->draw(m_sFondEc);

    if(m_typeMenu==MenuPrincipale)
    {
        afficheMenuP();
    }
    else if(m_typeMenu==MenuNvlPartie)
    {
        afficheMenuNP();
    }
    else if(m_typeMenu==MenuInstructions)
    {
        afficheMenuI();
    }
    else
    {
        afficheMenuAp();
    }
}

void Menu::afficheMenuP()
{
    m_fenetre->draw(m_txtNouvlPartie);
    m_fenetre->draw(m_txtInstructions);
    m_fenetre->draw(m_txtAPropos);
    m_fenetre->draw(m_txtQuitter);

    m_txtTypeMenu.setString("Menu Principale");
    m_fenetre->draw(m_txtTypeMenu);
}

void Menu::afficheMenuNP()
{
    m_fenetre->draw(m_txtJLibre);
    m_fenetre->draw(m_txtJChrono);
    m_fenetre->draw(m_txtJDplRest);
    m_fenetre->draw(m_txtRetour);

    m_txtTypeMenu.setString("       Type Jeu");
    m_fenetre->draw(m_txtTypeMenu);
}

void Menu::afficheMenuI()
{
    m_fenetre->draw(m_txtRetour);
    m_txtTypeMenu.setString("   Instructions");
    m_fenetre->draw(m_txtTypeMenu);

    m_fenetre->draw(m_txtTMI);
    m_fenetre->draw(m_txtMI);
}

void Menu::afficheMenuAp()
{
    m_fenetre->draw(m_txtRetour);
    m_txtTypeMenu.setString("       A propos");
    m_fenetre->draw(m_txtTypeMenu);
}

void Menu::quitterJeu()
{
    m_fenetre->close();
}

void Menu::elementActif(sf::Vector2f posSouris)
{

    if(m_typeMenu==MenuPrincipale)
    {
        if(collisionTS(m_txtNouvlPartie.getGlobalBounds()))
        {
            m_txtNouvlPartie.setColor(sf::Color::Red);
            m_elementActif=NP_ACTIF;
        }
        else if(collisionTS(m_txtInstructions.getGlobalBounds()))
        {
            m_txtInstructions.setColor(sf::Color::Red);
            m_elementActif=I_ACTIF;
        }
        else if(collisionTS(m_txtAPropos.getGlobalBounds()))
        {
            m_txtAPropos.setColor(sf::Color::Red);
            m_elementActif=AP_ACTIF;
        }
        else if(collisionTS(m_txtQuitter.getGlobalBounds()))
        {
            m_txtQuitter.setColor(sf::Color::Red);
            m_elementActif=Q_ACTIF;
        }
        else
        {
            m_txtNouvlPartie.setColor(sf::Color::Black);
            m_txtInstructions.setColor(sf::Color::Black);
            m_txtAPropos.setColor(sf::Color::Black);
            m_txtQuitter.setColor(sf::Color::Black);
            m_elementActif=AUCUN_EL_ACT;
        }

    }
    else if(m_typeMenu==MenuNvlPartie)
    {
        if(collisionTS(m_txtJLibre.getGlobalBounds()))
        {
            m_txtJLibre.setColor(sf::Color::Red);
            m_elementActif=JL_ACTIF;
        }
        else if(collisionTS(m_txtJChrono.getGlobalBounds()))
        {
            m_txtJChrono.setColor(sf::Color::Red);
            m_elementActif=JC_ACTIF;
        }
        else if(collisionTS(m_txtJDplRest.getGlobalBounds()))
        {
            m_txtJDplRest.setColor(sf::Color::Red);
            m_elementActif=JR_ACTIF;
        }
        else if(collisionTS(m_txtRetour.getGlobalBounds()))
        {
            m_txtRetour.setColor(sf::Color::Red);
            m_elementActif=R_ACTIF;
        }
        else
        {
            m_txtJLibre.setColor(sf::Color::Black);
            m_txtJChrono.setColor(sf::Color::Black);
            m_txtJDplRest.setColor(sf::Color::Black);
            m_txtRetour.setColor(sf::Color::Black);
            m_elementActif=AUCUN_EL_ACT;
        }
    }
    else if(m_typeMenu==MenuInstructions)
    {
        if(collisionTS(m_txtRetour.getGlobalBounds()))
        {
            m_txtRetour.setColor(sf::Color::Red);
            m_elementActif=R_ACTIF;
        }
        else
        {
            m_txtRetour.setColor(sf::Color::Black);
            m_elementActif=AUCUN_EL_ACT;
        }
    }
    else
    {
        if(collisionTS(m_txtRetour.getGlobalBounds()))
        {
            m_txtRetour.setColor(sf::Color::Red);
            m_elementActif=R_ACTIF;
        }
        else
        {
            m_txtRetour.setColor(sf::Color::Black);
            m_elementActif=AUCUN_EL_ACT;
        }
    }

}

void Menu::selectionElActif()
{
    if(m_typeMenu==MenuPrincipale)
    {
        if(m_elementActif==NP_ACTIF)
        {
            m_txtNouvlPartie.setColor(sf::Color::Black);
            m_sFondEc.setTexture(m_tFondEc2);
            m_typeMenu=MenuNvlPartie;
        }
        else if(m_elementActif==I_ACTIF)
        {
            m_txtInstructions.setColor(sf::Color::Black);
            m_sFondEc.setTexture(m_tFondEc2);
            m_typeMenu=MenuInstructions;
        }
        else if(m_elementActif==AP_ACTIF)
        {
            m_txtAPropos.setColor(sf::Color::Black);
            m_sFondEc.setTexture(m_tFondEc2);
            m_typeMenu=MenuApropos;
        }
        else if(m_elementActif==Q_ACTIF)
        {
            m_txtQuitter.setColor(sf::Color::Black);
            quitterJeu();
        }
        else
        {

        }
    }
    else if(m_typeMenu==MenuNvlPartie)
    {
        if(m_elementActif==JL_ACTIF)
        {
            m_txtJLibre.setColor(sf::Color::Black);
            jeuEnCours=true;
            m_typeJeu=LIBRE;
        }
        else if(m_elementActif==JC_ACTIF)
        {
            m_txtJChrono.setColor(sf::Color::Black);
            jeuEnCours=true;
            m_typeJeu=CHRONO;
        }
        else if(m_elementActif==JR_ACTIF)
        {
            m_txtJDplRest.setColor(sf::Color::Black);
            jeuEnCours=true;
            m_typeJeu=COUPSRESTREINTS;
        }
        else if(m_elementActif==R_ACTIF)
        {
             m_txtRetour.setColor(sf::Color::Black);
             m_sFondEc.setTexture(m_tFondEc);
             m_typeMenu=MenuPrincipale;
        }
        else
        {

        }

    }
    else if(m_typeMenu==MenuInstructions)
    {
        if(m_elementActif==R_ACTIF)
        {
            m_txtRetour.setColor(sf::Color::Black);
            m_sFondEc.setTexture(m_tFondEc);
            m_typeMenu=MenuPrincipale;
        }
        else
        {

        }

    }
    else
    {
        if(m_elementActif==R_ACTIF)
        {
            m_txtRetour.setColor(sf::Color::Black);
            m_sFondEc.setTexture(m_tFondEc);
            m_typeMenu=MenuPrincipale;
        }
        else
        {

        }
    }
}

bool Menu::collisionTS(sf::FloatRect elem)
{
    bool collision=false;
    if((elem.left<posSouris.x && elem.left+elem.width>posSouris.x) && (elem.top<posSouris.y && elem.top+elem.height>posSouris.y))
    {
        collision=true;
    }
    return collision;
}

void Menu::retourMenuP()
{
    m_typeMenu=MenuPrincipale;
    m_sFondEc.setTexture(m_tFondEc);
    m_elementActif=AUCUN_EL_ACT;
}

TypeJeu Menu::getTypeJeu()
{
    return m_typeJeu;
}

Menu::~Menu()
{

}
