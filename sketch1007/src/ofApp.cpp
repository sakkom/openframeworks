#include "ofApp.h"
#include "ofGraphics.h"
#include "ofMath.h"
#include "ofMathConstants.h"
#include "ofUtils.h"

//--------------------------------------------------------------
void ofApp::setup(){
  ofSetBackgroundColor(0);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
  ofTranslate(ofGetWidth() / 2.0, ofGetHeight() / 2.0);
  ofPolyline polyline;
  float radius = 150;
  float radiusX = radius * 1.414;
  float radiusY = radius * 1;
  float freq = 3;
  for(float j = 0; j < TWO_PI * 1 ; j += TWO_PI / 360) {
    int loop = j / TWO_PI + 1;
    ofSetRandomSeed(pow(j, 0.8));
    float radiusNoise = sin(j * freq + loop + ofGetElapsedTimef() * 1) * radius;
    float mappedRadius = ofMap(radiusNoise, -radius, radius, radius/6, radius);
    float time = abs(sin(ofGetElapsedTimef() * 2));
    time = time > 0.66f ? 1 : time > 0.33f ? 0.5 : 0;
    float kaos = pow(time, 2) * radius ;
    float x = cos(j) * mappedRadius  * radiusX / radius  + ofRandom(-kaos, kaos);
    float y = sin(j) * mappedRadius * radiusY / radius  + ofRandom(-kaos, kaos);
    polyline.addVertex( x,  y);
  }

  polyline.close();
  polyline.draw();
  auto vertices = polyline.getVertices();
  for(auto& vertex : vertices) {
    // ofDrawRectangle(vertex, 1, 5);
    ofNoFill();
    ofDrawCircle(vertex, 15);
    ofFill();
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
