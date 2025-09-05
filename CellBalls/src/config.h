#pragma once

#include "ofMain.h"

//[静的使用] Config::
struct Config {
  static inline bool initialized = false;
  static constexpr int rows = 3;
  static constexpr int cols = 3;
  static constexpr int ballsPerCell = 5;

  static inline float cellHeight;
  static inline std::pair<float, float> globalX;
  static inline std::pair<float, float> globalY;
  static inline std::pair<float, float> ballSizeRange;

  /*
   [実行依存] 静的変数初期化 -> main()
   */
  static void init(){
    if(!initialized) {
      cellHeight = ofGetHeight() / rows;
      globalX = {-ofGetWidth() / 2, ofGetWidth() / 2};
      globalY = {-ofGetHeight() / 2, ofGetHeight() / 2};
      ballSizeRange = {5, cellHeight / 3};
      initialized = true;
    }
  }
};
