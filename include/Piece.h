#pragma once
#include "Location.h"
#include "Board.h"
#include "Color.h"



class Board;


class Piece {

protected:
	Color color;
public:
	Piece(Color White);

	virtual bool isLegalMove(Location src,Location dst,const Board* board) = 0;// llegal movement of that piece
	Color getColor();
};