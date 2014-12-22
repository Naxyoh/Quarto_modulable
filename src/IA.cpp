#include "IA.h"

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

void IA::calcJoue(board myBoard, Piece pieceAJouer)
{
    if(m_level == 0)
    {
        int pos = -1;
        do
        {
           pos = rand() % 15;
        }
        while (myBoard.getListePieceBoard()[pos] == Piece());
        myBoard.setListePieceBoard(pieceAJouer, pos);
    }

    else if(m_level == 1)
    {
        //profondeur de 2
    }

    else if(m_level == 2)
    {
        //profondeur de 5
    }

}

Piece IA::calcDonner(board myBoard)
{
    Piece pieceADonner = Piece();
    if(m_level == 0)
    {
        int pos = -1;
//        do
//        {
           pos = rand() % (myBoard.getListePieceJouable().size()-1);
        //}while (myBoard.getListePieceBoard()[pos] == Piece());
        pieceADonner = myBoard.getListePieceJouable()[pos];
        myBoard.eraseFromJouable(pos);
    }

    else if(m_level == 1)
    {
        //profondeur de 2
    }

    else if(m_level == 2)
    {
        //profondeur de 5
    }

    return pieceADonner;
}

int IA::evalue(board myBoard)
{
    int score = 0;
    for(size_t i = 0; i<myBoard.getListePieceBoard().size(); i++)
    {
        if(myBoard.getListePieceBoard()[i] != Piece()) score++;
    }
    return score;
}
