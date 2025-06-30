// 136. ** Single Number ** (platform: LeetCode,Geekforgeeeks) (array , bit manipulation)

/*Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
You must implement a solution with a linear runtime complexity and use only constant extra space.*/

#include <iostream>
#include <vector>
using namespace std;

int singleNumber(vector<int> &nums)
{
    int xorr = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        xorr = xorr ^ nums[i];
    }
    return xorr;
}

int main()
{
    vector<int> nums = {4, 1, 2, 1, 2};

    int result = singleNumber(nums);
    cout << "The number that appears only once is: " << result << endl;

    return 0;
}

// Time complexity: O(n)
// Space complexity: O(1)
