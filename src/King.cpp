#include "king.h"

bool King::isLegalMove(Location src, Location dst, const Board* board)
/**
 * Checks if a move from the source location to the destination location is legal for a King.
 *
 * @param src The source location of the King.
 * @param dst The destination location of the King.
 * @return True if the move is legal, false otherwise.
 */
{
    // Check if the destination location is within one square in any direction 
    if (abs(src.c - dst.c) > 1 || abs(src.r - dst.r) > 1)
        return false;
    return true;
}