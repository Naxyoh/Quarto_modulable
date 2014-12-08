#include "general.h"

using namespace std;

int main()
{
    AffichageConsole affich;
    AffichageSFML affichSFML;
    ControleurConsole control;

    board monPlateau = board();

    affichSFML.drawBoard(monPlateau);
    monPlateau.setListePieceBoard(Piece(blanc, petit, rond, creux),4);
    if(typeid(affich) == typeid(AffichageConsole))
    {
      // A utiliser quand on voudra mettre la boucle de la SFML dans le main
    }
    while(monPlateau.isQuarto() != true)
    {
        Piece pieceSelectionne = Piece();
        affich.drawBoard(monPlateau);
        pieceSelectionne = control.selectionnerPiece(monPlateau);
        control.jouerPiece(monPlateau, pieceSelectionne);
    }
    affich.drawBoard(monPlateau);
    cout<<"Quarto !\n";
    return 0;
}
