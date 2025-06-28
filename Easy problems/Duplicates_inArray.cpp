// 26. **Remove Duplicates from Sorted Array** (platform: LeetCode) (array)

/*Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once.
 The relative order of the elements should be kept the same. Then return the number of unique elements in nums.

Consider the number of unique elements of nums to be k, to get accepted, you need to do the following things:

Change the array nums such that the first k elements of nums contain the unique elements in the order they were present in nums initially.
The remaining elements of nums are not important as well as the size of nums.
Return k.*/

#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int> &nums)
{
    int i = 0; // Pointer to track position of unique elements
    int n = nums.size();

    for (int j = 1; j < n; j++)
    {
        // If current element is different from the last unique one
        if (nums[j] != nums[i])
        {
            i++;               // Move the unique pointer forward
            nums[i] = nums[j]; // Overwrite the duplicate with the new unique element
        }
    }

    return i + 1; // Length of the array with unique elements
}

int main()
{
    vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};

    int k = removeDuplicates(nums); // k = number of unique elements

    cout << "After removing duplicates, unique elements are:" << endl;
    for (int i = 0; i < k; i++)
    {
        cout << nums[i] << " ";
    }
    cout << "\nTotal unique elements: " << k << endl;

    return 0;
}

// Time complexity: O(n)
// Space complexity: O(1)