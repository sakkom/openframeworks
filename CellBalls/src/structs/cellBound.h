#pragma once

#include "ofMain.h"
#include "config.h"

struct CellBound {
  int row, col;
  ofVec2f center;
  float currentNoise;
  float dynamicBoundSize;
  //動的なサイズに則る
  std::pair<float, float> boundX, boundY;

  /*
   [実行依存]
   一貫したGridアニメーションにおいて
   update()から始まる実行タイミングにおけるまでインスタンス化はされない
   そのためデフォルトコンストラクタを使用する必要がある。
   */
  CellBound() = default;
  CellBound(int row, int col): row(row), col(col) {
    center = getCellCenter(row, col);
  }

  void drawWireBoxeis(float time) {
    ofPushStyle();
    ofNoFill();
    ofSetColor(ofColor(128));
    ofDrawBox(center.x, center.y, 0,  dynamicBoundSize);
    ofPopStyle();
  }

  void updateBound(float time) {
    auto [noise, size] = getDynamicBoxSize(row, col, time);
    currentNoise = noise;
    dynamicBoundSize = size;
    boundX = getAxisBound(center.x);
    boundY = getAxisBound(center.y);
  };

  std::pair<float, float> getAxisBound(float center) {
    float half = dynamicBoundSize / 2;
    return {center - half, center + half};
  }

  std::array<float, 2> getDynamicBoxSize(int row, int col, float time) {
    float voxcelNoise = ofNoise(row, col, time);
    return {
      voxcelNoise,
      Config::cellHeight * voxcelNoise,
    };
  }

  ofVec2f getCellCenter(int row, int col) {
    float centerX = ofMap(col + 0.5, 0, 3, Config::globalX.first, Config::globalX.second);
    float centerY = ofMap(row + 0.5, 0, 3, Config::globalY.first, Config::globalY.second);
    return {centerX, centerY};
  }

};
