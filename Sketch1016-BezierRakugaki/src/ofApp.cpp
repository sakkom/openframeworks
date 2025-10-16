#include "ofApp.h"
#include "ofAppRunner.h"
#include "ofEvents.h"
#include "ofGraphics.h"
#include "ofMath.h"
#include "ofMathConstants.h"
#include "ofPolyline.h"
#include "ofUtils.h"
#include "ofVec2f.h"

//--------------------------------------------------------------
void ofApp::setup(){
  ofSetBackgroundColor(0);
  regeneratePoints();
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
  ofPolyline line;

  for(int i = 0; i < points.size(); i++) {
    line.curveTo(points[i]);
  }

  line.draw();
}

void ofApp::regeneratePoints() {
  points.clear();

  glm::vec3 center = glm::vec3(ofGetWidth()/2, ofGetHeight()/2, 0);
  float radius = 300;

  for(int i = 0; i < 500; i++) {
    glm::vec3 point = randomPointInCicle(center, radius);
    points.push_back(point);
  }
}

glm::vec3 ofApp::randomPointInCicle(glm::vec3 center, float radius) {
  // glm::vec3 point;

  // do{
  //   float randomX = ofRandom(center.x - radius, center.x + radius);
  //   float randomY = ofRandom(center.y - radius, center.y + radius);
  //   point = glm::vec3(randomX, randomY, 0);
  // } while(glm::distance(point, center) >= radius);

  // return point;
  float angle = ofRandom(0, TWO_PI);
  float randomRadius = pow(ofRandom(), exponent) * radius;
  float x = center.x + randomRadius * cos(angle);
  float y = center.y + randomRadius * sin(angle);

  return glm::vec3(x, y, 0);
}

//--------------------------------------------------------------
void ofApp::exit(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
  if(key == OF_KEY_UP) {
    exponent += 0.25;
    exponent = fmin(exponent, 10.0);
    regeneratePoints();
  }
  else if(key == OF_KEY_DOWN) {
    exponent -= 0.25;
    exponent = fmax(exponent, 0.0);
    regeneratePoints();
  }
  else if(key == 's') {
    exponent = 0.0;
    regeneratePoints();
  }
  else if(key == 'j') {
    exponent = 10.0;
    regeneratePoints();
  }
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
