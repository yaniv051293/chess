#include "Board.h"
#include "Rook.h"
#include "King.h"
#include "Bishop.h"
#include "Queen.h"
#include "Pawn.h"
#include "Knight.h"


Board::Board(string gameState):board{}
{
	for (int i = 0; i < gameState.size(); i++)
	{
		whoTurn = WHITE;
		switch (gameState[i])
		{
		case 'R':
			board[i / 8][i % 8 ]= new Rook(WHITE);
			break;
		case 'r':
			board[i / 8][i % 8] = new Rook(BLACK);
			break;
		case 'K':
			board[i / 8][i % 8] =new King(WHITE);
			break;
		case 'k':
			board[i / 8][i % 8] = new King(BLACK);
			break;
		case 'B':
			board[i / 8][i % 8] = new Bishop(WHITE);
			break;
		case 'b':
			board[i / 8][i % 8] = new Bishop(BLACK);
			break;
		case 'Q':
			board[i / 8][i % 8] = new Queen(WHITE);
			break;
		case 'q':
			board[i / 8][i % 8] = new Queen(BLACK);
			break;
		case 'P':
			board[i / 8][i % 8] = new Pawn(WHITE);
			break;
		case 'p':
			board[i / 8][i % 8] = new Pawn(BLACK);
			break;
		case 'N':
			board[i / 8][i % 8] = new Knight(WHITE);
			break;
		case 'n':
			board[i / 8][i % 8] = new Knight(BLACK);
			break;
		case '#':
			board[i / 8][i % 8] = nullptr;
			break;
		default:
			board[i / 8][i % 8] = nullptr;
			break;
		}
	}
}

Board::~Board() {
	// Delete dynamically allocated pieces in the board array
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			delete board[i][j];
		}
	}
}


int Board::playMove(string move)
/**
 * Play a move on the board.
 *
 * @param move The move string in standard algebraic notation (e.g., "e2e4").
 * @return 0 if the move is successful, otherwise an error code.
 */
{
	Location src(move.substr(0, 3));
	Location dest(move.substr(2, 3));
	if (isSourceEmpty(src))             //   if there is not piece at the source
		return	11;
	else if (isSourceNotYours(src))     //   if the piece in the source is piece of your opponent
		return 12;
	else if (isDestFull(dest))         //	if there one of your pieces at the destination
		return 13;
	else if (!board[src.r][src.c]->isLegalMove(src, dest,this))
		return 21;
	else if (isSelfCheckmate(src, dest)) //	if this movement will cause you checkmate
		return 31;

	// do the move
	board[dest.r][dest.c] = board[src.r][src.c];
	board[src.r][src.c] = nullptr;
	whoTurn = (whoTurn == WHITE) ? BLACK : WHITE;

	if (isHasCheckmate(whoTurn)) // if you make check to the opponent
		return 41;
	else
		return 42;
}

bool Board::isSourceEmpty(Location src)
{
	if (board[src.r][ src.c] == nullptr)
		return true;
	return false;
}

bool Board::isSourceNotYours(Location src)
//   if the piece in the source is piece of your opponent
{
	if (board[src.r][src.c] != nullptr && board[src.r][src.c]->getColor() != whoTurn)
		return true;
	return false;
}

bool Board::isDestFull(Location dest)
//	return true if there one of your pieces at the destination
{
	if (board[dest.r][dest.c] != nullptr && board[dest.r][dest.c]->getColor() == whoTurn)
		return true;
	return false;
}

Location Board::findKingLocation(Color color)
/**
 * Find the location of the King of the specified color on the board.
 *
 * @param color The color of the King to find.
 * @return The location of the King.
 */
{
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			// Check if the piece at the current location is a King of the specified color
			if (board[i][j] != nullptr && typeid(*(board[i][j])) == typeid(King) && (*board[i][j]).getColor() == color)
				return Location(i, j);
	throw std::runtime_error("King of the specified color not found on the board.");
}

bool Board::isSelfCheckmate(Location src, Location dst)
/**
 * Checks if a move from the source location to the destination location will result in self-checkmate.
 *
 * @param src The source location of the piece to move.
 * @param dst The destination location to move the piece to.
 * @return True if the move will result in self-checkmate, false otherwise.
 */
{
	Piece* tmp=board[dst.r][dst.c];
	board[dst.r][dst.c] = board[src.r][src.c];
	board[src.r][src.c] = nullptr;
	bool causeChess;
	if (isHasCheckmate(whoTurn))
		causeChess = true;
	else
		causeChess = false;
	board[src.r][src.c]= board[dst.r][dst.c];
	board[dst.r][dst.c]=tmp;
	return causeChess;
}

bool Board::isHasCheckmate(Color color)
/**
 * Checks if the specified color is in a checkmate position.
 *
 * @param color The color to check for checkmate.
 * @return True if the specified color is in checkmate, false otherwise.
 */
{
	Location kingLocation = findKingLocation(color);
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			if ((board[i][j] != nullptr && (*board[i][j]).getColor() != color) // if there is here piece of the opposite
				&& (*board[i][j]).isLegalMove(Location(i, j), kingLocation,this))      // and it cause chess on the king
			{
				return true;
			}
	return false;
}


Piece* Board:: getValueFromMat(int r, int c) const
/**
 * Get the piece pointer from a specific board location.
 *
 * @param r The row index of the board location.
 * @param c The column index of the board location.
 * @return A pointer to the piece at the specified location.
 */
{
	return board[r][c];
}

