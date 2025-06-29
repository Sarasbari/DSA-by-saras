// 28. **Merge Sorted Array** (platform: LeetCode) (array)

/*You are given two integer arrays nums1 and nums2, sorted in non-decreasing order,
and two integers m and n, representing the number of elements in nums1 and nums2 respectively.
Merge nums1 and nums2 into a single array sorted in non-decreasing order.
The final sorted array should not be returned by the function, but instead be stored inside the array nums1.
To accommodate this, nums1 has a length of m + n,
 where the first m elements denote the elements that should be merged,
  and the last n elements are set to 0 and should be ignored. nums2 has a length of n.*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to merge two sorted arrays nums1 and nums2
// nums1 has enough space to hold all elements of nums2
void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int left = m - 1; // Pointer at the end of initialized part of nums1
    int right = 0;    // Pointer at the start of nums2

    // Swap elements to make larger ones go to nums2 and smaller ones to nums1
    while (left >= 0 && right < n)
    {
        if (nums1[left] > nums2[right])
        {
            swap(nums1[left], nums2[right]);
            left--;
            right++;
        }
        else
        {
            break; // Arrays are already in correct order
        }
    }

    // Sort both arrays individually after swap operation
    sort(nums1.begin(), nums1.begin() + m);
    sort(nums2.begin(), nums2.end());

    // Copy sorted nums2 into the remaining space in nums1
    for (int i = 0; i < n; i++)
    {
        nums1[m + i] = nums2[i];
    }
}

int main()
{
    vector<int> nums1 = {1, 3, 5, 0, 0, 0}; // First array with extra space
    vector<int> nums2 = {2, 4, 6};          // Second array

    int m = 3; // Number of initialized elements in nums1
    int n = 3; // Number of elements in nums2

    merge(nums1, m, nums2, n);

    cout << "Merged array: ";
    // Print all elements in the nums1 array
    for (int i = 0; i < nums1.size(); i++)
    {
        cout << nums1[i] << " ";
    }
    cout << endl; // Move to the next line after printing

    return 0;
}

// Time complexity: O((m+n) log(m+n))
// Space complexity: O(1)