//  Created by sak h on 2025/09/07.
#pragma once
#include "ofMain.h"
#include "config.h"

struct Helix {
public:

  Helix() = default;
  Helix(float radius, ofVec3f place)
  : basicR(radius), place(place) {
    setCylinder(radius);
  };

  void update() {
    float delay = 1.0f;
    if(ofGetElapsedTimef() < delay) return;

    xzRotate();

    bool isRunning = addHeight(delay, cylinder.getHeight());
    if(isRunning) return;

    updateRadius();

    polyLine.addVertex(pos);
  };

  void draw() {
    Utils::draw(cylinder, polyLine);
  }

protected:
  ofCylinderPrimitive cylinder;
  ofPolyline polyLine;
  ofVec3f place;
  //  cylinderとpolyLineの軸となる
  float basicR;
  ofVec3f pos;
  virtual void updateRadius(){};

private:
  void setCylinder(float basicR) {
    float r = basicR - Config::RadiusDiff;
    float h = r * 1;
    cylinder.set(r, h);
    cylinder.setPosition(place.x, place.y, place.z);
    cylinder.setResolution(32, 32);
  }

  void xzRotate() {
    float polyRadius = basicR + Config::Gap;
    float speed = ofGetElapsedTimef() * 6.227f; //README.md参照

    pos.x = polyRadius * cos(speed) + place.x;
    pos.z = polyRadius * sin(speed) + place.z;
  }

  bool addHeight(float delay, float cylinderHeihgt) {
    float targetTime = 2.5f;
    float currentTime = ofMin(ofGetElapsedTimef() - delay, targetTime);
    float progress = currentTime / targetTime;

    float startY = place.y - cylinderHeihgt / 2;
    pos.y = startY + cylinderHeihgt * progress;
    //progress=1で無限になるので明示的に終了
    bool isRunning = progress >= 1.0f;
    return isRunning;
  }
};
