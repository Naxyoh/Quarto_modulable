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

        void setJoueur(joueur);
        joueur getJoueur();

        void setPieceSelectionnee(Piece);
        Piece getPieceSelectionnee();

        std::vector<Piece> getListePieceBoard();
        void setListePieceBoard(Piece, int);

        std::list<int> genererPositionPossible(Piece pieceDonnee);

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
        joueur m_joueur;
        int m_joueurActuel;
        Piece m_pieceSelectiionnee;
        std::vector<Piece> m_listePieceBoard;
        std::vector<Piece> m_listePieceJouable;
    private:
};

#endif // BOARD_H
