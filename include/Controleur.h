#ifndef CONTROLEUR_H
#define CONTROLEUR_H

#include "general.h"

class Controleur
{
    public:
        virtual void selectionnerPiece(board&) = 0;
        virtual bool jouerPiece(board&, Piece) = 0;
    protected:
    private:
};

class ControleurConsole : public Controleur
{
    public:
        virtual void selectionnerPiece(board&);
        virtual bool jouerPiece(board&, Piece);
};

class ControleurSFML : public Controleur
{
    public:
        virtual void selectionnerPiece(board&);
        virtual bool jouerPiece(board&, Piece);
        void setEvent(sf::Event);
        sf::Event &getEvent();
    protected :
        sf::Event m_event;
};

#endif // CONTROLEUR_H
