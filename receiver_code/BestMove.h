// BestMove.h
#ifndef BestMove_h
#define BestMove_h

#include <Arduino.h>

class BestMove {
  private:
    void vibrate(int element);
    void vibrate();
    void vibrate_alert();
    unsigned long time;


  public:
    BestMove();
    void check_move();
    int getState();
    char last_move[5];
    char next_move[5];
    // BestMove(char new_move[]);
    // BestMove(char last_move[]);

};

#endif