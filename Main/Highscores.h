#ifndef HIGHSCORE_H
#define HIGHSCORE_H

#include "Arduino.h"
#include <EEPROM.h>

struct Highscores_S {
    int highScoreOne;
    int highScoreTwo;
    int highScoreThree;
    int highScoreFour;
    int highScoreFive;
};

class Highscores {
private:
    Highscores_S highScores;
    bool newHighScore;
    
public:
    // Constructor - loads scores from EEPROM
    Highscores();
    
    // Load high scores from EEPROM
    void loadScores();
    
    // Save high scores to EEPROM
    void saveScores();
    
    // Check if a score qualifies as a new high score
    bool isNewHighScore(int score);
    
    // Update high scores with a new score
    bool updateHighScore(int score);
    
    // Get the current high scores
    Highscores_S getHighScores() const;
    
    // Get a specific high score by position (1-5)
    int getHighScore(int position) const;
    
    // Check if the last update was a new high score
    bool wasNewHighScore() const;
    
    // Reset all high scores to zero
    void resetHighScores();
    
    // Print high scores to Serial (for debugging)
    void printHighScores();
};

#endif