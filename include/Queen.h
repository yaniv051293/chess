#pragma once
#include "Piece.h"


class Queen : public Piece
{
public:
	Queen(Color White) :Piece(White) {};
	bool isLegalMove(Location src, Location dst, const Board* board) override;

};
