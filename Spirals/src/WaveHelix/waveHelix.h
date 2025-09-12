//  Created by sak h on 2025/09/07.
#pragma once
#include "ofAppRunner.h"
#include "ofMain.h"
#include "config.h"

struct WaveHelix {
public:
  WaveHelix() = default;
  WaveHelix(float radius, ofVec3f place): radius(radius), place(place) {
    float r = radius  - Config::RadiusDiff;
    float h = radius;
    cylinder.set(r, h);
    cylinder.setPosition(place.x, place.y, place.z);
    cylinder.setResolution(32, 32);
  }

  void update() {
    float theta = (ofGetElapsedTimef() - 1.0f) * 6.227f;

    float startY =  place.y - cylinder.getHeight() / 2;
    /*
     * sin(theta)は[-1, 1]になる+1して[0, 2]になる/2して[0, 1]にする。
     * 関数ないでsin(0) = 0.5になるため位相を sin(0) = -1 + 1にするために-PI/2する。
     * theta / 2はデザイン一周の同期とかさなるので遅くする。
     */
    float yRanage= (sin(theta - PI/2) + 1) / 2;
    pos.y = ofLerp(startY, startY + cylinder.getHeight(), yRanage);

    float polyRadius = radius + Config::Gap;
    pos.x = polyRadius * cos(theta) + place.x;
    pos.z = polyRadius * sin(theta) + place.z;
     // pos.y = cos(progress) * cylinder.getHeight();

    polyLine.addVertex(pos.x, pos.y, pos.z);


  }

  void draw() {
    Utils::draw(cylinder, polyLine);
  }

private:
  static constexpr float ANGLE_SPEED = 0.05f;
  ofCylinderPrimitive cylinder;
  ofPolyline polyLine;
  ofVec3f place;
  float radius;
  ofVec3f pos;


};

//worm animation(update())
//    if(polyLine.size() > 50) {
//      ofVec3f target = polyline.getVertices().begin();
//      polyLine.getVertices().erase(target);
//    }
