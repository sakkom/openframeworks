#include "ofApp.h"
#include "ofAppRunner.h"
#include "ofColor.h"
#include "ofGraphics.h"
#include "ofMath.h"
#include "ofMathConstants.h"
#include "ofUtils.h"

//--------------------------------------------------------------
void ofApp::setup(){
  ofSetBackgroundAuto(false);
  ofSetFrameRate(60);
  ofSetBackgroundColor(ofColor::black);
  sketch1005();
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){

  ofSetColor(0,0,0, 4);
  ofDrawRectangle(0,0, ofGetWidth(), ofGetHeight());
  ofSetColor(255, 255, 255 , 100);
  static float amp = 1.0;
  static float offsetY = 0;

  if(ofGetFrameNum() % 60 == 0) {

    sketch1005();
    // amp = 1.0;
    offsetY = 0;
  } else {
    // offsetY += abs(sin(ofGetFrameNum() * PI / 60.0)) * 0.5 ;
  }
 amp = abs(sin(ofGetFrameNum() * PI / 120.0));
 amp = ofMap(amp, 0, 1, 0, 1);

  for(int i = 1; i < points.size(); i++) {
    float y0 = points[i - 1].y * amp + ofGetHeight() / 2.0;
    float y1 = points[i].y * amp + ofGetHeight() / 2.0;
    // float y0 = points[i - 1].y * amp + ofGetHeight() / 2.0 - offsetY;
    // float y1 = points[i].y * amp + ofGetHeight() / 2.0 - offsetY;
    ofDrawLine(points[i - 1].x, y0, points[i].x, y1);
  }
}
void ofApp::sketch1005() {
  static bool stepStatus;
  points.clear();
  float startX = 0;
  float endX = ofGetWidth();
  // float linearArea = ofGetWidth() / 1.0;
  float linearArea = 0.0;
  float linearStartArea = startX + linearArea ;
  float linearEndArea = endX - linearArea;

  float step = stepStatus ? 30 : 30;
  stepStatus = !stepStatus;
  for(int x = 0; x < endX; x+= step) {
    float y;
    if(x < linearStartArea || x > linearEndArea) {
      y = 0;
    } else {
      y = ofRandom(-30, 30);
    }
    points.push_back(ofVec2f(x, y));
  }
}


void ofApp::sketchP103() {
  float width = ofGetWidth();
  float height = ofGetHeight();
  float border = 20;
  float y = 50;
  int step = 10;
  float lastx = -999;
  float lasty = -999;
  float bordery = 10;
  for(int x = border; x <= width - border; x+=step) {
    y = bordery +  ofRandom( height - 2*bordery);
    if(lastx > -999) {
    ofDrawLine(x, y, lastx, lasty);
    }
    lastx = x;
    lasty = y;
  }
}

void ofApp::sketchP104() {
  float width = ofGetWidth();
  float height = ofGetHeight();
  float border = 20;
  float y = height/2.0;
  int xStep = 10;
  float yStep = 10;
  float lastx = 0;
  float lasty = 0;

  for(int x = border; x <= width; x+=xStep) {
    if(lastx > 0) {
      if(x >= width) {
        y = height/2.0;
      } else {
        yStep = ofRandom(-10, 10);
        y += yStep;
      }
      ofDrawLine(x, y, lastx, lasty);
    }
    lastx = x;
    lasty = y;
  }
}


//--------------------------------------------------------------
void ofApp::exit(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseScrolled(int x, int y, float scrollX, float scrollY){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}
