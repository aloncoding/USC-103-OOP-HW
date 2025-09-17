/********************************************************
 * Description:
 *   Displays the top 3 most "abundant" (see writeup)
 *   numbers in the input sequence.  The input sequence
 *   is assumed to be valid natural numbers separated
 *   by spaces and ending with 0.
 *
 *   ABSOLUTELY NO ARRAY or `string`/`vector`/etc. usage
 *   is allowed!

 *   You may only declare: bool, int, or unsigned int
 *   No library functions (beyond cin/cout) are allowed.
 *
 *   You may NOT modify any of the given template code.
 *   This ensures our automated checkers can parse your
 *   output.  You MAY add functions, prototypes, etc.
 *   to aide your implementation. Failure to follow this 
 *   direction will lead to a score of 0 on this 
 *   part of the assignment.
 ********************************************************/

#include <iostream>
using namespace std;

bool isAbundant(int x);
int getAbundance(int x);

int main()
{
  // n1 is the number with the highest abundance, a1
  // n2 is the number with the 2nd-highest abundance, a2
  // n3 is the number with the 3rd-highest abundance, a3
  unsigned int n1 = 0, n2 = 0, n3 = 0;
  int a1 = 0, a2 = 0, a3 = 0;
  // num_abundant counts how many numbers in the input
  // sequence are abundant
  int num_abundant = 0;

  cout << "Enter a sequence of natural numbers, separated by spaces, ";
  cout << "and ending with 0."<< endl;

  /*====================*/
  /* Start of your code */
  
  int input;
  cin >> input;
  while(input != 0){
    if(isAbundant(input)){
      num_abundant++;

      if(a1 < getAbundance(input)){
        a3 = a2;
        n3 = n2;
        a2 = a1;
        n2 = n1;
        a1 = getAbundance(input);
        n1 = input;
      }
      else if(a2 < getAbundance(input)){
        a3 = a2;
        n3 = n2;
        a2 = getAbundance(input);
        n2 = input;
      }
      else if(a3 < getAbundance(input)){
        a3 = getAbundance(input);
        n3 = input;
      }
    }

    cin >> input;
  }
  
  /* End of your code */
  /*==================*/
  
  cout << "Abundant number count: " << num_abundant << endl;
  cout << "Top 3 most abundant numbers: " << endl;
  cout << n1 << " : " << a1 << endl;
  cout << n2 << " : " << a2 << endl;
  cout << n3 << " : " << a3 << endl;

  return 0;

}

bool isAbundant(int x){
  bool abundant = true;

  if(getAbundance(x) <= x){
    abundant = false;
  }

  return abundant;
}

int getAbundance(int x){
  int abundance = 0;

  for(int i = 1; i < x; i++){
    if(x % i == 0){
      abundance += i;
    }
  }

  return abundance;
}
