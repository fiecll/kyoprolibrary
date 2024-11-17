// 基本的なUnion-Find
#include <vector>
#include <optional>
#include <algorithm>

class UnionFind {
private:
    std::vector<int> parent;
    std::vector<int> size;
    int num_groups;

public:
    UnionFind(int n) : parent(n), size(n, 1), num_groups(n) {
        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }

    int root(int x) {
        if (parent[x] == x)
            return x;
        else
            return parent[x] = root(parent[x]);
    }

    bool same(int x, int y) {
        return root(x) == root(y);
    }

    bool unite(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y)
            return false;
        if (size[x] < size[y])
            std::swap(x, y);
        parent[y] = x;
        size[x] += size[y];
        --num_groups;
        return true;
    }

    int same_count(int x) {
        return size[root(x)];
    }

    int num_groups() const {
        return num_groups;
    }
};
