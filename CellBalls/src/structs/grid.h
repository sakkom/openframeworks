//  Created by sak h on 2025/09/05.
#pragma once

#include "ofMain.h"
#include "config.h"
#include "cellBound.h"
#include "ball.h"

struct Grid {
public:
  Grid() {
    for(int row = 0; row < Config::rows; row++) {
      for(int col = 0; col < Config::cols; col ++) {
        cells[row][col] = CellBound(row, col);
        balls[row][col] = Ball(row, col, Config::ballsPerCell);
      }
    }
  };

  void update() {
    float currentTime = ofGetElapsedTimef();
    for(int row = 0; row < Config::rows; row++) {
      for(int col = 0; col < Config::cols; col ++) {
        cells[row][col].updateBound(currentTime);
        balls[row][col].updateBalls(cells[row][col], currentTime);
      }
    }
  }

  void draw() {
    float currentTime = ofGetElapsedTimef();
    for(int row = 0; row < Config::rows; row++) {
      for(int col = 0; col < Config::cols; col ++) {
        cells[row][col].drawWireBoxeis(currentTime);
        balls[row][col].drawBalls(cells[row][col]);
      }
    }
  }

private:
  /*
   Gridアニメーションの為に一貫したオブジェクトにする必要がある
   つまりGPU処理と適合する為、同じセルは常に同じ振る舞いを更新する
   */
  /*
   上記よりこれら配列からなるメンバとしてそれらは当たり前に存在し定義されるが
   update()から始まる実行タイミングにおけるまでインスタンス化はされない
   そのためデフォルトコンストラクタを使用する必要がある。
   */
  CellBound cells[Config::rows][Config::cols];
  Ball balls[Config::rows][Config::cols];
};
