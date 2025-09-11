//  Created by sak h on 2025/09/11.
#pragma once
#include "ofMain.h"

struct Archimedes {
public:
  Archimedes() = default;
  Archimedes(ofVec3f center, float maxR, float targetTime): center(center), maxR(maxR), targetTime(targetTime) {
  }

  void update() {
    float currentTime = ofMin(ofGetElapsedTimef() - 1.0f, targetTime);

//    float progress = currentTime / targetTime;　//うち->そと
    float progress = 1.0f -  currentTime / targetTime;//そと->うち
    //    if(progress >= 1.0) return;
        if(progress <= 0.0) return;

    float radius = maxR * progress;
    float theta = ofGetElapsedTimef() * 6.227f;
    pos.x = radius * cos(theta) + center.x;
    pos.z = radius * sin(theta) + center.z ;

    polyLine.addVertex(pos);
  }

  void draw() {
    ofPushMatrix();
    ofRotateXDeg(20);

    auto vertices = polyLine.getVertices();
    for(auto& vertex: vertices) {
      ofSetColor(ofColor::white);
      ofDrawSphere(vertex.x, vertex.y, vertex.z, 3);
    }
    ofPopMatrix();


  }

protected:
  ofPolyline polyLine;

  ofVec3f center;
  float maxR;
  float targetTime;

  ofVec3f pos;
};
