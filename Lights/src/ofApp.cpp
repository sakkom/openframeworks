#include "ofApp.h"
#include "ofColor.h"
#include "ofGraphics.h"
#include "ofShadow.h"

void ofApp::setup(){
    ofShadow::enableAllShadows();

    // shadows and lights work with materials
    // create some different materials so the lighting and shadows can be applied
    planeMaterial.setDiffuseColor(ofFloatColor(0.8, 0.8, 0.8));  // グレー
    planeMaterial.setSpecularColor(ofFloatColor(0.2));
    planeMaterial.setShininess(1);

    boxMaterial.setDiffuseColor(ofFloatColor(0.8, 0.3, 0.3));    // 赤
    boxMaterial.setSpecularColor(ofFloatColor(0.5));
    boxMaterial.setShininess(64);

    cout << "Shadows supported: " << ofShadow::areShadowsSupported() << endl;
    cout << "GL Programmable: " << ofIsGLProgrammableRenderer() << endl;

    box.set(100, 100, 100);
    boxMesh = box.getMesh();

    plane.set(1500, 1500);
    planeMesh = plane.getMesh();

    cam.setDistance(1000);
    light.setPointLight();
    light.setDiffuseColor(ofColor::cyan);
}

void ofApp::update(){
}

void ofApp::draw(){
    ofEnableDepthTest();

    if(light.shouldRenderShadowDepthPass()){
        light.beginShadowDepthPass(0);
        renderScene();
        light.endShadowDepthPass(0);
    }

    // 通常描画
    cam.begin();
    light.enable();
    light.setPosition(0, 0, 1000);
    light.getShadow().setStrength(0.8f);

    ofSetColor(light.getDiffuseColor());
    ofDrawSphere(light.getPosition(), 12);
    // light.draw();????
    // light->getShadow().drawFrustum();

    renderScene();
    cam.end();
    ofDisableDepthTest();
}

void ofApp::renderScene(){
  planeMaterial.begin();
    ofPushMatrix();
    ofTranslate(0, 0, 0);
    planeMesh.draw();
    ofPopMatrix();
    planeMaterial.end();

    boxMaterial.begin();
    ofPushMatrix();
    ofTranslate(0, 0, 300);
    boxMesh.draw();
    ofPopMatrix();
    boxMaterial.end();
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
