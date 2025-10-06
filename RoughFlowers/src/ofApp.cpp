#include "ofApp.h"
#include "ofAppRunner.h"
#include "ofGraphics.h"
#include "ofMath.h"
#include "ofMathConstants.h"
#include "ofPolyline.h"
#include "ofUtils.h"
#include "vector_float2.hpp"
#include <cmath>

//--------------------------------------------------------------
void ofApp::setup(){
  ofSetBackgroundColor(ofColor::black);
  colors.push_back(ofColor::fromHex(0xaaffff));  // 水色
  colors.push_back(ofColor::fromHex(0xffffaa));  // 淡い黄色
  colors.push_back(ofColor::fromHex(0xffaaff));

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
  sinFlower();

}

void ofApp::sinFlower() {

  for(int i = 0; i< 50; i++) {
    ofPolyline polyline;

    int timeStep = int(ofGetElapsedTimef() / 1.0);

    ofSetRandomSeed(i + timeStep * 50);
    glm::vec2 pos(ofRandom(0, ofGetWidth()), ofRandom(0, ofGetHeight()));
    ofPushMatrix();
    ofTranslate(pos.x, pos.y);

    float progress = ofMap(i, 0, 50, 0.1, 1);
    float radius = 75 * progress;
    float circleStep = TWO_PI / 200;

    float delay = i * 0.1;
    float time = ofGetElapsedTimef() * 3 - delay;



    for(float j = 0; j < TWO_PI * 3 ; j += circleStep) {
      int loopNum = int(j / TWO_PI) + 1;
      ofSetRandomSeed(j);
      float radiusNoise = sin(j * 5 + time * loopNum) * radius;
      float mappedRadius = ofMap(radiusNoise, -radius, radius, 5, radius);
      float x = cos(j) * mappedRadius;
      float y = sin(j) * mappedRadius;
      polyline.addVertex( x,  y);
  }

    polyline.close();

    ofSetColor(colors[i % colors.size()]);
    auto vertices = polyline.getVertices();
    for(auto& vertex : vertices) {
      ofDrawRectangle(vertex, 1, 5);
    }
    ofPopMatrix();

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
