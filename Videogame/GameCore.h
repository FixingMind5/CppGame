#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include "PlayerHero.h"
using namespace std;

//Hero* Player;

string map[11][15];

/*void set_nick_name(string *userName) {
  string* nickName;
  nickName = *userName
  cout << "Please enter a user name: " << endl;
  cin >> nickName;

  *userName = nickName;
}*/

void game_winned(Hero* Player){
  system("clear");

  cout << "▓██   ██▓ ▒█████   █    ██     █     █░ ▒█████   ███▄    █ " << endl;
  cout << " ▒██  ██▒▒██▒  ██▒ ██  ▓██▒   ▓█░ █ ░█░▒██▒  ██▒ ██ ▀█   █ " << endl;
  cout << "  ▒██ ██░▒██░  ██▒▓██  ▒██░   ▒█░ █ ░█ ▒██░  ██▒▓██  ▀█ ██▒" << endl;
  cout << "  ░ ▐██▓░▒██   ██░▓▓█  ░██░   ░█░ █ ░█ ▒██   ██░▓██▒  ▐▌██▒" << endl;
  cout << "  ░ ██▒▓░░ ████▓▒░▒▒█████▓    ░░██▒██▓ ░ ████▓▒░▒██░   ▓██░" << endl;
  cout << "   ██▒▒▒ ░ ▒░▒░▒░ ░▒▓▒ ▒ ▒    ░ ▓░▒ ▒  ░ ▒░▒░▒░ ░ ▒░   ▒ ▒ " << endl;
  cout << " ▓██ ░▒░   ░ ▒ ▒░ ░░▒░ ░ ░      ▒ ░ ░    ░ ▒ ▒░ ░ ░░   ░ ▒░" << endl;
  cout << " ▒ ▒ ░░  ░ ░ ░ ▒   ░░░ ░ ░      ░   ░  ░ ░ ░ ▒     ░   ░ ░ " << endl;
  cout << " ░ ░         ░ ░     ░            ░        ░ ░           ░ " << endl;
  cout << " ░ ░                                                       "<< endl;
  cout << "Your score: " << Player -> score << endl;
  //cout << "      : \\ \\  \\  \\ .'   '  :  `--'  \\            :   '  |--'   \\  \\ .'   '   : |      " << endl;
  //cout << "      \\  ' ;    `---`     :  ,      .-./            \\  \\ ;        `---`     ;   |.'      " << endl;
  //cout << "        `--`                `--`----'                  '---'                   '---'        " << endl;
  //cout << "Your Player -> score" << Player -> score << endl;
}

int print_menu(string* mapName){
  //cout << l << endl;
  string game = "ew";
  int value = 1;
  cout << "Welcome to my liberynth" << endl;
  cout << "What do you wanna do?" << endl;
  cout << "New game type \"new\" " << endl;
  cout << "Reload game type \"reload\""<< endl;
  while (game != "new" && game != "reload"){
    cin >> game;
    if (game == "new") {
      value = 1;
    } else if (game == "reload") {
      cout << "Type the name of your map" << endl;
      value = 0;
    } else {
      cout << "Option isnt't valid, try again :((" << endl;
    }
  }
  system("clear");
  cout << "Here's the controls" << endl;
  cout << "[A] to move left" << endl;
  cout << "[D] to move right" << endl;
  cout << "[W] to move up" << endl;
  cout << "[S] to move down" << endl;
  cout << "[P] to end game" << endl;
  cout << "Every move press enter" << endl;
  cout << "Tap any button to start" << endl;

  return value;
}

void draw_map(Hero* Player, string map[11][15]) {

  for(int i = 0; i < 11 ; i++){
    for(int j = 0; j < 15; j++){
      if (i != Player -> position[0] /* && j != Player -> position[0][1] */){
        cout << map[i][j];
      } else {
        if (j != Player -> position[1]){
          cout << map[i][j];
        }else{
          cout << "  H  ";
        }
      }
    }
    cout << ' ' << endl;
  }

}

