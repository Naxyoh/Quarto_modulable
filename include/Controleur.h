#ifndef CONTROLEUR_H
#define CONTROLEUR_H

#include "general.h"

class Controleur
{
    public:
        virtual void selectionnerPiece(board&) = 0; // méthode virtuelle pour selectionner une piece
        virtual void jouerPiece(board&, Piece) = 0; // methode virtuelle pour jouer une piece
};

class ControleurConsole : public Controleur // Version Console
{
    public:
        virtual void selectionnerPiece(board&);
        virtual void jouerPiece(board&, Piece);
        void restart(board&); // recommence le jeu
};

class ControleurSFML : public Controleur // Version SFML
{
    public:
        virtual void selectionnerPiece(board&);
        virtual void jouerPiece(board&, Piece);
        void restart(board&); // recommence le jeu
        void setEvent(sf::Event); // affecte un evenement
        sf::Event &getEvent(); // renvoi un evenement
    protected :
        sf::Event m_event; // evenement utilisé dans le traitement du controleur
};

#endif // CONTROLEUR_H
