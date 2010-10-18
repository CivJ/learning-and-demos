//Selection sort
#include <stdio.h>
#include <stdlib.h>

int main ( int argc, char** argv ) {

  if ( argc == 1 ){
    printf("Must enter a size\n");
    return 0;
  }

  //Get array of random numbers
  int size = atoi(argv[1]);
  int* array = malloc(sizeof(int)*size);

  srand(time(NULL));

  int i;
  for(i=0; i<size; i++) {
    array[i] = rand();
  }

  int j;
  int tmp;
  int smallest;
  int smallestIndex;

  //Selection sort
  for ( i = 0; i < size - 1; i++){
    smallest = array[i];
    smallestIndex = i;
    for ( j = i + 1; j < size; j++ ){
      if ( smallest > array[ j ] ){
	smallest = array[ j ];
	smallestIndex = j;
      }
    }
    tmp = array[ i ];
    array[ i ] = smallest;
    array[ smallestIndex ] = tmp;
  }

  int k;
  for ( k = 0; k < size; k++ ){
    printf( "%d,", array[ k ] );
  }
  printf( "\n" );

  int sorted = 1;
  while ( k < size - 1 && sorted == 1 ){
    if ( array [ k ] > array [ k + 1 ])
      sorted = 0;
    k++; 
  }
  if ( sorted ) 
    printf("Sorted!\n");
  else
    printf("Not sorted!\n");

  return 0;
}
