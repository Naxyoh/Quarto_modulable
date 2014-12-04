#ifndef BOARD_H
#define BOARD_H

#include "general.h"
#include "Piece.h"

class board
{
    public:
        board();
        virtual ~board();
        int getSizeBoard();
        std::vector<Piece> getListePieceBoard();
        void setListePieceBoard(Piece, int);
        std::vector<Piece> getListePieceJouable();
        void eraseFromJouable(int);
        bool isQuartoCouleur();
        bool isQuartoTaille();
        bool isQuartoForme();
        bool isQuartoProfondeur();
        bool isQuarto();
    protected:
        int m_sizeBoard;
        std::vector<Piece> m_listePieceBoard;
        std::vector<Piece> m_listePieceJouable;
    private:
};

#endif // BOARD_H