#include "Pawn.h"

bool Pawn::isLegalMove(Location src, Location dst, const Board* board)
/**
 * Checks if a move from the source location to the destination location is legal for a Pawn.
 *
 * @param src The source location of the Pawn.
 * @param dst The destination location of the Pawn.
 * @return True if the move is legal, false otherwise.
 */
{
	if (color == WHITE)
	{
		if (src.c == dst.c) // Check for vertical movement
		{
			if (src.r + 1 == dst.r)
				return true;
			if (src.r == 1 && dst.r == 3 && board->getValueFromMat(2, src.c) == nullptr)
				return true;
		}
		else              // Check for capturing diagonally
			if ((abs(dst.c - src.c) == 1) && (dst.r == src.r + 1) && (board->getValueFromMat(dst.r, dst.c) != nullptr))
				return true;
	}
	else //color == BLACK 
	{
		if (src.c == dst.c)  // Check for vertical movement
		{
			if (src.r - 1 == dst.r)
				return true;
			if (src.r == 6 && dst.r == 4 && board->getValueFromMat(5, src.c) == nullptr)
				return true;
		}
		else             // Check for capturing diagonally
			if ((abs(dst.c - src.c) == 1) && (dst.r == src.r - 1) && (board->getValueFromMat(dst.r, dst.c) != nullptr))
				return true;

	}
	return false;
}