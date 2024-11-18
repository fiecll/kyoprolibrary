#include <vector>
#include <optional>
#include <algorithm>

// Union-Find (Disjoint Set Union) クラス
// グラフの連結性を効率的に管理するデータ構造
class UnionFind {
private:
    std::vector<int> parent; // 各頂点の親を記録する配列
    std::vector<int> size;   // 各集合のサイズを記録する配列
    int num_groups;          // 現在のグループの数

public:
    // コンストラクタ
    // n: 頂点の数
    UnionFind(int n) : parent(n), size(n, 1), num_groups(n) {
        // 初期化: 各頂点を自分自身を親とする
        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }

    // 根を見つける（経路圧縮を適用）
    // x: 対象の頂点
    // 戻り値: x が属する集合の根
    int root(int x) {
        if (parent[x] == x)
            return x; // 自身が根の場合
        else
            return parent[x] = root(parent[x]); // 経路圧縮: 再帰的に根を探索し更新
    }

    // 2つの頂点が同じ集合に属しているか判定
    // x, y: 対象の頂点
    // 戻り値: 同じ集合に属していれば true
    bool same(int x, int y) {
        return root(x) == root(y); // 根が同じであれば同じ集合
    }

    // 2つの集合を統合
    // x, y: 対象の頂点
    // 戻り値: 統合が成功すれば true, 既に同じ集合なら false
    bool unite(int x, int y) {
        x = root(x); // x の根を取得
        y = root(y); // y の根を取得
        if (x == y) // 既に同じ集合の場合
            return false;

        // サイズが小さい方を大きい方に併合
        if (size[x] < size[y])
            std::swap(x, y);

        parent[y] = x;      // y を x の子にする
        size[x] += size[y]; // x の集合のサイズを更新
        --num_groups;       // グループ数を減少
        return true;
    }

    // x が属する集合のサイズを取得
    // x: 対象の頂点
    // 戻り値: x が属する集合のサイズ
    int same_count(int x) {
        return size[root(x)];
    }

    // 現在のグループ数を取得
    // 戻り値: 現在のグループ数
    int num_groups() const {
        return num_groups;
    }
};
