#ifndef BOARD_H
#define BOARD_H

#include "general.h"
#include "Piece.h"

enum joueur{humain, facile, moyen, difficile};

class board
{
    public:
        board();
        virtual ~board();

        int getSizeBoard();

        void setListeJoueur(std::vector<joueur>);
        void ajouterListeJoueur(joueur, int);
        std::vector<joueur> getListeJoueur();
        void changementJoueur();

        void setJoueurActuel(int);
        int getJoueurActuel();

        void setPieceSelectionnee(Piece);
        Piece getPieceSelectionnee();

        std::vector<Piece> getListePieceBoard();
        void setListePieceBoard(Piece, int);

        std::vector<Piece> getListePieceJouable();
        void eraseFromJouable(int);
        bool isQuartoCouleur();
        bool isQuartoTaille();
        bool isQuartoForme();
        bool isQuartoProfondeur();
        bool isQuarto();
        bool isDraw();

    protected:
        int m_sizeBoard;
        std::vector<joueur> m_listeJoueur;
        int m_joueurActuel;
        Piece m_pieceSelectiionnee;
        std::vector<Piece> m_listePieceBoard;
        std::vector<Piece> m_listePieceJouable;
    private:
};

#endif // BOARD_H
