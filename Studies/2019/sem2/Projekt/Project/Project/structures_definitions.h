#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>


/**
 * @brief board represents matrice of pieces
 *
 */
typedef struct
{
	struct piece *box[8][8];
} board;



/**
 * @brief point represents x,y point on the board
 *
 */
typedef struct
{
	int x;
	int y;
} point;

/**
 * @brief possibleMoves contains list of possible moves for given piece
 *
 */
typedef struct
{
	point* pointList;
	int length;
} possibleMoves;

/**
 * @brief moves generates possible moves for piece
 *
 */
typedef possibleMoves(*moves)(board* const, point*);

/**
 * @brief piece represents chess piece
 *
 */
typedef enum { pawn, rook, knight, bishop, queen, king, unknown } pieceType;

typedef struct
{
	bool player;
	pieceType type;
	char symbol;
	moves Moves;
} piece;

/**
 * @brief move represents desired move of piece
 *
 */
typedef struct
{
	point piece;
	point to;
} move;