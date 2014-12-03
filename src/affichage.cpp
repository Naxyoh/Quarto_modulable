#include "general.h"

using namespace std;

void AffichageConsole::drawPieceAt(board &myBoard, int position)
{
    Piece pieceAAfficher = myBoard.getListePieceBoard()[position];

}

void AffichageConsole::drawBoard(board &monPlateau )
{
    for (size_t i =0; i<monPlateau.getListePieceBoard().size(); i++)
    {
       // cout<<"\n"<<"i = "<<i<<"\n";
        if(i%4==0) cout<<"\n+-------------------------------------------------------------------------------+\n";
        if(i%4==0) cout<<"|";
        afficherPiece(monPlateau.getListePieceBoard()[i]);
        cout<<"|";
        if(i==15) cout<<"\n+-------------------------------------------------------------------------------+\n";
    }

    cout<<"\n\nPiece Jouable : \n";
    for(size_t j = 0; j<monPlateau.getListePieceJouable().size(); j++)
    {
        cout<<j+1<<") ";
        afficherPiece(monPlateau.getListePieceJouable()[j]);
        cout<<"\n";
    }
}

void AffichageConsole::afficherPiece(Piece const& piece )
{
    cout<<convertPieceToString(piece);
}

void AffichageConsole::afficherListePiece(vector<Piece> const& listePiece )
{
    for (size_t i =0; i<listePiece.size(); i++)
    {
        afficherPiece(listePiece[i]);
        cout<<"\n";
    }
}

void AffichageConsole::afficherPieceBoard(board monPlateau )
{
    for (size_t i =0; i<monPlateau.getListePieceBoard().size(); i++)
    {
       // cout<<"\n"<<"i = "<<i<<"\n";
        if(i%4==0) cout<<"\n+-------------------------------------------------------------------------------+\n";
        if(i%4==0) cout<<"|";
        afficherPiece(monPlateau.getListePieceBoard()[i]);
        cout<<"|";
        if(i==15) cout<<"\n+-------------------------------------------------------------------------------+\n";
    }
    cout<<"\n\nPiece Jouable : \n";
    for(size_t j = 0; j<monPlateau.getListePieceJouable().size(); j++)
    {
        cout<<j+1<<") ";
        afficherPiece(monPlateau.getListePieceJouable()[j]);
        cout<<"\n";
    }

}
