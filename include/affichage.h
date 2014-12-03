#ifndef AFFICHAGE_H
#define AFFICHAGE_H

#include "general.h"
//#include "IAffichage.h"

class IAffichage
{
    public:
        virtual void drawPieceAt(board, int) = 0;
        virtual void drawBoard(board) = 0;
    protected:
    private:
};

class AffichageConsole : public IAffichage
{
    public:
        virtual void drawPieceAt(board, int);
        virtual void drawBoard(board);
        void afficherPiece(Piece const& );
        void afficherListePiece(std::vector<Piece> const& );
        void afficherPieceBoard(board );

    protected:

    private:
};



#endif // AFFICHAGE_H
