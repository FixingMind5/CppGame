#include <iostream>
#include <stdlib.h>

using namespace std;

void print_menu(){
  cout << "Welcome to my liberynth" << endl;
  cout << "Here's te controls" << endl;
  cout << "[A] to move left" << endl;
  cout << "[D] to move right" << endl;
  cout << "[W] to move up" << endl;
  cout << "[S] to move down" << endl;
  cout << "[P] to end game" << endl;
  cout << "Every move press enter" << endl;
  cout << "Tap any button to start" << endl;
}

void draw_map(int HeroPosition[2][1], string map[11][15]) {

  for(int i = 0; i < 11 ; i++){
    for(int j = 0; j < 15; j++){
      if (i != HeroPosition[0][0] /* && j != HeroPosition[0][1] */){
        cout << map[i][j];
      } else {
        if (j != HeroPosition[0][1]){
          cout << map[i][j];
        }else{
          cout << "  H  ";
        }
      }
    }
    cout << ' ' << endl;
  }

}

int change_position(char move, int HeroPosition[2][1], bool* endGame){
  //bool localEndGame = *endGame;

  switch (move) {
    case 'a':
      HeroPosition[0][1]--;
      break;
    case 'd':
      HeroPosition[0][1]++;
      break;
    case 's':
      HeroPosition[0][0]++;
      break;
    case 'w':
      HeroPosition[0][0]--;
      break;
    case 'p':
      *endGame = true;
      break;
  }

  return HeroPosition[2][1];
}

int main(){
  char move;
  int HeroPosition[2][1] = {
    {1}, {13}
  };
  string map[11][15] = {
    {"||", "=====", "=====", "=====", "=====", "=====", "=====", "=====", "=====", "=====", "=====", "=====", "=====", "=====", "||"},
    {"||", "     ", "     ", "     ", "     ", "     ", "     ", "     ", "     ", "     ", "     ", "     ", "     ", "     ", "||"},
    {"||", "     ", "=====", "     ", "=====", "=====", "=====", "     ", "=====", "=====", "=====", "=====", "=====", "=====", "||"},
    {"||", "     ", "=====", "     ", "=====", "=====", "=====", "     ", "=====", "=====", "=====", "=====", "=====", "     ", "||"},
    {"||", "     ", "=====", "     ", "=====", "=====", "=====", "     ", "     ", "     ", "  *  ", "=====", "     ", "  *  ", "||"},
    {"||", "     ", "=====", "  *  ", "=====", "=====", "=====", "  *  ", "=====", "=====", "=====", "=====", "=====", "=====", "||"},
    {"||", "     ", "=====", "=====", "=====", "=====", "=====", "=====", "=====", "=====", "=====", "=====", "=====", "=====", "||"},
    {"||", "     ", "     ", "     ", "     ", "     ", "     ", "     ", "     ", "     ", "     ", "     ", "     ", "  S  ", "||"},
    {"||", "=====", "     ", "=====", "=====", "=====", "=====", "     ", "=====", "=====", "=====", "=====", "=====", "=====", "||"},
    {"||", "  *  ", "     ", "  *  ", "=====", "=====", "=====", "     ", "     ", "     ", "     ", "     ", "     ", "  *  ", "||"},
    {"||", "=====", "=====", "=====", "=====", "=====", "=====", "=====", "=====", "=====", "=====", "=====", "=====", "=====", "||"}
  };
  bool endGame = false;

  print_menu();
  do {
    cout << ' ' << endl;
    cin >> move;

    system("clear");

    HeroPosition[2][1] = change_position(move, HeroPosition, &endGame);

    if (HeroPosition[0][0] == 0)
      HeroPosition[0][0]++;
    else if (HeroPosition[0][0] == 10)
      HeroPosition[0][0]--;
    else if (HeroPosition[1][0] == 0)
      HeroPosition[1][0]++;
    else if (HeroPosition[1][0] == 14)
      HeroPosition[1][0]--;
    draw_map(HeroPosition, map);
  } while(!endGame);
  
}
