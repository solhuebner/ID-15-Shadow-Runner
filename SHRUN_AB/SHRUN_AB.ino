/*
  SHADOW RUNNER: http://www.team-arg.org/shrun-manual.html

  Arduboy version 1.6 : http://www.team-arg.org/more-about.html

  MADE by TEAM a.r.g. : http://www.team-arg.org/more-about.html

  2015 - JO3RI - Trodoss

  Special thanks to Dreamer3 for helping with the conversion

  Game License: MIT : https://opensource.org/licenses/MIT

*/

//determine the game
#define GAME_ID 15

#include "globals.h"
#include "runner.h"
#include "menu.h"
#include "game.h"
#include "items.h"
#include "playfield.h"


typedef void (*FunctionPointer) ();

const FunctionPointer PROGMEM mainGameLoop[] = {
  stateMenuIntro,
  stateMenuMain,
  stateMenuHelp,
  stateMenuPlay,
  stateMenuInfo,
  stateMenuSoundfx,
  stateGameInitLevel,
  stateGamePlaying,
  stateGamePause,
  stateGameOver,
};

void setup () {
  arduboy.begin();
  arduboy.setFrameRate(60);
}

void loop() {
  if (!(arduboy.nextFrame())) return;
  arduboy.pollButtons();
  arduboy.clear();
  ((FunctionPointer) pgm_read_word (&mainGameLoop[gameState]))();
  arduboy.display();
}

