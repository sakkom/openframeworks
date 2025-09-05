#include "ofApp.h"
//--------------------------------------------------------------
void ofApp::setup(){
  ofSetFrameRate(60);
  ofEnableDepthTest();
  light.setPosition(0,0, 1000);

  /*
   Config -> Gridという依存関係がある。
   静的メンバはmain()よりも先に実行されるためoF関数が使えない。
   そのため人為的に静的メンバをここで初期化する。
   Gridは依存関係より静的メンバが確約されてからインスタンス化する。
   */
  Config::init();
  grid.emplace();
}

//--------------------------------------------------------------
void ofApp::update(){
  grid->update();
}

//--------------------------------------------------------------
void ofApp::draw(){
  cam.begin();
  light.enable();
  grid->draw();
  light.disable();
  cam.end();

  //  ofDrawBitmapString(ofToString(ofGetFrameRate(), 1), 10, 10);
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
