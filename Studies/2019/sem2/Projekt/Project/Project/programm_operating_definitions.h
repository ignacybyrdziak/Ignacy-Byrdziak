#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#include "structures_definitions.h"

void draw_board(board data);

board starting_board();

piece* pieceFactory(pieceType type, bool player);

char symbol(bool player, pieceType type);

bool violatesChessRules(board, move *);

bool captureSelf(board chessboard, move *nm);