class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        const int MAXX = 2048;

        vector<bool> one(MAXX, false);
        vector<bool> two(MAXX, false);
        vector<bool> three(MAXX, false);

        for (int num : nums) {
            for (int x = 0; x < MAXX; x++) {
                if (two[x])
                    three[x ^ num] = true;
            }
            for (int x = 0; x < MAXX; x++) {
                if (one[x])
                    two[x ^ num] = true;
            }
            one[num] = true;
        }

        for (int num : nums)
            three[num] = true;
        int ans = 0;
        for (bool x : three) {
            if (x)
                ans++;
        }
        return ans;
    }
};