# 任意のひとつの軸中心回転

```cpp
  drawAxes();

  ofRotateXDeg(ofGetFrameNum() * 1.0f);
  // ofRotateYDeg(ofGetFrameNum() * 1.0f);
  // ofRotateZDeg(ofGetFrameNum() * 1.0f);

  cone.setPosition(128, 128, -128);
  ofSetColor(ofColor::white);
  cone.drawWireframe();
```
