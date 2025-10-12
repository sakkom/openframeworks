#include "ofApp.h"
#include "ofAppRunner.h"
#include "ofArduino.h"
#include "ofGraphics.h"
#include "ofMath.h"
#include "ofMathConstants.h"
#include "ofUtils.h"
#include "ofVec2f.h"

//--------------------------------------------------------------
void ofApp::setup(){
  // ofSetBackgroundAuto(true);
  ofSetBackgroundColor(ofColor::black);
  circleNum = 5;
  radius = 100.0;
}
//--------------------------------------------------------------
void ofApp::update(){
  mandara.clear();
  if(ofGetFrameNum() % 60 == 0) {
    radius = ofRandom(200, 200);
  }
  float currentRadius = radius;
  int circlePoints = 16;
  for(int i = 0; i < circleNum; i++) {
    vector<ofVec2f> circle;
    for(int j = 0; j < circlePoints; j++) {
      float angle = j * TWO_PI / circlePoints;
      // float x = currentRadius * cos(angle + ofGetElapsedTimef());
      // float y = currentRadius * sin(angle + ofGetElapsedTimef());
      float x = currentRadius * cos(angle);
      float y = currentRadius * sin(angle);
      circle.push_back(ofVec2f(x, y));
    }
    mandara.push_back(circle);
    currentRadius += radius / 5;
  }
  // int clearIndex = ofRandom(0, circleNum);
  // if(clearIndex < mandara.size()) {
  //   mandara[clearIndex].clear();
  // }
}

//--------------------------------------------------------------
void ofApp::draw(){
  ofTranslate(ofGetWidth() / 2.0, ofGetHeight() / 2.0);
  ofSetColor(255);
  for(int circle = 0; circle < mandara.size(); circle++){
    int num = mandara[circle].size();
    for(int i = 0; i < num; i++){
      for(int j = i + 2; j < num; j++) {
        if((i == 0 && j == num - 1) || (i == num - 1 && j == 0)) continue;
        ofDrawLine(mandara[circle][i], mandara[circle][j]);
      }
    }
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
