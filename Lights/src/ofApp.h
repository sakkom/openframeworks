#pragma once

#include "of3dGraphics.h"
#include "of3dPrimitives.h"
#include "ofMain.h"
#include "ofShadow.h"

class ofApp : public ofBaseApp{

	public:
		void setup() override;
		void update() override;
		void draw() override;
		void exit() override;

		void keyPressed(int key) override;
		void keyReleased(int key) override;
		void mouseMoved(int x, int y ) override;
		void mouseDragged(int x, int y, int button) override;
		void mousePressed(int x, int y, int button) override;
		void mouseReleased(int x, int y, int button) override;
		void mouseScrolled(int x, int y, float scrollX, float scrollY) override;
		void mouseEntered(int x, int y) override;
		void mouseExited(int x, int y) override;
		void windowResized(int w, int h) override;
		void dragEvent(ofDragInfo dragInfo) override;
		void gotMessage(ofMessage msg) override;
		void renderScene();
		/* */

		ofEasyCam cam;
		ofLight light1, light2, light3;
		// ofMaterial material;
		ofBoxPrimitive box;
		ofPlanePrimitive plane;
		ofMesh planeMesh, boxMesh, cylinderMesh;
		ofCylinderPrimitive cylinder;

		ofMaterial planeMaterial, boxMaterial, cylinderMaterial;
};
