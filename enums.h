#pragma once

enum
{
    P_GAUCHE,
    P_DROITE,
    P_HAUT,
    P_BAS
};


enum
{
    VIDE,
    MUR1,
    CAISSE,
    OBJECTIF,
    PERSONNAGE,
    MUR2,
    CAISSE2
};

enum
{
    CAISSE_NORMALE,
    CAISSE_OK
};


enum
{
    T_MUR1,
    T_MUR2,
    T_CAISSE,
    T_CAISSE_OK,
    T_OBJECTIF
};

enum
{
    GAUCHE,
    DROITE,
    HAUT,
    BAS
};

enum EtatH
{
    Demarre,
    EnPause
};

enum TypeMenu
{
    MenuPrincipale,
    MenuNvlPartie,
    MenuInstructions,
    MenuApropos
};

enum TypeJeu
{
    LIBRE,
    CHRONO,
    COUPSRESTREINTS
};

enum
{
    AUCUN_EL_ACT,
    NP_ACTIF,
    I_ACTIF,
    AP_ACTIF,
    Q_ACTIF,
    JL_ACTIF,
    JC_ACTIF,
    JR_ACTIF,
    R_ACTIF
};
