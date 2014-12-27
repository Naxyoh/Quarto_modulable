#include "general.h"

void ControleurConsole::selectionnerPiece(board &myBoard)
{
    if(myBoard.isDraw() != true && myBoard.isQuarto() != true)
    {
        if(myBoard.getJoueur() == humain)
        {
            int position = -1;
            do
            {
                std::cout<<std::endl<<"Rentrer le numero de la piece que vous souhaitez donner (Veuillez rentrer un numero entre 1 et 16)\n";
                std::cin>>position;
                if(position<1 || position>16 || std::cin.fail())
                {
                    std::cout<<"Numero de piece invalide\n";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //Pour eviter que ca plante si on rentre un char
                }
            }
            while(position<1 || position>16 || std::cin.fail());

            Piece pieceSelectionne = myBoard.getListePieceJouable()[position-1];
            std::cout<<"Vous avez selectionne "<<convertPieceToString(pieceSelectionne)<<std::endl;
            myBoard.setPieceSelectionnee(pieceSelectionne);
        }
        else if (myBoard.getJoueur() == facile)
        {
            std::cout<<"IA"<<std::endl;
            IA ordi = IA();
            ordi.setLevel(0);
            myBoard.setPieceSelectionnee(ordi.calcDonner(myBoard));
        }
    }
    return;
}

void ControleurConsole::jouerPiece(board &myBoard, Piece pieceAJouer)
{
    if(myBoard.isDraw() != true && myBoard.isQuarto() != true)
    {
        if(myBoard.getJoueur() == humain)
        {
        int pos = -1;
        do
        {
            std::cout<<"Quelle position ? (Veuillez rentrer une position entre 1 et 16)\n";
            std::cin>>pos;
            if(pos<1 || pos>16 || (myBoard.getListePieceBoard()[pos-1] != Piece())) std::cout<<"Position invalide\n";
        }
        while(pos<1 || pos>16 || (myBoard.getListePieceBoard()[pos-1] != Piece()));

        myBoard.setListePieceBoard(pieceAJouer, pos-1);
        myBoard.eraseFromJouable(pos-1);
    }
    else if(myBoard.getJoueur() == facile)
    {
        std::cout<<"IA"<<std::endl;
        IA ordi = IA();
        ordi.setLevel(0);
        ordi.calcJoue(myBoard, pieceAJouer);
    }
    }
    return;
}

void ControleurConsole::restart(board& myBoard)
{
    system("cls");
    std::vector<joueur> liste;
    liste = myBoard.getListeJoueur();
    myBoard = board();
    myBoard.setJoueurActuel(1);
    myBoard.setListeJoueur(liste);
}

void ControleurSFML::selectionnerPiece(board &myBoard)
{
    if(myBoard.isDraw() != true && myBoard.isQuarto() != true)
    {
        if(myBoard.getJoueur() == humain)
        {
            int position = -1;
            if (m_event.type == sf::Event::MouseButtonPressed)
            {
                sf::Mouse::Button button = m_event.mouseButton.button;
                if (button == sf::Mouse::Left)
                {
                    if(m_event.mouseButton.x>110 && m_event.mouseButton.x<650 && m_event.mouseButton.y >20 && m_event.mouseButton.y < 170 && myBoard.getPieceSelectionnee() == Piece() )
                    {
                        if (m_event.mouseButton.y < 80 && m_event.mouseButton.y > 20)
                        {
                            if (m_event.mouseButton.x < 170 && m_event.mouseButton.x > 100) position = 0;
                            else if (m_event.mouseButton.x < 240 && m_event.mouseButton.x > 170 && myBoard.getListePieceJouable().size()>1) position = 1;
                            else if (m_event.mouseButton.x < 310 && m_event.mouseButton.x> 240 && myBoard.getListePieceJouable().size()>2) position = 2;
                            else if (m_event.mouseButton.x < 380 && m_event.mouseButton.x > 310 && myBoard.getListePieceJouable().size()>3) position = 3;
                            else if (m_event.mouseButton.x < 450 && m_event.mouseButton.x > 380 && myBoard.getListePieceJouable().size()>4) position = 4;
                            else if (m_event.mouseButton.x < 520 && m_event.mouseButton.x > 450 && myBoard.getListePieceJouable().size()>5) position = 5;
                            else if (m_event.mouseButton.x < 590 && m_event.mouseButton.x > 520 && myBoard.getListePieceJouable().size()>6) position = 6;
                            else if (m_event.mouseButton.x < 660 && m_event.mouseButton.x > 590 && myBoard.getListePieceJouable().size()>7) position = 7;
                        }
                        else if (m_event.mouseButton.y < 170 && m_event.mouseButton.y > 110)
                        {
                            if (m_event.mouseButton.x < 170 && m_event.mouseButton.x > 100 && myBoard.getListePieceJouable().size()>8) position = 8;
                            else if (m_event.mouseButton.x < 240 && m_event.mouseButton.x > 170 && myBoard.getListePieceJouable().size()>9) position = 9;
                            else if (m_event.mouseButton.x < 310 && m_event.mouseButton.x> 240 && myBoard.getListePieceJouable().size()>10) position = 10;
                            else if (m_event.mouseButton.x < 380 && m_event.mouseButton.x > 310 && myBoard.getListePieceJouable().size()>11) position = 11;
                            else if (m_event.mouseButton.x < 450 && m_event.mouseButton.x > 380 && myBoard.getListePieceJouable().size()>12) position = 12;
                            else if (m_event.mouseButton.x < 520 && m_event.mouseButton.x > 450 && myBoard.getListePieceJouable().size()>13) position = 13;
                            else if (m_event.mouseButton.x < 590 && m_event.mouseButton.x > 520 && myBoard.getListePieceJouable().size()>14) position = 14;
                            else if (m_event.mouseButton.x < 660 && m_event.mouseButton.x > 590 && myBoard.getListePieceJouable().size()>15) position = 15;
                        }
                    }
                }
            }
            else return;
            if(position == -1) return;
            Piece pieceSelectionne = myBoard.getListePieceJouable()[position];
            std::cout<<"Piece selec : "<<convertPieceToString(pieceSelectionne)<<" position : "<<position<<std::endl;
            myBoard.setPieceSelectionnee(pieceSelectionne);
        }

        else if(myBoard.getJoueur() == facile)
        {
            std::cout<<"IA"<<std::endl;
            IA ordi = IA();
            ordi.setLevel(0);
            myBoard.setPieceSelectionnee(ordi.calcDonner(myBoard));
        }
        myBoard.changementJoueur();
    }
    return;
}


