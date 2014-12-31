#ifndef AFFICHAGE_H
#define AFFICHAGE_H

#include "general.h"

class IAffichage // Interface pour l'affichage
{
    public:
        virtual void drawBoard(board&) = 0; // m�thode virtuelle pour afficher le plateau
};

class AffichageConsole : public IAffichage // Version Console
{
    public:
        virtual void drawBoard(board&);
        void drawPieceJouable(board &); // affiche les pieces jouables
        void afficherPiece(Piece const& ); // affiche une piece
        void afficherListePiece(std::vector<Piece> const& ); // affiche un vector de piece
        void afficherPieceBoard(board ); //affiche les pieces jouees
};

class AffichageSFML : public IAffichage // Version SFML
{
    public:
        virtual void drawBoard(board&);
        void setWindow(); // cr�e la fenetre principale du jeu
        sf::RenderWindow &getMainWindow(); // renvoie la fenetre du jeu
    protected:
        sf::RenderWindow m_mainWindow; //fenetre principale du jeu
};

#endif // AFFICHAGE_H
