//
//  config.h
//  Orbit
//
//  Created by sak h on 2025/09/07.
//
#pragma once
#include "ofMain.h"

struct Config {
  static constexpr float RadiusDiff = 1.0f;
  static constexpr float Gap = 5.0f;
};

struct Utils {
  //外部呼び出しstatic
  static void draw(ofCylinderPrimitive& cylinder,ofPolyline& polyLine) {
    ofSetColor(ofColor::black);
    cylinder.draw();
    ofSetColor(ofColor::white);
//    ofSetLineWidth(10);
//    polyLine.draw();

    auto vertices = polyLine.getVertices();
    for(auto& vertex: vertices) {
      ofSetColor(ofColor::white);
//      ofDrawBox(vertex.x, vertex.y, vertex.z, ofRandom(0.5, 5));
      ofDrawSphere(vertex.x, vertex.y, vertex.z, 2);
//      ofDrawBox(vertex.x, vertex.y, vertex.z, 15);
    }
  }
};
