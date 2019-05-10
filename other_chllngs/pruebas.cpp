#include <iostream>

using namespace std;

int main(){
  int k = 0;
  string vector[10];
  string equals = "==================================================";

  for(int i = 0; i < 10; i++) {
    for(int j = 0; j < 5; j++) {
      vector[i] += equals[k + j];
    }
    k += 5;
  }

  for(int i = 0; i < 10; i++)
    cout << vector[i] << endl;
}