void change_position(char move, Hero* Player, bool* endGame, bool* gameWinned){
  char quit = 'f';

  switch (move) {
    case 'a':
      if (map[Player -> position[0]][(Player -> position[1] - 1)] != "=====")
        Player -> position[1]--;
      if (map[Player -> position[0]][(Player -> position[1])] == "  *  ") {
        Player -> score++;
        map[Player -> position[0]][Player -> position[1]] = "     ";
      }
      if (map[Player -> position[0]][(Player -> position[1])] == "  S  ")
        {*gameWinned = true; *endGame = true;}
      break;
    case 'd':
      if (map[Player -> position[0]][(Player -> position[1] + 1)] != "=====")
        Player -> position[1]++;
      if (map[Player -> position[0]][(Player -> position[1])] == "  *  ") {
        Player -> score++;
        map[Player -> position[0]][Player -> position[1]] = "     ";
      }
      if (map[Player -> position[0]][(Player -> position[1])] == "  S  ")
        {*gameWinned = true; *endGame = true;}
      break;
    case 's':
      if (map[(Player -> position[0] + 1)][Player -> position[1]] != "=====")
        Player -> position[0]++;
      if (map[(Player -> position[0])][Player -> position[1]] == "  *  ") {
        Player -> score++;
        map[Player -> position[0]][Player -> position[1]] = "     ";
      }
      if (map[Player -> position[0]][(Player -> position[1])] == "  S  ")
        {*gameWinned = true; *endGame = true;}
      break;
    case 'w':
      if (map[Player -> position[0] - 1][(Player -> position[1])] != "=====")
        Player -> position[0]--;
      if (map[Player -> position[0]][(Player -> position[1])] == "  *  ") {
        Player -> score++;
        map[Player -> position[0]][Player -> position[1]] = "     ";
      }
      if (map[Player -> position[0]][(Player -> position[1])] == "  S  ")
        {*gameWinned = true; *endGame = true;}
      break;
    case 'p':
      system("clear");
      while (quit != 'y' && quit != 'n') {
        cout << "Do you wanna quit? [y/n]" << endl;
        cin >> quit;
        if (quit == 'y') {
          *endGame = true;
        } else if (quit == 'n'){
          move = 'a';
        } else {
          cout << "That isn't a valid option, try again :((" << endl;
        }
      }
      break;
  }
}

void save_game(string mapName, Hero* Player) {
  ofstream MyFile(mapName + ".txt");

  if (MyFile.is_open()) {
    for(int i = 0; i < 11 ; i++){
      for(int j = 0; j < 15; j++){
        if (i != Player -> position[0] /* && j != Player -> position[0][1] */){
          MyFile << map[i][j];
        } else {
          if (j != Player -> position[1]){
            MyFile << map[i][j];
          }else{
            MyFile << "  H  ";
          }
        }
      }
      MyFile << ' ' << endl;
    }
  } else {
    system("clear");
    cout << "File is corrupted or doesn't exists" << endl;
  }
  MyFile.close();
}

void open_game(string mapName, Hero* Player) {
  ifstream MyFileRead(mapName + ".txt");
  string lines;
  int row = 0, line = 0, k = 0;

  if (MyFileRead.is_open()) {
    while(getline(MyFileRead, lines)){
      map[line][0] = lines[0];
      map[line][0] += lines[1];
      for (int i = 1; i < 15; i++) {
        for(int j = 2; j < 7; j++){
          map[line][i] += lines[k + j];
          if(lines[k + j] == 'H') {
            Player -> position[0] = line; //AQUÍ
            Player -> position[1] = i; //AQUÍ
          }
        }
        k += 5;
      }
      k = 0;
      line++;
    }
  } else {
    cout << "file doesn't exists or is corrupted" << endl;
  }
  MyFileRead.close();
}

void start_game(int value, class Hero User){
  Hero* Player;
  *Player = User;
  char move; string mapName;
  char guardar = 'f';
  bool endGame = false, gameWinned = false;

  if (value == 0) {
    cout << "Digite el nombre de su mapa" << endl;
    cin >> mapName;
    open_game(mapName, Player);
  } else {
    open_game("DefaultGame", Player);
  }

  map[Player -> position[0]][Player -> position[1]] = "     ";

  do {
    cout << ' ' << endl;
    move = getchar();

    system("clear");

    change_position(move, Player, &endGame, &gameWinned);

    if (Player -> position[0] == 0)
      Player -> position[0]++;
    else if (Player -> position[0] >= 10)
      Player -> position[0]--;
    else if (Player -> position[1] == 0)
      Player -> position[1]++;
    else if (Player -> position[1] >= 14)
      Player -> position[1]--;

    cout << "score: " << Player -> score << endl;
    draw_map(Player, map);
    cout << "X: " << Player -> position[1] << "Y: "<< Player -> position[0] << endl;

  } while(!endGame);

  if (gameWinned == true) {
    game_winned(Player);
  }

  //system("clear");

  while (guardar != 'y' && guardar != 'n'){
    cout << "Do you wanna save the current game?: [y/n]" << endl;
    cin >> guardar;
    if (guardar == 'y') {
      cout << "Type the name of your game" << endl;
      cin >> mapName;
      save_game(mapName, Player);
      cout << "GameSaved" << endl;
    } else if (guardar == 'n') {

    } else {
      cout << "opcion no valida" << endl;
    }
  }
}
