//  Created by sak h on 2025/09/07.
#pragma once
#include "ofMain.h"
#include "config.h"

struct UpCircle {
public:

  UpCircle() = default;
  UpCircle(float radius, ofVec3f posOffset)
  : radius(radius), posOffset(posOffset) {
    float r = radius - Config::RadiusDiff;
    float h = r * 8;
    cylinder.set(r, h);
    cylinder.setPosition(posOffset.x, h/2 + posOffset.y, posOffset.z);
    cylinder.setResolution(32, 32);

    offSet = h/4;
    pos.y = -offSet + posOffset.y;
  };

  void update() {
    angle += ANGLE_SPEED;

    if(pos.y > cylinder.getHeight() + offSet + posOffset.y) {
      return;
    } else {
      pos.y += UP;
    }

    //デザイン  間
    float polyRadius = radius + Config::Gap;
    pos.x = polyRadius * cos(angle) + posOffset.x;
    pos.z = polyRadius * sin(angle) + posOffset.z;

    polyLine.addVertex(pos);
  };

  void draw() {
    Utils::draw(cylinder, polyLine);
  }

private:
  static constexpr float ANGLE_SPEED = 0.05f;
  static constexpr float UP = ANGLE_SPEED * 20.0f;
  ofCylinderPrimitive cylinder;
  ofPolyline polyLine;
  ofVec3f posOffset;
  float radius;
  float offSet;
  //インスタンスではstatic不要。同じ関数呼び出しで保持するにはstatic必要 counterとして
  float angle = 0;
  ofVec3f pos;
  float cylStart;
};
