# 時間ベースのアルキメデススパイラル
[ヘリックス](https://github.com/sakkom/openframeworks/tree/main/Spirals/src/Helix/README.md)
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
### <ins>ぐるぐる内から見るか外からみるか</ins>
時間の変化のに対して`radius = maxRadius * progress`で半径を変化させるが`[0, 1]`の範囲では内から外になるが、範囲をずらし`[1, 0]`ならば外から内にスタートと同時に最大値を迎えることができる。
余談で`radius = maxRadius * progress`は等間隔な線形増加だが、二次関数や対数関数で半径の間隔を調整しても面白い。
これらのRadiusのスピード的な関数については別途どこかで取り組むたい。
