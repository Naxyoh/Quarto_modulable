#include "general.h"


bool Engine::isMovePossible(std::vector<Piece> liste, int pos)
{
    if(liste[pos] == Piece()) return true;
    else return false;
}

bool Engine::isPieceNonVide(Piece &pieceATester)
{
    if(pieceATester != Piece()) return true;
    else return false;
}
