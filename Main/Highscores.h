#ifndef HIGHSCORE_H
#define HIGHSCORE_H

#include "Arduino.h"
#include <EEPROM.h>

struct Highscores_S{
    int highScoreOne;
    int highScoreTwo;
    int highScoreThree;
    int highScoreFour;
    int highScoreFive;
}

class Highscore{
    



}


highScores = EEPROM.get(0, highScores);


void calcHighScore() {
  highScores = EEPROM.get(0, highScores);//READ EEPROM HIGH SCORES
  newHighScore = true;
  if (score < highScores.highScoreFive) {
    newHighScore = false;
  } else if (score > highScores.highScoreOne) { //NEW HIGHEST SCORE, SHIFT EVERYTHING DOWN 1 POSITION
    highScores.highScoreFive = highScores.highScoreFour;
    highScores.highScoreFour = highScores.highScoreThree;
    highScores.highScoreThree = highScores.highScoreTwo;
    highScores.highScoreTwo = highScores.highScoreOne;
    highScores.highScoreOne = score;
  } else if (score > highScores.highScoreTwo) { //SECOND HIGHEST SCORE SHIFT 2-5 DOWN
    highScores.highScoreFive = highScores.highScoreFour;
    highScores.highScoreFour = highScores.highScoreThree;
    highScores.highScoreThree = highScores.highScoreTwo;
    highScores.highScoreTwo = score;
  }
  else if (score > highScores.highScoreThree) { //THIRD HIGHEST SCORE SHIFT 3-5 DOWN
    highScores.highScoreFive = highScores.highScoreFour;
    highScores.highScoreFour = highScores.highScoreThree;
    highScores.highScoreThree = score;
  }
  else if (score > highScores.highScoreFour) { //THIRD HIGHEST SCORE SHIFT 3-5 DOWN
    highScores.highScoreFive = highScores.highScoreFour;
    highScores.highScoreFour = score;
  }
  else if (score > highScores.highScoreFive) { //THIRD HIGHEST SCORE SHIFT 3-5 DOWN
    highScores.highScoreFive = score;
  }
  //EEPROM.put(0, highScores);//WRITE THE NEW SCORES BACK TO THE EEPROM ONLY IF A NEW HIGH SCORE IS MADE
}


#endif