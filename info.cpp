#include "info.h"


Info::Info(sf::RenderWindow &fenetre):m_fenetre(0)
{
    m_fenetre=&fenetre;
    m_tempsEcoule=0;

}

void Info::initInfo()
{
   m_etatH=EnPause;
   m_tCadre.loadFromFile("donnees/cadre.png");
   m_sCadre.setTexture(m_tCadre);
   m_sCadre.setPosition(700,0);

   m_fntTemps.loadFromFile("donnees/charlbold.ttf");
   m_fntAutre.loadFromFile("donnees/keypunc.ttf");

   m_txtTemps.setFont(m_fntTemps);
   m_txtTemps.setCharacterSize(40);
   m_txtTemps.setPosition(830,300);
   m_txtTemps.setFillColor(sf::Color::Black);
   gestionTemps();

   m_txtNiveau.setFont(m_fntAutre);
   m_txtNiveau.setCharacterSize(40);
   m_txtNiveau.setPosition(850,160);
   m_txtNiveau.setFillColor(sf::Color::Black);
   indiquerNiveau();

   m_nbDeplacementP=0;
   m_txtCompDepl.setFont(m_fntAutre);
   m_txtCompDepl.setCharacterSize(40);
   m_txtCompDepl.setPosition(830,430);
   m_txtCompDepl.setFillColor(sf::Color::Black);

   std::ostringstream m_streamTxtNbDpl;
   m_streamTxtNbDpl.str("");
   m_streamTxtNbDpl<<nbEnString(m_nbDeplacementP);
   m_txtCompDepl.setString(m_streamTxtNbDpl.str());

}

void Info::reinitInfo()
{
    m_nbDeplacementP=0;
    std::ostringstream m_streamTxtNbDpl;
    m_streamTxtNbDpl.str("");
    m_streamTxtNbDpl<<nbEnString(m_nbDeplacementP);
    m_txtCompDepl.setString(m_streamTxtNbDpl.str());
    indiquerNiveau();
    reinitialiserH();
    demarrerH();
}

void Info::reinitialiserH()
{
    m_horloge.restart();
    pauseH();
    m_tempsEcoule=0.f;
}

void Info::demarrerH()
{
    if(m_etatH !=Demarre)
    {
        m_horloge.restart();
        m_etatH=Demarre;
    }
}

void Info::pauseH()
{
    if(m_etatH !=EnPause)
    {
        m_etatH=EnPause;
        m_tempsEcoule += m_horloge.getElapsedTime().asSeconds();
    }
}

float Info::getTemps()
{
    float temps;
    if(m_etatH == EnPause)
    {
        temps=m_tempsEcoule;
    }
    else
    {
        temps= m_horloge.getElapsedTime().asSeconds() + m_tempsEcoule;
    }

    return temps;
}

int Info::getNbDplP()
{
    return m_nbDeplacementP;
}

template <class T> std::string Info::nbEnString(T nb)
{
    std::ostringstream chaineCar;
    chaineCar << nb;
    return chaineCar.str();
}

void Info::indiquerNiveau()
{
    std::ostringstream m_streamTxtNiveau;
    m_streamTxtNiveau.str("");
    m_streamTxtNiveau<<nbEnString(niveau);
    m_txtNiveau.setString(m_streamTxtNiveau.str());
}

void Info::compteurDeplacementP()
{
    m_nbDeplacementP++;
    std::ostringstream m_streamTxtNbDpl;
    m_streamTxtNbDpl.str("");
    m_streamTxtNbDpl<<nbEnString(m_nbDeplacementP);
    m_txtCompDepl.setString(m_streamTxtNbDpl.str());
}

void Info::gestionTemps()
{
    int temps=int(getTemps());
    std::ostringstream m_streamTxtTemps;
    m_streamTxtTemps.str("");
    m_streamTxtTemps<< nbEnString(temps/60) << " : "<< nbEnString(temps%60);

    m_txtTemps.setString(m_streamTxtTemps.str());
}


void Info::afficheInfo()
{
    m_fenetre->draw(m_sCadre);
    m_fenetre->draw(m_txtTemps);
    m_fenetre->draw(m_txtNiveau);
    m_fenetre->draw(m_txtCompDepl);
}



Info::~Info()
{

}
