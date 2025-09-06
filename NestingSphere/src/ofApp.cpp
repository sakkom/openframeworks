#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  ofEnableDepthTest();
  spheres.resize(3);
  lights.resize(3);

//  cam.setNearClip(3.0f);
//  cam.setTarget(ofVec3f(0));
//  cam.setTranslationSensitivity(glm::vec3(0.1f, 0.1f, 0.1f));

  for(int i = 0; i < 3; i++) {
    float base = 300;
    float radius = base + base * i;
    
    spheres[i].setPosition(0, 0, 0);
    spheres[i].setRadius(radius);
    lights[i].setPosition(ofVec3f(radius + base / 2));
  }

  //
//  material.setAmbientColor(ofColor::white);
//  material.setDiffuseColor(ofColor(250, 250, 250));
//  material.setSpecularColor(ofColor(200, 200, 200));
//  material.setShininess(100);
}

//--------------------------------------------------------------
void ofApp::update(){
  float time = ofGetElapsedTimef();

  float cameraWidth = 2000;

  float z = cameraWidth * cos(time * 0.5f);

  cam.setPosition(0, 0, z);
  cam.lookAt(ofVec3f(0));
}

//--------------------------------------------------------------
void ofApp::draw(){

  cam.begin();
//  ofVec3f pos = cam.getPosition();
//  cout << "カメラ" << pos << endl;

  for(int i = 0; i < 3; i++) {
    lights[i].enable();

    switch(i) {
      case 0:
        ofSetColor(ofColor::red);
        break;
      case 1:
        ofSetColor(ofColor::green);
        break;
      case 2: ofSetColor(ofColor::blue);
        break;
      default:
        ofSetColor(ofColor::white);
        break;
    }

    spheres[i].drawFaces();
    lights[i].disable();
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
