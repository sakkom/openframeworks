#include "ofApp.h"
#include "of3dPrimitives.h"
#include "ofAppRunner.h"
#include "ofGraphics.h"
#include "ofUtils.h"

//--------------------------------------------------------------
void ofApp::setup(){
  ofSetWindowShape(1280, 720);
  img.load("tree.jpg");
  img.resize(1280, 720);
  shader.load("shader/shader.vert", "shader/shader.frag");
  vdo.setDeviceID(0);
  vdo.setup(ofGetWidth(), ofGetWidth());
  for(int i = 0; i < 10; i++) {
    ofBoxPrimitive temp;
    glm::vec2 pos(ofRandom(0, ofGetWidth()), ofRandom(ofGetHeight()));
    float size = ofRandom(50, 150);
    temp.set(size);
    temp.setPosition(pos.x, pos.y, 0);
    boxies.push_back(temp);
  }
}

//--------------------------------------------------------------
void ofApp::update(){
  vdo.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
  float time = ofGetElapsedTimef();
  float exp = ofMap(cos(time * 1), -1, 1, 2, 1.0);
  float rot = ofMap(cos(time * 0.5), -1, 1, 2, 0);

  shader.begin();
  shader.setUniform2f("u_resolution", ofGetWidth(), ofGetHeight());
  shader.setUniformTexture("tex0", img.getTexture(), 0);
  shader.setUniform1f("u_exp", exp);
  shader.setUniform1f("u_rot", rot);

  // for(auto& box: boxies) {
  //   box.drawWireframe();
  // }
  img.getTexture().draw(0, 0, 1280, 720);
  // vdo.getTexture().draw(0, 0, vdo.getWidth(), vdo.getHeight());
  shader.end();
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
