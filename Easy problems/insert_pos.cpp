// 35. **Search Insert Position** (platform: LeetCode) (array)

/*Given a sorted array of distinct integers and a target value, return the index if the target is found.
 If not, return the index where it would be if it were inserted in order.*/

#include <iostream>
#include <vector>
using namespace std;

int searchInsert(vector<int> &nums, int target)
{
    int n = nums.size();
    int low = 0, high = n - 1;
    int ans = n; // Default insert position is at the end

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (nums[mid] >= target)
        {
            // If current mid is greater or equal to target,
            // update answer and move to the left half
            ans = mid;
            high = mid - 1;
        }
        else
        {
            // Else, move to the right half
            low = mid + 1;
        }
    }

    return ans;
}

int main()
{
    vector<int> nums = {1, 3, 5, 6};
    int target = 5;

    int index = searchInsert(nums, target);

    cout << "Target " << target << " should be at index: " << index << endl;

    return 0;
}

// Time complexity: O(log n)
// Space complexity: O(1)