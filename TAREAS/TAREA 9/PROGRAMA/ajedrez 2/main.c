#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>

#define BOARD_SIZE 8

typedef enum { EMPTY, PAWN, KNIGHT, BISHOP, ROOK, QUEEN, KING } PieceType;
typedef enum { WHITE, BLACK, NONE } Color;

typedef struct {
    PieceType type;
    Color color;
} Piece;

typedef struct {
    Piece board[BOARD_SIZE][BOARD_SIZE];
    Color turn;
} GameState;

#ifdef _WIN32
    #define CLEAR "cls"
#else
    #define CLEAR "clear"
#endif
void clear_screen() {
    system(CLEAR);
}

const char *piece_unicode(PieceType type, Color color) {
    if (color == WHITE) {
        switch (type) {
            case PAWN:   return "♙";
            case KNIGHT: return "♘";
            case BISHOP: return "♗";
            case ROOK:   return "♖";
            case QUEEN:  return "♕";
            case KING:   return "♔";
            default:     return " ";
        }
    } else if (color == BLACK) {
        switch (type) {
            case PAWN:   return "♟";
            case KNIGHT: return "♞";
            case BISHOP: return "♝";
            case ROOK:   return "♜";
            case QUEEN:  return "♛";
            case KING:   return "♚";
            default:     return " ";
        }
    }
    return " ";
}

int piece_value(PieceType type) {
    switch(type) {
        case PAWN: return 10;
        case KNIGHT: return 30;
        case BISHOP: return 30;
        case ROOK: return 50;
        case QUEEN: return 90;
        case KING: return 900;
        default: return 0;
    }
}

void init_board(GameState *game) {
    memset(game, 0, sizeof(GameState));
    game->turn = WHITE;
    for(int i=0; i<BOARD_SIZE; i++) {
        game->board[1][i] = (Piece){ PAWN, BLACK };
        game->board[6][i] = (Piece){ PAWN, WHITE };
    }
    PieceType backrow[8] = { ROOK, KNIGHT, BISHOP, QUEEN, KING, BISHOP, KNIGHT, ROOK };
    for(int i=0; i<BOARD_SIZE; i++) {
        game->board[0][i] = (Piece){ backrow[i], BLACK };
        game->board[7][i] = (Piece){ backrow[i], WHITE };
    }
}

void print_board(GameState *game) {
    printf("\n     a   b   c   d   e   f   g   h  \n");
    printf("   +---+---+---+---+---+---+---+---+\n");
    for(int i=0; i<BOARD_SIZE; i++) {
        printf(" %d |", 8-i);
        for(int j=0; j<BOARD_SIZE; j++) {
            Piece p = game->board[i][j];
            const char *symbol = piece_unicode(p.type, p.color);
            printf(" %s |", symbol);
        }
        printf(" %d\n", 8-i);
        printf("   +---+---+---+---+---+---+---+---+\n");
    }
    printf("     a   b   c   d   e   f   g   h  \n\n");
}

int is_path_clear(GameState *game, int sx, int sy, int dx, int dy) {
    int stepx = (dx - sx) ? ((dx - sx) > 0 ? 1 : -1) : 0;
    int stepy = (dy - sy) ? ((dy - sy) > 0 ? 1 : -1) : 0;
    int x = sx + stepx, y = sy + stepy;
    while (x != dx || y != dy) {
        if (game->board[x][y].type != EMPTY) return 0;
        x += stepx;
        y += stepy;
    }
    return 1;
}

int is_valid_move(GameState *game, int sx, int sy, int dx, int dy) {
    if(sx < 0 || sx >= 8 || sy < 0 || sy >= 8 || dx < 0 || dx >= 8 || dy < 0 || dy >= 8) return 0;
    Piece src = game->board[sx][sy];
    Piece dst = game->board[dx][dy];
    if(src.type == EMPTY || src.color != game->turn) return 0;
    if(dst.type != EMPTY && dst.color == src.color) return 0;

    int dxAbs = abs(dx-sx), dyAbs = abs(dy-sy);

    switch(src.type) {
        case PAWN: {
            int dir = (src.color == WHITE) ? -1 : 1;
            if(dy == sy && dx == sx + dir && dst.type == EMPTY) return 1;
            if(dy == sy && ((src.color == WHITE && sx == 6 && dx == 4) || (src.color == BLACK && sx == 1 && dx == 3))
                && dst.type == EMPTY && game->board[sx+dir][sy].type == EMPTY) return 1;
            if(dx == sx + dir && dyAbs == 1 && dst.type != EMPTY && dst.color != src.color) return 1;
            break;
        }
        case KNIGHT:
            if((dxAbs == 2 && dyAbs == 1) || (dxAbs == 1 && dyAbs == 2)) return 1;
            break;
        case BISHOP:
            if(dxAbs == dyAbs && is_path_clear(game, sx, sy, dx, dy)) return 1;
            break;
        case ROOK:
            if((dx == sx || dy == sy) && is_path_clear(game, sx, sy, dx, dy)) return 1;
            break;
        case QUEEN:
            if(((dx == sx || dy == sy) || (dxAbs == dyAbs)) && is_path_clear(game, sx, sy, dx, dy)) return 1;
            break;
        case KING:
            if(dxAbs <= 1 && dyAbs <= 1) return 1;
            break;
        default: break;
    }
    return 0;
}

