#include "general.h"

using namespace std;

void AffichageConsole::drawBoard(board &monPlateau )
{
    for (size_t i =0; i<monPlateau.getListePieceBoard().size(); i++)
    {
        if(i%4==0) cout<<"\n+-----------------------------------------------------------------------------------+\n";
        if(i%4==0) cout<<"|";
        afficherPiece(monPlateau.getListePieceBoard()[i]);
        cout<<"|";
        if(i==15) cout<<"\n+-----------------------------------------------------------------------------------+\n";
    }
}

void AffichageConsole::drawPieceJouable(board &monPlateau)
{
    cout<<"\nPiece Jouable : \n";
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
        if(i%4==0) cout<<"\n+---------------------------------------------------------------------------------------+\n";
        if(i%4==0) cout<<"|";
        afficherPiece(monPlateau.getListePieceBoard()[i]);
        cout<<"|";
        if(i==15) cout<<"\n+---------------------------------------------------------------------------------------+\n";
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
    sf::Texture grille, fond;
    sf::Texture NoirPetitCarrePlein, NoirPetitCarreCreux, NoirPetitRondPlein, NoirPetitRondCreux,
    NoirGrandCarrePlein, NoirGrandCarreCreux, NoirGrandRondPlein, NoirGrandRondCreux,
    BlancPetitCarrePlein, BlancPetitCarreCreux, BlancPetitRondPlein, BlancPetitRondCreux,
    BlancGrandCarrePlein, BlancGrandCarreCreux, BlancGrandRondPlein, BlancGrandRondCreux;

    //Chargement des images de la grille et du fond
    if(grille.loadFromFile("images/Grille.png") != true || fond.loadFromFile("images/fond.png") != true)
        return;

    //Chargement des images des pièces
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

    //Création des sprites associés aux pieces
    sf::Sprite  NoirPetitCarrePleinSprite(NoirPetitCarrePlein), NoirPetitCarreCreuxSprite(NoirPetitCarreCreux), NoirPetitRondPleinSprite(NoirPetitRondPlein), NoirPetitRondCreuxSprite(NoirPetitRondCreux),
    NoirGrandCarrePleinSprite(NoirGrandCarrePlein), NoirGrandCarreCreuxSprite(NoirGrandCarreCreux), NoirGrandRondPleinSprite(NoirGrandRondPlein), NoirGrandRondCreuxSprite(NoirGrandRondCreux),
    BlancPetitCarrePleinSprite(BlancPetitCarrePlein), BlancPetitCarreCreuxSprite(BlancPetitCarreCreux), BlancPetitRondPleinSprite(BlancPetitRondPlein), BlancPetitRondCreuxSprite(BlancPetitRondCreux),
    BlancGrandCarrePleinSprite(BlancGrandCarrePlein), BlancGrandCarreCreuxSprite(BlancGrandCarreCreux), BlancGrandRondPleinSprite(BlancGrandRondPlein), BlancGrandRondCreuxSprite(BlancGrandRondCreux);

    //Lien entre piece affichée et présence dans le vecteur de piece jouable
    std::vector<sf::Sprite> listeSpritePiece;
    for(size_t i = 0; i<monPlateau.getListePieceJouable().size(); i++)
    {
        if(convertPieceToString(monPlateau.getListePieceJouable()[i]) == "NoirPetitCarrePlein ") listeSpritePiece.push_back(NoirPetitCarrePleinSprite);
        else if(convertPieceToString(monPlateau.getListePieceJouable()[i]) == "NoirPetitCarreCreux ") listeSpritePiece.push_back(NoirPetitCarreCreuxSprite);
        else if(convertPieceToString(monPlateau.getListePieceJouable()[i]) == "NoirPetitRondPlein  ") listeSpritePiece.push_back(NoirPetitRondPleinSprite);
        else if(convertPieceToString(monPlateau.getListePieceJouable()[i]) == "NoirPetitRondCreux  ") listeSpritePiece.push_back(NoirPetitRondCreuxSprite);
        else if(convertPieceToString(monPlateau.getListePieceJouable()[i]) == "NoirGrandCarrePlein ") listeSpritePiece.push_back(NoirGrandCarrePleinSprite);
        else if(convertPieceToString(monPlateau.getListePieceJouable()[i]) == "NoirGrandCarreCreux ") listeSpritePiece.push_back(NoirGrandCarreCreuxSprite);
        else if(convertPieceToString(monPlateau.getListePieceJouable()[i]) == "NoirGrandRondPlein  ") listeSpritePiece.push_back(NoirGrandRondPleinSprite);
        else if(convertPieceToString(monPlateau.getListePieceJouable()[i]) == "NoirGrandRondCreux  ") listeSpritePiece.push_back(NoirGrandRondCreuxSprite);
        else if(convertPieceToString(monPlateau.getListePieceJouable()[i]) == "BlancPetitCarrePlein") listeSpritePiece.push_back(BlancPetitCarrePleinSprite);
        else if(convertPieceToString(monPlateau.getListePieceJouable()[i]) == "BlancPetitCarreCreux") listeSpritePiece.push_back(BlancPetitCarreCreuxSprite);
        else if(convertPieceToString(monPlateau.getListePieceJouable()[i]) == "BlancPetitRondPlein ") listeSpritePiece.push_back(BlancPetitRondPleinSprite);
        else if(convertPieceToString(monPlateau.getListePieceJouable()[i]) == "BlancPetitRondCreux ") listeSpritePiece.push_back(BlancPetitRondCreuxSprite);
        else if(convertPieceToString(monPlateau.getListePieceJouable()[i]) == "BlancGrandCarrePlein") listeSpritePiece.push_back(BlancGrandCarrePleinSprite);
        else if(convertPieceToString(monPlateau.getListePieceJouable()[i]) == "BlancGrandCarreCreux") listeSpritePiece.push_back(BlancGrandCarreCreuxSprite);
        else if(convertPieceToString(monPlateau.getListePieceJouable()[i]) == "BlancGrandRondPlein ") listeSpritePiece.push_back(BlancGrandRondPleinSprite);
        else if(convertPieceToString(monPlateau.getListePieceJouable()[i]) == "BlancGrandRondCreux ") listeSpritePiece.push_back(BlancGrandRondCreuxSprite);
    }

    //Lien entre piece affichée et présence dans le vecteur de piece jouée
    std::vector<sf::Sprite> listeSpritePieceBoard;
    for(size_t i = 0; i<monPlateau.getListePieceBoard().size(); i++)
    {
        if(convertPieceToString(monPlateau.getListePieceBoard()[i]) == "NoirPetitCarrePlein ") listeSpritePieceBoard.push_back(NoirPetitCarrePleinSprite);
        else if(convertPieceToString(monPlateau.getListePieceBoard()[i]) == "NoirPetitCarreCreux ") listeSpritePieceBoard.push_back(NoirPetitCarreCreuxSprite);
        else if(convertPieceToString(monPlateau.getListePieceBoard()[i]) == "NoirPetitRondPlein  ") listeSpritePieceBoard.push_back(NoirPetitRondPleinSprite);
        else if(convertPieceToString(monPlateau.getListePieceBoard()[i]) == "NoirPetitRondCreux  ") listeSpritePieceBoard.push_back(NoirPetitRondCreuxSprite);
        else if(convertPieceToString(monPlateau.getListePieceBoard()[i]) == "NoirGrandCarrePlein ") listeSpritePieceBoard.push_back(NoirGrandCarrePleinSprite);
        else if(convertPieceToString(monPlateau.getListePieceBoard()[i]) == "NoirGrandCarreCreux ") listeSpritePieceBoard.push_back(NoirGrandCarreCreuxSprite);
        else if(convertPieceToString(monPlateau.getListePieceBoard()[i]) == "NoirGrandRondPlein  ") listeSpritePieceBoard.push_back(NoirGrandRondPleinSprite);
        else if(convertPieceToString(monPlateau.getListePieceBoard()[i]) == "NoirGrandRondCreux  ") listeSpritePieceBoard.push_back(NoirGrandRondCreuxSprite);
        else if(convertPieceToString(monPlateau.getListePieceBoard()[i]) == "BlancPetitCarrePlein") listeSpritePieceBoard.push_back(BlancPetitCarrePleinSprite);
        else if(convertPieceToString(monPlateau.getListePieceBoard()[i]) == "BlancPetitCarreCreux") listeSpritePieceBoard.push_back(BlancPetitCarreCreuxSprite);
        else if(convertPieceToString(monPlateau.getListePieceBoard()[i]) == "BlancPetitRondPlein ") listeSpritePieceBoard.push_back(BlancPetitRondPleinSprite);
        else if(convertPieceToString(monPlateau.getListePieceBoard()[i]) == "BlancPetitRondCreux ") listeSpritePieceBoard.push_back(BlancPetitRondCreuxSprite);
        else if(convertPieceToString(monPlateau.getListePieceBoard()[i]) == "BlancGrandCarrePlein") listeSpritePieceBoard.push_back(BlancGrandCarrePleinSprite);
        else if(convertPieceToString(monPlateau.getListePieceBoard()[i]) == "BlancGrandCarreCreux") listeSpritePieceBoard.push_back(BlancGrandCarreCreuxSprite);
        else if(convertPieceToString(monPlateau.getListePieceBoard()[i]) == "BlancGrandRondPlein ") listeSpritePieceBoard.push_back(BlancGrandRondPleinSprite);
        else if(convertPieceToString(monPlateau.getListePieceBoard()[i]) == "BlancGrandRondCreux ") listeSpritePieceBoard.push_back(BlancGrandRondCreuxSprite);
    }

    //Placement des piece sur le board
    int cmpPiece = 0;
    for(size_t i = 0; i<monPlateau.getListePieceBoard().size(); i++)
    {
        if(monPlateau.getListePieceBoard()[i] != Piece())
        {
                if(i<4) listeSpritePieceBoard[cmpPiece].setPosition((170+80*i),240);
                if(i>=4 && i < 8) listeSpritePieceBoard[cmpPiece].setPosition(170+80*(i-4),320);
                if(i>=8 && i < 12) listeSpritePieceBoard[cmpPiece].setPosition(170+80*(i-8),400);
                if(i>=12 && i < 16) listeSpritePieceBoard[cmpPiece].setPosition(170+80*(i-12),480);
                cmpPiece++;
        }
    }

    grilleSprite.setPosition(150,220);

    //Positionnement des pièces
    for(size_t i = 0; i<listeSpritePiece.size(); i++)
    {
        if(i<8) listeSpritePiece[i].setPosition(100+70*i, 20);
        else listeSpritePiece[i].setPosition(100+70*(i-8), 110);
    }

    //Gestion de la piece selectionnee
    sf::Texture pieceSelec;
    if(convertPieceToString(monPlateau.getPieceSelectionnee())== "NoirPetitCarrePlein ") pieceSelec.loadFromFile("images/NoirPetitCarrePlein.png");
    else if(convertPieceToString(monPlateau.getPieceSelectionnee())== "NoirPetitCarreCreux ") pieceSelec.loadFromFile("images/NoirPetitCarreCreux.png");
    else if(convertPieceToString(monPlateau.getPieceSelectionnee())== "NoirPetitRondPlein  ") pieceSelec.loadFromFile("images/NoirPetitRondPlein.png");
    else if(convertPieceToString(monPlateau.getPieceSelectionnee())== "NoirPetitRondCreux  ") pieceSelec.loadFromFile("images/NoirPetitRondCreux.png");
    else if(convertPieceToString(monPlateau.getPieceSelectionnee())== "NoirGrandCarrePlein ") pieceSelec.loadFromFile("images/NoirGrandCarrePlein.png");
    else if(convertPieceToString(monPlateau.getPieceSelectionnee())== "NoirGrandCarreCreux ") pieceSelec.loadFromFile("images/NoirGrandCarreCreux.png");
    else if(convertPieceToString(monPlateau.getPieceSelectionnee())== "NoirGrandRondPlein  ") pieceSelec.loadFromFile("images/NoirGrandRondPlein.png");
    else if(convertPieceToString(monPlateau.getPieceSelectionnee())== "NoirGrandRondCreux  ") pieceSelec.loadFromFile("images/NoirGrandRondCreux.png");
    else if(convertPieceToString(monPlateau.getPieceSelectionnee())== "BlancPetitCarrePlein") pieceSelec.loadFromFile("images/BlancPetitCarrePlein.png");
    else if(convertPieceToString(monPlateau.getPieceSelectionnee())== "BlancPetitCarreCreux") pieceSelec.loadFromFile("images/BlancPetitCarreCreux.png");
    else if(convertPieceToString(monPlateau.getPieceSelectionnee())== "BlancPetitRondPlein ") pieceSelec.loadFromFile("images/BlancPetitRondPlein.png");
    else if(convertPieceToString(monPlateau.getPieceSelectionnee())== "BlancPetitRondCreux ") pieceSelec.loadFromFile("images/BlancPetitRondCreux.png");
    else if(convertPieceToString(monPlateau.getPieceSelectionnee())== "BlancGrandCarrePlein") pieceSelec.loadFromFile("images/BlancGrandCarrePlein.png");
    else if(convertPieceToString(monPlateau.getPieceSelectionnee())== "BlancGrandCarreCreux") pieceSelec.loadFromFile("images/BlancGrandCarreCreux.png");
    else if(convertPieceToString(monPlateau.getPieceSelectionnee())== "BlancGrandRondPlein ") pieceSelec.loadFromFile("images/BlancGrandRondPlein.png");
    else if(convertPieceToString(monPlateau.getPieceSelectionnee())== "BlancGrandRondCreux ") pieceSelec.loadFromFile("images/BlancGrandRondCreux.png");
    sf::Sprite pieceSelecSprite(pieceSelec);
    pieceSelecSprite.setPosition(600,500);

    //Gestion des differents textes affichés à l'écran
    sf::Text quarto, draw, restart,joueurText, joueurText2, pieceSelecText, gagnant;
    sf::Font font;

    //Si quarto
    font.loadFromFile("Font/Arial.ttf");
    quarto.setString("Quarto !");
    quarto.setCharacterSize(72);
    quarto.setStyle(sf::Text::Bold);
    quarto.setFont(font);
    quarto.setColor(sf::Color::Red);
    quarto.setPosition(270,100);

    //Si match nul
    draw.setString("Match Nul !");
    draw.setCharacterSize(72);
    draw.setStyle(sf::Text::Bold);
    draw.setFont(font);
    draw.setColor(sf::Color::Red);
    draw.setPosition(250,100);

    //Gestion affichage reset
    restart.setString("Appuyez sur une touche pour rejouer !");
    restart.setCharacterSize(28);
    restart.setStyle(sf::Text::Bold);
    restart.setFont(font);
    restart.setColor(sf::Color::Red);
    restart.setPosition(150,175);

    //Affichage Joueur
    std::string joueurString = toString(monPlateau.getJoueurActuel());
    joueurText.setString("Joueur");
    joueurText2.setString(joueurString);
    joueurText.setCharacterSize(30);
    joueurText2.setCharacterSize(30);
    joueurText.setFont(font);
    joueurText2.setFont(font);
    if(monPlateau.isQuarto() == false)
    {
        joueurText.setColor(sf::Color::Black);
        joueurText2.setColor(sf::Color::Black);
    }
    else
    {
        joueurText.setColor(sf::Color::Red);
        joueurText2.setColor(sf::Color::Red);
    }
    joueurText.setPosition(525,400);
    joueurText2.setPosition(625, 400);

    //Joueur gagnant
    gagnant.setString("gagne !");
    gagnant.setCharacterSize(30);
    gagnant.setFont(font);
    gagnant.setColor(sf::Color::Red);
    gagnant.setPosition(655,400);

    //Piece selectionnee
    pieceSelecText.setCharacterSize(20);
    pieceSelecText.setFont(font);
    pieceSelecText.setColor(sf::Color::Black);
    pieceSelecText.setPosition(525,450);

    //Affichages des sprites et textes
    m_mainWindow.clear();
    m_mainWindow.draw(fondSprite);
    m_mainWindow.draw(grilleSprite);
    m_mainWindow.draw(pieceSelecSprite);
    if(monPlateau.getPieceSelectionnee() != Piece())
    {
        pieceSelecText.setString("Vous devez jouer : ");
        if(monPlateau.isDraw() == false && monPlateau.isQuarto() == false)
        m_mainWindow.draw(pieceSelecText);
    }
    else
    {
        pieceSelecText.setString("Veuillez selectionner une piece ");
        if(monPlateau.isDraw() == false && monPlateau.isQuarto() == false)
        m_mainWindow.draw(pieceSelecText);
    }
    m_mainWindow.draw(joueurText);
    m_mainWindow.draw(joueurText2);

    for(size_t i = 0; i<listeSpritePieceBoard.size(); i++)
    {
        m_mainWindow.draw(listeSpritePieceBoard[i]);
    }
    for(size_t i = 0; i<listeSpritePiece.size(); i++)
    {
        m_mainWindow.draw(listeSpritePiece[i]);
    }
    if(monPlateau.isQuarto())
    {
        m_mainWindow.draw(gagnant);
        m_mainWindow.draw(quarto);
        m_mainWindow.draw(restart);
    }
    if(monPlateau.isDraw())
    {
        m_mainWindow.draw(draw);
        m_mainWindow.draw(restart);
    }
    m_mainWindow.display();
}

void AffichageSFML::setWindow()
{
    int win_width = 600;
    int win_height = 800;
    m_mainWindow.create(sf::VideoMode(win_height,win_width),"Quarto", sf::Style::Titlebar | sf::Style::Close);
}

sf::RenderWindow &AffichageSFML::getMainWindow()
{
    return m_mainWindow;
}
