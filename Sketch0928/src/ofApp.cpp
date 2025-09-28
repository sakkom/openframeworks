#include "ofApp.h"
#include "of3dGraphics.h"
#include "ofAppRunner.h"
#include "ofColor.h"
#include "ofGraphics.h"
#include "ofMath.h"
#include "ofMathConstants.h"
#include "ofUtils.h"
#include "vector_float3.hpp"

//--------------------------------------------------------------
void ofApp::setup(){
  ofSetBackgroundColor(ofColor::black);
  light.setPosition(200, 200, 200);
  material.setDiffuseColor(ofFloatColor::white);
  material.setSpecularColor(ofFloatColor::gray);
  material.setShininess(1);
}

//--------------------------------------------------------------
void ofApp::update(){

}

void ofApp::draw(){
    ofEnableDepthTest();
    cam.begin();
    light.enable();
    material.begin();

    ofPushMatrix();
    float direction = ofSign(sin(ofGetElapsedTimef()));
    ofRotateYRad(ofGetElapsedTimef() * direction);
    ofRotateXRad(ofGetElapsedTimef() * -direction);
    ofRotateZRad(ofGetElapsedTimef() * direction);

    for(float theta = 0; theta < TWO_PI; theta += 0.3) {
        float innerRadius = 150;
        float x = innerRadius * cos(theta);
        float y = innerRadius * sin(theta);
        float z = 0;

        ofPushMatrix();
        ofTranslate(x, y, z);
        ofRotateZRad(theta + ofGetElapsedTimef());

        ofPolyline circle;
        for(float phi = 0; phi < TWO_PI; phi += TWO_PI / 32.0) {
          float circleRadiusZ = 50;
            float circleRadiusY = 100;
            circle.addVertex(0, circleRadiusY * cos(phi), circleRadiusZ * sin(phi));
        }
        for(int i = 0; i < circle.getVertices().size(); i++){
          ofSetRandomSeed(theta + ofGetElapsedTimef() * 2.0);
          float size = ofRandom(1, 10);
          ofDrawBox(circle.getVertices()[i], size);
        }
        ofPopMatrix();
    }
    ofPopMatrix();

    material.end();
    light.disable();
    cam.end();
    ofDisableDepthTest();
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
