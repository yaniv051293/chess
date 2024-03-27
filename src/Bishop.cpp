#include "Bishop.h"

bool Bishop::isLegalMove(Location src, Location dst, const Board* board)
{
/**
 * Checks if a move from the source location to the destination location is legal for a Bishop.
 *
 * @param src The source location of the Bishop.
 * @param dst The destination location of the Bishop.
 * @return True if the move is legal, false otherwise.
 */
	int dy = dst.c - src.c;
	int dx = dst.r - src.r;

	// Check if the movement is diagonal
	if (abs(dx) != abs(dy))
		return false;

	// Check if any piece obstructs the movement path
	for (int i = 1; i < abs(dx); i++)
	{
		int col, row;
		// Determine the next position on the diagonal path
		if (dx > 0)
			row = src.r + i;
		else
			row = src.r - i;
		if (dy > 0)
			col = src.c + i;
		else
			col = src.c - i;
		// Check if there is a piece at the next position
		if (board->getValueFromMat(row, col) != nullptr)
			return false;
	}
	// The move is legal if no obstructions were found
	return true;
}