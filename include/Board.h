#pragma once
#include "Piece.h"
#include <string>
#include "Color.h"
class Piece;
using namespace std;

class Board
{
private:
	Color whoTurn;              	// Current turn color
	Piece* board[8][8];             // 2D array representing the game board

	// Helper functions for move validation
	bool isSourceEmpty(Location src);                   //	11 - there is not piece at the source
	bool isSourceNotYours(Location src);				//  12 - the piece in the source is piece of your opponent
	bool isDestFull(Location dest);                    //	13 - the piece in the source is piece of yours
	bool isSelfCheckmate(Location src, Location dst);  //	31 - this movement will cause you checkmate

	// Check if a player has a checkmate position
	bool isHasCheckmate( Color color);

	// Find the location of the king of the given color
	Location findKingLocation(Color color);
public:
	Board(string gameState = "RNBQKBNRPPPPPPPP################################pppppppprnbqkbnr");
	
	int playMove(string move);
	Piece* getValueFromMat(int r, int c) const;
	~Board();
	

};