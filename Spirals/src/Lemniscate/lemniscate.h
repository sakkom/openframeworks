#pragma once
#include "ofGraphics.h"
#include "ofMain.h"
#include "ofMathConstants.h"
#include "ofUtils.h"

struct Lemniscate {

    void update() {
      static double theta = 0.0;
      static int counter = 0;
      float scale = 100.0f;
      float speed = 6.227f;
      theta += ofGetLastFrameTime() * speed;

      if(theta > TWO_PI) {
        theta -= TWO_PI;
        counter++;
      }

      float progress = theta / TWO_PI;
      float offset = ofLerp(counter * scale, (counter + 1) * scale, progress);

      float x = scale * cos(theta);
      float y = scale * sin(theta) * cos(theta);

      polyLine.addVertex(x + offset - 300, y , 0);
    }

    void draw() {
        ofPushMatrix();
        ofSetLineWidth(5);
        polyLine.draw();
        auto vertices = polyLine.getVertices();
        for(auto& vertex: vertices) {
          ofSetColor(ofColor::white);
          ofDrawSphere(vertex.x, vertex.y, vertex.z, 5);
        }
        ofPopMatrix();
    }

protected:
    ofPolyline polyLine;
};
