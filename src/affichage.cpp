#include "general.h"

using namespace std;

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


void AffichageSFML::drawBoard(board& monPlateau)
{
    sf::RenderWindow mainWindow;
    sf::Texture grille, fond;
    sf::Texture NoirPetitCarrePlein, NoirPetitCarreCreux, NoirPetitRondPlein, NoirPetitRondCreux,
                NoirGrandCarrePlein, NoirGrandCarreCreux, NoirGrandRondPlein, NoirGrandRondCreux,
                BlancPetitCarrePlein, BlancPetitCarreCreux, BlancPetitRondPlein, BlancPetitRondCreux,
                BlancGrandCarrePlein, BlancGrandCarreCreux, BlancGrandRondPlein, BlancGrandRondCreux;

    int win_width = 600;
    int win_height = 800;

    mainWindow.create(sf::VideoMode(win_height,win_width,32),"Quarto", sf::Style::Titlebar | sf::Style::Close);

    if(grille.loadFromFile("images/Grille.png") != true || fond.loadFromFile("images/fond.png") != true)
        return;

    //Chargement des images des pi�ces
    if( NoirPetitCarrePlein.loadFromFile("images/NoirPetitCarrePlein.png") != true || NoirPetitCarreCreux.loadFromFile("images/NoirPetitCarreCreux.png") != true ||
        NoirPetitRondPlein.loadFromFile("images/NoirPetitRondPlein.png") != true ||  NoirPetitRondCreux.loadFromFile("images/NoirPetitRondCreux.png") != true ||
        NoirGrandCarrePlein.loadFromFile("images/NoirGrandCarrePlein.png") != true ||  NoirGrandCarreCreux.loadFromFile("images/NoirGrandCarreCreux.png") != true ||
        NoirGrandRondPlein.loadFromFile("images/NoirGrandRondPlein.png") != true ||  NoirGrandRondCreux.loadFromFile("images/NoirGrandRondCreux.png") != true ||
        BlancPetitCarrePlein.loadFromFile("images/BlancPetitCarrePlein.png") != true ||  BlancPetitCarreCreux.loadFromFile("images/BlancPetitCarreCreux.png") != true ||
        BlancPetitRondPlein.loadFromFile("images/BlancPetitRondPlein.png") != true ||  BlancPetitRondCreux.loadFromFile("images/BlancPetitRondCreux.png") != true ||
        BlancGrandCarrePlein.loadFromFile("images/BlancGrandCarrePlein.png") != true ||  BlancGrandCarreCreux.loadFromFile("images/BlancGrandCarreCreux.png") != true ||
        BlancGrandRondPlein.loadFromFile("images/BlancGrandRondPlein.png") != true ||  BlancGrandRondCreux.loadFromFile("images/BlancGrandRondCreux.png") != true)
            return;

    sf::Sprite grilleSprite(grille), fondSprite(fond);

    //Cr�ation des sprites associ�s aux pieces
    sf::Sprite  NoirPetitCarrePleinSprite(NoirPetitCarrePlein), NoirPetitCarreCreuxSprite(NoirPetitCarreCreux), NoirPetitRondPleinSprite(NoirPetitRondPlein), NoirPetitRondCreuxSprite(NoirPetitRondCreux),
                NoirGrandCarrePleinSprite(NoirGrandCarrePlein), NoirGrandCarreCreuxSprite(NoirGrandCarreCreux), NoirGrandRondPleinSprite(NoirGrandRondPlein), NoirGrandRondCreuxSprite(NoirGrandRondCreux),
                BlancPetitCarrePleinSprite(BlancPetitCarrePlein), BlancPetitCarreCreuxSprite(BlancPetitCarreCreux), BlancPetitRondPleinSprite(BlancPetitRondPlein), BlancPetitRondCreuxSprite(BlancPetitRondCreux),
                BlancGrandCarrePleinSprite(BlancGrandCarrePlein), BlancGrandCarreCreuxSprite(BlancGrandCarreCreux), BlancGrandRondPleinSprite(BlancGrandRondPlein), BlancGrandRondCreuxSprite(BlancGrandRondCreux);

    //Lien entre piece affich�e et pr�sence dans le vecteur de piece jouable
    std::vector<sf::Sprite> listeSpritePiece;
    for(size_t i = 0; i<monPlateau.getListePieceJouable().size(); i++)
    {
        if(convertPieceToString(monPlateau.getListePieceJouable()[i]) == "NoirPetitCarrePlein") listeSpritePiece.push_back(NoirPetitCarrePleinSprite);
        else if(convertPieceToString(monPlateau.getListePieceJouable()[i]) == "NoirPetitCarreCreux") listeSpritePiece.push_back(NoirPetitCarreCreuxSprite);
        else if(convertPieceToString(monPlateau.getListePieceJouable()[i]) == "NoirPetitRondPlein") listeSpritePiece.push_back(NoirPetitRondPleinSprite);
        else if(convertPieceToString(monPlateau.getListePieceJouable()[i]) == "NoirPetitRondCreux") listeSpritePiece.push_back(NoirPetitRondCreuxSprite);
        else if(convertPieceToString(monPlateau.getListePieceJouable()[i]) == "NoirGrandCarrePlein") listeSpritePiece.push_back(NoirGrandCarrePleinSprite);
        else if(convertPieceToString(monPlateau.getListePieceJouable()[i]) == "NoirGrandCarreCreux") listeSpritePiece.push_back(NoirGrandCarreCreuxSprite);
        else if(convertPieceToString(monPlateau.getListePieceJouable()[i]) == "NoirGrandRondPlein") listeSpritePiece.push_back(NoirGrandRondPleinSprite);
        else if(convertPieceToString(monPlateau.getListePieceJouable()[i]) == "NoirGrandRondCreux") listeSpritePiece.push_back(NoirGrandRondCreuxSprite);
        else if(convertPieceToString(monPlateau.getListePieceJouable()[i]) == "BlancPetitCarrePlein") listeSpritePiece.push_back(BlancPetitCarrePleinSprite);
        else if(convertPieceToString(monPlateau.getListePieceJouable()[i]) == "BlancPetitCarreCreux") listeSpritePiece.push_back(BlancPetitCarreCreuxSprite);
        else if(convertPieceToString(monPlateau.getListePieceJouable()[i]) == "BlancPetitRondPlein") listeSpritePiece.push_back(BlancPetitRondPleinSprite);
        else if(convertPieceToString(monPlateau.getListePieceJouable()[i]) == "BlancPetitRondCreux") listeSpritePiece.push_back(BlancPetitRondCreuxSprite);
        else if(convertPieceToString(monPlateau.getListePieceJouable()[i]) == "BlancGrandCarrePlein") listeSpritePiece.push_back(BlancGrandCarrePleinSprite);
        else if(convertPieceToString(monPlateau.getListePieceJouable()[i]) == "BlancGrandCarreCreux") listeSpritePiece.push_back(BlancGrandCarreCreuxSprite);
        else if(convertPieceToString(monPlateau.getListePieceJouable()[i]) == "BlancGrandRondPlein") listeSpritePiece.push_back(BlancGrandRondPleinSprite);
        else if(convertPieceToString(monPlateau.getListePieceJouable()[i]) == "BlancGrandRondCreux") listeSpritePiece.push_back(BlancGrandRondCreuxSprite);
    }

    //Placement des piece sur le board (a tester) faux, faut refaire une liste Jouable puis push_back et ensuite les d�placer
    for(size_t i = 0; i<monPlateau.getListePieceJouable().size(); i++)
    {
        if(monPlateau.getListePieceBoard()[i] != Piece())
        {
            if(i<4) listeSpritePiece[i].setPosition(win_width/3.5+60*i, win_height/4);
            else if(i>=4 && i<8) listeSpritePiece[i].setPosition(win_width/3.5+60*i, win_height/4+60*i);
            else if(i>=8 && i<12) listeSpritePiece[i].setPosition(win_width/3.5+60*i, win_height/4+60*2*i);
            else if(i>=12 && i<16) listeSpritePiece[i].setPosition(win_width/3.5+60*i, win_height/4+60*3*i);
        }
    }

    grilleSprite.setPosition(win_width/3.5,win_height/4);

    //Positionnement des pi�ces
    for(size_t i = 0; i<listeSpritePiece.size(); i++)
    {
        if(i<8) listeSpritePiece[i].setPosition(100+70*i, 20);
        else listeSpritePiece[i].setPosition(100+70*(i-8), 110);
    }

    while (mainWindow.isOpen())
    {
        sf::Event event;
        while (mainWindow.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                mainWindow.close();
        }

        mainWindow.clear();
        mainWindow.draw(fondSprite);
        mainWindow.draw(grilleSprite);
        for(size_t i = 0; i<listeSpritePiece.size(); i++)
        {
            mainWindow.draw(listeSpritePiece[i]);
        }
        mainWindow.display();
    }
}
