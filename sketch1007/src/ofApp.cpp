#include "ofApp.h"
#include "ofGraphics.h"
#include "ofMath.h"
#include "ofMathConstants.h"
#include "ofUtils.h"

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
  ofTranslate(ofGetWidth() / 2.0, ofGetHeight() / 2.0);
  ofPolyline polyline;
  float radius = 100;
  for(float j = 0; j < TWO_PI * 3 ; j += TWO_PI / 1000) {
    int num = int(j / TWO_PI) + 1;
    float radiusNoise = sin(j * 5) * radius;
    float mappedRadius = ofMap(radiusNoise, -radius, radius, 5, radius);
    ofSetRandomSeed(j);
    // float kaos = abs(sin(ofGetElapsedTimef())) * 100;
    // float x = cos(j) * mappedRadius + ofRandom(-kaos, kaos);
    // float y = sin(j) * mappedRadius + ofRandom(-kaos, kaos);
    // float x = cos(j * num) * mappedRadius ;
    // float y = sin(j * num) * mappedRadius;
    float x = cos(j * num) * mappedRadius ;
    float y = sin(j * num) * mappedRadius;
    polyline.addVertex( x,  y);
  }

  auto vertices = polyline.getVertices();
  for(auto& vertex : vertices) {
    ofDrawRectangle(vertex, 1, 5);
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
