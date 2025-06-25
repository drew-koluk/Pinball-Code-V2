#include "Highscores.h"

// Constructor - loads scores from EEPROM
Highscores::Highscores() {
    loadScores();
    newHighScore = false;
}

// Load high scores from EEPROM
void Highscores::loadScores() {
    EEPROM.get(0, highScores);
    
    // Initialize with zeros if EEPROM is uninitialized (all 0xFF)
    if (highScores.highScoreOne == -1) {
        highScores.highScoreOne = 0;
        highScores.highScoreTwo = 0;
        highScores.highScoreThree = 0;
        highScores.highScoreFour = 0;
        highScores.highScoreFive = 0;
        saveScores();
    }
}

// Save high scores to EEPROM
void Highscores::saveScores() {
    EEPROM.put(0, highScores);
}

// Check if a score qualifies as a new high score
bool Highscores::isNewHighScore(int score) {
    return score > highScores.highScoreFive;
}

// Update high scores with a new score
bool Highscores::updateHighScore(int score) {
    newHighScore = false;
    
    if (score <= highScores.highScoreFive) {
        return false; // Not a high score
    }
    
    newHighScore = true;
    
    if (score > highScores.highScoreOne) {
        // NEW HIGHEST SCORE, SHIFT EVERYTHING DOWN 1 POSITION
        highScores.highScoreFive = highScores.highScoreFour;
        highScores.highScoreFour = highScores.highScoreThree;
        highScores.highScoreThree = highScores.highScoreTwo;
        highScores.highScoreTwo = highScores.highScoreOne;
        highScores.highScoreOne = score;
    } else if (score > highScores.highScoreTwo) {
        // SECOND HIGHEST SCORE SHIFT 2-5 DOWN
        highScores.highScoreFive = highScores.highScoreFour;
        highScores.highScoreFour = highScores.highScoreThree;
        highScores.highScoreThree = highScores.highScoreTwo;
        highScores.highScoreTwo = score;
    } else if (score > highScores.highScoreThree) {
        // THIRD HIGHEST SCORE SHIFT 3-5 DOWN
        highScores.highScoreFive = highScores.highScoreFour;
        highScores.highScoreFour = highScores.highScoreThree;
        highScores.highScoreThree = score;
    } else if (score > highScores.highScoreFour) {
        // FOURTH HIGHEST SCORE SHIFT 4-5 DOWN
        highScores.highScoreFive = highScores.highScoreFour;
        highScores.highScoreFour = score;
    } else if (score > highScores.highScoreFive) {
        // FIFTH HIGHEST SCORE
        highScores.highScoreFive = score;
    }
    
    // Save to EEPROM if a new high score was made
    if (newHighScore) {
        saveScores();
    }
    
    return newHighScore;
}

// Get the current high scores
Highscores_S Highscores::getHighScores() const {
    return highScores;
}

// Get a specific high score by position (1-5)
int Highscores::getHighScore(int position) const {
    switch(position) {
        case 1: return highScores.highScoreOne;
        case 2: return highScores.highScoreTwo;
        case 3: return highScores.highScoreThree;
        case 4: return highScores.highScoreFour;
        case 5: return highScores.highScoreFive;
        default: return 0;
    }
}

// Check if the last update was a new high score
bool Highscores::wasNewHighScore() const {
    return newHighScore;
}

// Reset all high scores to zero
void Highscores::resetHighScores() {
    highScores.highScoreOne = 0;
    highScores.highScoreTwo = 0;
    highScores.highScoreThree = 0;
    highScores.highScoreFour = 0;
    highScores.highScoreFive = 0;
    saveScores();
}

// Print high scores to Serial (for debugging)
void Highscores::printHighScores() {
    Serial.println("=== HIGH SCORES ===");
    Serial.print("1st: "); Serial.println(highScores.highScoreOne);
    Serial.print("2nd: "); Serial.println(highScores.highScoreTwo);
    Serial.print("3rd: "); Serial.println(highScores.highScoreThree);
    Serial.print("4th: "); Serial.println(highScores.highScoreFour);
    Serial.print("5th: "); Serial.println(highScores.highScoreFive);
    Serial.println("==================");
}