int move_piece(GameState *game, int sx, int sy, int dx, int dy) {
    if(!is_valid_move(game, sx, sy, dx, dy)) return 0;
    game->board[dx][dy] = game->board[sx][sy];
    game->board[sx][sy].type = EMPTY;
    game->board[sx][sy].color = NONE;
    game->turn = (game->turn == WHITE) ? BLACK : WHITE;
    return 1;
}

int eval(GameState *game) {
    int score = 0;
    for(int i=0; i<8; i++)
        for(int j=0; j<8; j++)
            if(game->board[i][j].type != EMPTY)
                score += (game->board[i][j].color == WHITE ? 1 : -1) * piece_value(game->board[i][j].type);
    return score;
}

int minimax(GameState *game, int depth, int maximizing, int *fromX, int *fromY, int *toX, int *toY) {
    if(depth == 0) return eval(game);
    int bestScore = maximizing ? INT_MIN : INT_MAX;
    for(int sx=0; sx<8; sx++) {
        for(int sy=0; sy<8; sy++) {
            Piece p = game->board[sx][sy];
            if(p.type == EMPTY || p.color != (maximizing ? BLACK : WHITE)) continue;
            for(int dx=0; dx<8; dx++) {
                for(int dy=0; dy<8; dy++) {
                    if(is_valid_move(game, sx, sy, dx, dy)) {
                        GameState copy = *game;
                        move_piece(&copy, sx, sy, dx, dy);
                        int score = minimax(&copy, depth-1, !maximizing, NULL, NULL, NULL, NULL);
                        if(maximizing && score > bestScore) {
                            bestScore = score;
                            if(fromX) { *fromX = sx; *fromY = sy; *toX = dx; *toY = dy; }
                        }
                        if(!maximizing && score < bestScore) {
                            bestScore = score;
                            if(fromX) { *fromX = sx; *fromY = sy; *toX = dx; *toY = dy; }
                        }
                    }
                }
            }
        }
    }
    return bestScore;
}

int is_checkmate(GameState *game, Color color) {
    for(int i=0; i<8; i++)
        for(int j=0; j<8; j++)
            if(game->board[i][j].type == KING && game->board[i][j].color == color)
                return 0;
    return 1;
}

int main() {
    GameState game;
    init_board(&game);

    char move[10];
    printf("Bienvenido al Ajedrez.\n");
    printf("Juegas con blancas. Mueve usando notación tipo e2e4.\n");
    printf("IA juega negras. Para salir, presiona Ctrl+C.\n\n");

    while(1) {
        clear_screen();
        print_board(&game);
        if(is_checkmate(&game, game.turn)) {
            printf("¡Jaque mate! %s gana.\n", game.turn == WHITE ? "Negras" : "Blancas");
            break;
        }
        if(game.turn == WHITE) {
            printf("Tu movimiento (ejemplo e2e4): ");
            scanf("%s", move);
            for(int i=0; move[i]; i++) move[i] = tolower(move[i]);
            if(strlen(move) < 4 || move[0] < 'a' || move[0] > 'h' || move[2] < 'a' || move[2] > 'h') {
                printf("Formato inválido, usa notación tipo e2e4.\n");
                while (getchar() != '\n');
                continue;
            }
            int sx = 8 - (move[1] - '0');
            int sy = move[0] - 'a';
            int dx = 8 - (move[3] - '0');
            int dy = move[2] - 'a';
            if(!move_piece(&game, sx, sy, dx, dy)) {
                printf("Movimiento inválido.\n");
                while (getchar() != '\n');
            }
        } else {
            int fx, fy, tx, ty;
            printf("IA pensando...\n");
            minimax(&game, 3, 1, &fx, &fy, &tx, &ty);
            printf("IA mueve: %c%d%c%d\n", 'a'+fy, 8-fx, 'a'+ty, 8-tx);
            move_piece(&game, fx, fy, tx, ty);
            while (getchar() != '\n');
        }
    }
    return 0;
}
