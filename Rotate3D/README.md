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

### <ins>軸に直角に回転する</ins>
軸に直角に回転するので
x軸回転のときはx座標は不変。yz平面で座標が変化。
y軸回転のときはy座標は不変。xz平面で座標が変化。
z軸回転のときはz座標は不変。xy平面で座標が変化。
