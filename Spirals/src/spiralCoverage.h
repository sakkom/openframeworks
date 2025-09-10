//
//  spiralCoverage.h
//  Orbit
//
//  Created by sak h on 2025/09/10.
//
#pragma once
#include "ofMain.h"
#include "basicSpiral.h"
#include "config.h"

struct SpiralCoverage : public UpCircle {
public:
  SpiralCoverage(float radius, ofVec3f place)
  : UpCircle(radius, place), originalRadius(radius) {
    float r = radius - Config::RadiusDiff;
    float h = r * 1;
    cylinder.set(r, h);
    cylinder.setPosition(place.x, place.y, place.z);
    cylinder.setResolution(32, 32);
  };

  void updateRadius() override {
    float startY =   place.y;
    float endY = cylinder.getHeight()  + place.y;
    float progress = (pos.y - startY) / (endY - startY);  // 0〜1

    float radiusMultiplier = 2.0f * abs(progress - 0.5f);  // 1→0→1
    basicR = originalRadius * radiusMultiplier;
  }

private:
  float originalRadius;

};
