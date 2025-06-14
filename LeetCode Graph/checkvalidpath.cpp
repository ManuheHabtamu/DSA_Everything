class Solution {
public:
    vector<int> parent;

int find(int a) {
    if (parent[a] != a) parent[a] = find(parent[a]);
    return parent[a];
}

bool hasValidPath(vector<vector<int>>& grid) {
    int x = grid.size();
    int y = grid[0].size();
    parent.resize(x * y);
    for (int i = 0; i < parent.size(); i++) parent[i] = i;

    auto connectLeft = [&](int p, int q) {
        if (q > 0 && (grid[p][q - 1] == 1 || grid[p][q - 1] == 4 ||
                       grid[p][q - 1] == 6)) {
            parent[find(p * y + q)] = find(p * y + q - 1);
        }
    };
    auto connectRight = [&](int p, int q) {
        if (q < y - 1 && (grid[p][q + 1] == 1 ||
                           grid[p][q + 1] == 3 ||
                           grid[p][q + 1] == 5)) {
            parent[find(p * y + q)] = find(p * y + q + 1);
        }
    };
    auto connectUp = [&](int p, int q) {
        if (p > 0 && (grid[p - 1][q] == 2 ||
                       grid[p - 1][q] == 3 ||
                       grid[p - 1][q] == 4)) {
            parent[find(p * y + q)] = find((p - 1) * y + q);
        }
    };
    auto connectDown = [&](int p, int q) {
        if (p < x - 1 && (grid[p + 1][q] == 2 ||
                           grid[p + 1][q] == 5 ||
                           grid[p + 1][q] == 6)) {
            parent[find(p * y + q)] = find((p + 1) * y + q);
        }
    };

    for (int p = 0; p < x; p++) {
        for (int q = 0; q < y; q++) {
            int t = grid[p][q];
            if (t == 1) {
                connectLeft(p, q);
                connectRight(p, q);
            } else if (t == 2) {
                connectUp(p, q);
                connectDown(p, q);
            } else if (t == 3) {
                connectLeft(p, q);
                connectDown(p, q);
            } else if (t == 4) {
                connectRight(p, q);
                connectDown(p, q);
            } else if (t == 5) {
                connectLeft(p, q);
                connectUp(p, q);
            } else {
                connectRight(p, q);
                connectUp(p, q);
            }
        }
    }
    return find(0) == find(x * y - 1);
}
};