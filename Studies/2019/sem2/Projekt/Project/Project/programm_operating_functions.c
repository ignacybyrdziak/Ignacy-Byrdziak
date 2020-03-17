#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#include "programm_operating_definitions.h"
#include "moves_definitions.h"

board 	starting_board()
{
	pieceType chessboard[8][8] = {
		{rook, knight, bishop, queen, king, bishop, knight, rook},
		{pawn, pawn, pawn, pawn, pawn, pawn, pawn, pawn},
		{unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown},
		{unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown},
		{unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown},
		{unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown},
		{pawn, pawn, pawn, pawn, pawn, pawn, pawn, pawn},
		{rook, knight, bishop, queen, king, bishop, knight, rook},
	};

	board InitialBoard;

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			InitialBoard.box[i][j] = pieceFactory(chessboard[i][j], i > 3 ? false : true); //true is white player, false is black
		}
	}

	return InitialBoard;
}

void draw_board(board data)
{
	char symbolBoard[8][8];
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			piece *p = data.box[i][j];
			if (p != NULL)
			{
				symbolBoard[i][j] = symbol(p->player, p->type);
				continue;
			}
			symbolBoard[i][j] = '_';
		}
	}
	char X[8] = { '1', '2', '3', '4', '5', '6', '7', '8' };
	char Y[8] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H' };

	for (int i = 0; i < 10; i++)
	{
		printf("\t");
		for (int j = 0; j < 8; j++)
		{
			if (i == 0)
			{
				printf("%c ", Y[j]);
				continue;
			}
			if (i == 1)
			{
				printf("_ ");
				if (j == 7)
				{
					printf("\n");
				}
				continue;
			}
			printf("%c ", symbolBoard[i - 2][j]);
			if (j == 7)
			{
				printf("  | %c \n", X[i - 2]);
			}
		}
		printf("\n");
	}
}

void save_game()
{
	return;
}

void load_game()
{
	return;
}

piece *pieceFactory(pieceType type, bool player)
{
	piece *p = malloc(sizeof(piece));
	p->player = player;
	p->type = type;
	p->symbol = symbol(player, type);
	switch (type)
	{
	case pawn:
	{
		p->Moves = move_pawn;
		return p;
	}
	case rook:
	{
		p->Moves = move_knight;
		return p;
	}
	case knight:
	{
		p->Moves = move_knight;
		return p;
	}
	case bishop:
	{
		p->Moves = move_bishop;
		return p;
	}
	case queen:
	{
		p->Moves = move_queen;
		return p;
	}
	case king:
	{
		p->Moves = move_king;
		return p;
	}
	default:
	{
		return NULL;
	}
	}
}

char symbol(bool player, pieceType type)
{
	switch (type)
	{
	case pawn:
	{
		return player ? 'p' : 'P';
	}
	case rook:
	{
		return player ? 'r' : 'R';
	}
	case knight:
	{
		return player ? 'n' : 'N';
	}
	case king:
	{
		return player ? 'k' : 'K';
	}
	case queen:
	{
		return player ? 'q' : 'Q';
	}
	case bishop:
	{
		return player ? 'b' : 'B';
	}
	default:
	{
		return ' ';
	}
	}
}
