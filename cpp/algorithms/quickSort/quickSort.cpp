#include <iostream>
#include <vector>
#include <time.h>
using namespace std;

vector<int>* quickSort( vector<int> * vect );

int main(){
  srand( time( NULL) );
  const int SIZE = 50;
  vector<int> input;

  int r;
  for ( int i = 0; i < SIZE; i++ ){
    r = rand() % SIZE * 2;
    cout << r << ",";
    input.push_back( r );
  } 
  cout << endl << endl;


  vector<int> * output = quickSort( &input );
  for ( int i = 0; i < SIZE; i++ ){
    cout << (*output)[ i ] << ",";
  }
  cout << endl;

  return 0;
}


vector<int>* quickSort( vector<int>* vect ){
  
  int vectSize = vect->size();
  if( vectSize <= 1 )
    return vect;

  //arbitrarily pick pivot 
  int pivotIndex = vectSize / 2;
  vector<int> * less= new vector<int>();
  vector<int> * more= new vector<int>();

  for ( int i = 0; i < vectSize; i++ ){
    if ( i == pivotIndex )
      continue;
    
    int current = (*vect)[ i ];
    if ( current > (*vect)[ pivotIndex ] )
      more->push_back( current );
    else
      less->push_back( current );
  } 
    less = quickSort( less );
    more = quickSort( more );

    vector<int> * sorted = new vector<int>();
    sorted->insert( 
		   sorted->end(), 
		   less->begin(),
		   less->end() );
    sorted->insert( sorted->end(),
		    (*vect)[ pivotIndex ] );
    sorted->insert( sorted->end(),
		    more->begin(),
		    more->end() );

    return sorted;

}
