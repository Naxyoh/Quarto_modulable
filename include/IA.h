#ifndef IA_H
#define IA_H

#include "general.h"

class IA
{
    public:
        IA();
        virtual ~IA();

        void setLevel(int);
        int getLevel();

        //Fonction qui calcule le prochain coup
        void calcJoue(board&, Piece);

        //Fonction qui calcule quelle piece donner
        Piece calcDonner(board&);

        //Fonction pour le calcul de min max
        int calcMin(board, int);
        int calcMax(board, int);

        //Fonction qui evalue le jeu
        int evalue(board);
        int minimax(board &myBoard, int depth, bool maxingPlayer);

    protected:
        int m_level; // Niveau de l'IA
    private:
};

#endif // IA_H
