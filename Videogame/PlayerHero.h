#include <iostream>
#ifndef PLAYERHERO_H
#define PLAYERHERO_H

using namespace std;

class Hero {

public:
  int position[2];
  int score;

  Hero(string heroName, int positionY, int positionX, int spawnScore) {
    namePlayer = heroName;
    position[0] = positionY;
    position[1] = positionX;
    score = spawnScore;
  }

private:
  string namePlayer;

};


#endif
