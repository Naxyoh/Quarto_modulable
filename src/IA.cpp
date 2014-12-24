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

void IA::calcJoue(board& myBoard, Piece pieceAJouer)
{
    std::cout<<"calcJoue"<<std::endl;
    if(m_level == 0)
    {
        int pos = -1;
        do
        {
           pos = rand() % 15;
        }
        while (myBoard.getListePieceBoard()[pos] != Piece());
        myBoard.setListePieceBoard(pieceAJouer, pos);
        myBoard.setPieceSelectionnee(Piece());
        int indicePiece = -1;
        for(size_t indicePieceTmp = 0; indicePieceTmp<myBoard.getListePieceJouable().size(); indicePieceTmp++)
        {
            if(myBoard.getListePieceJouable()[indicePiece] == pieceAJouer) break;
            indicePiece = (int)indicePieceTmp;
        }
        myBoard.eraseFromJouable(indicePiece);
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

Piece IA::calcDonner(board& myBoard)
{
    std::cout<<"CalcDonner "<< m_level <<std::endl;
    Piece pieceADonner = Piece();
    if(m_level == 0)
    {
        int pos = -1;
//        do
//        {
           pos = rand() % (myBoard.getListePieceJouable().size()-1);
           std::cout<<"CalcDonner "<< pos <<std::endl;
        //}while (myBoard.getListePieceBoard()[pos] == Piece());
        pieceADonner = myBoard.getListePieceJouable()[pos];
        std::cout<<"CalcDonner "<< convertPieceToString(pieceADonner) <<std::endl;
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
