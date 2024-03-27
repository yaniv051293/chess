#include "Knight.h"

bool Knight::isLegalMove(Location src, Location dst, const Board* board)
/**
 * Checks if a move from the source location to the destination location is legal for a Knight.
 *
 * @param src The source location of the Knight.
 * @param dst The destination location of the Knight.
 * @return True if the move is legal, false otherwise.
 */
{
	int dx =abs(dst.r-src.r) ;
	int dy = abs(dst.c - src.c);
	if ((dx == 2 && dy == 1) || (dx == 1 && dy == 2))
		return true;
	return false;
}