#include "ofApp.h"
#include "of3dUtils.h"
#include "ofColor.h"
#include "ofGraphics.h"
#include "ofShader.h"
#include "ofShadow.h"
#include "ofUtils.h"
#include "vector_float3.hpp"

void ofApp::setup(){
    ofShadow::enableAllShadows();

    // shadows and lights work with materials
    // create some different materials so the lighting and shadows can be applied
    planeMaterial.setDiffuseColor(ofFloatColor(0.0f, 0.0f, 0.0f));
    planeMaterial.setSpecularColor(ofFloatColor(1.0f));
    planeMaterial.setShininess(64);

    boxMaterial.setDiffuseColor(ofFloatColor(1.0f, 0.5f, 0.0f));
    // boxMaterial.setSpecularColor(ofFloatColor(1.0f));
    // boxMaterial.setShininess(64);

    cylinderMaterial.setDiffuseColor(ofFloatColor(1.0f, 0.0f, 1.0f));

    cout << "Shadows supported: " << ofShadow::areShadowsSupported() << endl;
    cout << "GL Programmable: " << ofIsGLProgrammableRenderer() << endl;

    box.set(100, 100, 100);
    boxMesh = box.getMesh();

    plane.set(1500, 1500);
    planeMesh = plane.getMesh();

    cylinder.set(5, 200);
    cylinderMesh = cylinder.getMesh();

    cam.setDistance(1000);
    light1.setPointLight();
    light2.setPosition(500, 0, 1000);
    // light3.setPosition(-500, -500, 1000);
}

void ofApp::update(){
  float radius = 500;
  light1.setPosition(cos(ofGetElapsedTimef())* radius , sin(ofGetElapsedTimef())* radius, 1000);
}

void ofApp::draw(){
    ofEnableDepthTest();

    if(light1.shouldRenderShadowDepthPass()){
        light1.beginShadowDepthPass(0);
        renderScene();
        light1.endShadowDepthPass(0);
    }

    if(light2.shouldRenderShadowDepthPass()){
        light2.beginShadowDepthPass(0);
        renderScene();
        light2.endShadowDepthPass(0);
    }

    // if(light3.shouldRenderShadowDepthPass()){
    //     light3.beginShadowDepthPass(0);
    //     renderScene();
    //     light3.endShadowDepthPass(0);
    // }
    // 通常描画
    cam.begin();
    light1.enable();
    light2.enable();
    light3.enable();
    // light.setPosition(500, 500, 1000);
    light1.getShadow().setStrength(1.0f);
    light2.getShadow().setStrength(1.0f);
    // light3.getShadow().setStrength(1.0f);

    ofSetColor(light1.getDiffuseColor());
    ofDrawSphere(light1.getPosition(), 12);
    ofSetColor(light2.getDiffuseColor());
    ofDrawSphere(light2.getPosition(), 12);
    // ofSetColor(light3.getDiffuseColor());
    // ofDrawSphere(light3.getPosition(), 12);
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

    // boxMaterial.begin();
    // ofPushMatrix();
    // ofTranslate(0, 0, 300);
    // boxMesh.draw();
    // ofPopMatrix();
    // boxMaterial.end();

    // cylinderMaterial.begin();
    // ofPushMatrix();
    // ofTranslate(300, 0, 300);
    // cylinderMesh.draw();
    // ofPopMatrix();
    // cylinderMaterial.end();
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
