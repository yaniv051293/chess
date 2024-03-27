#pragma once
#include "Piece.h"


class King : public Piece
{
public:

	King(Color White) :Piece(White) {};
	bool isLegalMove(Location src, Location dst, const Board* board) override;

};
