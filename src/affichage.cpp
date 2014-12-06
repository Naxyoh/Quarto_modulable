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

/////////////////////////////////////////////////////////
/*Affichage SFML*/
/////////////////////////////////////////////////////////


void AffichageSFML::drawBoard(board&)
{
    sf::Vector2u size;
    sf::RenderWindow m_mainWindow;
    sf::Texture grille, fond;


    int win_height = 800;
    int win_width = 600;
    m_mainWindow.create(sf::VideoMode(win_height,win_width,32),"Quarto");


    if(grille.loadFromFile("images/Grille.png") != true || fond.loadFromFile("images/fond.png") != true)
        return;

    sf::Sprite grilleSprite(grille), fondSprite(fond);
    size = fond.getSize();


    grilleSprite.setPosition(win_width/3.5,win_height/4);


    while (m_mainWindow.isOpen())
    {
        sf::Event event;
        while (m_mainWindow.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                m_mainWindow.close();
        }

        m_mainWindow.clear();
        m_mainWindow.draw(fondSprite);
        m_mainWindow.draw(grilleSprite);
        m_mainWindow.display();
    }
}

void AffichageSFML::drawPieceAt(board &myBoard, int position)
{

}
