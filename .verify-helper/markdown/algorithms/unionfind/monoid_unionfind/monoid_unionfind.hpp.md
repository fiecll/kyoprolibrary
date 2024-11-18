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
  bundledCode: "#line 1 \"algorithms/unionfind/monoid_unionfind/monoid_unionfind.hpp\"\
    \n// \u53EF\u63DB\u30E2\u30CE\u30A4\u30C9\u3092\u4E57\u305B\u305FUnion-Find\u69CB\
    \u9020\u4F53\n// \u5404\u9023\u7D50\u6210\u5206\u306E\u30E2\u30CE\u30A4\u30C9\u5024\
    \u3092\u7BA1\u7406\u3059\u308B\ntemplate<typename T, typename MonoidOp>\nclass\
    \ MonoidUnionFind {\nprivate:\n    std::vector<int> parent; // \u89AA\u30CE\u30FC\
    \u30C9\n    std::vector<int> size;   // \u5404\u6728\u306E\u30B5\u30A4\u30BA\n\
    \    std::vector<T> data;     // \u5404\u9023\u7D50\u6210\u5206\u306E\u30E2\u30CE\
    \u30A4\u30C9\u5024\n    int num_groups;          // \u30B0\u30EB\u30FC\u30D7\u306E\
    \u6570\n    MonoidOp op;             // \u30E2\u30CE\u30A4\u30C9\u6F14\u7B97\n\
    \npublic:\n    // \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\n    MonoidUnionFind(const\
    \ std::vector<T>& initial_data, MonoidOp op)\n        : parent(initial_data.size()),\
    \ size(initial_data.size(), 1), data(initial_data), num_groups(initial_data.size()),\
    \ op(op) {\n        for (int i = 0; i < parent.size(); ++i)\n            parent[i]\
    \ = i;\n    }\n\n    // x\u306E\u6839\u3092\u898B\u3064\u3051\u308B\uFF08\u7D4C\
    \u8DEF\u5727\u7E2E\u3042\u308A\uFF09\n    int root(int x) {\n        if (parent[x]\
    \ == x)\n            return x;\n        else {\n            parent[x] = root(parent[x]);\
    \ // \u7D4C\u8DEF\u5727\u7E2E\n            return parent[x];\n        }\n    }\n\
    \n    // x\u3068y\u304C\u540C\u3058\u30B0\u30EB\u30FC\u30D7\u306B\u5C5E\u3059\u308B\
    \u304B\u3092\u5224\u5B9A\n    bool same(int x, int y) {\n        return root(x)\
    \ == root(y);\n    }\n\n    // x\u3068y\u306E\u30B0\u30EB\u30FC\u30D7\u3092\u4F75\
    \u5408\n    // \u65E2\u306B\u540C\u3058\u30B0\u30EB\u30FC\u30D7\u306E\u5834\u5408\
    \u306Ffalse\u3092\u8FD4\u3059\n    bool unite(int x, int y) {\n        x = root(x);\n\
    \        y = root(y);\n        if (x == y)\n            return false;\n\n    \
    \    // \u30B5\u30A4\u30BA\u306B\u3088\u308B\u5408\u4F75\n        if (size[x]\
    \ < size[y])\n            std::swap(x, y);\n\n        parent[y] = x;\n       \
    \ size[x] += size[y];\n        data[x] = op(data[x], data[y]); // \u30E2\u30CE\
    \u30A4\u30C9\u5024\u3092\u66F4\u65B0\n        --num_groups;\n        return true;\n\
    \    }\n\n    // x\u304C\u5C5E\u3059\u308B\u30B0\u30EB\u30FC\u30D7\u306E\u30B5\
    \u30A4\u30BA\u3092\u53D6\u5F97\n    int same_count(int x) {\n        return size[root(x)];\n\
    \    }\n\n    // x\u304C\u5C5E\u3059\u308B\u30B0\u30EB\u30FC\u30D7\u306E\u30E2\
    \u30CE\u30A4\u30C9\u5024\u3092\u53D6\u5F97\n    T same_data(int x) {\n       \
    \ return data[root(x)];\n    }\n\n    // \u30B0\u30EB\u30FC\u30D7\u306E\u6570\u3092\
    \u53D6\u5F97\n    int num_groups() const {\n        return num_groups;\n    }\n\
    \n    // \u30B0\u30EB\u30FC\u30D7\u3092\u53D6\u5F97\n    std::vector<std::vector<int>>\
    \ groups() {\n        int n = parent.size();\n        std::vector<int> root_ids(n);\n\
    \        std::vector<int> group_size(n);\n        for (int i = 0; i < n; ++i)\
    \ {\n            root_ids[i] = root(i);\n            group_size[root_ids[i]]++;\n\
    \        }\n        std::vector<std::vector<int>> result(n);\n        for (int\
    \ i = 0; i < n; ++i) {\n            result[root_ids[i]].push_back(i);\n      \
    \  }\n        // \u7A7A\u3067\u306A\u3044\u30B0\u30EB\u30FC\u30D7\u306E\u307F\u3092\
    \u53CE\u96C6\n        std::vector<std::vector<int>> groups;\n        for (auto&\
    \ group : result) {\n            if (!group.empty())\n                groups.push_back(group);\n\
    \        }\n        return groups;\n    }\n};\n"
  code: "// \u53EF\u63DB\u30E2\u30CE\u30A4\u30C9\u3092\u4E57\u305B\u305FUnion-Find\u69CB\
    \u9020\u4F53\n// \u5404\u9023\u7D50\u6210\u5206\u306E\u30E2\u30CE\u30A4\u30C9\u5024\
    \u3092\u7BA1\u7406\u3059\u308B\ntemplate<typename T, typename MonoidOp>\nclass\
    \ MonoidUnionFind {\nprivate:\n    std::vector<int> parent; // \u89AA\u30CE\u30FC\
    \u30C9\n    std::vector<int> size;   // \u5404\u6728\u306E\u30B5\u30A4\u30BA\n\
    \    std::vector<T> data;     // \u5404\u9023\u7D50\u6210\u5206\u306E\u30E2\u30CE\
    \u30A4\u30C9\u5024\n    int num_groups;          // \u30B0\u30EB\u30FC\u30D7\u306E\
    \u6570\n    MonoidOp op;             // \u30E2\u30CE\u30A4\u30C9\u6F14\u7B97\n\
    \npublic:\n    // \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\n    MonoidUnionFind(const\
    \ std::vector<T>& initial_data, MonoidOp op)\n        : parent(initial_data.size()),\
    \ size(initial_data.size(), 1), data(initial_data), num_groups(initial_data.size()),\
    \ op(op) {\n        for (int i = 0; i < parent.size(); ++i)\n            parent[i]\
    \ = i;\n    }\n\n    // x\u306E\u6839\u3092\u898B\u3064\u3051\u308B\uFF08\u7D4C\
    \u8DEF\u5727\u7E2E\u3042\u308A\uFF09\n    int root(int x) {\n        if (parent[x]\
    \ == x)\n            return x;\n        else {\n            parent[x] = root(parent[x]);\
    \ // \u7D4C\u8DEF\u5727\u7E2E\n            return parent[x];\n        }\n    }\n\
    \n    // x\u3068y\u304C\u540C\u3058\u30B0\u30EB\u30FC\u30D7\u306B\u5C5E\u3059\u308B\
    \u304B\u3092\u5224\u5B9A\n    bool same(int x, int y) {\n        return root(x)\
    \ == root(y);\n    }\n\n    // x\u3068y\u306E\u30B0\u30EB\u30FC\u30D7\u3092\u4F75\
    \u5408\n    // \u65E2\u306B\u540C\u3058\u30B0\u30EB\u30FC\u30D7\u306E\u5834\u5408\
    \u306Ffalse\u3092\u8FD4\u3059\n    bool unite(int x, int y) {\n        x = root(x);\n\
    \        y = root(y);\n        if (x == y)\n            return false;\n\n    \
    \    // \u30B5\u30A4\u30BA\u306B\u3088\u308B\u5408\u4F75\n        if (size[x]\
    \ < size[y])\n            std::swap(x, y);\n\n        parent[y] = x;\n       \
    \ size[x] += size[y];\n        data[x] = op(data[x], data[y]); // \u30E2\u30CE\
    \u30A4\u30C9\u5024\u3092\u66F4\u65B0\n        --num_groups;\n        return true;\n\
    \    }\n\n    // x\u304C\u5C5E\u3059\u308B\u30B0\u30EB\u30FC\u30D7\u306E\u30B5\
    \u30A4\u30BA\u3092\u53D6\u5F97\n    int same_count(int x) {\n        return size[root(x)];\n\
    \    }\n\n    // x\u304C\u5C5E\u3059\u308B\u30B0\u30EB\u30FC\u30D7\u306E\u30E2\
    \u30CE\u30A4\u30C9\u5024\u3092\u53D6\u5F97\n    T same_data(int x) {\n       \
    \ return data[root(x)];\n    }\n\n    // \u30B0\u30EB\u30FC\u30D7\u306E\u6570\u3092\
    \u53D6\u5F97\n    int num_groups() const {\n        return num_groups;\n    }\n\
    \n    // \u30B0\u30EB\u30FC\u30D7\u3092\u53D6\u5F97\n    std::vector<std::vector<int>>\
    \ groups() {\n        int n = parent.size();\n        std::vector<int> root_ids(n);\n\
    \        std::vector<int> group_size(n);\n        for (int i = 0; i < n; ++i)\
    \ {\n            root_ids[i] = root(i);\n            group_size[root_ids[i]]++;\n\
    \        }\n        std::vector<std::vector<int>> result(n);\n        for (int\
    \ i = 0; i < n; ++i) {\n            result[root_ids[i]].push_back(i);\n      \
    \  }\n        // \u7A7A\u3067\u306A\u3044\u30B0\u30EB\u30FC\u30D7\u306E\u307F\u3092\
    \u53CE\u96C6\n        std::vector<std::vector<int>> groups;\n        for (auto&\
    \ group : result) {\n            if (!group.empty())\n                groups.push_back(group);\n\
    \        }\n        return groups;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: algorithms/unionfind/monoid_unionfind/monoid_unionfind.hpp
  requiredBy: []
  timestamp: '2024-11-17 21:48:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: algorithms/unionfind/monoid_unionfind/monoid_unionfind.hpp
layout: document
redirect_from:
- /library/algorithms/unionfind/monoid_unionfind/monoid_unionfind.hpp
- /library/algorithms/unionfind/monoid_unionfind/monoid_unionfind.hpp.html
title: algorithms/unionfind/monoid_unionfind/monoid_unionfind.hpp
---
