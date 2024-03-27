#pragma once
#include "Piece.h"


class Bishop : public Piece
{
public:
	Bishop(Color White) :Piece(White) {};

	bool isLegalMove(Location src, Location dst, const Board* board) override;

};
