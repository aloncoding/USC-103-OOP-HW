#include <iostream>

using namespace std;

int main(){
  int input = 0, twos = 0, threes = 0;
  int temp;

  cout << "Enter a positive integer: ";
  cin >> input;
  temp = input;

  if((input % 2 != 0 && input % 3 != 0) || (input % 5 == 0 || input % 7 == 0)){
    cout << "\nNo";
  }
  else{
    while(temp / 2 != 0 || temp / 3 != 0){
      if(temp % 2 == 0){
        twos++;
        temp /= 2;
      }
      else if(temp % 3 == 0){
        threes++;
        temp /= 3;
      }
    }

  cout << "\nYes\nTwos=" << twos << " Threes=" << threes;
  }

  return 0;
}
