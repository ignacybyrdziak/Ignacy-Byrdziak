#pragma once

#include "structures_definitions.h"

//struct coordinates diagonal_move(int currentXcoordinate, int currentYcoordinate, int targetXcoordinate, int targetYcoordinate);

//struct coordinates line_move(int currentXcoordinate, int currentYcoordinate, int targetXcoordinate, int targetYcoordinate);

move* getting_coordinates();

possibleMoves move_king(board *chessboard, point *coordinates);

possibleMoves move_queen(board *chessboard, point *coordinates);

possibleMoves move_bishop(board *chessboard, point *coordinates);

possibleMoves move_knight(board *chessboard, point *coordinates);

possibleMoves move_rook(board *chessboard, point *coordinates);

possibleMoves move_pawn(board *chessboard, point *coordinates);

bool moveInsideBoardRanges(move*);

bool allowedMove(point*, possibleMoves);
