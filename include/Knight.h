#pragma once
#include "Piece.h"


class Knight : public Piece
{
public:
	Knight(Color White) :Piece(White) {};
	bool isLegalMove(Location src, Location dst, const Board* board) override;//21 - illegal movement of that piece

};
