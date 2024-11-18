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
  bundledCode: "#line 1 \"src/unionfind/unionfind.hpp\"\n#include <vector>\n#include\
    \ <optional>\n#include <algorithm>\n\n// Union-Find (Disjoint Set Union) \u30AF\
    \u30E9\u30B9\n// \u30B0\u30E9\u30D5\u306E\u9023\u7D50\u6027\u3092\u52B9\u7387\u7684\
    \u306B\u7BA1\u7406\u3059\u308B\u30C7\u30FC\u30BF\u69CB\u9020\nclass UnionFind\
    \ {\nprivate:\n    std::vector<int> parent; // \u5404\u9802\u70B9\u306E\u89AA\u3092\
    \u8A18\u9332\u3059\u308B\u914D\u5217\n    std::vector<int> size;   // \u5404\u96C6\
    \u5408\u306E\u30B5\u30A4\u30BA\u3092\u8A18\u9332\u3059\u308B\u914D\u5217\n   \
    \ int num_groups;          // \u73FE\u5728\u306E\u30B0\u30EB\u30FC\u30D7\u306E\
    \u6570\n\npublic:\n    // \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\n    // n:\
    \ \u9802\u70B9\u306E\u6570\n    UnionFind(int n) : parent(n), size(n, 1), num_groups(n)\
    \ {\n        // \u521D\u671F\u5316: \u5404\u9802\u70B9\u3092\u81EA\u5206\u81EA\
    \u8EAB\u3092\u89AA\u3068\u3059\u308B\n        for (int i = 0; i < n; ++i)\n  \
    \          parent[i] = i;\n    }\n\n    // \u6839\u3092\u898B\u3064\u3051\u308B\
    \uFF08\u7D4C\u8DEF\u5727\u7E2E\u3092\u9069\u7528\uFF09\n    // x: \u5BFE\u8C61\
    \u306E\u9802\u70B9\n    // \u623B\u308A\u5024: x \u304C\u5C5E\u3059\u308B\u96C6\
    \u5408\u306E\u6839\n    int root(int x) {\n        if (parent[x] == x)\n     \
    \       return x; // \u81EA\u8EAB\u304C\u6839\u306E\u5834\u5408\n        else\n\
    \            return parent[x] = root(parent[x]); // \u7D4C\u8DEF\u5727\u7E2E:\
    \ \u518D\u5E30\u7684\u306B\u6839\u3092\u63A2\u7D22\u3057\u66F4\u65B0\n    }\n\n\
    \    // 2\u3064\u306E\u9802\u70B9\u304C\u540C\u3058\u96C6\u5408\u306B\u5C5E\u3057\
    \u3066\u3044\u308B\u304B\u5224\u5B9A\n    // x, y: \u5BFE\u8C61\u306E\u9802\u70B9\
    \n    // \u623B\u308A\u5024: \u540C\u3058\u96C6\u5408\u306B\u5C5E\u3057\u3066\u3044\
    \u308C\u3070 true\n    bool same(int x, int y) {\n        return root(x) == root(y);\
    \ // \u6839\u304C\u540C\u3058\u3067\u3042\u308C\u3070\u540C\u3058\u96C6\u5408\n\
    \    }\n\n    // 2\u3064\u306E\u96C6\u5408\u3092\u7D71\u5408\n    // x, y: \u5BFE\
    \u8C61\u306E\u9802\u70B9\n    // \u623B\u308A\u5024: \u7D71\u5408\u304C\u6210\u529F\
    \u3059\u308C\u3070 true, \u65E2\u306B\u540C\u3058\u96C6\u5408\u306A\u3089 false\n\
    \    bool unite(int x, int y) {\n        x = root(x); // x \u306E\u6839\u3092\u53D6\
    \u5F97\n        y = root(y); // y \u306E\u6839\u3092\u53D6\u5F97\n        if (x\
    \ == y) // \u65E2\u306B\u540C\u3058\u96C6\u5408\u306E\u5834\u5408\n          \
    \  return false;\n\n        // \u30B5\u30A4\u30BA\u304C\u5C0F\u3055\u3044\u65B9\
    \u3092\u5927\u304D\u3044\u65B9\u306B\u4F75\u5408\n        if (size[x] < size[y])\n\
    \            std::swap(x, y);\n\n        parent[y] = x;      // y \u3092 x \u306E\
    \u5B50\u306B\u3059\u308B\n        size[x] += size[y]; // x \u306E\u96C6\u5408\u306E\
    \u30B5\u30A4\u30BA\u3092\u66F4\u65B0\n        --num_groups;       // \u30B0\u30EB\
    \u30FC\u30D7\u6570\u3092\u6E1B\u5C11\n        return true;\n    }\n\n    // x\
    \ \u304C\u5C5E\u3059\u308B\u96C6\u5408\u306E\u30B5\u30A4\u30BA\u3092\u53D6\u5F97\
    \n    // x: \u5BFE\u8C61\u306E\u9802\u70B9\n    // \u623B\u308A\u5024: x \u304C\
    \u5C5E\u3059\u308B\u96C6\u5408\u306E\u30B5\u30A4\u30BA\n    int same_count(int\
    \ x) {\n        return size[root(x)];\n    }\n\n    // \u73FE\u5728\u306E\u30B0\
    \u30EB\u30FC\u30D7\u6570\u3092\u53D6\u5F97\n    // \u623B\u308A\u5024: \u73FE\u5728\
    \u306E\u30B0\u30EB\u30FC\u30D7\u6570\n    int num_groups() const {\n        return\
    \ num_groups;\n    }\n};\n"
  code: "#include <vector>\n#include <optional>\n#include <algorithm>\n\n// Union-Find\
    \ (Disjoint Set Union) \u30AF\u30E9\u30B9\n// \u30B0\u30E9\u30D5\u306E\u9023\u7D50\
    \u6027\u3092\u52B9\u7387\u7684\u306B\u7BA1\u7406\u3059\u308B\u30C7\u30FC\u30BF\
    \u69CB\u9020\nclass UnionFind {\nprivate:\n    std::vector<int> parent; // \u5404\
    \u9802\u70B9\u306E\u89AA\u3092\u8A18\u9332\u3059\u308B\u914D\u5217\n    std::vector<int>\
    \ size;   // \u5404\u96C6\u5408\u306E\u30B5\u30A4\u30BA\u3092\u8A18\u9332\u3059\
    \u308B\u914D\u5217\n    int num_groups;          // \u73FE\u5728\u306E\u30B0\u30EB\
    \u30FC\u30D7\u306E\u6570\n\npublic:\n    // \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\
    \u30BF\n    // n: \u9802\u70B9\u306E\u6570\n    UnionFind(int n) : parent(n),\
    \ size(n, 1), num_groups(n) {\n        // \u521D\u671F\u5316: \u5404\u9802\u70B9\
    \u3092\u81EA\u5206\u81EA\u8EAB\u3092\u89AA\u3068\u3059\u308B\n        for (int\
    \ i = 0; i < n; ++i)\n            parent[i] = i;\n    }\n\n    // \u6839\u3092\
    \u898B\u3064\u3051\u308B\uFF08\u7D4C\u8DEF\u5727\u7E2E\u3092\u9069\u7528\uFF09\
    \n    // x: \u5BFE\u8C61\u306E\u9802\u70B9\n    // \u623B\u308A\u5024: x \u304C\
    \u5C5E\u3059\u308B\u96C6\u5408\u306E\u6839\n    int root(int x) {\n        if\
    \ (parent[x] == x)\n            return x; // \u81EA\u8EAB\u304C\u6839\u306E\u5834\
    \u5408\n        else\n            return parent[x] = root(parent[x]); // \u7D4C\
    \u8DEF\u5727\u7E2E: \u518D\u5E30\u7684\u306B\u6839\u3092\u63A2\u7D22\u3057\u66F4\
    \u65B0\n    }\n\n    // 2\u3064\u306E\u9802\u70B9\u304C\u540C\u3058\u96C6\u5408\
    \u306B\u5C5E\u3057\u3066\u3044\u308B\u304B\u5224\u5B9A\n    // x, y: \u5BFE\u8C61\
    \u306E\u9802\u70B9\n    // \u623B\u308A\u5024: \u540C\u3058\u96C6\u5408\u306B\u5C5E\
    \u3057\u3066\u3044\u308C\u3070 true\n    bool same(int x, int y) {\n        return\
    \ root(x) == root(y); // \u6839\u304C\u540C\u3058\u3067\u3042\u308C\u3070\u540C\
    \u3058\u96C6\u5408\n    }\n\n    // 2\u3064\u306E\u96C6\u5408\u3092\u7D71\u5408\
    \n    // x, y: \u5BFE\u8C61\u306E\u9802\u70B9\n    // \u623B\u308A\u5024: \u7D71\
    \u5408\u304C\u6210\u529F\u3059\u308C\u3070 true, \u65E2\u306B\u540C\u3058\u96C6\
    \u5408\u306A\u3089 false\n    bool unite(int x, int y) {\n        x = root(x);\
    \ // x \u306E\u6839\u3092\u53D6\u5F97\n        y = root(y); // y \u306E\u6839\u3092\
    \u53D6\u5F97\n        if (x == y) // \u65E2\u306B\u540C\u3058\u96C6\u5408\u306E\
    \u5834\u5408\n            return false;\n\n        // \u30B5\u30A4\u30BA\u304C\
    \u5C0F\u3055\u3044\u65B9\u3092\u5927\u304D\u3044\u65B9\u306B\u4F75\u5408\n   \
    \     if (size[x] < size[y])\n            std::swap(x, y);\n\n        parent[y]\
    \ = x;      // y \u3092 x \u306E\u5B50\u306B\u3059\u308B\n        size[x] += size[y];\
    \ // x \u306E\u96C6\u5408\u306E\u30B5\u30A4\u30BA\u3092\u66F4\u65B0\n        --num_groups;\
    \       // \u30B0\u30EB\u30FC\u30D7\u6570\u3092\u6E1B\u5C11\n        return true;\n\
    \    }\n\n    // x \u304C\u5C5E\u3059\u308B\u96C6\u5408\u306E\u30B5\u30A4\u30BA\
    \u3092\u53D6\u5F97\n    // x: \u5BFE\u8C61\u306E\u9802\u70B9\n    // \u623B\u308A\
    \u5024: x \u304C\u5C5E\u3059\u308B\u96C6\u5408\u306E\u30B5\u30A4\u30BA\n    int\
    \ same_count(int x) {\n        return size[root(x)];\n    }\n\n    // \u73FE\u5728\
    \u306E\u30B0\u30EB\u30FC\u30D7\u6570\u3092\u53D6\u5F97\n    // \u623B\u308A\u5024\
    : \u73FE\u5728\u306E\u30B0\u30EB\u30FC\u30D7\u6570\n    int num_groups() const\
    \ {\n        return num_groups;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/unionfind/unionfind.hpp
  requiredBy: []
  timestamp: '2024-11-19 06:07:23+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/unionfind/unionfind.hpp
layout: document
title: Union-Find
---

基本的なUnion-Findは、以下の2つの操作を効率的に行うデータ構造です。

1. **Find（グループ判定）**: 要素が属する集合を見つける。
2. **Union（集合の併合）**: 2つの集合を1つにまとめる。

以下はそのC++コードの実装例です。

