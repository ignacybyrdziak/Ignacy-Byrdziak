#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>

#include "moves_definitions.h"

bool captureSelf(board chessboard, move *nm)
{
	piece *src = (piece *)chessboard.box[nm->piece.y][nm->piece.x];
	piece *dst = (piece *)chessboard.box[nm->to.y][nm->to.x];
	if (dst == NULL) {
		return false;
	}
	if (src->player == dst->player) {
		printf("can't capture self\n");
		return true;
	}
	return false;
}

bool violatesChessRules(board chessboard, move *nm)
{
	return captureSelf(chessboard, nm) || false;
}

move *getting_coordinates()
{
	move *currentMove = (move *)malloc(sizeof(move));
	char readBuffer[120];
	int reads = 0;
	char pieceX = 0;
	char toX = 0;
	int pieceY = 0;
	int toY = 0;

	printf("Type coordinates of chess piece you want to move and desired destination eg. a1-a2 or A1-A2.\n\n");
	scanf_s("%100s", readBuffer);
	// Check for exit...
	reads = sscanf_s(readBuffer, "%d", &toY);
	if (reads == 1 && toY == 0)
	{
		// return impossible move to indicate loop break.
		currentMove->piece.x = -1;
		return currentMove;
	}
	reads = sscanf_s(readBuffer, "%c%d-%c%d", &pieceX, &pieceY, &toX, &toY);
	printf("\n");
	if (reads != 4)
	{
		printf("failed to parse your move, please retry. Fromat: a1-a2 or A1-A2, reads: %d\n", reads);
		return NULL;
	}
	pieceX = toupper(pieceX);
	toX = toupper(toX);

	currentMove->piece.x = pieceX - 65;
	currentMove->piece.y = pieceY - 1;
	currentMove->to.x = toX - 65;
	currentMove->to.y = toY - 1;

	printf("%d %d -- %d %d\n", currentMove->piece.x, currentMove->piece.y, currentMove->to.x, currentMove->to.y);


	if (!moveInsideBoardRanges(currentMove)) {
		printf("desired move is outside board ranges\n");
		return NULL;
	}

	return currentMove;
}

bool moveInsideBoardRanges(move *nm)
{
	return nm->piece.x < 8 && nm->piece.x >= 0 &&
		nm->piece.y < 8 && nm->piece.y >= 0 &&
		nm->to.x < 8 && nm->to.x >= 0 &&
		nm->to.y < 8 && nm->to.y >= 0;
}

bool allowedMove(point *nm, possibleMoves pm)
{
	for (int i = 0; i < pm.length; i++) {
		point *pmp = pm.pointList + i;
		printf("%d %d -- %d %d\n", nm->x, nm->y, pmp->x, pmp->y);
		if (nm->x == pmp->x && nm->y == pmp->y) {
			return true;
		}
	}
	return false;
}


possibleMoves move_pawn(board *chessboard, point *coordinates)
{
	possibleMoves pm;
	pm.pointList = calloc(3, sizeof(point));
	pm.length = 0;
	piece *pawn = (piece *)chessboard->box[coordinates->y][coordinates->x];
	int direction = pawn->player ? 1 : -1;

	// Move forward if clear.
	if (!chessboard->box[coordinates->y + direction][coordinates->x])
	{
		point *newPoint = &pm.pointList[pm.length];
		newPoint->x = coordinates->x;
		newPoint->y = coordinates->y + direction;
		pm.length++;
	}
	return pm;
}

possibleMoves move_rook(board *chessboard, point *coordinates)
{
	possibleMoves pm;
	pm.pointList = (point *)calloc(16, sizeof(point));
	pm.length = 0;

	piece *rook = (piece *)chessboard->box[coordinates->x][coordinates->y];
	//	if (rook->player == true)
	//	{
	if (chessboard->box[(coordinates->x) + 1][coordinates->y])
	{
		point *newPoint = pm.pointList + pm.length;
		newPoint->x = 1;
		newPoint->y = 2;
		pm.length++;
	}
	pm.length++;
	//	}

	return pm;
}

