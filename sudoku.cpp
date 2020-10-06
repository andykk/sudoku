// sample implementation of solving Sudoku problems

#include <stdio.h>

#define SIZE   9
#define EMPTY  ' '

struct prob_t {
   char board[SIZE][SIZE];
};

void readProb( prob_t &p )
{
   char tmp;
   for ( int i = 0; i < SIZE; i++ ) {
      scanf( "%9c%c", p.board[ i ], &tmp );
      for ( int j = 0; j < SIZE; j++ ) {
         if ( p.board[ i ][ j ] != EMPTY )
            p.board[ i ][ j ] -= '0';
      }
   }
}

void printBoard( prob_t &p )
{
   printf( "-----------\n" );
   for ( int x = 0; x < SIZE; x++ ) {
      printf( "|" );
      for ( int y = 0; y < SIZE; y++ ) {
         printf( "%c", p.board[ x ][ y ] == EMPTY ? '.' : 
               p.board[ x ][ y ] + '0' );
      }
      printf( "|\n" );
   }
   printf( "-----------\n" );
}

int check( prob_t &p, int x, int y, int val )
{
   for ( int i = 0; i < SIZE; i++ ) {
      if ( p.board[ i ][ y ] == val || p.board[ x ][ i ] == val )
         return 0;
   }
   int x1 = x / 3;
   int y1 = y / 3;
   for ( int i = 0; i < 3; i++ ) {
      for ( int j = 0; j < 3; j++ ) {
         if ( p.board[ x1 * 3 + i ][ y1 * 3 + j ] == val )
            return 0;
      }
   }
   return 1;
}

int solve( prob_t &p )
{
   int filled = 0;
   for ( int x = 0; x < SIZE; x++ ) {
      for ( int y = 0; y < SIZE; y++ ) {
         if ( p.board[ x ][ y ] == EMPTY ) {
            for ( int val = 1; val <= 9; val++ ) {
               if ( check( p, x, y, val ) ) {
                  p.board[ x ][ y ] = val;
                  if ( solve( p ) )
                     return 1;
               }
            }
            p.board[ x ][ y ] = EMPTY;
            return 0;
         } else {
            filled++;
         }
      }
   }
   return filled == SIZE * SIZE;
}

int main()
{
   prob_t p = { 0 };
   readProb( p );
   printBoard( p );
   if ( solve( p ) )
      printBoard( p );
   return 0;
}

