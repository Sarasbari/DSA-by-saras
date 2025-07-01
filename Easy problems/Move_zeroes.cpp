// 283. ** Moving Zeroes at end ** (platform: Leetcode,geeksforgeeks) {array, two pointers}

/*Given an integer array nums, move all 0's to the end of
 it while maintaining the relative order of the non-zero elements.
Note that you must do this in-place without making a copy of the array.*/

#include <iostream>
#include <vector>
using namespace std;

void moveZeroes(vector<int> &nums)
{
    int j = 0; // j points to where the next non-zero element should be placed
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        if (nums[i] != 0)
        {
            swap(nums[i], nums[j]);
            j++;
        }
    }
}

int main()
{
    // Example input
    vector<int> nums = {0, 1, 0, 3, 12}; // Expected output: 1 3 12 0 0

    moveZeroes(nums);

    cout << "Array after moving zeroes: ";
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}

// Time complexity: O(n)
// space complexity:O(1)
