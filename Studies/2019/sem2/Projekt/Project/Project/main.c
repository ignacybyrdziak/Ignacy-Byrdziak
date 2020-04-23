#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#include "moves_definitions.h"
#include "programm_operating_definitions.h"
#include "structures_definitions.h"
 
int main(void)
{
	int interfaceOption;
	move *nextMove;
	int turn = 0;
	printf("\nType 1 if you want to start a new game or 0 if you want to quit\n\nBig letters stands for black pieces and small ones for white pieces\n\n");
	scanf_s("%d", &interfaceOption);
	printf("\n");
	board chessboard = starting_board();
	while (interfaceOption != 0)
	{
		draw_board(chessboard);
		printf("\n\n");
		if (turn % 2 == 0)
		{
			printf("White player turn:\n\n");
		}
		else
		{
			printf("Black player turn:\n\n");
		}
		nextMove = getting_coordinates();
		if (nextMove == NULL)
		{
			// There was invalid format need to retry.
			continue;
		}
		if (nextMove->piece.x == -1)
		{
			interfaceOption = 0;
			break;
		}

		piece *pieceToMove = chessboard.box[nextMove->piece.y][nextMove->piece.x];
		if (pieceToMove == NULL)
		{
			printf("no piece on selected place, please retry\n");
			continue;
		}
		possibleMoves allowedMoves = pieceToMove->Moves(&chessboard, &nextMove->piece);

		if (violatesChessRules(chessboard, nextMove))
		{
			continue;
		}
		if (!allowedMove(&nextMove->to, allowedMoves)) {
			printf("move not allowed! Please retry\n");
			continue;
		}

		piece *pieceToReplace = (piece *)chessboard.box[nextMove->to.y][nextMove->to.x];
		if (pieceToReplace != NULL)
		{
			free(pieceToReplace);
		}
		chessboard.box[nextMove->piece.y][nextMove->piece.x] = NULL;
		chessboard.box[nextMove->to.y][nextMove->to.x] = pieceToMove;
		free(nextMove);
		turn++;
	}

	printf("Goodbye\n");
	return 0;
}