---
layout: algorithm
title: ポテンシャル付きUnion-Find
permalink: /algorithms/unionfind/potential_unionfind/
---

ポテンシャル付きUnion-Findは、各要素間の「差分」や「ポテンシャル」を管理する拡張版です。

例えば、以下のような用途に使えます：
- グラフ上の重み付き辺の管理。
- 制約付き等式の判定。

以下はそのC++コードの実装例です。

```cpp
{% include_relative code.cpp %}