#pragma once
#include "Piece.h"


class Rook : public Piece
{
public:
	Rook(Color White) :Piece(White) {};
	bool isLegalMove(Location src, Location dst, const Board* board) override;

};
