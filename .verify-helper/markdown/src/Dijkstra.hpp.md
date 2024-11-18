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
  bundledCode: "#line 1 \"src/Dijkstra.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n#define rep(i, n) for (int i = 0; i < (int)(n); i++)\n#define all(v) v.begin(),\
    \ v.end()\nusing ll = long long;\nusing P = pair<ll, int>; // Fix 1: Correct pair\
    \ comparison\nstruct Edge {\n  int to, cost;\n  Edge(int to, int cost) : to(to),\
    \ cost(cost) {}\n};\nusing Graph = vector<vector<Edge>>;\nconst long long INF\
    \ = 1LL << 60;\nvoid dijkstra(const Graph &G, int s, vector<long long> &dis) {\n\
    \    int N = G.size();\n    dis.resize(N, INF);\n    priority_queue<P, vector<P>,\
    \ greater<P>> pq;  // \u300C\u4EEE\u306E\u6700\u77ED\u8DDD\u96E2, \u9802\u70B9\
    \u300D\u304C\u5C0F\u3055\u3044\u9806\u306B\u4E26\u3076\n    dis[s] = 0;\n    pq.emplace(dis[s],\
    \ s);\n    while (!pq.empty()) {\n        P p = pq.top();\n        pq.pop();\n\
    \        int v = p.second;\n        if (dis[v] < p.first) {  // \u6700\u77ED\u8DDD\
    \u96E2\u3067\u7121\u3051\u308C\u3070\u7121\u8996\n            continue;\n    \
    \    }\n        for (auto &e : G[v]) {\n            if (dis[e.to] > dis[v] + e.cost)\
    \ {  // \u6700\u77ED\u8DDD\u96E2\u5019\u88DC\u306A\u3089 priority_queue \u306B\
    \u8FFD\u52A0\n                dis[e.to] = dis[v] + e.cost;\n                pq.emplace(dis[e.to],\
    \ e.to);\n            }\n        }\n    }\n}\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n#define rep(i, n) for (int\
    \ i = 0; i < (int)(n); i++)\n#define all(v) v.begin(), v.end()\nusing ll = long\
    \ long;\nusing P = pair<ll, int>; // Fix 1: Correct pair comparison\nstruct Edge\
    \ {\n  int to, cost;\n  Edge(int to, int cost) : to(to), cost(cost) {}\n};\nusing\
    \ Graph = vector<vector<Edge>>;\nconst long long INF = 1LL << 60;\nvoid dijkstra(const\
    \ Graph &G, int s, vector<long long> &dis) {\n    int N = G.size();\n    dis.resize(N,\
    \ INF);\n    priority_queue<P, vector<P>, greater<P>> pq;  // \u300C\u4EEE\u306E\
    \u6700\u77ED\u8DDD\u96E2, \u9802\u70B9\u300D\u304C\u5C0F\u3055\u3044\u9806\u306B\
    \u4E26\u3076\n    dis[s] = 0;\n    pq.emplace(dis[s], s);\n    while (!pq.empty())\
    \ {\n        P p = pq.top();\n        pq.pop();\n        int v = p.second;\n \
    \       if (dis[v] < p.first) {  // \u6700\u77ED\u8DDD\u96E2\u3067\u7121\u3051\
    \u308C\u3070\u7121\u8996\n            continue;\n        }\n        for (auto\
    \ &e : G[v]) {\n            if (dis[e.to] > dis[v] + e.cost) {  // \u6700\u77ED\
    \u8DDD\u96E2\u5019\u88DC\u306A\u3089 priority_queue \u306B\u8FFD\u52A0\n     \
    \           dis[e.to] = dis[v] + e.cost;\n                pq.emplace(dis[e.to],\
    \ e.to);\n            }\n        }\n    }\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/Dijkstra.hpp
  requiredBy: []
  timestamp: '2024-11-19 06:07:23+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/Dijkstra.hpp
layout: document
title: "\u30C0\u30A4\u30AF\u30B9\u30C8\u30E9"
---

ダイクストラ法の説明内容を書きます。
