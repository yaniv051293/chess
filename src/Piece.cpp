#include "Piece.h"

/*
Piece:: Piece(Color White, Board* pb)
{
	color = White;
	board = pb;
}
*/
Piece::Piece(Color White)
{
	color = White;
}
Color Piece::getColor()
{
	return color;
}