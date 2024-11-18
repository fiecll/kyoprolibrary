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
  bundledCode: "#line 1 \"src/2D_CumulativeSum.hpp\"\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n#define rep(i, n) for (int i = 0; i < (int)(n); i++)\nusing\
    \ ll = long long;\nusing Graph = vector<vector<int>>;\nusing P = pair<int,int>;\n\
    \n// a:\u5BFE\u8C61\u306E\u4E8C\u6B21\u5143\u914D\u5217\n// [h1,h2)\xD7[w1,w2)\
    \ \u306E\u7BC4\u56F2\u306E\u533A\u9593\u548C\u3092\u8FD4\u3057\u307E\u3059\n\n\
    // \u524D\u51E6\u7406\u3092\u884C\u3046\n// S:\u7D2F\u7A4D\u548C\u3092\u8A18\u9332\
    \u3059\u308B\u914D\u5217\nvoid pre_process(vector<vector<int>> const &a, vector<vector<int>>\
    \ &S) {\n    int H = (int)a.size();\n    int W = (int)a[0].size();\n    S.assign(H\
    \ + 1, vector<int>(W + 1));\n    for (int h = 1; h < H + 1; h++) {\n        for\
    \ (int w = 1; w < W + 1; w++) {\n            S[h][w] = a[h - 1][w - 1] + S[h][w\
    \ - 1] + S[h - 1][w] - S[h - 1][w - 1];\n        }\n    }\n}\n// [h1,h2)\xD7[w1,w2)\
    \ \u306E\u533A\u9593\u548C\u3092\u6C42\u3081\u308B\nint query(int h1, int h2,\
    \ int w1, int w2, vector<vector<int>> const &S) {\n    return S[h2][w2] - S[h1][w2]\
    \ - S[h2][w1] + S[h1][w1];\n}\n//\u4EE5\u4E0B\u3000H*W\nint main() {\n    int\
    \ h,w;\n    cin >> h >> w;\n    vector<vector<int>>a(h,vector<int>(w));\n    vector<vector<int>>S(h,vector<int>(w));\n\
    \    rep(i,hh)rep(j,w) cin >> a[i] >> a[j];\n    pre_process(a, S);\n    int p,q,r,s;\n\
    \    cij >> p >> q >> r >> s;\n    cout << query(p,r,q,s,S) << endl;  // [1,3)\xD7\
    [2,3) = 3+3 = 6\n    return 0;\n}\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n#define rep(i, n) for (int\
    \ i = 0; i < (int)(n); i++)\nusing ll = long long;\nusing Graph = vector<vector<int>>;\n\
    using P = pair<int,int>;\n\n// a:\u5BFE\u8C61\u306E\u4E8C\u6B21\u5143\u914D\u5217\
    \n// [h1,h2)\xD7[w1,w2) \u306E\u7BC4\u56F2\u306E\u533A\u9593\u548C\u3092\u8FD4\
    \u3057\u307E\u3059\n\n// \u524D\u51E6\u7406\u3092\u884C\u3046\n// S:\u7D2F\u7A4D\
    \u548C\u3092\u8A18\u9332\u3059\u308B\u914D\u5217\nvoid pre_process(vector<vector<int>>\
    \ const &a, vector<vector<int>> &S) {\n    int H = (int)a.size();\n    int W =\
    \ (int)a[0].size();\n    S.assign(H + 1, vector<int>(W + 1));\n    for (int h\
    \ = 1; h < H + 1; h++) {\n        for (int w = 1; w < W + 1; w++) {\n        \
    \    S[h][w] = a[h - 1][w - 1] + S[h][w - 1] + S[h - 1][w] - S[h - 1][w - 1];\n\
    \        }\n    }\n}\n// [h1,h2)\xD7[w1,w2) \u306E\u533A\u9593\u548C\u3092\u6C42\
    \u3081\u308B\nint query(int h1, int h2, int w1, int w2, vector<vector<int>> const\
    \ &S) {\n    return S[h2][w2] - S[h1][w2] - S[h2][w1] + S[h1][w1];\n}\n//\u4EE5\
    \u4E0B\u3000H*W\nint main() {\n    int h,w;\n    cin >> h >> w;\n    vector<vector<int>>a(h,vector<int>(w));\n\
    \    vector<vector<int>>S(h,vector<int>(w));\n    rep(i,hh)rep(j,w) cin >> a[i]\
    \ >> a[j];\n    pre_process(a, S);\n    int p,q,r,s;\n    cij >> p >> q >> r >>\
    \ s;\n    cout << query(p,r,q,s,S) << endl;  // [1,3)\xD7[2,3) = 3+3 = 6\n   \
    \ return 0;\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/2D_CumulativeSum.hpp
  requiredBy: []
  timestamp: '2024-11-19 06:07:23+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/2D_CumulativeSum.hpp
layout: document
redirect_from:
- /library/src/2D_CumulativeSum.hpp
- /library/src/2D_CumulativeSum.hpp.html
title: src/2D_CumulativeSum.hpp
---