void ControleurSFML::jouerPiece(board& myBoard, Piece pieceAJouer)
{
    if(myBoard.isDraw() != true && myBoard.isQuarto() != true)
    {
        if(myBoard.getJoueur() == humain)
        {
            int position = -1;
            if (m_event.type == sf::Event::MouseButtonPressed)
            {
                sf::Mouse::Button button = m_event.mouseButton.button;

                if (button == sf::Mouse::Left)
                {
                    if(myBoard.getPieceSelectionnee() != Piece() && (m_event.mouseButton.y > 230 && m_event.mouseButton.y < 550) && (m_event.mouseButton.x > 160 && m_event.mouseButton.x < 480))
                    {
                        if (m_event.mouseButton.y > 230 && m_event.mouseButton.y < 310)
                        {
                            if (m_event.mouseButton.x > 160 && m_event.mouseButton.x < 240) position = 0;
                            else if (m_event.mouseButton.x > 240 && m_event.mouseButton.x < 320) position = 1;
                            else if (m_event.mouseButton.x > 320 && m_event.mouseButton.x < 400) position = 2;
                            else if (m_event.mouseButton.x > 400 && m_event.mouseButton.x < 480) position = 3;
                        }
                        else if (m_event.mouseButton.y > 310 && m_event.mouseButton.y < 390)
                        {
                            if (m_event.mouseButton.x > 160 && m_event.mouseButton.x < 240) position = 4;
                            else if (m_event.mouseButton.x > 240 && m_event.mouseButton.x < 320) position = 5;
                            else if (m_event.mouseButton.x > 320 && m_event.mouseButton.x < 400) position = 6;
                            else if (m_event.mouseButton.x > 400 && m_event.mouseButton.x < 480) position = 7;
                        }
                        else if (m_event.mouseButton.y > 390 && m_event.mouseButton.y < 470)
                        {
                            if (m_event.mouseButton.x > 160 && m_event.mouseButton.x < 240) position = 8;
                            else if (m_event.mouseButton.x > 240 && m_event.mouseButton.x < 320) position = 9;
                            else if (m_event.mouseButton.x > 320 && m_event.mouseButton.x < 400) position = 10;
                            else if (m_event.mouseButton.x > 400 && m_event.mouseButton.x < 480) position = 11;
                        }
                        else if (m_event.mouseButton.y > 470 && m_event.mouseButton.y < 550)
                        {
                            if (m_event.mouseButton.x > 160 && m_event.mouseButton.x < 240) position = 12;
                            else if (m_event.mouseButton.x > 240 && m_event.mouseButton.x < 320) position = 13;
                            else if (m_event.mouseButton.x > 320 && m_event.mouseButton.x < 400) position = 14;
                            else if (m_event.mouseButton.x > 400 && m_event.mouseButton.x < 480) position = 15;
                        }
                    }
                }
            }
            else return;

            if(position == -1 || pieceAJouer == Piece() || myBoard.getListePieceBoard()[position] != Piece())
            {
                std::cout<<"position wrong ou piece vide"<<std::endl;
                return;
            }
            myBoard.setListePieceBoard(pieceAJouer, position);
            myBoard.setPieceSelectionnee(Piece());
            int indicePiece = -1;
            for(size_t indicePieceTmp = 0; indicePieceTmp<myBoard.getListePieceJouable().size(); indicePieceTmp++)
            {
                if(myBoard.getListePieceJouable()[indicePiece] == pieceAJouer) break;
                indicePiece = (int)indicePieceTmp;
            }
            myBoard.eraseFromJouable(indicePiece);
        }

        else if(myBoard.getJoueur() == facile)
        {
            std::cout<<"IA"<<std::endl;
            IA ordi = IA();
            ordi.setLevel(0);
            ordi.calcJoue(myBoard, pieceAJouer);
        }
    }
    return;
}

void ControleurSFML::restart(board& myBoard)
{
    if(myBoard.isDraw() || myBoard.isQuarto())
    {
        std::vector<joueur> liste;
        liste = myBoard.getListeJoueur();
        myBoard = board();
        myBoard.setJoueurActuel(1);
        myBoard.setJoueur(humain);
        myBoard.setListeJoueur(liste);
    }
}

void ControleurSFML::setEvent(sf::Event myEvent)
{
    m_event = myEvent;
}

sf::Event &ControleurSFML::getEvent()
{
    return m_event;
}


