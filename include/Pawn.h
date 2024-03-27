#pragma once
#include "Piece.h"


class Pawn : public Piece
{
public:
	Pawn(Color White) :Piece(White) {};
	bool isLegalMove(Location src, Location dst, const Board* board) override;


};
