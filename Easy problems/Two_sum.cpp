
// 1. **Two Sum** (platform: LeetCode) (array)
/*Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
    int n = nums.size();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (nums[i] + nums[j] == target)
            {
                return {i, j};
            }
        }
    }
    return {};
}

int main()
{
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> result = twoSum(nums, target);

    if (!result.empty())
    {
        cout << "[" << result[0] << ", " << result[1] << "]" << endl;
    }
    else
    {
        cout << "No solution found" << endl;
    }

    return 0;
}

// Time complexity: O(n^2)
// Space complexity: O(1)
