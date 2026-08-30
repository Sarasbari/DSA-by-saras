class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size())
            swap(nums1, nums2);
        int m = nums1.size();
        int n = nums2.size();

        int left = 0;
        int right = m;
        int half = (m + n + 1) / 2;

        while (left <= right) {
            int i = left + (right - left) / 2;
            int j = half - i;

            int Aleft = (i == 0) ? INT_MIN : nums1[i - 1];
            int Aright = (i == m) ? INT_MAX : nums1[i];
            int Bleft = (j == 0) ? INT_MIN : nums2[j - 1];
            int Bright = (j == n) ? INT_MAX : nums2[j];

            if (Aleft <= Bright && Bleft <= Aright) {
                if ((m + n) % 2 == 1)
                    return max(Aleft, Bleft);
                return (max(Aleft, Bleft) + min(Aright, Bright)) / 2.0;
            } else if (Aleft > Bright)
                right = i - 1;
            else
                left = i + 1;
        }
        return 0.0;
    }
};