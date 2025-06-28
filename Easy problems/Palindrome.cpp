// 9. **Palindrome Number** (platform: LeetCode) (Math)
/*Given an integer x, return true if x is a palindrome, and false otherwise.*/

#include <iostream>
#include <climits>
using namespace std;

bool isPalindrome(int x)
{
    if (x < 0)
        return false;

    int ans = 0, rem;
    int num = x;

    while (num != 0)
    {
        rem = num % 10;
        num /= 10;
        if (ans > INT_MAX / 10)
            return false;
        ans = ans * 10 + rem;
    }

    return ans == x;
}

int main()
{
    int x = 121; // You can change this to test other values

    if (isPalindrome(x))
    {
        cout << x << " is a palindrome." << endl;
    }
    else
    {
        cout << x << " is not a palindrome." << endl;
    }

    return 0;
}

// Time complexity : O(logn)
// Space complexity : O(1)
