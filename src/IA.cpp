#include "general.h"

IA::IA() : m_level(0)
{
    //ctor
}

IA::~IA()
{
    //dtor
}

void IA::setLevel(int level)
{
    m_level = level;
}

int IA::getLevel()
{
    return m_level;
}

void IA::calcJoue(board& myBoard, Piece pieceAJouer)
{
    if(m_level == 0) // au niveau 0 l'IA joue de facon aléatoire
    {
        int pos = -1;
        do
        {
           pos = rand() % 16;
        }
        while (myBoard.getListePieceBoard()[pos] != Piece());
        myBoard.setListePieceBoard(pieceAJouer, pos);
        myBoard.setPieceSelectionnee(Piece());
        int indicePiece = 0;
        for(size_t indicePieceTmp = 0; indicePieceTmp<myBoard.getListePieceJouable().size(); indicePieceTmp++)
        {
            if(myBoard.getListePieceJouable()[indicePiece] == pieceAJouer) break;
            indicePiece = (int)indicePieceTmp;
        }
        myBoard.eraseFromJouable(indicePiece);
    }

    else if(m_level == 1) // au niveau 1 l'IA joue en utilisant MiniMax avec une profondeur de 2
    {
        //profondeur de 2
    }

    else if(m_level == 2) // au niveau 2 l'IA joue en utilisant MiniMax avec une profondeur de 5
    {
        //profondeur de 5
    }

}

Piece IA::calcDonner(board& myBoard)
{
    Piece pieceADonner = Piece();
    if(m_level == 0) // au niveau 0 l'IA joue de facon aléatoire
    {
        int pos = -1;
        pos = rand() % (myBoard.getListePieceJouable().size());
        pieceADonner = myBoard.getListePieceJouable()[pos];
    }

    else if(m_level == 1) // au niveau 1 l'IA joue en utilisant MiniMax avec une profondeur de 2
    {
        //profondeur de 2
    }

    else if(m_level == 2) // au niveau 2 l'IA joue en utilisant MiniMax avec une profondeur de 5
    {
        //profondeur de 5
    }

    return pieceADonner;
}

int IA::evalue(board myBoard) // donne une note au plateau
{
    int score = 0;
    for(size_t i = 0; i<myBoard.getListePieceBoard().size(); i++)
    {
        if(myBoard.getListePieceBoard()[i] != Piece()) score++;
    }
    return score;
}

int minimax(board &myBoard, int depth, bool maxingPlayer) // algorithme de MiniMax
{
    std::list<int> listeCoup = myBoard.genererNextCoup();
    IA ordi = IA();
    if(depth == 0 || myBoard.isQuarto() || myBoard.isDraw()) return ordi.evalue(myBoard);
    if(maxingPlayer)
    {

    }
    return 0;
}
