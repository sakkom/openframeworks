#include "ofApp.h"
#include "ofAppRunner.h"
#include "ofColor.h"
#include "ofGraphics.h"
#include "ofUtils.h"

//--------------------------------------------------------------
void ofApp::setup(){
  ofBackground(ofColor::black);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
  cam.begin();
  // ofRotateZRad(-PI/4);
  float angleStep = (PI / 2) / 4;
  float radius =  100;

  for(int i = 0; i < 4; i++) {
    float angle = i * angleStep;

    float x = cos(angle);
    float y = sin(angle);
    float d = abs(x-y);
    float similality = 1.0 - (d);
    float currentRadius = radius * similality;

    if(angle > 0 && angle < PI/2) {
      float diagonalAngle = PI + angle;
      if(diagonalAngle > PI && diagonalAngle < 3*PI/2) {
        // glm::vec2 start = glm::vec2(x, y) * currentRadius;
        // glm::vec2 end = glm::vec2(-x,-y) * currentRadius;
        int colorIndex = ofClamp(similality * 2, 0, 1);
        ofColor colors[] = {ofColor(255, 255, 127), ofColor(255, 127, 127)};
        ofSetColor(colors[colorIndex]);
        // ofDrawLine(start, end);
        //
        // float point1 = ofNoise(currentRadius, ofGetElapsedTimef()) * radius;
        ofPushMatrix();
        ofRotateRad(angle);
        ofDrawRectangle(-currentRadius, 0, currentRadius * 2, 10);
        ofPopMatrix();

      }
    }
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
