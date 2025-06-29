// 69. ** Sqrt(x) ** (platform: leetcode,geeksforgeeks) (binary search)

/*Given a non-negative integer x, return the square root of x rounded down to the nearest integer.
 The returned integer should be non-negative as well.
You must not use any built-in exponent function or operator.
For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.*/

#include <iostream>
using namespace std;

int mySqrt(int x)
{
    if (x < 2)
        return x;

    int low = 1, high = x, ans;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (mid == x / mid)
        {
            return mid;
        }
        else if (mid < x / mid)
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return ans;
}

int main()
{
    int x;
    cout << "Enter a number to find its square root: ";
    cin >> x;

    int result = mySqrt(x);
    cout << "Square root of " << x << " is: " << result << endl;

    return 0;
}

// Time complexity: O(log n)
// Space complexity: O(1)


/* There is also a built in function in c++ sqrt(input)*/