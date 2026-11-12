class DetectSquares {
public:
    vector<vector<int>> cnt;
    DetectSquares() { cnt.resize(1001, vector<int>(1001, 0)); }

    void add(vector<int> point) {
        int x = point[0];
        int y = point[1];

        cnt[x][y]++;
    }

    int count(vector<int> point) {
        int x = point[0];
        int y = point[1];
        int ans = 0;

        for (int ny = 0; ny <= 1000; ny++) {
            int d = ny - y;
            if (d == 0)
                continue;

            int vertical = cnt[x][ny];

            int right = x + d;
            if (right >= 0 && right <= 1000) {
                ans += vertical * cnt[right][y] * cnt[right][ny];
            }

            int left = x - d;
            if (left >= 0 && left <= 1000) {
                ans += vertical * cnt[left][y] * cnt[left][ny];
            }
        }
        return ans;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */