# 螺旋座標
`ofSetFrameRate(60`  
## ヘリックス
```cpp
float speed = ofGetElapsedTimef() * 6.227f
pos.x = cos(speed);
pos.z = sin(speed);
```
#### <ins>底面となる円</ins>
円(2D)は(x, y)によって円を描くことができる。  sinは高さの位相でcosは底辺の位相である。底辺がx軸で高さがy軸であらわされることが多い。  
今回は高さをz軸にすることで3D空間でPolyLineを使用し円を描くことを試みる。
#### <ins>円周運動、1秒間に1周する</ins>
円周2PIは1周分の位相空間として認識する。  
位相がframe毎に増えるにしたがい現在の(x, z)が決まる。  
**60fpsでは1frameは0.0167f**で実際のスピード感覚として、1秒間で`0.0167f * 60.0f = 1`であり、円周上の2PIのうちの1の位相であり遅く感じる。  
1秒間で1周するには`2PI / 60.0f = 0.104f`の**間隔**が必要であることがわかる。
当たり前であるが`update()`はframe毎に実行されるので`0.0167f * x = 0.104f = 6.227f`でスケールすれば**0.0167fの間隔から0.104fの間隔**になり一秒間に一周する。

```cpp
//並行移動とスケールで任意の場所・大きさに
    pos.x = radius * cos(speed) + place.x;
    pos.z = radius * sin(speed) + place.z;
```
#### <ins>高さをつけてHelixらしくする</ins>
高さがなければ線の変化は生まれない。
```cpp
  bool addHeight(float delay, float cylinderHeihgt) {
    float targetTime = 2.5f;
        float currentTime = ofMin(ofGetElapsedTimef() - delay, targetTime);
    float progress = currentTime / targetTime;
    
    float startY = place.y - cylinderHeihgt / 2;
    pos.y = startY + cylinderHeihgt * progress;
    //progress=1で無限になるので明示的に終了
    bool isRunning = progress >= 1.0f;
    return isRunning;
  }
```
ここで紹介する方法としてはどれくらいの時間で任意の高さ(ここではCylinderとセットのデザイン)に到達するのかである。  
進捗度に応じた高さの位相`ajustedTime / targetTime`として`cylinderHeihgt * progress`で高さが決まる。  注意として`ofMin`を使い最大値を拘束され正規化された値は、1(100%)を超えることはないが、100%の位相でのループが走るのでbool値を返して例外処理を行い止める必要がある。また起動時の`ofGetElapsedTimef()`の不安定性から`delay`を設定している。  
## 時間ベースのアルキメデススパイラル
```cpp
  Archimedes(ofVec3f center, float maxRadius, float targetTime) {
  }
```
前回のヘリックスからの文脈より最大経過時間`targetTime`で描写すると決めた。  
```cpp
    //float progress = currentTime / targetTime;　//うち->そと
    float progress = 1.0f - currentTime / targetTime;//そと->うち
    float radius = maxRadius * progress;
    //(略)後述はヘリックスの円周運動と類似
```
#### <ins>ぐるぐる内から見るか外からみるか</ins>
時間の変化のに対して`radius = maxRadius * progress`で半径を変化させるが`[0, 1]`の範囲では内から外になるが、範囲をずらし`[1, 0]`ならば外から内にスタートと同時に最大値を迎えることができる。  
余談で`radius = maxRadius * progress`は等間隔な線形増加だが、二次関数や対数関数で半径の間隔を調整しても面白い。
これらのRadiusのスピード的な関数については別途どこかで取り組むたい。






