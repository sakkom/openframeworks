//  Created by sak h on 2025/09/07.
#pragma once
#include "ofMain.h"
#include "config.h"

struct TurnCircle {
public:
  TurnCircle() = default;
  TurnCircle(float radius, ofVec3f posOffset): radius(radius), posOffset(posOffset) {
    float r = radius  - Config::RadiusDiff;
    float h = radius;
    cylinder.set(r, h);
    cylinder.setPosition(posOffset.x, h/2 + posOffset.y, posOffset.z);
    cylinder.setResolution(32, 32);

    offSet = h/4;
  }

  void update() {
    //y軸=0での二次元円周回転
    angle += ANGLE_SPEED;
    //上記が一周する間にちょうど半分。2週でちょうど一周するペース。
    time += ANGLE_SPEED * 0.5f;
    /*
     cosは1スタートなので0にしてbottomに
     また範囲は[-2, 0)になるのでyの位相を正規化するために/2する。
     */
    float worm = ofMap(cos(time + 0.6), -1, 1, cylinder.getHeight() + offSet, 0 - offSet);
    //  float worm = -((cos(time) - 1) * cylinder.getHeight() / 2);

    //デザイン  間
    float polyRadius = radius + Config::Gap;
    pos.x = polyRadius * cos(angle) + posOffset.x;
    pos.z = polyRadius * sin(angle) + posOffset.z;
    worm = worm + posOffset.y;

    polyLine.addVertex(pos.x, worm, pos.z);


  }

  void draw() {
    Utils::draw(cylinder, polyLine);
  }

private:
  static constexpr float ANGLE_SPEED = 0.05f;
  ofCylinderPrimitive cylinder;
  ofPolyline polyLine;
  ofVec3f posOffset;
  float offSet;
  float radius;
  float angle = 0;
  float time = 0;
  ofVec3f pos;


};

//worm animation(update())
//    if(polyLine.size() > 50) {
//      ofVec3f target = polyline.getVertices().begin();
//      polyLine.getVertices().erase(target);
//    }
