//  Created by sak h on 2025/09/05.
#pragma once

#include "ofMain.h"
#include "config.h"

struct Ball{
  int row, col;
  //update()とdraw()に処理を切り離すため直前update()の座標を保持
  ofVec3f positions[Config::ballsPerCell];

  /*
   [実行依存]
   一貫したGridアニメーションにおいて
   update()から始まる実行タイミングにおけるまでインスタンス化はされない
   そのためデフォルトコンストラクタを使用する必要がある。
   */
  Ball() = default;
  Ball(int row, int col, int amount): row(row), col(col) {
  }

  void drawBalls(CellBound& cell) {
    for(int i = 0; i < Config::ballsPerCell; i++) {
      ofMaterial material;
      material.setDiffuseColor(ofColor(ofMap(i, 0, Config::ballsPerCell - 1, 0, 255)));
      material.begin();
      //ノイズによって間接的に変動する可動域の大きさに応じてボールの大きさを調整
      ofDrawSphere(positions[i], ofMap(cell.currentNoise, 0, 1, Config::ballSizeRange.first, Config::ballSizeRange.second));
      material.end();
    }
  }

  void updateBalls(CellBound& cells, float time) {
    for(int i = 0; i < Config::ballsPerCell; i++) {
      std::array<float, 3> noise = getPosCurrentNoise(row, col, i);
      positions[i] = getBallPos(cells, noise, time);
    }
  }

  //ボールはCellに内在する立方体内において可動域をもっている
  ofVec3f getBallPos(CellBound& cells, std::array<float, 3> xyzNoise, float time) {
    std::pair<float, float> boundZ = {-cells.dynamicBoundSize / 2, cells.dynamicBoundSize / 2};
    return {
      ofMap(ofNoise(xyzNoise[0], time), 0, 1, cells.boundX.first, cells.boundX.second),
      ofMap(ofNoise(xyzNoise[1], time), 0, 1, cells.boundY.first, cells.boundY.second),
      ofMap(ofNoise(xyzNoise[2], time), 0, 1, boundZ.first, boundZ.second),
    };
  }

  //indexと座標にユニークなノイズ
  std::array<float, 3> getPosCurrentNoise(int row, int col, int index) {
    return {
      (row * 5 + col) * 10 + index * 1.5f,
      (row * 5 + col) * 10 + index * 1.3f,
      (row * 5 + col) * 10 + index * 1.4f,
    };
  }

};
