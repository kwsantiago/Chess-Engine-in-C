#ifndef DEFS_H	
#define DEFS_H

#include <stdlib.h>

// This debugging definition is from the book "Beginning Programming in C++"
// Very important for debugging
#define DEBUG // comment out if not needed

#ifndef DEBUG
#define ASSERT(n)
#else
#define ASSERT(n) \
if(!(n)){ \
printf("%s - Failed",#n); \
printf("On %s ", __DATE__); \
printf("At %s ", __TIME__); \
printf("In File %s ", __FILE__); \
printf("At Line %d\n ", __LINE__); \
exit(1);}
#endif

typedef unsigned long long U64;

#define NAME "Vice 1.0"
#define BRD_SQ_NUM 120

#define MAXGAMEMOVES 2048

enum { EMPTY, wP, wN, wB, wR, wQ, wK, bP, bN, bB, bR, bQ, bK };
enum { FILE_A, FILE_B, FILE_C, FILE_D, FILE_E, FILE_F, FILE_G, FILE_H, FILE_NONE };
enum { RANK_1, RANK_2, RANK_3, RANK_4, RANK_5, RANK_6, RANK_7, RANK_8, RANK_NONE };
enum { WHITE, BLACK, BOTH };

enum {
    A1 = 21, B1, C1, D1, E1, F1, G1, H1,
    A2 = 31, B2, C2, D2, E2, F2, G2, H2,
    A3 = 41, B3, C3, D3, E3, F3, G3, H3,
    A4 = 51, B4, C4, D4, E4, F4, G4, H4,
    A5 = 61, B5, C5, D5, E5, F5, G5, H5,
    A6 = 71, B6, C6, D6, E6, F6, G6, H6,
    A7 = 81, B7, C7, D7, E7, F7, G7, H7,
    A8 = 91, B8, C8, D8, E8, F8, G8, H8, NO_SQ
};

enum { FALSE, TRUE };

enum { WKCA = 1, WQCA = 2, BKCA = 4, BQCA = 8}; // Castling move

typedef struct{
    int move;
    int castlePerm; // Castle permission
    int enPas; // En passant square
    int fiftyMove;
    U64 posKey; 
} S_UNDO; // before move was made

typedef struct{
    int pieces[BRD_SQ_NUM];
    U64 pawns[3];

    int KingSq[2];

    int side;
    int enPas; // En passant square
    int fiftyMove; // Draw if fifity moves hit

    int ply; // how many half moves
    int hisPly; // how many half moves total

    int castlePerm; // Castling move

    U64 posKey; // unique key for each position

    int pceNum[13]; // Number of pieces on the board
    int bigPce[3]; // anything that isn't a pawn and sorted by color
    int majPce[3]; // rooks and queens
    int minPce[3]; // bishop and knights

    S_UNDO history[MAXGAMEMOVES]; // history of all moves
     
    int pList[13][10]; // piece list

} S_BOARD;

// MACROS
#define FR2SQ(f, r) ((21+(f))+((r)*10)) // return 120 array based number for given square 
#define SQ64(sq120) Sq120ToSq64[sq120]

// GLOBALS
extern int Sq120ToSq64[BRD_SQ_NUM]; 
extern int Sq64ToSq120[64]; // Convert board from the array and vice versa

// FUNCTIONS

// init.c
extern void AllInIt();

// bitboards.c
extern void PrintBitBoard(U64 bb);

#endif