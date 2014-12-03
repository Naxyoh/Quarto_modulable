#include "general.h"

using namespace std;

int main()
{
    //Essai création piece
    /*Piece piece2 = Piece(noir, grand, carre, creux);
    Piece piece1 = Piece();

    afficherpiece(piece1);
    afficherpiece(piece2);*/

    //Essai affichage liste piece
    /*vector<Piece> listePiece = creerToutePiece();
    afficherListePiece(listePiece);
    cout<<"\n";*/

    board monPlateau = board();
    AffichageConsole affich;

    affich.drawBoard(monPlateau);

   /* while(monPlateau.isQuarto() != true)
    {
        //affich.afficherPieceBoard(monPlateau);
        //monPlateau.deplacerPiece();
        int position = -1;
        cout<<"Quelle position ?\n";
        cin>>position;
        affich.drawPieceAt(monPlateau, position);
        affich.drawBoard(monPlateau);
    }*/
    //affich.afficherPieceBoard(monPlateau);
    cout<<"Quarto !\n";
    return 0;
}
