class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());
        int answer = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (check(piles, mid, h)) {
                answer = mid;
                right = mid - 1;
            } else
                left = mid + 1;
        }
        return answer;
    }

    bool check(vector<int>& piles, int k, int hours) {
        for (int pile : piles) {
            hours -= pile / k;

            if (pile % k != 0)
                hours--;
            if (hours < 0)
                return false;
        }
        return true;
    }
};