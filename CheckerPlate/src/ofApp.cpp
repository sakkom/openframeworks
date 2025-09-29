#include "ofApp.h"
#include "of3dGraphics.h"
#include "ofAppRunner.h"
#include "ofColor.h"
#include "ofGraphics.h"
#include "ofMath.h"
#include "ofShader.h"
#include "ofUtils.h"

//--------------------------------------------------------------
void ofApp::setup(){
  ofSetBackgroundColor(ofColor::black);
  ofSetLineWidth(5);
  material.setDiffuseColor(ofFloatColor::white);
  material.setSpecularColor(ofFloatColor::gray);
  material.setShininess(100);
  light.setPosition(200,200, 200);
  light.enable();
  ofEnableDepthTest();
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
  cam.begin();
  float spacing = 50.0;
  float width = ofGetWidth() / 2.0;
  float height = ofGetHeight() / 2.0;

  int rowIndex = 0;
  for(float row = -height; row < height; row+= spacing) {
    for(float col = -width; col < width; col+= spacing * 2) {

      material.begin();
      ofPushMatrix();

      float rectW = spacing * 1.414;
      float rectH = spacing / 10;

      if(rowIndex % 2 == 0) {
        ofSetColor(255, 200, 200);
        ofTranslate(col, row, 0);
        ofRotateZDeg(45);
        // ofDrawRectangle(-rectW/2, -rectH/2, 0, rectW, rectH);
        ofDrawEllipse(0, 0, 0, rectW, rectH);
        // ofDrawLine(-rectW / 2, 0, rectW / 2, 0);
      } else {
        ofSetColor(200, 255, 200);
        ofTranslate(col + spacing, row, 0);
        ofRotateZDeg(-45);
        // ofDrawRectangle(-rectW/2, -rectH/2, 0, rectW, rectH);
        ofDrawEllipse(0, 0, 0, rectW, rectH);
        // ofDrawLine(-rectW / 2, 0, rectW / 2, 0);
      }
      ofPopMatrix();
      material.end();

      // ofDrawLine(start, end);
    }
    rowIndex++;
  }


  cam.end();
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
