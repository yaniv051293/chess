#include "Queen.h"
#include "Bishop.h"
#include "Rook.h"

bool Queen::isLegalMove(Location src, Location dst, const Board* board)
/**
 * Checks if a move from the source location to the destination location is legal for a Queen.
 *
 * @param src The source location of the Queen.
 * @param dst The destination location of the Queen.
 * @return True if the move is legal, false otherwise.
 */
{
	Rook rook(color);
	Bishop bishop(color);
	// Check if the move is legal for either Rook or Bishop
	if (rook.isLegalMove(src, dst, board) || bishop.isLegalMove(src, dst, board))
		return true;
	return false;
}