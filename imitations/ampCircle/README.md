### 学んだテクニック
```cpp
void draw() {
  for(int theta = 0;, theta < TWO_PI; TWO_PI/256){
    //前略
    ofPushMatrix();
    ofTranslate(x, y);
    ofRotateRad(theta);
    ofDrawRectangle(0, 0, 75, 8);
    ofPopMatrix();
  }
}
```
`ofTranslate`は描写そのものの移動である。  
ひとつひとつのその地点での操作、回転もその地点中心で行われる。
