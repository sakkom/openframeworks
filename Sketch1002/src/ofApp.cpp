#include "ofApp.h"
#include "ofGraphics.h"
#include "ofMath.h"
#include "ofUtils.h"

//--------------------------------------------------------------
void ofApp::setup(){
  ofEnableDepthTest();
  plane.set(500, 500, 100, 100);
  plane.setMode(OF_PRIMITIVE_TRIANGLES);
  mesh = plane.getMesh();
}

//--------------------------------------------------------------
void ofApp::update(){
  for(int i = 0; i < mesh.getNumVertices(); i++){
    glm::vec3 pos = mesh.getVertex(i);
    float r = sqrt(pos.x * pos.x + pos.y*pos.y);
    float wave = sin(r * 0.01 + ofGetElapsedTimef()) * 100;
    mesh.setVertex(i, glm::vec3(pos.x, pos.y, wave));
  }
}

//--------------------------------------------------------------
void ofApp::draw(){
  cam.begin();
  mesh.draw();
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
