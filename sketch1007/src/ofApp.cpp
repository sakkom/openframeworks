#include "ofApp.h"
#include "ofAppRunner.h"
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
  float radius = 100;
  float radiusX = radius * 1.414;
  float radiusY = radius * 1;
  float petalsLength = ofMap(sin(ofGetElapsedTimef() * 0.1), -1, 1, 3,3);
  for(float t = 0; t < TWO_PI * 1; t += TWO_PI / (360 * petalsLength / 2.0)) {
    int loop = t / TWO_PI + 1;
    float petals = sin(t * petalsLength + loop + ofGetElapsedTimef() * 1);
    float staticRadius = ofMap(petals, -1, 1, radius/6, radius);

    float time = abs(sin(ofGetElapsedTimef() * 2));
    // float time = 0;
    time = time > 0.66f ? 1 : time > 0.33f ? 0.5 : 0;
    float kaos = pow(time, 2) * ofGetHeight()/2.0 ;
    ofSetRandomSeed(pow(t, 0.7) + ofGetElapsedTimef());
    float offsetX = ofRandom(-kaos, kaos);
    ofSetRandomSeed(pow(2*t, 0.7) + ofGetElapsedTimef());
    float offsetY = ofRandom(-kaos, kaos);
    float x = cos(t) * staticRadius  * radiusX / radius + offsetX;
    float y = sin(t) * staticRadius * radiusY / radius + offsetY;
    polyline.addVertex( x,  y);
  }

  polyline.close();
  // polyline.draw();
  auto vertices = polyline.getVertices();
  for(auto& vertex : vertices) {
    // ofDrawRectangle(vertex, 1, 5);
    ofNoFill();
    ofDrawCircle(vertex, 5);
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
