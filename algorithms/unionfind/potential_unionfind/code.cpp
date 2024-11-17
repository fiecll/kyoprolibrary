// Potentialized Union-Find構造体
// 各要素間のポテンシャル差を管理する
class PotentializedUnionFind {
private:
    std::vector<int> parent;      // 親ノード
    std::vector<int64_t> weight;  // weight[x]: potential[x] - potential[parent[x]]

public:
    // コンストラクタ
    PotentializedUnionFind(int n) : parent(n), weight(n, 0) {
        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }

    // xの根を見つける（経路圧縮あり）
    // weight[x]をpotential[x] - potential[root]に更新
    int root(int x) {
        if (parent[x] == x)
            return x;
        int r = root(parent[x]);
        weight[x] += weight[parent[x]];
        return parent[x] = r;
    }

    // xとyをポテンシャル差wで併合
    // potential[y] = potential[x] + wとなるようにする
    // 一貫性が取れない場合はfalseを返す
    bool unite(int x, int y, int64_t w) {
        int rx = root(x);
        int ry = root(y);
        if (rx == ry) {
            // 一貫性のチェック
            if (potential(y) - potential(x) != w)
                return false;
            else
                return true;
        }
        w = w + weight[x] - weight[y]; // weightを調整
        parent[ry] = rx;
        weight[ry] = -w;
        return true;
    }

    // xのポテンシャルを取得
    int64_t potential(int x) {
        root(x); // weight[x]を更新
        return weight[x];
    }

    // xからyへのポテンシャル差（potential[y] - potential[x]）を取得
    // 連結していない場合はstd::nulloptを返す
    std::optional<int64_t> diff(int x, int y) {
        if (root(x) != root(y))
            return std::nullopt;
        return potential(y) - potential(x);
    }

    // xとyが同じグループに属するかを判定
    bool same(int x, int y) {
        return root(x) == root(y);
    }
};
