#include "Rook.h"
#include "Board.h"


bool Rook::isLegalMove(Location src, Location dst, const Board* board)
/**
 * Checks if a move from the source location to the destination location is legal for a Rook.
 *
 * @param src The source location of the Rook.
 * @param dst The destination location of the Rook.
 * @return True if the move is legal, false otherwise.
 */
{
	if (src.c == dst.c)
	{
		// Check for vertical movement
		int bigger = max(src.r, dst.r);
		for (int i = min(src.r, dst.r) + 1; i < bigger; i++)
		{
			// Check if there is any piece obstructing the vertical path
			if (board->getValueFromMat(i, src.c) != nullptr)
				return false;
		}
		return true;
	}
	else if (src.r == dst.r)
	{         // Check for horizontal movement
		int bigger = max(src.c, dst.c);
		for (int i = min(src.c, dst.c) + 1; i < bigger; i++)
		{
			// Check if there is any piece obstructing the vertical path
			if (board->getValueFromMat(src.r, i) != nullptr)
				return false;
		}
		return true;
	}
	else
		// Invalid move if it is neither vertical nor horizontal
		return false;
}