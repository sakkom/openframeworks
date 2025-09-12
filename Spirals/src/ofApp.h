#pragma once

#include "ofMain.h"
#include "./Helix/helix.h"
#include "ofVec2f.h"
#include "./WaveHelix/waveHelix.h"
#include "spiralCoverage.h"
#include "./Archimeds/archimedes.h"
#include "./Lemniscate/lemniscate.h"
//#include "config.h"

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

  ofEasyCam cam;
  ofPolyline polyLine1, polyLine2;
  ofCylinderPrimitive cylinder2;
  float x, y, z;
  std::optional<Helix> helix;
  std::optional<WaveHelix> waveHelix;
  std::optional<SpiralCoverage> spiralCoverage;
  std::optional<Archimedes> archimedes;
  std::optional<Lemniscate> lemniscate;
//  UpCircle upCircle;
};
