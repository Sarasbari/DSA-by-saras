class Solution {
public:
    vector<int> parent, sz;
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        parent.resize(n + 1);
        sz.assign(n + 1, 1);

        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }

        for (auto& edge : edges) {
            int a = edge[0];
            int b = edge[1];

            if (!unite(a, b))
                return edge;
        }
        return {};
    }

    bool unite(int a, int b) {
        int rootA = find(a);
        int rootB = find(b);

        if (rootA == rootB)
            return false; // already connected
        if (sz[rootA] < sz[rootB])
            swap(rootA, rootB);

        parent[rootB] = rootA;
        sz[rootA] += sz[rootB];

        return true;
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
};