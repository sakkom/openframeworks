#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  ofEnableDepthTest();
  ofSetFrameRate(60);
  ofSetBackgroundAuto(true);

//  helix.emplace(25, ofVec3f(-350, -200, 0));
  helix.emplace(150, ofVec3f(-200, -200, 0));
  spiralCoverage.emplace(150, ofVec3f(200, -200, 0));
//  turnCircle.emplace(80, ofVec3f(-220, 150, 0));
}

//--------------------------------------------------------------

void ofApp::update(){
  
  helix->update();
  spiralCoverage->update();
//  turnCircle->update();
}

//--------------------------------------------------------------
void ofApp::draw(){
  cam.begin();

  

  helix->draw();
  spiralCoverage->draw();
//  turnCircle->draw();

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
