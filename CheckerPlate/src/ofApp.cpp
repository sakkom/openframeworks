#include "ofApp.h"
#include "ofAppRunner.h"
#include "ofGraphics.h"
#include "ofMath.h"

//--------------------------------------------------------------
void ofApp::setup(){
  ofSetLineWidth(5);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
  cam.begin();
  float plateSize = 500.0;
  float spacing = 30.0;
  float width = ofGetWidth() / 2.0;
  float height = ofGetHeight() / 2.0;

  int rowIndex = 0;
  for(float row = -height; row < height; row+= spacing) {
    for(float col = -width; col < width; col+= spacing * 2) {
      glm::vec3 start, end;

      if(rowIndex % 2 == 0) {
        // ofSetColor(255, 0, 0);
        start = glm::vec3(col, row + spacing, 0);
        end = glm::vec3(col + spacing,row, 0);
      } else {
        // ofSetColor(0, 255, 0);
        float offset = spacing;
        start = glm::vec3(col + offset, row, 0);
        end = glm::vec3(col + spacing + offset,row + spacing, 0);
      }

      ofDrawLine(start, end);
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
