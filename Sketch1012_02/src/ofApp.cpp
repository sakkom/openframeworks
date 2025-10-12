#include "ofApp.h"
#include "ofAppRunner.h"
#include "ofMath.h"
#include "ofPolyline.h"
#include "ofUtils.h"

//--------------------------------------------------------------
void ofApp::setup(){
  centerX = ofGetWidth() / 2.0;
  centerY = ofGetHeight() / 2.0;
  ofSetBackgroundColor(ofColor::black);


}

//--------------------------------------------------------------
void ofApp::update(){

  // ofSetRandomSeed(ofGetElapsedTimef());
  // centerX = ofRandom(ofGetWidth() * 1 / (float)3, ofGetWidth() * 2 / (float)3);
  // centerY = ofRandom(ofGetHeight() * 1 / (float)3, ofGetHeight() * 2 / (float)3);

  radius = 10;
  float currentRadius = radius;
  circles.clear();

  for(int i = 0; i < ofGetWidth() / 1; i++){
    ofPolyline circle;
    float animation = ofMap(sin(ofGetElapsedTimef()), -1, 1, 0.05, 1);
    ofSetRandomSeed(i * animation);
    float step = TWO_PI / ofRandom(0.1, 100);
    for(float angle = 0; angle < TWO_PI; angle += step){
      float randomPos = ofRandom() ;
      circle.addVertex(cos(angle + randomPos + ofGetElapsedTimef()) * currentRadius, sin(angle + randomPos + ofGetElapsedTimef()) * currentRadius);
    }
    circles.push_back(circle);
    currentRadius += 1;
  }
}

//--------------------------------------------------------------
void ofApp::draw(){

  ofTranslate(centerX, centerY);
  for(auto &circle: circles) {

    for(auto &vertex: circle.getVertices()) {
      float gray = ofRandom(50, 255);
      ofSetColor(ofColor(gray, gray, gray));
      ofDrawCircle(vertex, 1);
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
