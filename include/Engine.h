#ifndef ENGINE_H
#define ENGINE_H

#include "general.h"

class Engine
{
    public:
        bool isMovePossible(std::vector<Piece>, int);
        bool isPieceNonVide(Piece&);
    protected:
    private:
};

//class EngineConsole : public Engine
//{
//    public :
//        virtual bool isMovePossible(board&);
//        virtual bool isPieceNonVide(Piece& const);
//};
//
//class EngineSFML : public Engine
//{
//    public :
//        virtual bool isMovePosible(board&);
//        virtual bool isPieceNonVide(Piece&)
//};

#endif // ENGINE_H
