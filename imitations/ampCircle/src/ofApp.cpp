#include "ofApp.h"
#include "ofAppRunner.h"
#include "ofGraphics.h"


//--------------------------------------------------------------
void ofApp::setup(){
  ofSetBackgroundColor(ofColor::red);
  ofEnableDepthTest();

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
// cam.begin();
  ofPushMatrix();
  ofTranslate(ofGetWidth() / 2.0, ofGetHeight() / 2.0);

  float baseMinOut = 50.0;
  float baseMaxOut = baseMinOut * 2;
  /*1024本で最大5円デザイン */
  float lines = pow(2, 10);
  int modulos[] = {16, 8,4, 2, 1};
  float ratios[] = {1.0, 1.3, 1.7, 2.2, 3.9};
  // float ratios[] = {1.0, 1.2, 1.4, 1.6, 2.0};

  for(float theta = 0; theta < TWO_PI ; theta += TWO_PI/lines) {
    //theta=6.28で理解する。
    int index = int(theta * lines/ TWO_PI);

    for(int i = 0; i < 3; i++) {
      if(index % modulos[i] == 0) {

        /*Color配置----------------------------------------- */
        // if((index / modulos[i]) % 2 == 0) {
        //     ofSetColor(ofColor::black);
        // } else {
        //     ofSetColor(ofColor::white);
        // }

        if(i % 2 == 0) {
            ofSetColor(ofColor::black);
        } else {
            ofSetColor(ofColor::white);
        }
        //---------------------------------------------------

        float r = ofMap(ofNoise(
          cos(theta) * 1.5,
          sin(theta) * 1.5,
          ofGetFrameNum() * 0.015f
        ), 0, 1, baseMinOut + i * 20, (baseMaxOut + i * 20) * ratios[i] );
        float x = r * cos(theta);
        float y = r * sin(theta);
c        ofPushMatrix();
        ofTranslate(x, y);
        ofRotateRad(theta);
        ofDrawRectangle(0, 0, 75, 8);
        ofPopMatrix();
      }
    }

  }
  ofPopMatrix();

  /*ストライプ背景 */
  // ofPushMatrix();
  // float gap = ofGetWidth() / 200.0;
  // for(int g = 0; g < ofGetWidth(); g += gap) {
  //     if(int(g / gap) % 2 == 0) {
  //         ofSetColor(ofColor::white);
  //     } else {
  //         ofSetColor(ofColor::black);
  //     }
  //     ofDrawRectangle(g, 0, gap, ofGetHeight());
  // }
  // ofPopMatrix();

  // cam.end();
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
