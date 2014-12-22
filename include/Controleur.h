#ifndef CONTROLEUR_H
#define CONTROLEUR_H

#include "general.h"

class Controleur
{
    public:
        virtual void selectionnerPiece(board&) = 0;
        virtual void jouerPiece(board&, Piece) = 0;
    protected:
    private:
};

class ControleurConsole : public Controleur
{
    public:
        virtual void selectionnerPiece(board&);
        virtual void jouerPiece(board&, Piece);
        void restart(board&);
};

class ControleurSFML : public Controleur
{
    public:
        virtual void selectionnerPiece(board&);
        virtual void jouerPiece(board&, Piece);
        void restart(board&);
        void setEvent(sf::Event);
        sf::Event &getEvent();
    protected :
        sf::Event m_event;
};

#endif // CONTROLEUR_H
