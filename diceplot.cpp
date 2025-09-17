// ============================================================================
// diceplot.cpp
//
//
// ============================================================================

#include <iostream>
#include <cstdlib>
using namespace std;

// Prototype/define functions anywhere below
int roll();
void printHistogram(int couunts[]);

int main()
{
  int seed, n;
  cin >> seed >> n;

  // Seed the pseudo-random number generator for repeatable results
  srand(seed);

  // Your code here

/* DUMMY (WORKS)
  int testCounts[21];
  for(int i = 0; i < 21; i++){
    testCounts[i] = i/2;
  }
  printHistogram(testCounts);
*/

//ACTUAL
  int r1, r2, r3, r4, rollTotal;
  int counts[21] = {};
  for(int j = 0; j < n; ++j){
    r1 = roll();
    r2 = roll();
    r3 = roll();
    r4 = roll();
    rollTotal = r1 + r2 + r3 + r4;
    counts[rollTotal-4]++;
  }

  printHistogram(counts);

  return 0;
}

int roll(){
  return rand() % 6 + 1;
}

void printHistogram(int counts[]){
  int label = 4;
  for(int i = 0; i < 21; ++i){
    cout << label << ":";
    for(int j = 0; j < counts[i]; ++j){
      cout << "X";
    }
    label++;
    cout << endl;
  }
}
