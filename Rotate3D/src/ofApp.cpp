#include "ofApp.h"
#include "ofAppRunner.h"
#include "ofColor.h"
#include "ofGraphics.h"
#include "ofGraphicsConstants.h"
#include "ofQuaternion.h"

//--------------------------------------------------------------
void ofApp::setup(){
  // ofSetBackgroundAuto(false);
  cone.set(50, 100, 32, 2, 2);
  /*深い意味はないコーン感のため */
  cone.rotateDeg(180, 1.0, 0, 0);
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
  cam.begin();
  drawAxes();
  ofPushMatrix();

  /*任意の一つの軸中心の回転 */
  ofRotateXDeg(ofGetFrameNum() * 1.0f);
  // ofRotateYDeg(ofGetFrameNum() * 1.0f);
  // ofRotateZDeg(ofGetFrameNum() * 1.0f);

  cone.setPosition(100, 100, -100);
  ofSetColor(ofColor::white);
  cone.drawWireframe();

  ofPopMatrix();
  cam.end();
}

void ofApp::drawAxes() {
  ofSetColor(ofColor::red);
  ofDrawLine(-ofGetWidth() / 2.0f, 0, 0, ofGetWidth() / 2.0f, 0, 0);
  ofSetColor(ofColor::blue);
  ofDrawLine(0, -ofGetHeight() / 2.0f, 0, 0, ofGetHeight() / 2.0f, 0);
  ofSetColor(ofColor::green);
  float xy_ = pow(ofGetWidth(), 2) + pow(ofGetHeight(), 2);
  ofDrawLine(0, 0, -sqrt(xy_) / 2.0f, 0, 0, sqrt(xy_) / 2.0f);
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
