---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/unionfind/potential_unionfind.hpp\"\n// Potentialized\
    \ Union-Find\u69CB\u9020\u4F53\n// \u5404\u8981\u7D20\u9593\u306E\u30DD\u30C6\u30F3\
    \u30B7\u30E3\u30EB\u5DEE\u3092\u7BA1\u7406\u3059\u308B\nclass PotentializedUnionFind\
    \ {\nprivate:\n    std::vector<int> parent;      // \u89AA\u30CE\u30FC\u30C9\n\
    \    std::vector<int64_t> weight;  // weight[x]: potential[x] - potential[parent[x]]\n\
    \npublic:\n    // \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\n    PotentializedUnionFind(int\
    \ n) : parent(n), weight(n, 0) {\n        for (int i = 0; i < n; ++i)\n      \
    \      parent[i] = i;\n    }\n\n    // x\u306E\u6839\u3092\u898B\u3064\u3051\u308B\
    \uFF08\u7D4C\u8DEF\u5727\u7E2E\u3042\u308A\uFF09\n    // weight[x]\u3092potential[x]\
    \ - potential[root]\u306B\u66F4\u65B0\n    int root(int x) {\n        if (parent[x]\
    \ == x)\n            return x;\n        int r = root(parent[x]);\n        weight[x]\
    \ += weight[parent[x]];\n        return parent[x] = r;\n    }\n\n    // x\u3068\
    y\u3092\u30DD\u30C6\u30F3\u30B7\u30E3\u30EB\u5DEEw\u3067\u4F75\u5408\n    // potential[y]\
    \ = potential[x] + w\u3068\u306A\u308B\u3088\u3046\u306B\u3059\u308B\n    // \u4E00\
    \u8CAB\u6027\u304C\u53D6\u308C\u306A\u3044\u5834\u5408\u306Ffalse\u3092\u8FD4\u3059\
    \n    bool unite(int x, int y, int64_t w) {\n        int rx = root(x);\n     \
    \   int ry = root(y);\n        if (rx == ry) {\n            // \u4E00\u8CAB\u6027\
    \u306E\u30C1\u30A7\u30C3\u30AF\n            if (potential(y) - potential(x) !=\
    \ w)\n                return false;\n            else\n                return\
    \ true;\n        }\n        w = w + weight[x] - weight[y]; // weight\u3092\u8ABF\
    \u6574\n        parent[ry] = rx;\n        weight[ry] = -w;\n        return true;\n\
    \    }\n\n    // x\u306E\u30DD\u30C6\u30F3\u30B7\u30E3\u30EB\u3092\u53D6\u5F97\
    \n    int64_t potential(int x) {\n        root(x); // weight[x]\u3092\u66F4\u65B0\
    \n        return weight[x];\n    }\n\n    // x\u304B\u3089y\u3078\u306E\u30DD\u30C6\
    \u30F3\u30B7\u30E3\u30EB\u5DEE\uFF08potential[y] - potential[x]\uFF09\u3092\u53D6\
    \u5F97\n    // \u9023\u7D50\u3057\u3066\u3044\u306A\u3044\u5834\u5408\u306Fstd::nullopt\u3092\
    \u8FD4\u3059\n    std::optional<int64_t> diff(int x, int y) {\n        if (root(x)\
    \ != root(y))\n            return std::nullopt;\n        return potential(y) -\
    \ potential(x);\n    }\n\n    // x\u3068y\u304C\u540C\u3058\u30B0\u30EB\u30FC\u30D7\
    \u306B\u5C5E\u3059\u308B\u304B\u3092\u5224\u5B9A\n    bool same(int x, int y)\
    \ {\n        return root(x) == root(y);\n    }\n};\n"
  code: "// Potentialized Union-Find\u69CB\u9020\u4F53\n// \u5404\u8981\u7D20\u9593\
    \u306E\u30DD\u30C6\u30F3\u30B7\u30E3\u30EB\u5DEE\u3092\u7BA1\u7406\u3059\u308B\
    \nclass PotentializedUnionFind {\nprivate:\n    std::vector<int> parent;     \
    \ // \u89AA\u30CE\u30FC\u30C9\n    std::vector<int64_t> weight;  // weight[x]:\
    \ potential[x] - potential[parent[x]]\n\npublic:\n    // \u30B3\u30F3\u30B9\u30C8\
    \u30E9\u30AF\u30BF\n    PotentializedUnionFind(int n) : parent(n), weight(n, 0)\
    \ {\n        for (int i = 0; i < n; ++i)\n            parent[i] = i;\n    }\n\n\
    \    // x\u306E\u6839\u3092\u898B\u3064\u3051\u308B\uFF08\u7D4C\u8DEF\u5727\u7E2E\
    \u3042\u308A\uFF09\n    // weight[x]\u3092potential[x] - potential[root]\u306B\
    \u66F4\u65B0\n    int root(int x) {\n        if (parent[x] == x)\n           \
    \ return x;\n        int r = root(parent[x]);\n        weight[x] += weight[parent[x]];\n\
    \        return parent[x] = r;\n    }\n\n    // x\u3068y\u3092\u30DD\u30C6\u30F3\
    \u30B7\u30E3\u30EB\u5DEEw\u3067\u4F75\u5408\n    // potential[y] = potential[x]\
    \ + w\u3068\u306A\u308B\u3088\u3046\u306B\u3059\u308B\n    // \u4E00\u8CAB\u6027\
    \u304C\u53D6\u308C\u306A\u3044\u5834\u5408\u306Ffalse\u3092\u8FD4\u3059\n    bool\
    \ unite(int x, int y, int64_t w) {\n        int rx = root(x);\n        int ry\
    \ = root(y);\n        if (rx == ry) {\n            // \u4E00\u8CAB\u6027\u306E\
    \u30C1\u30A7\u30C3\u30AF\n            if (potential(y) - potential(x) != w)\n\
    \                return false;\n            else\n                return true;\n\
    \        }\n        w = w + weight[x] - weight[y]; // weight\u3092\u8ABF\u6574\
    \n        parent[ry] = rx;\n        weight[ry] = -w;\n        return true;\n \
    \   }\n\n    // x\u306E\u30DD\u30C6\u30F3\u30B7\u30E3\u30EB\u3092\u53D6\u5F97\n\
    \    int64_t potential(int x) {\n        root(x); // weight[x]\u3092\u66F4\u65B0\
    \n        return weight[x];\n    }\n\n    // x\u304B\u3089y\u3078\u306E\u30DD\u30C6\
    \u30F3\u30B7\u30E3\u30EB\u5DEE\uFF08potential[y] - potential[x]\uFF09\u3092\u53D6\
    \u5F97\n    // \u9023\u7D50\u3057\u3066\u3044\u306A\u3044\u5834\u5408\u306Fstd::nullopt\u3092\
    \u8FD4\u3059\n    std::optional<int64_t> diff(int x, int y) {\n        if (root(x)\
    \ != root(y))\n            return std::nullopt;\n        return potential(y) -\
    \ potential(x);\n    }\n\n    // x\u3068y\u304C\u540C\u3058\u30B0\u30EB\u30FC\u30D7\
    \u306B\u5C5E\u3059\u308B\u304B\u3092\u5224\u5B9A\n    bool same(int x, int y)\
    \ {\n        return root(x) == root(y);\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/unionfind/potential_unionfind.hpp
  requiredBy: []
  timestamp: '2024-11-19 06:07:23+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/unionfind/potential_unionfind.hpp
layout: document
title: "\u30DD\u30C6\u30F3\u30B7\u30E3\u30EB\u4ED8\u304DUnion-Find"
---

ポテンシャル付きUnion-Findは、各要素間の「差分」や「ポテンシャル」を管理する拡張版です。

例えば、以下のような用途に使えます：
- グラフ上の重み付き辺の管理。
- 制約付き等式の判定。

以下はそのC++コードの実装例です。