possibleMoves move_knight(board *chessboard, point *coordinates)
{
	piece *knight = &chessboard->box[coordinates->x][coordinates->y];
	possibleMoves pm = (possibleMoves) { .length = 0 };
	return pm;
}

possibleMoves move_bishop(board *chessboard, point *coordinates)
{
	piece *bishop = &chessboard->box[coordinates->x][coordinates->y];
	possibleMoves pm = (possibleMoves) { .length = 0 };
	return pm;
}

possibleMoves move_queen(board *chessboard, point *coordinates)
{
	piece *queen = &chessboard->box[coordinates->x][coordinates->y];
	possibleMoves pm = (possibleMoves) { .length = 0 };
	return pm;
}

possibleMoves move_king(board *chessboard, point *coordinates)
{
	piece *king = &chessboard->box[coordinates->x][coordinates->y];
	possibleMoves pm = (possibleMoves) { .length = 0 };
	return pm;
}

//struct coordinates line_move(int currentXcoordinate, int currentYcoordinate, int targetXcoordinate, int targetYcoordinate)
//{
//	struct coordinates coord;
//	char MoveOnXAxis, MoveOnYAxis;
//
//	if (currentXcoordinate < targetXcoordinate)
//		MoveOnXAxis = 'r'; //move right
//
//	else if (currentXcoordinate > targetXcoordinate)
//		MoveOnXAxis = 'l'; //move left
//
//	else
//		MoveOnXAxis = 's'; //stay on the same field
//
//	if (currentXcoordinate < targetYcoordinate)
//		MoveOnYAxis = 'u'; //move up
//
//	else if (currentYcoordinate > targetYcoordinate)
//		MoveOnYAxis = 'd'; //move down
//
//	else
//		MoveOnYAxis = 's'; //stay on the same field
//
//	int X = currentXcoordinate;
//	int Y = currentYcoordinate;
//	int counter = 0;
//
//	while (X != targetXcoordinate || Y != targetYcoordinate)
//	{
//		coord.x[counter] = X;
//		coord.y[counter] = Y;
//		coord.MoveLenghtCounter++;
//		counter++;
//
//		if (MoveOnXAxis == 'r')
//			X++;
//		else if (MoveOnXAxis == 'l')
//			X--;
//		else if (MoveOnYAxis == 'u')
//			Y++;
//		else if (MoveOnYAxis == 'd')
//			Y--;
//	}
//
//	coord.x[counter] = X;
//	coord.y[counter] = Y;
//	coord.MoveLenghtCounter++;
//
//	return coord;
//}
//
//struct coordinates diagonal_move(int currentXcoordinate, int currentYcoordinate, int targetXcoordinate, int targetYcoordinate)
//{
//	struct coordinates coord;
//	char MoveOnXAxis, MoveOnYAxis;
//
//	if (currentXcoordinate < targetXcoordinate)
//		MoveOnXAxis = 'r'; //move right
//
//	else if (currentXcoordinate > targetXcoordinate)
//		MoveOnXAxis = 'l'; //move left
//
//	else
//		MoveOnXAxis = 's'; //stay on the same field
//
//	if (currentXcoordinate < targetYcoordinate)
//		MoveOnYAxis = 'u'; //move up
//
//	else if (currentYcoordinate > targetYcoordinate)
//		MoveOnYAxis = 'd'; //move down
//
//	else
//		MoveOnYAxis = 's'; //stay on the same field
//
//	int X = currentXcoordinate;
//	int Y = currentYcoordinate;
//	int counter = 0;
//
//	while (X != targetXcoordinate || Y != targetYcoordinate)
//	{
//		coord.x[counter] = X;
//		coord.y[counter] = Y;
//		coord.MoveLenghtCounter++;
//		counter++;
//
//		if (MoveOnXAxis == 'r')
//			X++;
//		else if (MoveOnXAxis == 'l')
//			X--;
//		else if (MoveOnYAxis == 'u')
//			Y++;
//		else if (MoveOnYAxis == 'd')
//			Y--;
//	}
//
//	coord.x[counter] = X;
//	coord.y[counter] = Y;
//	coord.MoveLenghtCounter++;
//
//	return coord;
//}